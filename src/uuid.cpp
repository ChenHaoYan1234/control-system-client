#include <UUID.h>
#include <Preferences.h>
#include <esp_random.h>

#include "uuid.hpp"

Preferences preferences;

bool hasUUID()
{
    preferences.begin("uuid", true);
    bool _ = preferences.isKey("uuid") && preferences.getBytesLength("uuid") == UUID_SIZE;
    preferences.end();
    return _;
}

void getUUID(char *uuid)
{
    preferences.begin("uuid", true);
    preferences.getBytes("uuid", uuid, UUID_SIZE);
    preferences.end();
}

void setUUID(char *uuid)
{
    preferences.begin("uuid", false);
    preferences.putBytes("uuid", uuid, UUID_SIZE);
    preferences.end();
}

void genUUID(char *uuid)
{
    UUID uuid_generator;
    uuid_generator.seed(esp_random());
    uuid_generator.setVersion4Mode();
    uuid_generator.generate();
    memcpy(uuid, uuid_generator.toCharArray(), UUID_SIZE);
}
