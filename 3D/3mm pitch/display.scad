bottom = 5;
pin=3;



difference() 
    {
    difference ()
        {
        translate([0,0,-1 * bottom])
            cube ([202,106,12 + bottom], true);
        cube ([192,96,12], true);
    }
    union() {
        translate([-96+pin,-16+pin,0])
            cylinder(h=30, r=3, center=true);
        translate([96-pin,16-pin,0])
            cylinder(h=30, r=3, center=true);
    }
}


