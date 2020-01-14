
bottom = 0;
//bottom = 5;


translate([0,0,6]) {
    union() {
        
        // Cut the device out of a larger rectangle
        // to make a basic frame
        difference() {
            translate([0,0,-1 * bottom])
                cube ([286,158,12 + bottom], true);
        
            cube ([256,128,12], true); // rectangle the size of the device: 
        }

        // Add words (green for legibility in OpenSCAD only
        color("green")
            translate([0,70,0])
                linear_extrude(8)
                    text (text="Conway's Game of Life"
                          ,font= "Chalkboard:style=Regular"
                          ,halign="center", valign="center"
                          ,size=8
                         );
    }
}



