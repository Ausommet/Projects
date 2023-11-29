function sortTable(n) {
    var table, rows, sorting, i, current, next, sortBool, order, timesSorted = 0;
    table = document.getElementById("postTable");
    sorting = true;
    order = "asc";
    while (sorting) {
      sorting = false;
      rows = table.rows;
      for (i = 1; i < (rows.length - 1); i++) {
        sortBool = false;
        current = rows[i].getElementsByTagName("td")[n];
        next = rows[i + 1].getElementsByTagName("td")[n];
        if (order == "asc") {
          if (current.innerHTML.toLowerCase() > next.innerHTML.toLowerCase()) {
            sortBool = true;
            break;
          }
        } else if (order == "desc") {
          if (current.innerHTML.toLowerCase() < next.innerHTML.toLowerCase()) {
            sortBool = true;
            break;
          }
        }
      }
      if (sortBool) {
        rows[i].parentNode.insertBefore(rows[i + 1], rows[i]);
        sorting = true;
        timesSorted ++;
      } else {
        if (timesSorted == 0 && order == "asc") {
          order = "desc";
          sorting = true;
        }
      }
    }
    var headerRow = table.rows[0];
    var headerCells = headerRow.getElementsByTagName("TH");
    for (i = 0; i < headerCells.length; i++) {
      headerCells[i].innerHTML = headerCells[i].innerHTML.replace(" ▲", "");
      headerCells[i].innerHTML = headerCells[i].innerHTML.replace(" ▼", "");
    }
    if (order == "asc") {
      headerCells[n].innerHTML += " ▲";
    } else if (order == "desc") {
      headerCells[n].innerHTML += " ▼";
    }
  }

  document.getElementById("colour_icon").onclick = function(){
    document.body.classList.toggle("dark-theme");
  }