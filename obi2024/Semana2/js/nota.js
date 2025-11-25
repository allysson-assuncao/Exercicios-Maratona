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

    const [corteA] = readLine().replace(/\s+$/g, '').split(' ').map(arrTemp => parseInt(arrTemp, 10));
    const [corteB] = readLine().replace(/\s+$/g, '').split(' ').map(arrTemp => parseInt(arrTemp, 10));
    novoScript(corteA,corteB)

}

function novoScript(corteA, corteB) {
    const larguraNota = 160
    const alturaNota = 70

    const corteAsc = [corteA,corteB].sort((a,b)=> a-b)

    const pedacoEsquerdoAreaQ = (corteAsc[0]*alturaNota)+((corteB-corteA)*alturaNota)
    const pedacoEsquerdoAreaT = ((corteB-corteA)*alturaNota)/2
    const pedacoEsquerdoArea = pedacoEsquerdoAreaQ+pedacoEsquerdoAreaT
    const areaTotal = larguraNota*alturaNota
    const areaDireito = areaTotal-pedacoEsquerdoArea

    let result = 0
    if(pedacoEsquerdoArea> areaDireito){
        result = 1
    }else if(pedacoEsquerdoArea< areaDireito){
        result = 2
    }

    console.log(result)

}