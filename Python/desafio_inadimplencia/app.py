import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import streamlit as st
import os

from sklearn.model_selection import train_test_split, GridSearchCV
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import classification_report, confusion_matrix, roc_auc_score, roc_curve
from sklearn.linear_model import LogisticRegression
from sklearn.ensemble import RandomForestClassifier

# Configuração da página
st.set_page_config(layout="wide")
st.title("📊 Previsão de Inadimplência em Cartões de Crédito")

# Carregamento com cache (evita carregar várias vezes desnecessariamente)
@st.cache_data
def carregar_dados():
    dados = pd.read_csv('UCI_Credit_Card.csv')
    dados.rename(columns={'default.payment.next.month': 'inadimplente'}, inplace=True)
    return dados

# Carregando os dados
dados = carregar_dados()

# Exibição inicial dos dados
st.subheader("📁 Olhando os Dados")
st.write(f"Número de linhas e colunas: {dados.shape}")
st.dataframe(dados.head())

# Verificar valores ausentes
st.subheader("🧼 Há dados faltando?")
st.write(dados.isnull().sum())

# Estatísticas básicas
st.subheader("📊 Como são os dados?")
st.write(dados.describe())

# Distribuição da variável alvo (inadimplente)
st.subheader("🎯 Quem pagou e quem não pagou?")
fig1, ax1 = plt.subplots()
sns.countplot(x='inadimplente', data=dados, ax=ax1)
ax1.set_title('0 = Pagou / 1 = Não pagou')
st.pyplot(fig1)

# Boxplots para verificar outliers
st.subheader("📦 Valores muito altos ou baixos (Outliers)")
for col in ['LIMIT_BAL', 'AGE']:
    fig, ax = plt.subplots()
    sns.boxplot(data=dados, y=col, ax=ax)
    ax.set_title(f'Boxplot - {col}')
    st.pyplot(fig)

# Histogramas das variáveis
st.subheader("📈 Como estão distribuídos os dados?")
for col in ['LIMIT_BAL', 'AGE']:
    fig, ax = plt.subplots()
    ax.hist(dados[col], bins=30)
    ax.set_title(f'Distribuição - {col}')
    ax.set_xlabel(col)
    ax.set_ylabel("Quantidade")
    st.pyplot(fig)

# Matriz de correlação entre as variáveis
st.subheader("🔗 Correlação entre Variáveis")
fig_corr, ax_corr = plt.subplots(figsize=(12, 8))
sns.heatmap(dados.corr(numeric_only=True), cmap='coolwarm', ax=ax_corr)
st.pyplot(fig_corr)

# Ajuste de valores extremos (outliers)
dados['LIMIT_BAL'] = dados['LIMIT_BAL'].clip(upper=dados['LIMIT_BAL'].quantile(0.99))
dados['AGE'] = dados['AGE'].clip(upper=dados['AGE'].quantile(0.99))

# Separando variáveis e alvo
dados.drop('ID', axis=1, inplace=True)
X = dados.drop('inadimplente', axis=1)
y = dados['inadimplente']

# Padronização (deixar todos os dados na mesma escala)
scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

# Divisão em treino e teste
X_train, X_test, y_train, y_test = train_test_split(
    X_scaled, y, test_size=0.3, random_state=42, stratify=y)

# Treinamento dos modelos
st.subheader("🤖 Treinando os Modelos")
with st.spinner("⏳ Treinando... isso pode levar alguns segundos"):
    # Regressão Logística
    modelo_rl = LogisticRegression(max_iter=1000)
    modelo_rl.fit(X_train, y_train)
    pred_rl = modelo_rl.predict(X_test)

    # Floresta Aleatória com validação (busca por melhores parâmetros)
    param_grid = {'n_estimators': [100], 'max_depth': [None]}
    modelo_rf = GridSearchCV(RandomForestClassifier(random_state=42), param_grid, cv=5, scoring='f1')
    modelo_rf.fit(X_train, y_train)
    pred_rf = modelo_rf.predict(X_test)

# Avaliação dos modelos
st.subheader("📊 Como os modelos se saíram?")

resultados = []

for nome, modelo, y_pred in [
    ('Regressão Logística', modelo_rl, pred_rl),
    ('Floresta Aleatória', modelo_rf.best_estimator_, pred_rf)
]:
    auc = roc_auc_score(y_test, modelo.predict_proba(X_test)[:, 1])
    relatorio = classification_report(y_test, y_pred, output_dict=True)

    st.markdown(f"### 🔍 {nome}")
    st.text(f"Matriz de Confusão:\n{confusion_matrix(y_test, y_pred)}")
    st.text(f"Relatório:\n{classification_report(y_test, y_pred)}")
    st.write(f"AUC (Área sob curva ROC): {auc:.4f}")

    resultados.append({
        "Modelo": nome,
        "Acurácia": relatorio['accuracy'],
        "Precisão": relatorio['1']['precision'],
        "Recall": relatorio['1']['recall'],
        "F1-Score": relatorio['1']['f1-score'],
        "AUC": auc
    })

# Tabela comparando os dois modelos
st.subheader("📋 Comparativo entre os Modelos")
st.dataframe(pd.DataFrame(resultados))

# Curvas ROC
fpr_rl, tpr_rl, _ = roc_curve(y_test, modelo_rl.predict_proba(X_test)[:, 1])
fpr_rf, tpr_rf, _ = roc_curve(y_test, modelo_rf.best_estimator_.predict_proba(X_test)[:, 1])

fig_roc, ax_roc = plt.subplots()
ax_roc.plot(fpr_rl, tpr_rl, label="Regressão Logística")
ax_roc.plot(fpr_rf, tpr_rf, label="Floresta Aleatória")
ax_roc.plot([0, 1], [0, 1], 'k--')
ax_roc.set_title("📉 Curvas ROC")
ax_roc.set_xlabel("Taxa de Falsos Positivos")
ax_roc.set_ylabel("Taxa de Verdadeiros Positivos")
ax_roc.legend()
st.pyplot(fig_roc)
#pip install streamlit
#cd Python/desafio_inadimplencia
#streamlit run app.py