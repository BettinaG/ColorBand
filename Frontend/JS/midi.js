// MIDI setup
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
