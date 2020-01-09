#
# Computer Graphics, Autumn 2019
#


To compile the code:

cd path/to/RayTracer/build
cmake3 ..
make
./raytracer input.json output.ppm

~~~~~~~~~~~~
get the result in build file

########################################

PLY-File_Parser_master file
Can parse .ply file.
copy the 3 points location from "TrianglePoints.txt" into input.json


########################################

To change the ThinLens into Pinhole, 
change the input.json:
camera: type:"thinlens" -> "pinhole"

########################################
More result shows in build file

########################################



