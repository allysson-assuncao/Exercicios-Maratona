'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputString = inputString.split('\n');

    main();
});

function readLine() {
    return inputString[currentLine++];
}

function main() {

    const [qtdPecas] = readLine().replace(/\s+$/g, '').split(' ').map(arrTemp => parseInt(arrTemp, 10));
    novoScript(qtdPecas+1)

}

function novoScript(qtdPecas) {
    const metadePecas = qtdPecas/2
    const ultimaLinha = qtdPecas+1

    console.log(metadePecas*ultimaLinha)

}