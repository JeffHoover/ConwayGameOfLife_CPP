
bottom = 0;
//bottom = 5;


translate([0,0,6]) {
difference() {
    difference ()
    {
        translate([0,0,-1 * bottom])
            cube ([222,126,12 + bottom], true);
        cube ([192,96,12], true);
    }


//    translate([-106,0,-26]) // touching
    translate([-106,0,-21])
        cube([5,5,20]);
    translate([101,0,-21])
        cube([5,5,20]); 
}
    color("green")
        translate([0,55,0])
            linear_extrude(8)
                text (text="Conway's Game of Life"
                      ,font= "Chalkboard:style=Regular"
                      ,halign="center", valign="center"
                      ,size=8
                     );
}
translate([-80,-10,0])
    cube([125,5,5]); 
translate([-80,0,0])
    cube([125,5,5]); 


// rectangle the size of the device: 
//    cube ([192,96,12], true);
