#version 330 core

in vec3 vPosition; //view coordinatess
in vec3 vNormal; //view coords
in vec2 vTexCoords; //not changed

out vec3 fFragColor;

void main() {

  fFragColor = normalize(vNormal);
	//fFragColor = vec3(0,1,0);
};