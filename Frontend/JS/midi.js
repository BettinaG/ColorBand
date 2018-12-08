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
var myGain;
var sGain;
var test;
var actualSound;
var savedSound;
var savedSounds = new Array ();

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
        //console.log(midiAccess);
        for (var input of midiAccess.inputs.values())
            input.onmidimessage = getMIDIMessage;
        var inputs = midiAccess.inputs;
        var outputs = midiAccess.outputs;
    }
    function onMIDIFailure() {
        console.log('Could not access your MIDI devices.');
    }   
    function saveSounds(){
        myGain = sGain;
        savedSound = actualSound;
        savedSounds.push(savedSound);
        console.log(actualSound);
        console.log(savedSound);
        console.log("Saved:" + sounds[savedSound]);
        saveGain();
    }
    function revertSavedSound(){
        savedSounds.splice((saveSounds.length-1), 1);
    }
    function clearSoundArray(){
        while(!savedSounds.length == 0){
            savedSounds.splice((fruits.length - 1), 1);
        }
    }
    function saveGain(){
    }
    function getMIDIMessage(midiMessage) {
        //console.log(midiMessage);
        //Can be ignored
        var startBit = midiMessage.data[0];
        //Color Value
        var color = midiMessage.data[1];
        //X-Coord divided by 6
        var xCoord3 = midiMessage.data[2];
        //Y-Coord divided by 6
        var yCoord3 = midiMessage.data[3];
        //Can be ignored
        var endBit = midiMessage.data[4];
        //X-Coord multiplied by 6
        var xCoord = (xCoord3 * 6);
        //Y-Coord multiplied by 6
        var yCoord = (yCoord3 * 6);

        //Divisor needs to be adjusted by Pixelsize of camera
        myGain =1 - (xCoord / 600);

        function controlSounds(){
            for (var i = 0; i<sounds.length; i++){
                //console.log(myGain);
                gainNodes[i].gain.value = myGain;
            }
        }
        function pauseSounds(){
            for (var i = 0; i<sounds.length; i++){
                if(!savedSounds.includes(i)){
                sounds[i].pause();
                sounds[i].currentTime = 0;
                }
            }
        }
        for (var j = 0; j<15; j++){
            var y = j*30;
            if (yCoord > y && yCoord < y+30){
                status = j;
                for (var i = 0; i < sounds.length; i++){
                    if (i == status){       
                        sounds[i].play();
                        sounds[i].loop = true;
                        actualSound = i;
                    } else if (!savedSounds.includes(i)){
                        sounds[i].pause();
                        sounds[i].currentTime = 0;
                    }
                }
            }
        }
        controlSounds();
        switch(color){
            case 0: //nichts
                //console.log('Keine Farbe');
                yCoord = -1;
                pauseSounds();
                if (savedSounds.length > 1){
                gainNodes[savedSound].gain.value = sGain;
                }
                break;
            case 1: //rot
                //console.log('ES IST ROT!!!!!!!');
                break;
            case 2: //blau
               // console.log('ES IST BLAU!!!!!!');
               // console.log(myGain);
               // console.log(yCoord);
                filterNode.type = "notch";
                filterNode.detune = 0;
                filterNode.Q = 0;
                break;
            case 3: //grün
               // console.log('ES IST GRÜN!!!!!!');
                filterNode.type = "lowshelf";
                filterNode.detune.value = 100;
                break;
        }
    }
} else {
	console.log('WebMIDI is not supported in this browser.');
}