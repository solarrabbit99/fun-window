#include <chrono>
#include <discord/core.h>
#include <discord/ffi.h>

discord::Core *core{};

namespace presence
{
    void discordSetup()
    {
        using namespace discord;
        auto result = Core::Create(936291126133022730, (std::uint64_t)DiscordCreateFlags_Default, &core);
        Activity activity{};
        activity.SetApplicationId(936291126133022730);
        activity.SetType(ActivityType::Watching);

        // What works and I know how it works
        ActivityAssets *assets = &(activity.GetAssets());
        assets->SetLargeImage("app-icon");
        assets->SetLargeText("Discord");
        activity.SetDetails("Application still in testing phase...");

        activity.SetState("Ready to mingle");
        PartySize *size = &(activity.GetParty().GetSize());
        size->SetMaxSize(10);
        size->SetCurrentSize(1);

        using namespace std::chrono;
        ActivityTimestamps *timestamp = &(activity.GetTimestamps());
        timestamp->SetStart(system_clock::to_time_t(system_clock::now()));

        core->ActivityManager().UpdateActivity(activity, [](Result result) {});
    }

    void discordTick()
    {
        ::core->RunCallbacks();
    }
}
