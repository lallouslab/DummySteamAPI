#include <string.h>

#include "debug.h"

#include "ISteamParentalSettings.h"
#include "ISteamParentalSettings_priv.h"
#include "ISteamParentalSettings001.h"

static const char *steam_parental_settings_version = NULL;

MEMBER steam_bool_t ISteamParentalSettings_BIsParentalLockEnabled(struct ISteamParentalSettings *iface)
{
	struct ISteamParentalSettingsImpl *This = impl_from_ISteamParentalSettings(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return STEAM_FALSE;
}

MEMBER steam_bool_t ISteamParentalSettings_BIsParentalLockLocked(struct ISteamParentalSettings *iface)
{
	struct ISteamParentalSettingsImpl *This = impl_from_ISteamParentalSettings(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return STEAM_FALSE;
}

MEMBER steam_bool_t ISteamParentalSettings_BIsAppBlocked(struct ISteamParentalSettings *iface, steam_app_id_t app_id)
{
	struct ISteamParentalSettingsImpl *This = impl_from_ISteamParentalSettings(iface);

	LOG_ENTER_NOTIMPL("(This = %p, app_id = %u)", VOIDPTR(This), app_id);

	return STEAM_FALSE;
}

MEMBER steam_bool_t ISteamParentalSettings_BIsAppInBlockList(struct ISteamParentalSettings *iface, steam_app_id_t app_id)
{
	struct ISteamParentalSettingsImpl *This = impl_from_ISteamParentalSettings(iface);

	LOG_ENTER_NOTIMPL("(This = %p, app_id = %u)", VOIDPTR(This), app_id);

	return STEAM_FALSE;
}

MEMBER steam_bool_t ISteamParentalSettings_BIsFeatureBlocked(struct ISteamParentalSettings *iface, enum steam_parental_settings_feature feature)
{
	struct ISteamParentalSettingsImpl *This = impl_from_ISteamParentalSettings(iface);

	LOG_ENTER_NOTIMPL("(This = %p, feature = %u)", VOIDPTR(This), feature);

	return STEAM_FALSE;
}

MEMBER steam_bool_t ISteamParentalSettings_BIsFeatureInBlockList(struct ISteamParentalSettings *iface, enum steam_parental_settings_feature feature)
{
	struct ISteamParentalSettingsImpl *This = impl_from_ISteamParentalSettings(iface);

	LOG_ENTER_NOTIMPL("(This = %p, feature = %u)", VOIDPTR(This), feature);

	return STEAM_FALSE;
}

struct ISteamParentalSettings *SteamParentalSettings_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamParentalSettings *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMPARENTALSETTINGS_INTERFACE_VERSION_001, SteamParentalSettings001 },
		{ NULL, NULL }
	};
	int i;

	LOG_ENTER("(version = \"%s\")", debug_str(version));

	i = 0;
	while (ifaces[i].name)
	{
		if (strcmp(ifaces[i].name, version) == 0)
		{
			if (ifaces[i].iface_getter)
				return ifaces[i].iface_getter();

			break;
		}
		i++;
	}

	WARN("Unable to find ISteamParentalSettings version \"%s\".", debug_str(version));

	return INVAL_PTR;
}

void SteamParentalSettings_set_version(const char *version)
{
	LOG_ENTER("(version = \"%s\")", debug_str(version));

	if (!steam_parental_settings_version)
		steam_parental_settings_version = version;
}

EXPORT struct ISteamParentalSettings *SteamParentalSettings(void)
{
	static struct ISteamParentalSettings *cached_iface = NULL;

	LOG_ENTER0("()");

	if (!steam_parental_settings_version)
	{
		steam_parental_settings_version = STEAMPARENTALSETTINGS_INTERFACE_VERSION_001;

		WARN("ISteamParentalSettings: No version specified, defaulting to \"%s\".", debug_str(steam_parental_settings_version));
	}

	if (!cached_iface)
		cached_iface = SteamParentalSettings_generic(steam_parental_settings_version);

	return cached_iface;
}
