difference() {
    union () {
        cube([45,5,5]); 

        translate([0, 15,0])
            cube([20,20,15]); 
        }

    translate([12.5,22.5,10])
        rotate([0,-90,0])
            cube([20,5,5]); 
    }
