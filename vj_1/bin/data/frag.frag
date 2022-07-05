#version 150

uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;

out vec4 outputColor;

#define PI 3.14

float rand(vec2 co){
    return fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453);
}

void main() {
	vec2 uv = gl_FragCoord.xy / u_resolution.xy;
	vec3 color = vec3(0.55, 0.76, 0.88);
	vec2 grid = vec2(1.0, 2.0);
	uv *= grid;
	vec2 ipos = floor(uv);
	vec2 fpos = fract(uv);
	// https://doc.magnum.graphics/magnum/namespaceMagnum_1_1Animation_1_1Easing.html#a1690363458094e85a31374a8d8ee1969
	float alpha = 1 - sqrt(1 - (fpos.y * fpos.y * fpos.y * fpos.y) );
	outputColor = vec4(color, alpha);
}
