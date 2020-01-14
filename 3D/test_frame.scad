difference() 
{
    cube ([117+20,11,11], center=true);
    translate([-58.5, 0,0])
        cylinder(h=50, d=6, center=true);
    translate([58.5, 0,0])
        cylinder(h=50, d=6, center=true);
}
//    cube ([117,11,11], center=true);
