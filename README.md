<html>
<body>
<h1>Codam Coding College project: Cub3D</h1>
<p></p>
<p>A simple graphics project (first graphics project by the user) that creates a Doom-esque game with sprites, walls, ceiling and floor that that the player can navigate through. Maps are made with the extension .cub and must have a minimum format of:<br>
<code>R 1920 1080</code><br>
<code>NO ./path_to_the_north_texture</code><br>
<code>SO ./path_to_the_south_texture</code><br>
<code>WE ./path_to_the_west_texture</code><br>
<code>EA ./path_to_the_east_texture</code><br>
<code>S ./path_to_the_sprite_texture</code><br>
<code>F 220,100,0</code><br>
<code>C 225,30,0</code><br><br>
<code>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1111111111111111111111111</code><br>
<code>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1000000000110000000000001</code><br>
<code>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1011000001110000002000001</code><br>
<code>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1001000000000000000000001</code><br>
<code>111111111011000001110000000000001</code><br>
<code>100000000011000001110111111111111</code><br>
<code>11110111111111011100000010001</code><br>
<code>11110111111111011101010010001</code><br>
<code>11000000110101011100000010001</code><br>
<code>10002000000000001100000010001</code><br>
<code>10000000000000001101010010001</code><br>
<code>11000001110101011111011110N0111</code><br>
<code>11110111 1110101 101111010001</code><br>
<code>11111111 1111111 111111111111</code>
<br><br>
<h2>How To Use The Project</h2>
<p>Clone the project<br><br>
Use <br><code>make</code><br> to create the <code>./cub3D</code> executable.<br><br>
Run the executable with a valid map using<br>
<code>./cub3D [map_name].cub</code> // a playable map is available using <code>./cub3d test.cub</code><br><br>
A bmp screenshot can also be made using:<br>
<code>./cub3D [map_name].cub --save</code>
