# 1. Criação e manipulação
minha_lista = [10, "Python", True, 3.14, [1, 2, 3]]
print("Primeiro elemento:", minha_lista[0])
print("Último elemento:", minha_lista[-1])
print("Três primeiros elementos:", minha_lista[:3])

# 2. Modificação e adição de elementos
minha_lista.append("Novo Elemento")
minha_lista.insert(2, "novo_valor_2")
removido = minha_lista.pop(2)
print("Lista após modificações:", minha_lista)
print("Elemento removido:", removido)

# 3. Ordenação e inversão
numeros = [5, 2, 9, 1, 7]
numeros.sort()
print("Lista ordenada:", numeros)
numeros.reverse()
print("Lista invertida:", numeros)

# Tentativa de ordenar lista com números e strings
try:
    mix = [3, "texto", 1, "abc"]
    mix.sort()
except TypeError as e:
    print("Erro ao tentar ordenar lista mista:", e)

# 4. Desafio - Operações matemáticas
lista_numeros = list(range(1, 11))
lista_multiplicada = [x * 2 for x in lista_numeros]
lista_pares = [x for x in lista_numeros if x % 2 == 0]
print("Lista multiplicada por 2:", lista_multiplicada)
print("Números pares da lista original:", lista_pares)

# Parte 2: Dicionários
# 5. Criação e acesso
dados_pessoais = {"nome": "João", "idade": 25, "cidade": "São Paulo"}
print("Idade:", dados_pessoais["idade"])
dados_pessoais["profissao"] = "Engenheiro"

# 6. Modificação e remoção
dados_pessoais["cidade"] = "Rio de Janeiro"
del dados_pessoais["idade"]
print("Dicionário após remoção:", dados_pessoais)
print("Chave 'telefone' presente?", "telefone" in dados_pessoais)

# 7. Iteração e métodos úteis
print("Chaves:", list(dados_pessoais.keys()))
print("Valores:", list(dados_pessoais.values()))
print("Itens:", list(dados_pessoais.items()))

# 8. Desafio - Cadastro de usuários
usuarios = {"12345678900": "Alice", "98765432100": "Bruno", "55566677700": "Carlos"}
cpf = input("Digite um CPF para consulta: ")
if cpf in usuarios:
    print("Nome cadastrado:", usuarios[cpf])
else:
    print("CPF não cadastrado.")
