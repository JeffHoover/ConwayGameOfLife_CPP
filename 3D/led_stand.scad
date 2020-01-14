h=45;
w=80;
d=15;
angle=55;

module piece() {
difference() {
translate([0,0,h/2])
    cube([w,d,h],center=true);

color("green") 
    translate([-0.5*w,0,h/2])
        rotate([0,angle,0])
            cube([w/2,d,2*h],center=true);  
color("blue") 
    translate([0.5*w,0,h/2])
        rotate([0,-1*angle,0])
            cube([w/2,d,2*h],center=true);     
rotate(00,0,0)      
color("red")
    translate([0,0,0.75*h])
        cube([15,d,h],center=true);
}
}


piece();
translate([0,3*d,0])
    piece();