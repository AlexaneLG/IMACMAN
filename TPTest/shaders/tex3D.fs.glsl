#version 330 core

in vec3 vPosition; //view coordinatess
in vec3 vNormal; //view coords
in vec2 vTexCoords; //not changed

out vec3 fFragColor;

uniform sampler2D uTexture;

void main() {
  fFragColor = texture(uTexture, vTexCoords).xyz;
};