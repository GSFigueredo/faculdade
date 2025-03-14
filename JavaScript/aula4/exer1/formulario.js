let res = document.getElementById("res");
let nomeVendedor = document.getElementById("nomeVendedor");
let valorVenda = document.getElementById("valorVenda");
let tabela = document.getElementById("tabela");
let id = 0;

let vendedor = [];
let venda = [];
let desconto = [];


function cadastrar() {
    id++;
    if (nomeVendedor.value == "" || valorVenda.value == "") {
        window.alert("Erro!!! Nome do vendedor ou Valor não foram preenchidos");
    } else {
        desconto.push(Number(valorVenda.value) * 0.1);
        vendedor.push(nomeVendedor.value);
        venda.push(Number(valorVenda.value));

        for (i = 0; i < id; i++) {

            console.log(vendedor[i]);
            tabela.innerHTML = `<tr><td>${id}</td><td>${vendedor[i]}</td><td>R$${venda[i].toFixed(2)}</td><td>R$${desconto[i].toFixed(2)}</td></tr>`;
        }

        event.preventDefault();
    }
}

function limpar() {
    tabela.innerHTML = "";
    vendedor = [];
    venda = [];
    desconto = [];
    event.preventDefault();
}

function removerAnterior() {
    desconto.pop();
    vendedor.pop();
    venda.pop();
    tabela.innerHTML = "";

    for (i = 0; i < vendedor.length; i++) {
        let o = i + 1;
        res.innerHTML += `<p>${o}</p><p>${vendedor[i]}</p><p>R$${venda[i].toFixed(2)}</p><p>R$${desconto[i].toFixed(2)}</p>`;
    }
    event.preventDefault();
}