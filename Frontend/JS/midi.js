var context = new AudioContext(),
    sound1 = new Audio("../Sounds/aGuitar.wav"),
    sound2 = new Audio("../Sounds/bass.wav"),
    sound3 = new Audio("../Sounds/cello.wav"),
    sound4 = new Audio("../Sounds/drums.wav"),
    sound5 = new Audio("../Sounds/drums2.wav"),
    sound6 = new Audio("../Sounds/eGuitar.wav"),
    sound7 = new Audio("../Sounds/ePiano.wav"),
    sound8 = new Audio("../Sounds/hawaiianDrums.wav"),
    sound9 = new Audio("../Sounds/percussions.wav"),
    sound10 = new Audio("../Sounds/piano1.wav"),
    sound11 = new Audio("../Sounds/piano2.wav"),
    sound12 = new Audio("../Sounds/piano3.wav"),
    sound13 = new Audio("../Sounds/rollingBrass.wav"),
    sound14 = new Audio("../Sounds/synth.wav"),
    sound15 = new Audio("../Sounds/violine.wav"),
    sounds = [sound1, sound2, sound3, sound4, sound5, sound6, sound7, sound8, sound9, sound10, sound11, sound12, sound13, sound14, sound15];
    
var test = 0;

var status,
    isInitialized = false,
    soundNodes = new Array (sounds.length),
    currentGain = 0,
    sGain,
    currentSound,
    savedSounds = new Array ();

var color,
    xCoord,
    yCoord;

var amountOfSavedElements = 0,
    filterNodes = new Array(),
    gainNodes = new Array ();


var savedPositions = new Array(),
    colorString;

var e = document.getElementById("meinRechteckCanvas"),
    canv = e.getContext("2d");
        canv.width = e.width;
        canv.height = e.height;


// for (var i = 0; i < sounds.length; i++){
//     soundNodes[i] = context.createMediaElementSource(sounds[i]);
//     gainNodes[i] = context.createGain();
//     soundNodes[i].connect(filterNode);
//     filterNode.connect(gainNodes[i]);
//     gainNodes[i].connect(context.destination);
// }

function initialize(){
    for(let i = 0; i < sounds.length; i++){
        soundNodes[i] = context.createMediaElementSource(sounds[i]);
    }
    gainNodes[0] = context.createGain();
    filterNodes[0] = context.createBiquadFilter();

    filterNodes[0].connect(gainNodes[0]);
    gainNodes[0].connect(context.destination);
    
    isInitialized = true;
}



function playSound(){   
    for (var j = 0; j<15; j++){
        var y = j*30;
        if (yCoord > y && yCoord < y+30){
            status = j;
            for (var i = 0; i < sounds.length; i++){
                if (i == status){       
                    soundNodes[i].connect(filterNodes[amountOfSavedElements]);

                    sounds[i].play();
                    sounds[i].loop = true;
                    currentSound = i;
                } else if (!savedSounds.includes(i)){
                    sounds[i].pause();
                    sounds[i].currentTime = 0;
                }
            }
        }
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

function setGain(){
    currentGain = 1 - (xCoord/630);
    gainNodes[amountOfSavedElements].gain.value = currentGain;
}

function setFilterType(){
    switch(color){
        case 0: //nichts
            //console.log('Keine Farbe');
            for(var i=0; i<sounds.length; i++){
                if(savedSounds.includes(i)){
                    gainNodes[savedSounds[amountOfSavedElements]].gain.value = gainNodes[amountOfSavedElements].gain.value;
                }
}
            pauseSounds();
            colorString = "";
            break;
        case 1: //rot
           // console.log('rot');
            filterNodes[amountOfSavedElements].type = "allpass";
            colorString = "red";
            break;
        case 2: //blau
            //console.log('blau');
            filterNodes[amountOfSavedElements].type = "lowpass";
            colorString = "blue";
            break;
        case 3: //grün
           // console.log('grün');
            filterNodes[amountOfSavedElements].type = "highpass";
            colorString = "green";
            break;
    }
}

//FUNCTIONS FOR SAVING/DELETING SOUNDS

function saveSounds(){
    gainNodes[amountOfSavedElements].gain.value = currentGain;
    savedSounds[amountOfSavedElements] = currentSound;
    savePosition(colorString, xCoord, yCoord, amountOfSavedElements);

    amountOfSavedElements++;
    gainNodes[amountOfSavedElements] = context.createGain();
    filterNodes[amountOfSavedElements] = context.createBiquadFilter();

    filterNodes[amountOfSavedElements].connect(gainNodes[amountOfSavedElements]);
    gainNodes[amountOfSavedElements].connect(context.destination);
}

function revertSavedSound(){
    savedSounds.splice((saveSounds.length-1), 1);
    savedPositions.splice((savedPositions.length - 1), 1);
}

function clearSoundArray(){
    confirm("Alles wird zurückgesetzt!");
    while(!savedSounds.length == 0){
        savedSounds.splice((saveSounds.length - 1), 1);
        gainNodes.splice((gainNodes.length - 1), 1);
        filterNodes.splice((filterNodes.length - 1), 1);
        savedPositions.splice(savedPositions.length - 1, 1);
    }

    amountOfSavedElements = 0;
    
    canv.clearRect(0, 0, canv.width, canv.height);
}

// FUNCTIONS FOR DRAWING

function drawPosition(x,y){
    canv.clearRect(0, 0, canv.width, canv.height);

    canv.fillStyle = "black";

    if(x != 0) canv.fillRect((canv.width-x/(520/canv.width))+20, (y-6)*0.32, 10, 10);
}

function savePosition(color, x, y, amountOfSavedElements){
    savedPositions[amountOfSavedElements] = new Array(color, x, y);
}

function drawAllSavedPositions(){
    for(let j = 0; j<savedPositions.length; j++){
        canv.fillStyle = savedPositions[j][0];
        canv.fillRect((canv.width-savedPositions[j][1]/(520/canv.width))+20, (savedPositions[j][2]/(380/canv.height))-5, 10, 10);
    }
}

//MIDI setup
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
    function getMIDIMessage(midiMessage) {
        //console.log(midiMessage);
        //Color Value
            color = midiMessage.data[1];
        //X-Coord - mulitplied by 6 because it was divided for MIDI transmission
            xCoord = midiMessage.data[2] * 6;
        //Y-Coord - mulitplied by 6 because it was divided for MIDI transmission
            yCoord = midiMessage.data[3] * 6;


            startPlaying();        
    }

} else {
	console.log('WebMIDI is not supported in this browser.');
}

function startPlaying(){
    if(!isInitialized) {
        initialize();
    }

    console.log("Can width: "+ canv.width + "   Can Height: " + canv.height);
    // console.log("x: " + xCoord + "   y: " + yCoord);
    // console.log("saved elemts: " + amountOfSavedElements + "   saved positions: " + savedPositions.length);
    if(gainNodes.length > 1){
        console.log("saved Gain: " + gainNodes[0].gain.value);
        console.log("current gain: " + currentGain);

    }

        playSound();

        setGain();
    
        setFilterType();
    
        drawPosition(xCoord, yCoord);
        drawAllSavedPositions();
}