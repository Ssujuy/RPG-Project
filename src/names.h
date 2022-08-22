#ifndef NAMES_H
#define NAMES_H

#include <time.h>
#include <iostream>
#include <cstdlib>

using namespace std;

//names.h
//Includes arrays for names initialization for all classes and other secondary functions



class Names{
	
	private :
		
		string weapon_names[100] = {"Caladbolg" , "TamingSword" , "CrystalSword" , "Excalibur" , "Ragnarok" , "Balmung" , "SavetheQueen" , "Heartbreaker", "Lionheart" , "Durandal" , "Ascalon" , "Ambitious" , "Hrunting" , "AstralSword" , "Apocalypse" , "Slowstrike" , "MasterSword" , "Rune-Master" , "Warlock" , "ArcSword" , "Gilventure" , "Tri-Steel" , "Helter-Skelter" , "Vendetta" , "Avenger" , "PrismSteel" , "MirageSword" , "Lifesaver" , "SonicSteel" , "Vigilante" , "DanceMacabre" , "Largamente" , "Gravestone" , "Sidewinder" , "Nightmare" , "MageMasher" , "Nightbringer" , "KnightSword" , "WizardSword" , "Double-Edge" , "Razzmatazz" , "Deathbringer" , "StunningSteel" , "BasiliskSteel" , "PoisonSteel" , "LullabySteel" , "MutedSteel" , "TwilightSteel" , "HunterSword" , "Flametongue" , "IceBrand" , "LightningSteel" , "ForceSaber" , "BaroqueSword" , "SorcerySword" , "SoldierSaber" , "RuneSteel" , "EnchantedSword" , "FencingSaber" , "Slasher" , "Nirvana" , "HerdingStaff" , "ArcArcana" , "Abraxas" , "HeavenlyAxis" , "Judgment" , "SeraphimRod" , "RodofRoses" , "NimbusRod" , "WingWand" , "WonderWand" , "Laevatein" , "AstralRod" , "ChaosRod" , "PowerStaff" , "ShiningStaff" , "FaerieStaff" , "MagistralRod" , "ElDorado" , "Tri-Rod" , "WickedWand" , "NemesisRod" , "Defender" , "PrismRod" , "MirageRod" , "HealingRod" , "WindRod" , "Conductor" , "Punisher" , "CalciteStaff" , "BizarreStaff" , "StaffofThorns" , "ReticentStaff" , "DarknessStaff" , "MonkStaff" , "MageStaff" , "DualRod" , "OminousRod" , "DeathWand" , "EntanglingRod"};
		string potion_names[70] = {"Hi-Potion" , "X-Potion" , "Mega-Potion" , "Ether" , "TurboEther" , "Elixir" , "Megalixir" , "PhoenixDown" , "MegaPhoenix" , "Antidote" , "EchoScreen" , "EyeDrops" , "HolyWater" , "Remedy" , "Soft" , "AlBhedPotion" , "HealingWater" , "TetraElemental" , "CandleofLife" , "DreamPowder" , "FarplaneShadow" , "FarplaneWind" , "FragGrenade" , "SilenceGrenade" , "SleepingPowder" , "SmokeBomb" , "PetrifyGrenade" , "PoisonFang" , "BlessedGem" , "DarkMatter" , "ShadowGem" , "ShiningGem" , "SupremeGem" , "GoldHourglass" , "HealingSpring" , "LightCurtain" , "LunarCurtain" , "ManaSpring" , "ManaTablet" , "ManaTonic" , "PurifyingSalt" , "SilverHourglass" , "SoulSpring" , "StaminaSpring" , "StaminaTablet" , "StaminaTonic" , "StarCurtain" , "ThreeStars" , "TwinStars" , "AbilityDistiller" , "Amulet" , "DesignerWallet" , "DoortoTomorrow" , "GamblerSpirit" , "HypelloPotion" , "ManaDistiller" , "Map" , "Musk" , "Pendulum" , "PowerDistiller"};
		string armor_names[80] = {"EndlessRoad" , "GenjiShield" , "Emblem" , "CrystalShield" , "AegisShield" , "GolemShield" , "ReviveShield" , "RescueShield" , "PaladinShield" , "DiamondShield" , "RubyShield" , "DynastyShield" , "MagisterShield" , "CollectorShield" , "TreasureShield" , "ShieldofHope" , "AssaultShield" , "PhantomShield" , "RecoveryShield" , "SpiritualShield" , "PhoenixShield" , "CurativeShield" , "RainbowShield" , "ShiningShield" , "FaerieShield" , "PeacefulShield" , "ShamanShield" , "BarrierShield" , "StarShield" , "MarchingShield" , "MoonShield" , "RegenShield"  , "HasteShield" , "ReflectShield" , "ProtectShield" , "ShellShield" , "PlatinumShield" , "SapphireShield" , "KnightShield" , "WizardShield" , "ElementalShield" , "DefendingShield" , "CrimsonShield" , "SnowShield" , "OchreShield" , "CeruleanShield" , "MedicalShield" , "LucidShield" , "SereneShield" , "LightShield" , "SoulShield" , "BlessedShield" , "SoftShield" , "SerumShield" , "AlertShield" , "EchoShield" , "BrightShield" , "RedShield" , "WhiteShield" , "YellowShield" , "BlueShield" , "NulTideShield" , "NulBlazeShield" , "NulFrostShield" , "AdeptShield" , "TetraShield" , "MythrilShield" , "GoldShield" , "EmeraldShield" , "SoldierShield" , "MageShield" , "SilverShield" , "OnyxShield" , "SorceryShield" , "WarriorShield" , "GloriousShield" , "MetalShield" , "PearlShield" , "MagicShield" , "SeekerShield"};
		string spell_names[91] = {"Flame" , "Torch" , "Eruption" , "Flare" , "Blaze" , "Inferno" , "Fireball" , "Explosion" , "Meteor" , "SalamanderBlade" , "DragonFire" , "Sinkhole" , "Pit" , "Chasm" , "Vine" , "Thorn" , "Nettle" , "Rockfall" , "Landslide" , "Avalanche" , "Chill" , "Freeze" , "Frostbite" , "Douse" , "Deluge" , "Flood" ,"Wave" , "Surge" , "Tsunami" , "NyadLore" , "Sleep" , "Slumber" , "Shock" , "Bolt" , "Plasma" , "Gust" , "Gale" , "Tempest" , "Whirlwhind" , "Cyclone" , "Vortex" , "WyvernWings" , "Daze" , "Stun" , "Confuse" , "Light" , "Flash" , "Radiance" , "Cleanse" , "Scour" , "Purge" , "Wrath" , "Retribution" , "Judgment" , "AngelMercy" , "Darkness" , "Shade" , "Gloom" , "Decay" , "Fester" , "Corrupt" , "Spite" , "Rancor" , "Malice" , "DemonRage" , "Drain" , "Siphon" , "Void" , "BoltStrike" , "FreezeWave" , "InfernoBlaze" , "ChannelEnergy" , "ShadowBlade" , "HeavenSword" , "BlazingKatana" , "StaffofIce" , "ArrowofPurity" , "BlazingArrows" , "BurntheSoul" , "FireWings" , "FuryofOsano-Wo" , "GaijinFlames" , "HungryBlade" , "YakamoWrath" , "YakamoEye" , "BreathofSuitengu" , "TheInnerOcean" , "SurgingSoul" , "EndlessDepth" , "KharmicIntent" , "WhisperedBlade"};
		string hero_names[10] = {"Geralt" , "Yenefer" , "Triss" , "Dandelion" , "Emhyr" , "KeiraMeitz" , "Roche" , "Halbjorn" , "Imlerith" , "Priscilla"};
		string monster_names[91] = {"BaervanWildwanderer" , "BaravarCloakshadow" , "BerronarTruesilver" , "Brandobaris", "CallarduranSmoothands" , "Charmalaine" , "ClangeddinSilverbeard" , "CorellonLarethian" , "Cyrrollalee" , "DeepSashelas" , "DugmarenBrightmantle" , "Dumathoin" , "Ehlonna" , "ErevanIlesere" , "FenmarelMestarine" , "Fharlanghn" , "FlandalSteelskin" , "Gadhelyn" , "GaerdalIronhand" , "GarlGlittergold" , "GendwarArgrim" , "HalaniCelanil" , "Heironeous" , "LabelasEnoreth" , "Moradin" , "MuammanDuathal" , "Olidammara" , "Pelor" , "RillifaneRallathil" , "Roykyn" , "SegojanEarthcaller" , "SehanineMoonbow" , "Sheela Peryroyl" , "SolonorThelandira" , "StCuthbert" , "Urdlen" , "Urogalan" , "Vergadain" , "YeCind" , "Yondalla" , "Annam" , "Bahamut" , "Blibdoolpoolp" , "Diirinka" , "Eadro" , "Gruumsh" , "Hruggek" , "Ilsensine" , "Jubilex" , "Kurtulmak" , "Laduguer" , "Loagzed" , "Lolth" , "Maglubiyet" , "Merrshaulk" , "Orcus" , "Sekolah" , "Semuanya" , "Shekinester" , "Skerrit" , "Stronmaus" , "Tiamat" , "Vaprak" , "Yeenoghu" , "Aasterinian" , "Bagrivyek" , "Bahgtru" , "Chronepsis" , "Doresain" , "Falazure" , "Gaknulak" , "Grankhul" , "GreatMother" , "Grolantor" , "Hiatea" , "Iallanis" , "Ilneval" , "Io" , "Karontor" , "Kiaransalee" , "Khurgorbaeyag" , "Luthic" , "Memnor" , "Nomog-Geaya" , "Panzuriel" , "Raxivort" , "Shargaas" , "Sixin" , "SkoraeusStonebones" , "Squerrik" , "Surtr"};
		
	public : 
	
		string get_weapon_name();
		string get_armor_name();
		string get_potion_name();
		string get_spell_name();
		string get_hero_name();
		string get_monster_name();
		
};

void help();

#endif

