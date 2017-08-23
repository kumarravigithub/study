#version 330 core
in vec3 ourColor;
in vec2 TexCoord;

out vec4 color;
uniform sampler2D face1;
uniform sampler2D face2;
uniform int whichTex;

void main() {
    vec4 colorFace1 = texture(face1, TexCoord);
    vec4 colorFace2 = texture(face2, TexCoord);
    color = colorFace2; //mix(colorFace1, colorFace2, 0.5); //* vec4(ourColor, 1.0);;//vec4(ourColor, 1.0f);
}
