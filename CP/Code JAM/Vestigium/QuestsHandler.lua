local RS = game:GetService("ReplicatedStorage")


local modules = RS.Modules
local remotes = RS.Remotes
local questRemote = remotes.Quests

local questDataModule = require(modules.Quests)

questRemote.OnServerEvent:Connect(function(player, action, questName)
    local data = player.Data
    local quests = data.Quests
    local attributes = data.Attributes
    local questsData = questDataModule.GetData(questName)

    if action == "GetQuest" then
        if quests.QuestName.Value ~= "None"  or attributes.Level.Value < questsData.QuestRequirement then return end
        
        quests.QuestName.Value = questName
        quests.QuestProgress.Value = 0
    elseif action == "CompleteQuest" then
        if quests.QuestName.Value == questName and quests.QuestProgress.Value >= questsData.TargetAmount then
            for rewardType, rewardValue in pairs(questData.Rewards) do
                if attributes:FindFirstChild(rewardType) then
                    attributes[rewardType] += rewardValue
                else
                    ---- items
                end
            end
        end
    elseif action == "AbortQuest" then
        if quests.QuestName.Value == questName then
            quests.QuestName.Value = "None"
            quests.QuestProgress.Value = 0
        end
    end
end)