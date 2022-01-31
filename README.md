# poorly-made-tic-tac-toe
Rookie amateur programmer who just discovered raylib tried re-creating tic tac toe.<br>

Runs on linux and probably depends on Raylib.<br>
Will give you a seizure on windows(in other words: doesn't function on windows)<br><br>

To make it run:<br>
1: Download tictactoe.out alongside tictactoe.png and arial.ttf <br>
2: Keep everything in the same directory or it probably wont run<br>
3: If tictactoe.out isn't an executeable, then run: `chmod +x tictactoe.out` <br>
4: Run tictactoe.out by using the command: `./tictactoe.out`<br><br>

If you'd like to compile it yourself:<br>
1: Download raylib libary from https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux<br>
2: Install the gcc compiler<br>
3: Download source.c, arial.ttf and tictactoe.png<br>
4: Compile the code by running:<br>
`gcc source.c -lraylib` <br><br>

Feel free to swap out the tictactoe.png file with something else<br>
Do note that the new image needs to have the same name and file format<br>
The program works by splitting the image in half and then placing a half inside of a tile<br>
Each tile takes up 300x300 pixels<br>

