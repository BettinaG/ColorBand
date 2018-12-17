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
 
var isInitialized = false,
    currentGain = 0,
    currentSound,
    color,
    colorString,
    xCoord,
    yCoord;

var soundNodes = new Array (sounds.length),
    filterNodes = new Array(),
    gainNodes = new Array ();

var amountOfSavedElements = 0,
    savedPositions = new Array(),
    savedSounds = new Array ();

var e = document.getElementById("meinRechteckCanvas"),
    canv = e.getContext("2d");
        canv.width = e.width;
        canv.height = e.height;