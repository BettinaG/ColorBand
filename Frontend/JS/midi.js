var context = new AudioContext();
var sound1 = new Audio("../Sounds/aGuitar.wav");
var sound2 = new Audio("../Sounds/bass.wav");
var sound3 = new Audio("../Sounds/cello.wav");
var sound4 = new Audio("../Sounds/drums.wav");
var soundNode = context.createMediaElementSource(sound1);
var gainNode = context.createGain();
gainNode.gain.value = 0.8;
soundNode.connect(gainNode);
gainNode.connect(context.destination);


if (navigator.requestMIDIAccess) {
	console.log('This browser supports WebMIDI!');
	navigator.requestMIDIAccess( { sysex: true } )
    .then(onMIDISuccess, onMIDIFailure);
function onMIDISuccess(midiAccess) {
    console.log(midiAccess);
	
	for (var input of midiAccess.inputs.values())
        input.onmidimessage = getMIDIMessage;
    var inputs = midiAccess.inputs;
    var outputs = midiAccess.outputs;
    sound4.play();
    sound4.loop = true;
    sound3.play();
    sound3.loop = true;
    sound2.play();
    sound2.loop = true;
    sound1.play();
    sound1.loop = true;
}

function onMIDIFailure() {
    console.log('Could not access your MIDI devices.');
}
function getMIDIMessage(midiMessage) {
    console.log(midiMessage);

    var startBit = midiMessage.data[0];
    var color = midiMessage.data[1];
    var xCoord3 = midiMessage.data[2];
    var yCoord3 = midiMessage.data[3];
    var endBit = midiMessage.data[4];
    var xCoord = (xCoord3 * 3);
    var yCoord = (yCoord3 * 3);

    // if(xCoord <= 3){
    //     gainNode.gain.setValueAtTime(xCoord, audioContext.currentTime);
    // }
    // else{
    //     gainNode.gain.setValueAtTime(xCoord, audioContext.currentTime);
    // }

    
    switch(color){
        case 0: //nichts
            console.log('Keine Farbe');
            playSound(color);
            console.log(index);
            
            break;
        case 1: //rot
            console.log('ES IST ROT!!!!!!!');
            playSound(color);
            break;
        case 2: //blau
            console.log('ES IST BLAU!!!!!!');
            console.log(index);
            playSound(color);
            break;
        case 3: //grün
            console.log('ES IST GRÜN!!!!!!');
            playSound(color);
            break;
        
    }
}

} else {
	console.log('WebMIDI is not supported in this browser.');
}