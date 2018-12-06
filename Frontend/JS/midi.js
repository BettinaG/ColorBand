var context = new AudioContext();
var sound1 = new Audio("../Sounds/aGuitar.wav");
var sound2 = new Audio("../Sounds/bass.wav");
var sound3 = new Audio("../Sounds/cello.wav");
var sound4 = new Audio("../Sounds/drums.wav");
var sound5 = new Audio("../Sounds/drums2.wav");
var sound6 = new Audio("../Sounds/eGuitar.wav");
var sound7 = new Audio("../Sounds/ePiano.wav");
var sound8 = new Audio("../Sounds/hawaiianDrums.wav");
var sound9 = new Audio("../Sounds/percussions.wav");
var sound10 = new Audio("../Sounds/piano1.wav");
var sound11 = new Audio("../Sounds/piano2.wav");
var sound12 = new Audio("../Sounds/piano3.wav");
var sound13 = new Audio("../Sounds/rollingBrass.wav");
var sound14 = new Audio("../Sounds/synth.wav");
var sound15 = new Audio("../Sounds/violine.wav");
var sounds = [sound1, sound2, sound3, sound4, sound5, sound6, sound7, sound8, sound9, sound10, sound11, sound12, sound13, sound14, sound15];
var status;
var soundNodes = new Array (sounds.length);
var filterNode = context.createBiquadFilter();
var gainNodes = new Array (sounds.length);

// var soundNode = context.createMediaElementSource(sound1);
var myGain;
// var gainNode = context.createGain();
// soundNode.connect(gainNode);
// gainNode.connect(context.destination);
// var soundNode2 = context.createMediaElementSource(sound2);
// var gainNode2 = context.createGain();
// soundNode2.connect(gainNode2);
// gainNode2.connect(context.destination);

for (var i = 0; i < sounds.length; i++){
    soundNodes[i] = context.createMediaElementSource(sounds[i]);
    gainNodes[i] = context.createGain();
    soundNodes[i].connect(filterNode);
    filterNode.connect(gainNodes[i]);
    gainNodes[i].connect(context.destination);
}
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
        var xCoord = (xCoord3 * 6);
        var yCoord = (yCoord3 * 6);
        myGain = xCoord / 600;

        function pauseSounds(){
            for (var i = 0; i<sounds.length; i++){
                sounds[i].pause();
                sounds[i].currentTime = 0;
            }
        }

        for (var j = 0; j<10; j++){
            var y = j*30;

            if (yCoord > y && yCoord < y+30){
                status = j;
                for (var i = 0; i < sounds.length; i++){
                    if (i == status){         
                        sounds[i].play();
                        sounds[i].loop = true;
                    }else{
                        sounds[i].pause();
                        sounds[i].currentTime = 0;
                    }
                }
            }
        }
        /* if (yCoord >= 270){
            status = 0;
            for (var i = 0; i < sounds.length; i++){
                if (i == status){         
                    sounds[i].play();
                    sounds[i].loop = true;
                }else{
                    sounds[i].pause();
                    sounds[i].currentTime = 0;
                }
            }
        }
        else if (240 <= yCoord && yCoord < 270) {
            status = 1;
            for (var i = 0; i < sounds.length; i++){
                if (i == status){         
                    sounds[i].play();
                    sounds[i].loop = true;
                }else{
                    sounds[i].pause();
                    sounds[i].currentTime = 0;
                }
            }
        }
        else if (210 <= yCoord && yCoord < 240) {
            status = 2;
            for (var i = 0; i < sounds.length; i++){
                if (i == status){         
                    sounds[i].play();
                    sounds[i].loop = true;
                }else{
                    sounds[i].pause();
                    sounds[i].currentTime = 0;
                }
            }
        }
        else if (180 <= yCoord && yCoord < 210) {
            status = 3;
            for (var i = 0; i < sounds.length; i++){
                if (i == status){         
                    sounds[i].play();
                    sounds[i].loop = true;
                }else{
                    sounds[i].pause();
                    sounds[i].currentTime = 0;
                }
            }
        }
        else if (150 <= yCoord && yCoord < 180) {
            status = 4;
            for (var i = 0; i < sounds.length; i++){
                if (i == status){         
                    sounds[i].play();
                    sounds[i].loop = true;
                }else{
                    sounds[i].pause();
                    sounds[i].currentTime = 0;
                }
            }
        }
        else if (120 <= yCoord && yCoord < 150) {
            status = 5;
            for (var i = 0; i < sounds.length; i++){
                if (i == status){         
                    sounds[i].play();
                    sounds[i].loop = true;
                }else{
                    sounds[i].pause();
                    sounds[i].currentTime = 0;
                }
            }
        }
        else if (90 <= yCoord && yCoord < 120) {
            status = 6;
            for (var i = 0; i < sounds.length; i++){
                if (i == status){         
                    sounds[i].play();
                    sounds[i].loop = true;
                }else{
                    sounds[i].pause();
                    sounds[i].currentTime = 0;
                }
            }
        }
        else if (60 <= yCoord && yCoord < 90) {
            status = 7;
            for (var i = 0; i < sounds.length; i++){
                if (i == status){         
                    sounds[i].play();
                    sounds[i].loop = true;
                }else{
                    sounds[i].pause();
                    sounds[i].currentTime = 0;
                }
            }
        }
        else if (30 <= yCoord && yCoord < 60) {
            status = 8;
            for (var i = 0; i < sounds.length; i++){
                if (i == status){         
                    sounds[i].play();
                    sounds[i].loop = true;
                }else{
                    sounds[i].pause();
                    sounds[i].currentTime = 0;
                }
            }
        }
        else {
            for (var i = 0; i < sounds.length; i++){
                sounds[i].pause();
                sounds[i].currentTime = 0;
            }
        } */


        switch(color){
            case 0: //nichts
                console.log('Keine Farbe');
                yCoord = -1;
                pauseSounds();
                break;
            case 1: //rot
                console.log('ES IST ROT!!!!!!!');
                
                break;
            case 2: //blau
                console.log('ES IST BLAU!!!!!!');
                console.log(myGain);
                console.log(yCoord);
                filterNode.type = "notch";
                filterNode.detune = 0;
                filterNode.Q = 0;
                filterNode.frequency = 5000;
                break;
            case 3: //grün
                console.log('ES IST GRÜN!!!!!!');
                filterNode.type = "lowshelf";
                filterNode.detune.value = 100;
                break;
            
        }
}

} else {
	console.log('WebMIDI is not supported in this browser.');
}