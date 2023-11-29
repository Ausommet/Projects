new Chart("graph_subreddit_scores", {
  type: "bar",
  data: {
    labels: graph1_x,
    datasets: [{
      fill: false,
      lineTension: 0,
      backgroundColor: "rgba(255, 139, 90, 1.0)",
      borderColor: "rgba(255, 139, 90, 1.0)",
      data: graph1_y
    }]
  },
  options: {
    legend: {display: false},
  }
});

new Chart("graph_posts_scores", {
  type: "bar",
  data: {
    labels: graph2_x,
    datasets: [{
      fill: false,
      lineTension: 0,
      backgroundColor: "rgba(147, 145, 255, 1.0)",
      borderColor: "rgba(255, 255, 255, 1)",
      data: graph2_y
    }]
  },
  options: {
    legend: {display: false},
    scales: {
      x: {
        ticks: {
          callback: function() {}
        }
      }
    }
  }
});

new Chart("graph_scores", {
  type: "pie",
  data: {
    labels: graph3_x,
    datasets: [{
      fill: false,
      lineTension: 0,
      backgroundColor: ["rgba(255, 139, 90, 1.0)", "rgba(147, 145, 255, 1.0)"],
      borderColor: "rgba(255, 255, 255, 1)",
      data: graph3_y
    }]
  },
  options: {
    legend: {display: false},
  }
}); 