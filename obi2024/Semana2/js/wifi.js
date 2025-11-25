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

    const [qtdQuadrados] = readLine().replace(/\s+$/g, '').split(' ').map(arrTemp => parseInt(arrTemp, 10));
    let quadradosPosis = []
    for(let i =0;i<qtdQuadrados;i++){
        // type = x1,y1,x2,y2
        const coordenadas = readLine().replace(/\s+$/g, '').split(' ').map(arrTemp => parseInt(arrTemp, 10));
        quadradosPosis.push(coordenadas)
    }
    
    wifi(qtdQuadrados,quadradosPosis)

}

function seQuadradoPossuiFilho([x1,y1,x2,y2], todosQuadrados){
    let has = false
    for(const [qx1,qy1,qx2,qy2] of todosQuadrados){
        const superiorEsquerdoX = x1<qx1
        const inferiorDireitoX = x2>qx2
        const superiorEsquerdoY = y1>qy1
        const inferiorDireitoY = y2<qy2
        if(superiorEsquerdoX && superiorEsquerdoY&& inferiorDireitoX&&inferiorDireitoY) {
            has=true
            break
        }
    }

    return has
}

function wifi(qtdQuadrados, todosQuadrados){
    let quadradosSemFilho = 0
    for(const quadrado of todosQuadrados){
        const possuiFilho = seQuadradoPossuiFilho(quadrado, todosQuadrados)
        if(!possuiFilho){
            quadradosSemFilho++
        }
    }

    console.log(quadradosSemFilho)
}