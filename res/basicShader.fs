#version 120

varying vec2 texCoord0;
uniform sampler2D diffuse;

void main() {
    // resolution of texture is between 0 and 1
    // this also automatically interpolates if needed
    gl_FragColor = texture2D(diffuse, texCoord0);
    
    // gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);
}