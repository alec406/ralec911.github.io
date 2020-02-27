var userName = null;
var score = 0;



function openGame() {
    console.log("GAME");
    $('.game-end-container').hide();
    $('.game-container').show();
    $('.scorecount').show();
    $('.game-end-container').hide();
    $('.highscore-container').hide();
    $('#but-game').addClass("tab-active");
    $('#but-highscore').removeClass("tab-active");
}

function openHighscore() {
     console.log("HIGHSCORE");
     $('.game-container').hide();
     $('.game-end-container').hide();
     $('.highscore-container').show();
     $('.scorecount').hide();
     $('#but-game').removeClass("tab-active");
     $('#but-highscore').addClass("tab-active");
}

function closeIntroPopin() {
   $(".intro-popin-container").fadeOut();
   $('.game-end-container').hide();
   $('.game-container').show();
   gameGo();
}

function gameEnd() {
  $('.game-end-container').show();
  $(".game-container").fadeOut();

}


//trying to disable keys scrolling the window -Evan
window.addEventListener("keydown", function(e) {
    // space and arrow keys
    if([32, 37, 38, 39, 40].indexOf(e.keyCode) > -1) {
        e.preventDefault();
    }
}, false);


function gameGo() {
    var SIZE = 700; // Size of the play-field in pixels
    var GRID_SIZE = SIZE / 50;
    var c = document.querySelector(".gamecanvas");
    c.height = c.width = SIZE * 2;
    c.style.width = c.style.height = SIZE + 'px';
    var context = c.getContext('2d');
    context.scale(2, 2);

    var direction = newDirection = 1; // -2: up, 2: down, -1: left, 1: right
    var snakeLength = 5;
    var snake = [{x: SIZE / 2, y: SIZE / 2}];
    var candy = null;
    var end = false;
    var score = 0;


    function randomOffset() {
      return Math.floor(Math.random() * SIZE / GRID_SIZE) * GRID_SIZE;
    }

    function text(txt, font, x, y, c) {
      context.fillStyle = c;
      context.font = font;
      context.fillText(txt,x,y)
    }

    function stringifyCoord(obj) {
      return [obj.x, obj.y].join(',');
    }

    function tick() {
      var newHead = {x: snake[0].x, y: snake[0].y};

      // Only change directon if the new direction is a different axis
      if (Math.abs(direction) !== Math.abs(newDirection)) {
        direction = newDirection;
      }
      var axis = Math.abs(direction) === 1 ? 'x' : 'y'; // 1, -1 are X; 2, -2 are Y
      if (direction < 0) {
        newHead[axis] -= GRID_SIZE;
      } else {
        newHead[axis] += GRID_SIZE;
      }

      // Did we eat a candy? Detect if our head is in the same cell as the candy
      if (candy && candy.x === newHead.x && candy.y === newHead.y) {
        candy = null;
        snakeLength += 20;
        score += 1;
      }

      context.fillStyle = 'lightblue';
      context.fillRect(0, 0, SIZE, SIZE);
      if (end) {
        context.fillStyle = 'black';
        context.font = '40px serif';
        context.textAlign = 'center';
        context.fillText('Refresh to play again\n', SIZE / 2, SIZE / 2);
        gameEnd();
      } else {
        snake.unshift(newHead);
        snake = snake.slice(0, snakeLength);
      }

      // Detect wall collisions
      if (newHead.x < 0 || newHead.x >= SIZE || newHead.y < 0 || newHead.y >= SIZE) {
        end = true;
      }

      context.fillStyle = '#FF0000';
      var snakeObj = {};
      for (var i = 0; i < snake.length; i++) {
        var a = snake[i];
        context.fillRect(a.x, a.y, GRID_SIZE, GRID_SIZE);
        // Build a collision lookup object
        if (i > 0) snakeObj[stringifyCoord(a)] = true;
      }

      if (snakeObj[stringifyCoord(newHead)]) end = true; // Collided with our tail


      while (!candy || snakeObj[stringifyCoord(candy)]) {
        candy = {x: randomOffset(), y: randomOffset()};
      }

      context.fillStyle = '#008000';
      context.fillRect(candy.x, candy.y, GRID_SIZE, GRID_SIZE);
      //text('Score: ' + score, '30px Cosmic Sans MS', 0, 50, 'black');

      document.getElementById('currscore').innerHTML = score;

    }

      setInterval(tick, 100); // Kick off the game loop!
      window.onkeydown = function(e) {
        newDirection = {37: -1, 38: -2, 39: 1, 40: 2}[e.keyCode] || newDirection;
    }

}
