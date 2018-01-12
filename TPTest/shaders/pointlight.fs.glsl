#version 330 core

in vec3 vPosition; //view coordinates
in vec3 vNormal; //view coords
in vec2 vTexCoords; //not changed

out vec3 fFragColor;

uniform sampler2D uTexture;

//material
uniform vec3 uKd; //coefficient de reflection diffuse
uniform vec3 uKs; //coefficient de reflection glossy
uniform float uShininess;

//light
uniform vec3 uLightPos_vs; //vs: working in view space
uniform vec3 uLightIntensity;

vec3 blinnPhong(vec3 vPosition_vs, vec3 vNormal, vec3 uLightDir_vs, vec3 uLightIntensity, vec3 uKd, vec3 uKs, float uShininess){
	vec3 w_i = normalize(uLightPos_vs-vPosition_vs);
	vec3 w_0 = normalize(-vPosition_vs);
	vec3 halfVector = (w_0 + w_i)/2.0;
	float dist = distance(uLightPos_vs,vPosition_vs);
	vec3 color = (uLightIntensity/(dist*dist))*(uKd *dot(w_i,vNormal) + uKs*pow(dot(halfVector,vNormal),uShininess));
	return color;
}
void main() {
  //fFragColor = texture(uTexture, vTexCoords).xyz;
  //vec3 vPosition_vs = vPosition * viewMatrix;
	vec3 vPosition_vs = vPosition;
	fFragColor = blinnPhong(vPosition_vs, vNormal,uLightPos_vs, uLightIntensity, uKd, uKs, uShininess);
};