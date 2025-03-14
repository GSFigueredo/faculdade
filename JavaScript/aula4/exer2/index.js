let valorEmp = document.getElementById("valorEmp");
let taxaJuros = document.getElementById("taxaJuros");
let tempo = document.getElementById("tempo");
let tabelaDados = document.getElementById("tabelaDados");
let id = 0;

let emp = [];
let jur = [];
let tem = [];

function calcularJuros() {
    id++;
    if (valorEmp.value == "" || taxaJuros.value == "" || tempo.value == "") {
        alert("Preencha todos os campos!");
    } else {

        emp.push(valorEmp.value);
        jur.push(taxaJuros.value);
        tem.push(tempo.value);

        for (i = 0; i < id; i++) {

            tabelaDados.innerHTML += `<p>${id}</p><p>${valorEmp}</p><p>${taxaJuros}</p><p>${tempo}</p>`;

            let juros = (emp[i].value * (jur[i].value/100) * tem[i].value );
            let valorTotal = (valorEmprestimo[i] + juros[i]);

            tabelaDados.innerHTML += `tr><td>${id}</td><td>${juros}</td><td>${valorTotal}</td></tr>`;
        }

        event.preventDefault();
    }
}

function limpar() {
    tabelaDados.innerHTML = '';
    event.preventDefault();
}

function removerAnterior() {
    tabelaDados.innerHTML = "";

    for (i = 0; i < id; i++) {
        if (i == id - 1) {
            id--;
        }
    }
    event.preventDefault();
}