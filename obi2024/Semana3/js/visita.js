'use strict';
const start = Date.now()
process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', function (inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function () {
    inputString = inputString.split('\n');

    main();
});

function readLine() {
    return inputString[currentLine++];
}

let todasCidades = null, custosLocomocao = null;
let cidadesTotalmenteExploradas = 0

function main() {

    // Ex: Leitura de linha que remove espaços em branco e transforma em array de numeros
    const [qtdCidades, cidadeOrigem, cidadeDestino] = readLine().replace(/\s+$/g, '').split(' ').map(arrTemp => parseInt(arrTemp, 10));
    const _todasCidades = {}
    const _custosLocomocao = {}

    for (let i = 0; i < qtdCidades - 1; i++) {
        const [pontoA, pontoB, custo] = readLine().replace(/\s+$/g, '').split(' ').map(arrTemp => parseInt(arrTemp, 10));

        if (!_todasCidades[pontoA]) _todasCidades[pontoA] = {
            id: pontoA,
            vizinhos: new Set(),
            totalmenteExplorada: false,
            locomocaoConsolidado: null
        }

        _todasCidades[pontoA].vizinhos.add(pontoB)

        if (!_todasCidades[pontoB]) _todasCidades[pontoB] = {
            id: pontoB,
            vizinhos: new Set(),
            totalmenteExplorada: false,
            locomocaoConsolidado: null
        }

        _todasCidades[pontoB].vizinhos.add(pontoA)


        _custosLocomocao[`${pontoA}-${pontoB}`] = custo
        _custosLocomocao[`${pontoB}-${pontoA}`] = custo
    }

    todasCidades = _todasCidades
    custosLocomocao = _custosLocomocao
    visita(qtdCidades, cidadeOrigem, cidadeDestino)

}

// function explorarCidade(cidadeSerExplorada) {
//     if (cidadeSerExplorada.totalmenteExplorada) return
//     cidadeSerExplorada.totalmenteExplorada = true
//
//     for (const numeroVizinho of cidadeSerExplorada.vizinhos) {
//         const cidadeVizinha = todasCidades[numeroVizinho]
//         if (cidadeVizinha.totalmenteExplorada) continue
//         const novoCusto = cidadeSerExplorada.locomocaoConsolidado + custosLocomocao[`${cidadeSerExplorada.id}-${cidadeVizinha.id}`]
//         if (!cidadeVizinha.locomocaoConsolidado || novoCusto < cidadeVizinha.locomocaoConsolidado) {
//             cidadeVizinha.locomocaoConsolidado = novoCusto
//         }
//         explorarCidade(cidadeVizinha)
//     }
// }

function visita(qtdCidades, cidadeOrigem, cidadeDestino) {
    todasCidades[cidadeOrigem].locomocaoConsolidado = 0
    // explorarCidade(todasCidades[cidadeOrigem])
    const cidadesQueue = [
        todasCidades[cidadeOrigem]
    ]

    do {
        const length = cidadesQueue.length
        for (const cidade of cidadesQueue) {
            if (cidade.totalmenteExplorada) continue
            cidade.totalmenteExplorada = true

            for (const numeroVizinho of cidade.vizinhos) {
                const cidadeVizinha = todasCidades[numeroVizinho]
                if (cidadeVizinha.totalmenteExplorada) continue
                const novoCusto = cidade.locomocaoConsolidado + custosLocomocao[`${cidade.id}-${cidadeVizinha.id}`]
                if (!cidadeVizinha.locomocaoConsolidado || novoCusto < cidadeVizinha.locomocaoConsolidado) {
                    cidadeVizinha.locomocaoConsolidado = novoCusto
                }

                cidadesQueue.push(cidadeVizinha)
            }
        }
        cidadesQueue.splice(0, length)
        if (cidadesQueue.length === 0) {
            console.log(todasCidades[cidadeDestino].locomocaoConsolidado)
        }
    } while (cidadesQueue.length > 0)
}