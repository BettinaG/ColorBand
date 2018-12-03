var e = document.getElementById("meinRechteckCanvas");
var canv = e.getContext("2d");
canv.fillStyle = "black";
canv.fillRect(75,0,400,400);
console.log(e);

function save(){
// Funktion zum speichern
console.log("SAVE");
}
function reset(){
// Funktion zum resetten
confirm("Alles wird zurückgesetzt!");
console.log("RESET");
}
function back(){
// FUnktion zum zurücksetzen
confirm("Das letzte Objekt wird gelöscht!");
console.log("BACK");
}