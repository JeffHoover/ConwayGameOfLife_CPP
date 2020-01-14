difference() 
{
    cube ([117+117+20,13,11], center=true);
    translate([-118.5, 0,0])
        cylinder(h=50, d=6, center=true);
    translate([118.5, 0,0])
        cylinder(h=50, d=6, center=true);
    translate([0, 0,0])
        cylinder(h=50, d=6, center=true);
}
