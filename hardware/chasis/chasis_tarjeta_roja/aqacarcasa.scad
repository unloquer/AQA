//no funciono la primera vez que se imprimo por tiempo por que quedo medio impreso 
difference(){
union(){
difference(){
union (){
large= 76;//las medidas de largo del sensor
largo = large+8;//cambio las variables de nombre para que las leea el codigo=84
deep=45;
profundo = deep+5;//50
 paredes=2;
 alto=20;
 tornilloyuno =  44.5;
cube([largo,profundo,paredes]);//base
//translate([0,0,2])//acrilico
//color("blue",0.7)//acrilico
//cube([large,4.7,0.2]);//acrilico
cube([largo,paredes,alto]);//lado  frente
translate([0,profundo,0])//lado trasero
cube([largo,paredes,alto]);//lado  trasero
cube([paredes,profundo,alto]);//lado 1 para micro usb
translate([largo,0,0])//lado 1 para mini usb
cube([paredes,profundo+2,alto]);//lado 1 para mini usb
}translate([-1,5,1])
cube([90,40,7]);}}
union(){
translate([67,39,-1])//grande
cylinder(r=4 ,h=3, $fn=100);}//grande
translate([77,44.5,-1])//pequño y2 x2
cylinder(r=2 ,h=3, $fn=100);
translate([9,44.5,-1])
//pequño y2 x1
cylinder(r=2 ,h=3, $fn=100);
//pequño y1 x2
translate([77,5,-1])
cylinder(r=2 ,h=3, $fn=100);
translate([30,-1,12])
cube ([15,4,7]);
translate([4,-1,16])
cube ([15,5,3]);
}