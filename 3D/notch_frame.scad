rotate([180,0,0])
{
difference() {
        union() {
            translate([(120)/2,0,0])
                bar();

            translate([(-120)/2,0,0])
                bar();
        }

        color("red")
        translate([120,0,-2.75])
            cube([20,13,5.5], center = true);

       color("green")
        translate([-120,0,-2.75])
            cube([20,13,5.5], center = true); 
    }

    translate([80,60,0])
    rotate([0,0,90]) {
        translate([0,30,5])
        {
            difference() {
                union() {
                color ("blue")
                    translate([-118.5,57.5,-2.75])
                            cube([20,128,5.5], center = true);
               color ("cyan")
                    translate([-118.5,64,-7])
                            cube([20,115,5.5], center = true);
                }
                translate([-120, 0,0])

                    cylinder(h=50, d=6, center=true);
            }

        }
    }
}
    
module bar () 
    {
        difference() 
        {
            cube ([117+20,13,11], center=true);
            translate([-60, 0,0])
                cylinder(h=50, d=6, center=true);
            translate([60, 0,0])
                cylinder(h=50, d=6, center=true);

        }
    }