if (navigator.requestMIDIAccess) {
	console.log('This browser supports WebMIDI!');
	navigator.requestMIDIAccess()
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
}

} else {
	console.log('WebMIDI is not supported in this browser.');
}







// ''function initialize(){
// 	let midi = null;  // global MIDIAccess object
// 	let midiInputs = [];
// 	function onMIDISuccess( midiAccess ) {
// 	  console.log( "MIDI ready!" );
// 	  midi = midiAccess;  // store in the global (in real usage, would probably keep in an object instance)
// 		listInputsAndOutputs(midi);
// 	}

// 	function onMIDIFailure(msg) {
// 	  console.log( "Failed to get MIDI access - " + msg );
// 	}

// 	navigator.requestMIDIAccess().then( onMIDISuccess, onMIDIFailure );
// 	function listInputsAndOutputs( midiAccess ) {
// 		const inputPortSelector = document.getElementById('inputportselector');
// 		for (let input of midiAccess.inputs.values()) {
// 		  var opt = document.createElement("option");
// 		  opt.text = input.name;
// 		  document.getElementById("inputportselector").add(opt);
// 		  midiInputs.push(input);
// 		  console.log( "Input port [type:'" + input.type + "'] id:'" + input.id +
// 			"' manufacturer:'" + input.manufacturer + "' name:'" + input.name +
// 			"' version:'" + input.version + "'" );
// 		}
// 		if (midiInputs.length > 1){
// 			inputPortSelector.addEventListener('click', ()=>{
// 				selectMidiInput(inputPortSelector.selectedIndex);
// 			});
// 		}
// 		selectMidiInput(inputPortSelector.selectedIndex);
// 	}

	
// 	function selectMidiInput(index){
// 		const selectedIndex = document.getElementById('inputportselector').selectedIndex;
// 		const midiInput = midiInputs[selectedIndex];
// 		midiInput.onmidimessage = MIDIMessageEventHandler;
// 		return midiInput;
// 	}
// 	function MIDIMessageEventHandler(event) {
//       // Mask off the lower nibble (MIDI channel, which we don't care about)
//       switch (event.data[0] & 0xf0) {
//         case 0x90:
// 			if (event.data[2]==0) { 
// 				noteOff(event.data[1]);
// 			}
// 			else{
// 				noteOn(event.data[1], event.data[2]);
// 			}
// 			break;
//         case 0x80:
// 			noteOff(event.data[1]);
// 			break;
// 		case 0xB0:
// 			controlChange(event.data[1], event.data[2]);
// 			break;
// 		case 0xC0:
// 			programChange(event.data[1]);
// 			break;
// 		case 0xE0:
// 			pitchbend(event.data[1], event.data[2]);
// 			break;
//       }
//     }
// 	function noteOn(noteNumber, velocity){
// 		console.log(`note on: note=${noteNumber}, velocity = ${velocity}`);
// 	}
// 	function noteOff(noteNumber){
// 		console.log(`note off: note=${noteNumber}`);
// 	}
// 	function controlChange(controller, value){
// 		console.log(`control change: controller = ${controller}, value = ${value}`);
// 	}
// 	function programChange(program){
// 		console.log(`program change: program=${program}`);
// 	}
// 	function pitchbend(value1, value2){
// 		console.log(value1 * 128 + " " + value2);
// 		const pitchbendValue = (value1 * 128 + value2) - 8192;
// 		console.log(`pitch bend: value = ${pitchbendValue}`);
// 	}
// }''