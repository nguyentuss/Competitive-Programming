local RS = game:GetService("ReplicatedStorage")
local TS = game:GetService("TweenService")
local players = game:GetService("Players")

local player = players.LocalPlayer

local frame = -- frame which contains quests
local remotes = RS.Remotes

local questRemote = remotes.Quests

for _, v in pairs(frame:GetChildren()) do
   if v:IsA("TextLabel") then
        v.MouseButton1Click:Connect(function()
            questRemote:FireServer("GetQuest", v.Name)
        end)
   end
end

