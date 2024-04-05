class boneco { 
    constructor(cor, tamanho, tipo) {
        this.cor = cor; 
        this.tamanho = tamanho;
        this.tipo = tipo; 
    }

    correr() {
        console.log("Correndo")
    }

    falar() { 
        console.log("Falando")
    }
}

let boneco1 = new boneco('preto', 20, 'héroi')

console.log(boneco1.correr())