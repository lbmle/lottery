const selecionados = [];
const acertos = [];
let fim = 0;
const buttons = document.getElementsByClassName("num-button");

for (let i = 0; i < buttons.length; i++) {
    buttons[i].addEventListener("click", function() {
        const marcado = parseInt(this.value);
        selecionarNumero(marcado);
        atualizarBotoes();
    });
}	

function selecionarNumero(marcado) {
    if (fim) window.location.reload();
    if (selecionados.includes(marcado)) {
        const index = selecionados.indexOf(marcado);
        selecionados.splice(index, 1);
    }
    else {
        if (selecionados.length < 6) {
            selecionados.push(marcado);
        }
    }
    if (selecionados.length == 6) {
        mostrarSelecionados();
        mostrarSorteados();
        mostrarAcertos();
        fim = 1;			
    }
}

function atualizarSelecionados() {
    const selecionadosDiv = document.getElementById("selecionados");
    selecionadosDiv.innerHTML = "";
    for (let i = 0; i < selecionados.length; i++) {
        const span = document.createElement("span");
        span.innerHTML = selecionados[i];
        selecionadosDiv.appendChild(span);
    }
}

function mostrarSelecionados() {
    const selecionadosDiv = document.getElementById("selecionados");
    const numbersAsc = selecionados.sort((a, b) => {
        return a - b;
    });
    selecionadosDiv.innerHTML = "Você selecionou os números: " + selecionados.join(", ");
}

function mostrarSorteados() {
    const sorteadosDiv = document.getElementById("sorteados");
    sorteadosDiv.innerHTML = "";
    const numerosAleatorios = [];			
    while (numerosAleatorios.length < 6) {
        const numero = Math.floor(Math.random() * 60) + 1;
        if (!numerosAleatorios.includes(numero)) {
            numerosAleatorios.push(numero);
                if (selecionados.includes(numero))
                        acertos.push(numero);
        }
    }

    for (let i = 0; i < buttons.length; i++) {																	
        if (acertos.includes(parseInt(buttons[i].value)))
            buttons[i].classList.add("acerto");
        else if (numerosAleatorios.includes(parseInt(buttons[i].value)))					
            buttons[i].classList.add("sorteado");						
        else if (selecionados.includes(parseInt(buttons[i].value))) 
            buttons[i].classList.add("selecionado");
        else
            buttons[i].classList.add("nada");				
    }
    const numbersAsc = numerosAleatorios.sort((a, b) => {
        return a - b;
    });
    sorteadosDiv.innerHTML = "Os números sorteados são: " + numerosAleatorios.join(", ");
    
}

function mostrarAcertos() {
    const acertosDiv = document.getElementById("acertos");
    const numbersAsc = acertos.sort((a, b) => {
        return a - b;
    });
    acertosDiv.innerHTML = "Você acertou os números: " + acertos.join(", ");
    acertos.length = 0;
}

function atualizarBotoes() {
    for (let i = 0; i < buttons.length; i++) {
        const numero = parseInt(buttons[i].value);
        if (selecionados.includes(numero)) {
            buttons[i].classList.add("selecionado");
        }
        else {
            buttons[i].classList.remove("selecionado");
            
        }
    }
}