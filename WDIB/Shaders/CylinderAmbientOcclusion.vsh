attribute vec3 position;
attribute vec2 inputImpostorSpaceCoordinate;
attribute vec3 direction;
attribute vec2 ambientOcclusionTextureOffset;

varying vec2 impostorSpaceCoordinate;
varying vec3 normalizedStartingCoordinate;
varying vec3 normalizedEndingCoordinate;
varying float halfCylinderRadius;
varying vec3 adjustmentForOrthographicProjection;
varying float depthAdjustmentForOrthographicProjection;

uniform mat3 modelViewProjMatrix;
uniform float cylinderRadius;
uniform mat3 orthographicMatrix;
uniform float ambientOcclusionTexturePatchWidth;

void main()
{
    vec3 transformedStartingCoordinate, transformedEndingCoordinate;
    
    if (inputImpostorSpaceCoordinate.t < 0.0)
    {
        transformedStartingCoordinate = modelViewProjMatrix * position;
        transformedEndingCoordinate = modelViewProjMatrix * (position + direction);
    }
    else
    {
        transformedStartingCoordinate = modelViewProjMatrix * (position - direction);
        transformedEndingCoordinate = modelViewProjMatrix * position;
    }

    transformedStartingCoordinate *= orthographicMatrix;
    transformedEndingCoordinate *= orthographicMatrix;

    adjustmentForOrthographicProjection = (vec3(0.5, 0.5, 0.5) * orthographicMatrix).xyz;

//    normalizedStartingCoordinate = (transformedStartingCoordinate.xyz + 1.0) * adjustmentForOrthographicProjection;
//    normalizedEndingCoordinate = (transformedEndingCoordinate.xyz + 1.0) * adjustmentForOrthographicProjection;

    normalizedStartingCoordinate = (transformedStartingCoordinate / 2.0) + 0.5;

    normalizedEndingCoordinate = (transformedEndingCoordinate / 2.0) + 0.5;

    impostorSpaceCoordinate = inputImpostorSpaceCoordinate.xy;
    
    halfCylinderRadius = cylinderRadius;
    
    gl_Position = vec4(ambientOcclusionTextureOffset * 2.0 - vec2(1.0) + (ambientOcclusionTexturePatchWidth * impostorSpaceCoordinate), 0.0, 1.0);
}
