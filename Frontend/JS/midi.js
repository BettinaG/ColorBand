var context = new AudioContext();
var source1, source2, source3;
var sourceBuffers = [source1, source2, source3];
var i = 0;
var drumpads = document.getElementsByClassName("drumpad");

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

    for (let i = 0; i < drumpads.length; i++) {
        getData(i);
        drumpads[i].addEventListener("mousedown", function (e) {playSound(i)});
    }

    function getData(color){
        var request = new XMLHttpRequest();
        request.open('GET, "../sounds/sound"+ (color + 1) + ".wav", true');
        request.responseType = 'arraybuffer';
        request.onload = function (){
            var undecodedAudio = request.response;
    
            context.decodeAudioData(undecodedAudio, function (buffer){
                sourceBuffers[color] = context.createBufferSource();
                sourceBuffers[color].buffer = buffer;
                sourceBuffers[color].connect(context.destination);
            });
        };
        request.send();
    }
    function playSound(color){
        getData(color);
        sourceBuffers[color].start(0);
    }
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