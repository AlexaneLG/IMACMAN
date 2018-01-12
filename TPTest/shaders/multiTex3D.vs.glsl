#version 330 core

layout(location = 0) in vec3 aVertexPosition;
layout(location = 1) in vec3 aVertexNormal;
layout(location = 2) in vec2 aVertexTexCoords;

uniform mat4 uMVPMatrix;
uniform mat4 uMVMatrix;
uniform mat4 uNormalMatrix;

out vec3 vPosition; //view coordinatess
out vec3 vNormal; //view coords
out vec2 vTexCoords; //not changed

void main() {
	vPosition = (uMVMatrix*vec4(aVertexPosition,1)).xyz;
	vNormal = (uNormalMatrix*vec4(aVertexNormal,1)).xyz;
	vTexCoords = aVertexTexCoords;
	gl_Position = uMVPMatrix*vec4(aVertexPosition,1); //compute projected position
};
