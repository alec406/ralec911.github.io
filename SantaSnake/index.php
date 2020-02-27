<html>
  <head>

    <meta charset="UTF-8">
    <meta name="Author" content="Evan Wilken, Alec Richardson">
    <meta name="Description" content="Santa Snake">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <script
      src="https://code.jquery.com/jquery-3.4.1.min.js"
      integrity="sha256-CSXorXvZcTkaix6Yvo6HppcZGetbYMGWSFlBw8HfCJo="
      crossorigin="anonymous">
    </script>
    <script type="text/javascript" src="./javascript/main.js"></script>
    <link rel="stylesheet" type="text/css" href="./CSS/style.css">
  </head>
  <body>

    <div class="top-container">
      <img class="santapicL" src="./images/santa art.png" alt="santa"
      title="santa shadow"/>
      <img class="santapicR" src="./images/santa art.png" alt="santa"
      title="santa shadow"/>
      <h1 class= "title">Santa Snake</h1>

    </div>

    <div class="main">

    <div class="tab-container">
        <div class="tabbut">
            <div class="tab-button tab-active" id="but-game" onclick="openGame()">Game</div>
        </div>
        <div class="tabbut">
            <div class="tab-button" id="but-highscore" onclick="openHighscore()">Highscores</div>
        </div>
    </div>

    <div class="scorecount">
        <h2 class="scoredisp"> Score:  </h2>
        <h2 id="currscore" class="currscoredisp"></h2>
    </div>

    <div class="game-end-container">    
            <form action="index.php" method="post">
            Name: <input type="text" name="name"><br>
            Score: <input type="text" name="score"><br>
            <input type="submit" name="submit" value="submit" onclick="openHighScore()">
            </form>
      </div>

    <div class="intro-popin-container">
      <div class="intro-popin">
          <div class="play-button-container">
              <div class="play-button" onclick="closeIntroPopin()">PLAY</div>
          </div>
      </div>
    </div>


    <div class="game-container">
        <canvas class="gamecanvas"></canvas>
    </div>

    </div>

    <div class="highscore-container">
      <div class="highscore-column">
        <h1><u>The Best Scores</u></h1>
         <table border="1" align="center">
            <tr>
               <td>Name</td>
               <td>Score</td>
            </tr>

     <?php
        $con = mysqli_connect("localhost", "root", "Rich94509!", "snake_game");

          $sql = mysqli_query($con, "SELECT * FROM players ORDER BY score DESC LIMIT 18");

           while ($row = mysqli_fetch_array($sql)) {
           echo
             "<tr>
              <td>{$row['name']}</td>
              <td>{$row['score']}</td>
              </tr>\n";
          }
  ?>  
  </table>

       
      </div>  

    </div>


    </div>


  </body>

</html>

<?php
   
   if(isset($_POST['submit'])) {  //the post form has been submitted
       $name = $_POST["name"];
       $score = $_POST["score"];
       $sql = "INSERT INTO PLAYERS (name, score) VALUES ('$name', '$score')";

       if (!mysqli_query($con, $sql)) {
           die('');
          } else {
          echo "";
       }
       

   }

?>
