#version 330 core

in vec3 vPosition; //view coordinatess
in vec3 vNormal; //view coords
in vec2 vTexCoords; //not changed

out vec3 fFragColor;

uniform sampler2D uEarthTexture;
uniform sampler2D uCloudTexture;

void main() {
  fFragColor = texture(uEarthTexture, vTexCoords).xyz + texture(uCloudTexture, vTexCoords).xyz;
};