vec3 BRDF(in vec3 wo, in vec3 wi, in int brdf_type, in vec3 kd) {
    switch(brdf_type) {
        // lambert
        case 0:
        return kd * PI_INV;
        break;
        // mirror
        case 1:
        return kd / abs(wi.y);
        break;
        // glass
        case 2:
        return kd / abs(wi.y);
        break;
    }
}

vec3 sampleBRDF(in vec3 wo, in int brdf_type, out float pdf) {
    switch(brdf_type) {
        // lambert
        case 0:
        return sampleCosineHemisphere(random(), random(), pdf);
        break;
        // mirror
        case 1:
        pdf = 1.0;
        return reflect(-wo, vec3(0, 1, 0));
        break;
        // glass
        case 2:
        break;
    }
}