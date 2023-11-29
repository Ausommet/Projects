var icon = document.querySelector('#icon');
var help = document.querySelector('#help');
var historyButton = document.querySelector('#history');
icon.onclick = function(){
    document.body.classList.toggle("dark-theme");
    if(document.body.classList.contains("dark-theme")){
        help.src = "/static/img/help-dark.png";
        console.log(help.src);
        historyButton.getElementsByTagName('img')[0].src = "/static/img/history-dark.png";
    } 
    else{
     
        help.src =  "/static/img/help.png";
        console.log(help.src)
        historyButton.getElementsByTagName('img')[0].src = "/static/img/history.png";
    }
}





function showTable() { //Function to toggle show/hide the table
    var table = document.getElementById("table");
    if (table.style.display === "none") {
        table.style.display = "table";
    } else {
        table.style.display = "none";
    }
}

