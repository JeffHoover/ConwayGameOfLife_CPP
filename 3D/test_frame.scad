difference() 
{
    cube ([117+20,13,11], center=true);
    translate([-60, 0,0])
        cylinder(h=50, d=6, center=true);
    translate([60, 0,0])
        cylinder(h=50, d=6, center=true);
}
//    cube ([117,11,11], center=true);
