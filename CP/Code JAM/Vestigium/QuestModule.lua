local modules = {}

local quests = {
    ["Example1"] = {
        QuestRequirement = 10,
        QuestTarget = "Titan (Level 1)",
        TargetAmount = 5,

        Rewards = {
            Cash = 150,
            XP = 25,
            Items = {}
        },
    }
}

function module.GetData(questName)
    return quests[questName]
end)


return modules