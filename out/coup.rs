// Example code that deserializes and serializes the model.
// extern crate serde;
// #[macro_use]
// extern crate serde_derive;
// extern crate serde_json;
//
// use generated_module::[object Object];
//
// fn main() {
//     let json = r#"{"answer": 42}"#;
//     let model: [object Object] = serde_json::from_str(&json).unwrap();
// }

extern crate serde_derive;
use std::collections::HashMap;

#[derive(Serialize, Deserialize)]
pub struct Coup {
    #[serde(rename = "$schema")]
    schema: String,

    #[serde(rename = "$ref")]
    coup_ref: String,

    #[serde(rename = "definitions")]
    definitions: Definitions,
}

#[derive(Serialize, Deserialize)]
pub struct Definitions {
    #[serde(rename = "Schema")]
    schema: Schema,

    #[serde(rename = "Node")]
    node: Node,

    #[serde(rename = "ModelFiles")]
    model_files: Auxiliary,

    #[serde(rename = "ModelFilesAtmosphericRelatedProcesses")]
    model_files_atmospheric_related_processes: SAtmosphericRelatedProcesses,

    #[serde(rename = "PurpleMeteorologicalData")]
    purple_meteorological_data: PurpleMeteorologicalData,

    #[serde(rename = "HeatPumpdata")]
    heat_pumpdata: HeatPumpdata,

    #[serde(rename = "Meteorologicaldata")]
    meteorologicaldata: Meteorologicaldata,

    #[serde(rename = "ModelFilesModelFacilities")]
    model_files_model_facilities: ModelSModelFacilities,

    #[serde(rename = "PurpleTechnical")]
    purple_technical: FluffyPlantGrowth,

    #[serde(rename = "OutputFile")]
    output_file: OutputFile,

    #[serde(rename = "ModelFilesNitrogenandCarbon")]
    model_files_nitrogenand_carbon: ModelFilesNitrogenandCarbon,

    #[serde(rename = "PurpleExternalNinputs")]
    purple_external_ninputs: PurpleExternalNinputs,

    #[serde(rename = "PurplePlantGrowth")]
    purple_plant_growth: PurplePlantGrowth,

    #[serde(rename = "ModelFilesNitrogenandCarbonBelowGround")]
    model_files_nitrogenand_carbon_below_ground: DrivingArraysNitrogenandCarbonBelowGroundClass,

    #[serde(rename = "PurpleAbioticdrivingvariables")]
    purple_abioticdrivingvariables: PurpleAbioticdrivingvariables,

    #[serde(rename = "ModelFilesPlantWaterProcesses")]
    model_files_plant_water_processes: ModelFilesPlantWaterProcesses,

    #[serde(rename = "PurplePlant")]
    purple_plant: PurplePlant,

    #[serde(rename = "PurpleSaltTracer")]
    purple_salt_tracer: PurpleSaltTracer,

    #[serde(rename = "SaltRoadDeposition")]
    salt_road_deposition: SaltRoadDeposition,

    #[serde(rename = "ModelFilesSoilWaterProcesses")]
    model_files_soil_water_processes: ModelFilesSoilWaterProcesses,

    #[serde(rename = "PurpleDrainageanddeeppercolation")]
    purple_drainageanddeeppercolation: PurpleDrainageanddeeppercolation,

    #[serde(rename = "ModelOptions")]
    model_options: ModelOptions,

    #[serde(rename = "ModelOptionsAtmosphericRelatedProcesses")]
    model_options_atmospheric_related_processes: ModelOptionsAtmosphericRelatedProcesses,

    #[serde(rename = "FluffyMeteorologicalData")]
    fluffy_meteorological_data: FluffyMeteorologicalData,

    #[serde(rename = "PrecInput")]
    prec_input: PrecInput,

    #[serde(rename = "PurpleRadiationproperties")]
    purple_radiationproperties: PurpleRadiationproperties,

    #[serde(rename = "PurpleSoilevaporation")]
    purple_soilevaporation: PurpleSoilevaporation,

    #[serde(rename = "EvaporationMethod")]
    evaporation_method: EvaporationMethod,

    #[serde(rename = "ModelOptionsModelFacilities")]
    model_options_model_facilities: ModelSModelFacilities,

    #[serde(rename = "FluffyTechnical")]
    fluffy_technical: FluffyTechnical,

    #[serde(rename = "ModelOptionsModelStructure")]
    model_options_model_structure: ModelStructure,

    #[serde(rename = "PurpleModelStructure")]
    purple_model_structure: PurpleModelStructure,

    #[serde(rename = "ModelOptionsPlantWaterProcesses")]
    model_options_plant_water_processes: ModelOptionsPlantWaterProcesses,

    #[serde(rename = "PurpleInterception")]
    purple_interception: PurpleInterception,

    #[serde(rename = "PurpleWateruptake")]
    purple_wateruptake: PurpleWateruptake,

    #[serde(rename = "ModelOptionsSoilWaterProcesses")]
    model_options_soil_water_processes: ModelOptionsSoilWaterProcesses,

    #[serde(rename = "FluffyDrainageanddeeppercolation")]
    fluffy_drainageanddeeppercolation: FluffyDrainageanddeeppercolation,

    #[serde(rename = "PurpleSurfacewater")]
    purple_surfacewater: PurpleSurfacewater,

    #[serde(rename = "OutputVariables")]
    output_variables: OutputVariables,

    #[serde(rename = "Auxiliary")]
    auxiliary: Auxiliary,

    #[serde(rename = "AuxiliaryAtmosphericRelatedProcesses")]
    auxiliary_atmospheric_related_processes: AuxiliaryAtmosphericRelatedProcesses,

    #[serde(rename = "FluffyRadiationproperties")]
    fluffy_radiationproperties: FluffyPlantGrowth,

    #[serde(rename = "AlbedoVar")]
    albedo_var: AlbedoVar,

    #[serde(rename = "CanopyFracRADDiffuse")]
    canopy_frac_rad_diffuse: CanopyFracRadDiffuse,

    #[serde(rename = "AuxiliaryModelStructure")]
    auxiliary_model_structure: ModelStructure,

    #[serde(rename = "FluffyModelStructure")]
    fluffy_model_structure: FluffyModelStructure,

    #[serde(rename = "AuxiliaryNitrogenandCarbon")]
    auxiliary_nitrogenand_carbon: NitrogenandCarbon,

    #[serde(rename = "FluffyExternalNinputs")]
    fluffy_external_ninputs: FluffyExternalNinputs,

    #[serde(rename = "AuxiliaryNitrogenandCarbonBelowGround")]
    auxiliary_nitrogenand_carbon_below_ground: AuxiliaryNitrogenandCarbonBelowGroundClass,

    #[serde(rename = "PurpleSoilmineralPProcesses")]
    purple_soilmineral_p_processes: PurpleSoilmineralPProcesses,

    #[serde(rename = "AuxiliaryPlantWaterProcesses")]
    auxiliary_plant_water_processes: AuxiliaryPlantWaterProcesses,

    #[serde(rename = "FluffyInterception")]
    fluffy_interception: FluffyInterception,

    #[serde(rename = "FluffyPlant")]
    fluffy_plant: FluffyPlant,

    #[serde(rename = "PurplePotentialTranspiration")]
    purple_potential_transpiration: PurplePotentialTranspiration,

    #[serde(rename = "FluffyWateruptake")]
    fluffy_wateruptake: FluffyWateruptake,

    #[serde(rename = "AuxiliarySoilHeatProcesses")]
    auxiliary_soil_heat_processes: AuxiliarySoilHeatProcessesClass,

    #[serde(rename = "PurpleSoilfrost")]
    purple_soilfrost: PurpleSoilfrost,

    #[serde(rename = "PurpleSoilheatflows")]
    purple_soilheatflows: PurpleSoilheatflows,

    #[serde(rename = "AuxiliarySoilWaterProcesses")]
    auxiliary_soil_water_processes: SoilWaterProcesses,

    #[serde(rename = "TentacledDrainageanddeeppercolation")]
    tentacled_drainageanddeeppercolation: TentacledDrainageanddeeppercolation,

    #[serde(rename = "PurpleSoilwaterflows")]
    purple_soilwaterflows: PurpleSoilwaterflows,

    #[serde(rename = "FluffySurfacewater")]
    fluffy_surfacewater: FluffySurfacewater,

    #[serde(rename = "AuxiliaryArrays")]
    auxiliary_arrays: Auxiliary,

    #[serde(rename = "AuxiliaryArraysAtmosphericRelatedProcesses")]
    auxiliary_arrays_atmospheric_related_processes: AuxiliaryArraysAtmosphericRelatedProcesses,

    #[serde(rename = "TentacledRadiationproperties")]
    tentacled_radiationproperties: TentacledRadiationproperties,

    #[serde(rename = "PurpleSnowPack")]
    purple_snow_pack: PurpleSnowPack,

    #[serde(rename = "AuxiliaryArraysNitrogenandCarbon")]
    auxiliary_arrays_nitrogenand_carbon: AuxiliaryArraysNitrogenandCarbon,

    #[serde(rename = "FluffyPlantGrowth")]
    fluffy_plant_growth: FluffyPlantGrowth,

    #[serde(rename = "AuxiliaryArraysNitrogenandCarbonBelowGround")]
    auxiliary_arrays_nitrogenand_carbon_below_ground: ArraysNitrogenandCarbonBelowGround,

    #[serde(rename = "PurpleGasprocesses")]
    purple_gasprocesses: PurpleGasprocesses,

    #[serde(rename = "CCoarseRootsATMLayer")]
    c_coarse_roots_atm_layer: CCoarseRootsAtmLayer,

    #[serde(rename = "FluffySoilmineralPProcesses")]
    fluffy_soilmineral_p_processes: FluffySoilmineralPProcesses,

    #[serde(rename = "AuxiliaryArraysPlantWaterProcesses")]
    auxiliary_arrays_plant_water_processes: AuxiliaryArraysPlantWaterProcesses,

    #[serde(rename = "TentacledInterception")]
    tentacled_interception: TentacledInterception,

    #[serde(rename = "TentacledPlant")]
    tentacled_plant: FluffyPlantGrowth,

    #[serde(rename = "FluffyPotentialTranspiration")]
    fluffy_potential_transpiration: FluffyPotentialTranspiration,

    #[serde(rename = "FluffySaltTracer")]
    fluffy_salt_tracer: FluffySaltTracer,

    #[serde(rename = "TentacledWateruptake")]
    tentacled_wateruptake: TentacledWateruptake,

    #[serde(rename = "AuxiliaryArraysSoilHeatProcesses")]
    auxiliary_arrays_soil_heat_processes: AuxiliaryArraysSoilHeatProcessesClass,

    #[serde(rename = "FluffySoilheatflows")]
    fluffy_soilheatflows: FluffySoilheatflows,

    #[serde(rename = "TempColdPipe")]
    temp_cold_pipe: TempColdPipe,

    #[serde(rename = "AuxiliaryArraysSoilWaterProcesses")]
    auxiliary_arrays_soil_water_processes: ArraysSoilWaterProcesses,

    #[serde(rename = "StickyDrainageanddeeppercolation")]
    sticky_drainageanddeeppercolation: StickyDrainageanddeeppercolation,

    #[serde(rename = "FluffySoilwaterflows")]
    fluffy_soilwaterflows: FluffySoilwaterflows,

    #[serde(rename = "Driving")]
    driving: Driving,

    #[serde(rename = "DrivingAtmosphericRelatedProcesses")]
    driving_atmospheric_related_processes: DrivingAtmosphericRelatedProcesses,

    #[serde(rename = "FluffySnowPack")]
    fluffy_snow_pack: FluffySnowPack,

    #[serde(rename = "DrivingNitrogenandCarbonBelowGround")]
    driving_nitrogenand_carbon_below_ground: DrivingArraysNitrogenandCarbonBelowGroundClass,

    #[serde(rename = "FluffyAbioticdrivingvariables")]
    fluffy_abioticdrivingvariables: FluffyAbioticdrivingvariables,

    #[serde(rename = "DrivingPlantWaterProcesses")]
    driving_plant_water_processes: PlantWaterProcesses,

    #[serde(rename = "TentacledSaltTracer")]
    tentacled_salt_tracer: TentacledSaltTracer,

    #[serde(rename = "DrivingArrays")]
    driving_arrays: DrivingArrays,

    #[serde(rename = "DrivingArraysAtmosphericRelatedProcesses")]
    driving_arrays_atmospheric_related_processes: SAtmosphericRelatedProcesses,

    #[serde(rename = "TentacledMeteorologicalData")]
    tentacled_meteorological_data: TentacledMeteorologicalData,

    #[serde(rename = "DrivingArraysNitrogenandCarbonBelowGround")]
    driving_arrays_nitrogenand_carbon_below_ground: DrivingArraysNitrogenandCarbonBelowGroundClass,

    #[serde(rename = "TentacledAbioticdrivingvariables")]
    tentacled_abioticdrivingvariables: TentacledAbioticdrivingvariables,

    #[serde(rename = "Flow")]
    flow: Auxiliary,

    #[serde(rename = "FlowAtmosphericRelatedProcesses")]
    flow_atmospheric_related_processes: FlowAtmosphericRelatedProcesses,

    #[serde(rename = "TentacledSnowPack")]
    tentacled_snow_pack: TentacledSnowPack,

    #[serde(rename = "FluffySoilevaporation")]
    fluffy_soilevaporation: FluffySoilevaporation,

    #[serde(rename = "FlowModelFacilities")]
    flow_model_facilities: ModelFacilities,

    #[serde(rename = "PurpleIrrigation")]
    purple_irrigation: PurpleIrrigation,

    #[serde(rename = "FlowNitrogenandCarbon")]
    flow_nitrogenand_carbon: FlowNitrogenandCarbon,

    #[serde(rename = "PurpleExternalPInputs")]
    purple_external_p_inputs: PurpleExternalPInputs,

    #[serde(rename = "FlowNitrogenandCarbonBelowGround")]
    flow_nitrogenand_carbon_below_ground: FlowNitrogenandCarbonBelowGroundClass,

    #[serde(rename = "FluffyGasprocesses")]
    fluffy_gasprocesses: FluffyGasprocesses,

    #[serde(rename = "TentacledSoilmineralPProcesses")]
    tentacled_soilmineral_p_processes: TentacledSoilmineralPProcesses,

    #[serde(rename = "PurpleSoilorganicprocesses")]
    purple_soilorganicprocesses: PurpleSoilorganicprocesses,

    #[serde(rename = "FlowPlantWaterProcesses")]
    flow_plant_water_processes: FlowPlantWaterProcesses,

    #[serde(rename = "FlowSoilHeatProcesses")]
    flow_soil_heat_processes: FlowSoilHeatProcesses,

    #[serde(rename = "Soilheatpump")]
    soilheatpump: Soilheatpump,

    #[serde(rename = "FlowSoilWaterProcesses")]
    flow_soil_water_processes: SoilWaterProcesses,

    #[serde(rename = "IndigoDrainageanddeeppercolation")]
    indigo_drainageanddeeppercolation: IndigoDrainageanddeeppercolation,

    #[serde(rename = "TentacledSoilwaterflows")]
    tentacled_soilwaterflows: TentacledSoilwaterflows,

    #[serde(rename = "TentacledSurfacewater")]
    tentacled_surfacewater: TentacledSurfacewater,

    #[serde(rename = "FlowArrays")]
    flow_arrays: Auxiliary,

    #[serde(rename = "FlowArraysNitrogenandCarbon")]
    flow_arrays_nitrogenand_carbon: NitrogenandCarbon,

    #[serde(rename = "TentacledExternalNinputs")]
    tentacled_external_ninputs: TentacledExternalNinputs,

    #[serde(rename = "SnowReduceLaiFactor")]
    snow_reduce_lai_factor: SnowReduceLaiFactor,

    #[serde(rename = "FlowArraysNitrogenandCarbonBelowGround")]
    flow_arrays_nitrogenand_carbon_below_ground: AuxiliaryNitrogenandCarbonBelowGroundClass,

    #[serde(rename = "StickySoilmineralPProcesses")]
    sticky_soilmineral_p_processes: StickySoilmineralPProcesses,

    #[serde(rename = "FlowArraysPlantWaterProcesses")]
    flow_arrays_plant_water_processes: ArraysPlantWaterProcesses,

    #[serde(rename = "StickyInterception")]
    sticky_interception: StickyInterception,

    #[serde(rename = "StickySaltTracer")]
    sticky_salt_tracer: FluffyPlantGrowth,

    #[serde(rename = "StickyWateruptake")]
    sticky_wateruptake: StickyWateruptake,

    #[serde(rename = "FlowArraysSoilHeatProcesses")]
    flow_arrays_soil_heat_processes: AuxiliarySoilHeatProcessesClass,

    #[serde(rename = "FluffySoilfrost")]
    fluffy_soilfrost: FluffySoilfrost,

    #[serde(rename = "TentacledSoilheatflows")]
    tentacled_soilheatflows: FluffyPlantGrowth,

    #[serde(rename = "HeatBox")]
    heat_box: HeatBox,

    #[serde(rename = "FlowArraysSoilWaterProcesses")]
    flow_arrays_soil_water_processes: ArraysSoilWaterProcesses,

    #[serde(rename = "IndecentDrainageanddeeppercolation")]
    indecent_drainageanddeeppercolation: IndecentDrainageanddeeppercolation,

    #[serde(rename = "StickySoilwaterflows")]
    sticky_soilwaterflows: StickySoilwaterflows,

    #[serde(rename = "State")]
    state: Auxiliary,

    #[serde(rename = "StateAtmosphericRelatedProcesses")]
    state_atmospheric_related_processes: AtmosphericRelatedProcesses,

    #[serde(rename = "StickySnowPack")]
    sticky_snow_pack: StickySnowPack,

    #[serde(rename = "StateModelFacilities")]
    state_model_facilities: ModelFacilities,

    #[serde(rename = "FluffyIrrigation")]
    fluffy_irrigation: FluffyIrrigation,

    #[serde(rename = "StateNitrogenandCarbon")]
    state_nitrogenand_carbon: StateNitrogenandCarbon,

    #[serde(rename = "StickyExternalNinputs")]
    sticky_external_ninputs: StickyExternalNinputs,

    #[serde(rename = "FluffyExternalPInputs")]
    fluffy_external_p_inputs: FluffyExternalPInputs,

    #[serde(rename = "TentacledPlantGrowth")]
    tentacled_plant_growth: TentacledPlantGrowth,

    #[serde(rename = "StateNitrogenandCarbonBelowGround")]
    state_nitrogenand_carbon_below_ground: FlowNitrogenandCarbonBelowGroundClass,

    #[serde(rename = "TentacledGasprocesses")]
    tentacled_gasprocesses: TentacledGasprocesses,

    #[serde(rename = "IndigoSoilmineralPProcesses")]
    indigo_soilmineral_p_processes: IndigoSoilmineralPProcesses,

    #[serde(rename = "FluffySoilorganicprocesses")]
    fluffy_soilorganicprocesses: FluffySoilorganicprocesses,

    #[serde(rename = "StatePlantWaterProcesses")]
    state_plant_water_processes: PlantWaterProcesses,

    #[serde(rename = "IndigoSaltTracer")]
    indigo_salt_tracer: IndigoSaltTracer,

    #[serde(rename = "StateSoilHeatProcesses")]
    state_soil_heat_processes: AuxiliaryArraysSoilHeatProcessesClass,

    #[serde(rename = "StickySoilheatflows")]
    sticky_soilheatflows: StickySoilheatflows,

    #[serde(rename = "StateSoilWaterProcesses")]
    state_soil_water_processes: StateSoilWaterProcesses,

    #[serde(rename = "StickySurfacewater")]
    sticky_surfacewater: StickySurfacewater,

    #[serde(rename = "StateArrays")]
    state_arrays: Auxiliary,

    #[serde(rename = "StateArraysNitrogenandCarbon")]
    state_arrays_nitrogenand_carbon: StateArraysNitrogenandCarbon,

    #[serde(rename = "LaiAbovecanopy")]
    lai_abovecanopy: LaiAbovecanopy,

    #[serde(rename = "StateArraysNitrogenandCarbonBelowGround")]
    state_arrays_nitrogenand_carbon_below_ground: ArraysNitrogenandCarbonBelowGround,

    #[serde(rename = "StickyGasprocesses")]
    sticky_gasprocesses: StickyGasprocesses,

    #[serde(rename = "IndecentSoilmineralPProcesses")]
    indecent_soilmineral_p_processes: IndecentSoilmineralPProcesses,

    #[serde(rename = "StateArraysPlantWaterProcesses")]
    state_arrays_plant_water_processes: ArraysPlantWaterProcesses,

    #[serde(rename = "IndigoInterception")]
    indigo_interception: IndigoInterception,

    #[serde(rename = "IndecentSaltTracer")]
    indecent_salt_tracer: FluffyPlantGrowth,

    #[serde(rename = "IndigoWateruptake")]
    indigo_wateruptake: IndigoWateruptake,

    #[serde(rename = "StateArraysSoilHeatProcesses")]
    state_arrays_soil_heat_processes: AuxiliarySoilHeatProcessesClass,

    #[serde(rename = "TentacledSoilfrost")]
    tentacled_soilfrost: TentacledSoilfrost,

    #[serde(rename = "IndigoSoilheatflows")]
    indigo_soilheatflows: IndigoSoilheatflows,

    #[serde(rename = "StateArraysSoilWaterProcesses")]
    state_arrays_soil_water_processes: StateArraysSoilWaterProcesses,

    #[serde(rename = "IndigoSoilwaterflows")]
    indigo_soilwaterflows: IndigoSoilwaterflows,

    #[serde(rename = "Parameters")]
    parameters: ModelOptions,

    #[serde(rename = "ParametersAtmosphericRelatedProcesses")]
    parameters_atmospheric_related_processes: AtmosphericRelatedProcesses,

    #[serde(rename = "IndigoSnowPack")]
    indigo_snow_pack: IndigoSnowPack,

    #[serde(rename = "ParametersModelStructure")]
    parameters_model_structure: ModelStructure,

    #[serde(rename = "TentacledModelStructure")]
    tentacled_model_structure: TentacledModelStructure,

    #[serde(rename = "ParametersPlantWaterProcesses")]
    parameters_plant_water_processes: ParametersPlantWaterProcesses,

    #[serde(rename = "IndecentWateruptake")]
    indecent_wateruptake: IndecentWateruptake,

    #[serde(rename = "ParametersSoilHeatProcesses")]
    parameters_soil_heat_processes: ParametersSoilHeatProcesses,

    #[serde(rename = "SoilThermal")]
    soil_thermal: SoilThermal,

    #[serde(rename = "StickySoilfrost")]
    sticky_soilfrost: StickySoilfrost,

    #[serde(rename = "IndecentSoilheatflows")]
    indecent_soilheatflows: IndecentSoilheatflows,

    #[serde(rename = "ParametersSoilWaterProcesses")]
    parameters_soil_water_processes: SoilWaterProcesses,

    #[serde(rename = "HilariousDrainageanddeeppercolation")]
    hilarious_drainageanddeeppercolation: HilariousDrainageanddeeppercolation,

    #[serde(rename = "IndecentSoilwaterflows")]
    indecent_soilwaterflows: IndecentSoilwaterflows,

    #[serde(rename = "IndigoSurfacewater")]
    indigo_surfacewater: IndigoSurfacewater,

    #[serde(rename = "ParametersArrays")]
    parameters_arrays: Auxiliary,

    #[serde(rename = "ParametersArraysAtmosphericRelatedProcesses")]
    parameters_arrays_atmospheric_related_processes: ParametersArraysAtmosphericRelatedProcesses,

    #[serde(rename = "StickyRadiationproperties")]
    sticky_radiationproperties: StickyRadiationproperties,

    #[serde(rename = "KonzelmannCoef")]
    konzelmann_coef: KonzelmannCoef,

    #[serde(rename = "ParametersArraysModelFacilities")]
    parameters_arrays_model_facilities: ParametersArraysModelFacilities,

    #[serde(rename = "TentacledIrrigation")]
    tentacled_irrigation: TentacledIrrigation,

    #[serde(rename = "TentacledTechnical")]
    tentacled_technical: TentacledTechnical,

    #[serde(rename = "AbsError")]
    abs_error: AbsError,

    #[serde(rename = "BoxCox")]
    box_cox: BoxCox,

    #[serde(rename = "ParametersArraysNitrogenandCarbon")]
    parameters_arrays_nitrogenand_carbon: ParametersArraysNitrogenandCarbon,

    #[serde(rename = "RntLaIv")]
    rnt_la_iv: RntLaIv,

    #[serde(rename = "TentacledExternalPInputs")]
    tentacled_external_p_inputs: TentacledExternalPInputs,

    #[serde(rename = "StickyPlantGrowth")]
    sticky_plant_growth: FluffyPlantGrowth,

    #[serde(rename = "ParametersArraysNitrogenandCarbonBelowGround")]
    parameters_arrays_nitrogenand_carbon_below_ground: FlowNitrogenandCarbonBelowGroundClass,

    #[serde(rename = "IndigoGasprocesses")]
    indigo_gasprocesses: IndigoGasprocesses,

    #[serde(rename = "SoilmineralNprocesses")]
    soilmineral_nprocesses: DefinitionsSoilmineralNprocesses,

    #[serde(rename = "HilariousSoilmineralPProcesses")]
    hilarious_soilmineral_p_processes: HilariousSoilmineralPProcesses,

    #[serde(rename = "TentacledSoilorganicprocesses")]
    tentacled_soilorganicprocesses: TentacledSoilorganicprocesses,

    #[serde(rename = "ParametersArraysPlantWaterProcesses")]
    parameters_arrays_plant_water_processes: ParametersArraysPlantWaterProcesses,

    #[serde(rename = "IndecentInterception")]
    indecent_interception: IndecentInterception,

    #[serde(rename = "StickyPlant")]
    sticky_plant: FluffyPlantGrowth,

    #[serde(rename = "AlbedoV")]
    albedo_v: AlbedoV,

    #[serde(rename = "TentacledPotentialTranspiration")]
    tentacled_potential_transpiration: FluffyPlantGrowth,

    #[serde(rename = "HilariousSaltTracer")]
    hilarious_salt_tracer: HilariousSaltTracer,

    #[serde(rename = "ParametersArraysSoilHeatProcesses")]
    parameters_arrays_soil_heat_processes: ParametersArraysSoilHeatProcesses,

    #[serde(rename = "InfilDistF")]
    infil_dist_f: InfilDistF,

    #[serde(rename = "HilariousSoilheatflows")]
    hilarious_soilheatflows: HilariousSoilheatflows,

    #[serde(rename = "ParametersArraysSoilWaterProcesses")]
    parameters_arrays_soil_water_processes: ParametersArraysSoilWaterProcesses,

    #[serde(rename = "SoilHydraulic")]
    soil_hydraulic: SoilHydraulic,

    #[serde(rename = "HilariousSoilwaterflows")]
    hilarious_soilwaterflows: HilariousSoilwaterflows,

    #[serde(rename = "RunInfo")]
    run_info: RunInfo,

    #[serde(rename = "AdditionalDetails")]
    additional_details: AdditionalDetails,

    #[serde(rename = "GeneralInformation")]
    general_information: GeneralInformation,

    #[serde(rename = "NumericalOptions")]
    numerical_options: NumericalOptions,

    #[serde(rename = "SimulationPeriod")]
    simulation_period: SimulationPeriod,

    #[serde(rename = "TimeResolution")]
    time_resolution: TimeResolution,

    #[serde(rename = "PipeSegmentLength")]
    pipe_segment_length: PipeSegmentLength,

    #[serde(rename = "Condition3_Enum")]
    condition3_enum: AlbedoVArrayName,

    #[serde(rename = "Condition2_Enum")]
    condition2_enum: AlbedoVArrayName,

    #[serde(rename = "LAIAbovecanopyArrayName")]
    lai_abovecanopy_array_name: AlbedoVArrayName,

    #[serde(rename = "LAIAbovecanopyCondition1")]
    lai_abovecanopy_condition1: AlbedoVArrayName,

    #[serde(rename = "CCoarseRootsATMLayerArrayName")]
    c_coarse_roots_atm_layer_array_name: AlbedoVArrayName,

    #[serde(rename = "RntLAIvCondition1")]
    rnt_la_iv_condition1: AlbedoVArrayName,

    #[serde(rename = "AlbedoVArrayName")]
    albedo_v_array_name: AlbedoVArrayName,

    #[serde(rename = "ArrayName")]
    array_name: AlbedoVArrayName,
}

#[derive(Serialize, Deserialize)]
pub struct AbsError {
    #[serde(rename = "type")]
    abs_error_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: AbsErrorProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct AbsErrorProperties {
    #[serde(rename = "SizeofArray")]
    sizeof_array: SizeofArray,

    #[serde(rename = "ArrayName")]
    array_name: DefaultIndex1_Value,

    #[serde(rename = "Condition_1")]
    condition_1: DefaultIndex1_Value,
}

#[derive(Serialize, Deserialize)]
pub struct DefaultIndex1_Value {
    #[serde(rename = "type")]
    array_name_type: ArrayNameType,
}

#[derive(Serialize, Deserialize)]
pub struct SizeofArray {
    #[serde(rename = "type")]
    sizeof_array_type: ArrayNameType,

    #[serde(rename = "format")]
    format: Format,
}

#[derive(Serialize, Deserialize)]
pub struct AdditionalDetails {
    #[serde(rename = "type")]
    additional_details_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: AdditionalDetailsProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct AdditionalDetailsProperties {
    #[serde(rename = "LockedMultiStore")]
    locked_multi_store: SizeofArray,
}

#[derive(Serialize, Deserialize)]
pub struct AlbedoV {
    #[serde(rename = "type")]
    albedo_v_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: AlbedoVProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct AlbedoVProperties {
    #[serde(rename = "Default_Index_1")]
    default_index_1: DefaultIndex1_Value,

    #[serde(rename = "MinValue_Index_3")]
    min_value_index_3: DefaultIndex1_Value,

    #[serde(rename = "Condition_3")]
    condition_3: DefaultIndex1_Value,

    #[serde(rename = "MinValue_Index_5")]
    min_value_index_5: DefaultIndex1_Value,

    #[serde(rename = "MinValue_Index_2")]
    min_value_index_2: DefaultIndex1_Value,

    #[serde(rename = "SizeofArray")]
    sizeof_array: SizeofArray,

    #[serde(rename = "Index_1")]
    index_1: DefaultIndex1_Value,

    #[serde(rename = "MaxValue_Index_1")]
    max_value_index_1: DefaultIndex1_Value,

    #[serde(rename = "MinValue_Index_4")]
    min_value_index_4: DefaultIndex1_Value,

    #[serde(rename = "ArrayName")]
    array_name: NitrogenandCarbonValue,

    #[serde(rename = "MinValue_Index_1")]
    min_value_index_1: DefaultIndex1_Value,

    #[serde(rename = "Default_Index_3")]
    default_index_3: DefaultIndex1_Value,

    #[serde(rename = "MaxValue_Index_5")]
    max_value_index_5: DefaultIndex1_Value,

    #[serde(rename = "Index_5")]
    index_5: DefaultIndex1_Value,

    #[serde(rename = "Default_Index_2")]
    default_index_2: DefaultIndex1_Value,

    #[serde(rename = "MaxValue_Index_3")]
    max_value_index_3: DefaultIndex1_Value,

    #[serde(rename = "Index_3")]
    index_3: DefaultIndex1_Value,

    #[serde(rename = "MaxValue_Index_4")]
    max_value_index_4: DefaultIndex1_Value,

    #[serde(rename = "Index_4")]
    index_4: DefaultIndex1_Value,

    #[serde(rename = "Condition_1")]
    condition_1: DefaultIndex1_Value,

    #[serde(rename = "Default_Index_5")]
    default_index_5: DefaultIndex1_Value,

    #[serde(rename = "MaxValue_Index_2")]
    max_value_index_2: DefaultIndex1_Value,

    #[serde(rename = "Index_2")]
    index_2: DefaultIndex1_Value,

    #[serde(rename = "Condition_2")]
    condition_2: DefaultIndex1_Value,

    #[serde(rename = "Default_Index_4")]
    default_index_4: DefaultIndex1_Value,

    #[serde(rename = "Condition_4")]
    condition_4: DefaultIndex1_Value,
}

#[derive(Serialize, Deserialize)]
pub struct NitrogenandCarbonValue {
    #[serde(rename = "$ref")]
    array_name_ref: String,
}

#[derive(Serialize, Deserialize)]
pub struct AlbedoVArrayName {
    #[serde(rename = "type")]
    albedo_v_array_name_type: ArrayNameType,

    #[serde(rename = "enum")]
    albedo_v_array_name_enum: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct AlbedoVar {
    #[serde(rename = "type")]
    albedo_var_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: AlbedoVarProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct AlbedoVarProperties {
    #[serde(rename = "OutMulti")]
    out_multi: SizeofArray,

    #[serde(rename = "OutSingle")]
    out_single: SizeofArray,

    #[serde(rename = "Condition_1")]
    condition_1: NitrogenandCarbonValue,

    #[serde(rename = "Condition_2")]
    condition_2: DefaultIndex1_Value,

    #[serde(rename = "Condition_3")]
    condition_3: DefaultIndex1_Value,

    #[serde(rename = "Condition_4")]
    condition_4: DefaultIndex1_Value,

    #[serde(rename = "Condition_5")]
    condition_5: DefaultIndex1_Value,

    #[serde(rename = "Condition_6")]
    condition_6: DefaultIndex1_Value,
}

#[derive(Serialize, Deserialize)]
pub struct Auxiliary {
    #[serde(rename = "type")]
    auxiliary_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: AuxiliaryProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct AuxiliaryProperties {
    #[serde(rename = "ModelStructure")]
    model_structure: Option<NitrogenandCarbonValue>,

    #[serde(rename = "NitrogenandCarbon")]
    nitrogenand_carbon: NitrogenandCarbonValue,

    #[serde(rename = "SoilWaterProcesses")]
    soil_water_processes: NitrogenandCarbonValue,

    #[serde(rename = "SoilHeatProcesses")]
    soil_heat_processes: Option<NitrogenandCarbonValue>,

    #[serde(rename = "PlantWaterProcesses")]
    plant_water_processes: NitrogenandCarbonValue,

    #[serde(rename = "AtmosphericRelatedProcesses")]
    atmospheric_related_processes: Option<NitrogenandCarbonValue>,

    #[serde(rename = "NitrogenandCarbon-BelowGround")]
    nitrogenand_carbon_below_ground: NitrogenandCarbonValue,

    #[serde(rename = "ModelFacilities")]
    model_facilities: Option<NitrogenandCarbonValue>,
}

#[derive(Serialize, Deserialize)]
pub struct AuxiliaryArraysAtmosphericRelatedProcesses {
    #[serde(rename = "type")]
    auxiliary_arrays_atmospheric_related_processes_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: AuxiliaryArraysAtmosphericRelatedProcessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct AuxiliaryArraysAtmosphericRelatedProcessesProperties {
    #[serde(rename = "SnowPack")]
    snow_pack: NitrogenandCarbonValue,

    #[serde(rename = "Radiationproperties")]
    radiationproperties: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct AuxiliaryArraysNitrogenandCarbon {
    #[serde(rename = "type")]
    auxiliary_arrays_nitrogenand_carbon_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: AuxiliaryArraysNitrogenandCarbonProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct AuxiliaryArraysNitrogenandCarbonProperties {
    #[serde(rename = "PlantGrowth")]
    plant_growth: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct ArraysNitrogenandCarbonBelowGround {
    #[serde(rename = "type")]
    arrays_nitrogenand_carbon_below_ground_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: AuxiliaryArraysNitrogenandCarbonBelowGroundProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct AuxiliaryArraysNitrogenandCarbonBelowGroundProperties {
    #[serde(rename = "SoilmineralPProcesses")]
    soilmineral_p_processes: NitrogenandCarbonValue,

    #[serde(rename = "Gasprocesses")]
    gasprocesses: NitrogenandCarbonValue,

    #[serde(rename = "Soilorganicprocesses")]
    soilorganicprocesses: SoilmineralNprocesses,

    #[serde(rename = "SoilmineralNprocesses")]
    soilmineral_nprocesses: SoilmineralNprocesses,
}

#[derive(Serialize, Deserialize)]
pub struct SoilmineralNprocesses {
    #[serde(rename = "type")]
    soilmineral_nprocesses_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct AuxiliaryArraysPlantWaterProcesses {
    #[serde(rename = "type")]
    auxiliary_arrays_plant_water_processes_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: AuxiliaryArraysPlantWaterProcessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct AuxiliaryArraysPlantWaterProcessesProperties {
    #[serde(rename = "PotentialTranspiration")]
    potential_transpiration: NitrogenandCarbonValue,

    #[serde(rename = "Plant")]
    plant: NitrogenandCarbonValue,

    #[serde(rename = "Wateruptake")]
    wateruptake: NitrogenandCarbonValue,

    #[serde(rename = "SaltTracer")]
    salt_tracer: NitrogenandCarbonValue,

    #[serde(rename = "Interception")]
    interception: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct AuxiliaryArraysSoilHeatProcessesClass {
    #[serde(rename = "type")]
    soil_heat_processes_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: AuxiliaryArraysSoilHeatProcessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct AuxiliaryArraysSoilHeatProcessesProperties {
    #[serde(rename = "Soilheatflows")]
    soilheatflows: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct ArraysSoilWaterProcesses {
    #[serde(rename = "type")]
    arrays_soil_water_processes_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: AuxiliaryArraysSoilWaterProcessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct AuxiliaryArraysSoilWaterProcessesProperties {
    #[serde(rename = "Soilwaterflows")]
    soilwaterflows: NitrogenandCarbonValue,

    #[serde(rename = "Drainageanddeeppercolation")]
    drainageanddeeppercolation: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct AuxiliaryAtmosphericRelatedProcesses {
    #[serde(rename = "type")]
    auxiliary_atmospheric_related_processes_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: AuxiliaryAtmosphericRelatedProcessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct AuxiliaryAtmosphericRelatedProcessesProperties {
    #[serde(rename = "Soilevaporation")]
    soilevaporation: SoilmineralNprocesses,

    #[serde(rename = "SnowPack")]
    snow_pack: SoilmineralNprocesses,

    #[serde(rename = "Radiationproperties")]
    radiationproperties: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct ModelStructure {
    #[serde(rename = "type")]
    model_structure_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: AuxiliaryModelStructureProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct AuxiliaryModelStructureProperties {
    #[serde(rename = "ModelStructure")]
    model_structure: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct NitrogenandCarbon {
    #[serde(rename = "type")]
    nitrogenand_carbon_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: AuxiliaryNitrogenandCarbonProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct AuxiliaryNitrogenandCarbonProperties {
    #[serde(rename = "PlantGrowth")]
    plant_growth: SoilmineralNprocesses,

    #[serde(rename = "ExternalNinputs")]
    external_ninputs: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct AuxiliaryNitrogenandCarbonBelowGroundClass {
    #[serde(rename = "type")]
    nitrogenand_carbon_below_ground_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: AuxiliaryNitrogenandCarbonBelowGroundProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct AuxiliaryNitrogenandCarbonBelowGroundProperties {
    #[serde(rename = "SoilmineralPProcesses")]
    soilmineral_p_processes: NitrogenandCarbonValue,

    #[serde(rename = "Gasprocesses")]
    gasprocesses: SoilmineralNprocesses,

    #[serde(rename = "Soilorganicprocesses")]
    soilorganicprocesses: SoilmineralNprocesses,

    #[serde(rename = "SoilmineralNprocesses")]
    soilmineral_nprocesses: SoilmineralNprocesses,
}

#[derive(Serialize, Deserialize)]
pub struct AuxiliaryPlantWaterProcesses {
    #[serde(rename = "type")]
    auxiliary_plant_water_processes_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: AuxiliaryPlantWaterProcessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct AuxiliaryPlantWaterProcessesProperties {
    #[serde(rename = "PotentialTranspiration")]
    potential_transpiration: NitrogenandCarbonValue,

    #[serde(rename = "Plant")]
    plant: NitrogenandCarbonValue,

    #[serde(rename = "Wateruptake")]
    wateruptake: NitrogenandCarbonValue,

    #[serde(rename = "SaltTracer")]
    salt_tracer: SoilmineralNprocesses,

    #[serde(rename = "Interception")]
    interception: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct AuxiliarySoilHeatProcessesClass {
    #[serde(rename = "type")]
    soil_heat_processes_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: AuxiliarySoilHeatProcessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct AuxiliarySoilHeatProcessesProperties {
    #[serde(rename = "Soilfrost")]
    soilfrost: NitrogenandCarbonValue,

    #[serde(rename = "Soilheatflows")]
    soilheatflows: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct SoilWaterProcesses {
    #[serde(rename = "type")]
    soil_water_processes_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: AuxiliarySoilWaterProcessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct AuxiliarySoilWaterProcessesProperties {
    #[serde(rename = "Soilwaterflows")]
    soilwaterflows: NitrogenandCarbonValue,

    #[serde(rename = "Drainageanddeeppercolation")]
    drainageanddeeppercolation: NitrogenandCarbonValue,

    #[serde(rename = "Surfacewater")]
    surfacewater: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct BoxCox {
    #[serde(rename = "type")]
    box_cox_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: BoxCoxProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct BoxCoxProperties {
    #[serde(rename = "SizeofArray")]
    sizeof_array: SizeofArray,

    #[serde(rename = "ArrayName")]
    array_name: DefaultIndex1_Value,
}

#[derive(Serialize, Deserialize)]
pub struct CCoarseRootsAtmLayer {
    #[serde(rename = "type")]
    c_coarse_roots_atm_layer_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: CCoarseRootsAtmLayerProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct CCoarseRootsAtmLayerProperties {
    #[serde(rename = "OutSingle_Index_5")]
    out_single_index_5: SizeofArray,

    #[serde(rename = "OutMulti_Index_6")]
    out_multi_index_6: SizeofArray,

    #[serde(rename = "OutSingle_Index_8")]
    out_single_index_8: SizeofArray,

    #[serde(rename = "SizeofArray")]
    sizeof_array: SizeofArray,

    #[serde(rename = "OutMulti_Index_1")]
    out_multi_index_1: SizeofArray,

    #[serde(rename = "OutSingle_Index_2")]
    out_single_index_2: SizeofArray,

    #[serde(rename = "ArrayName")]
    array_name: NitrogenandCarbonValue,

    #[serde(rename = "OutSingle_Index_3")]
    out_single_index_3: SizeofArray,

    #[serde(rename = "OutSingle_Index_6")]
    out_single_index_6: SizeofArray,

    #[serde(rename = "OutMulti_Index_5")]
    out_multi_index_5: SizeofArray,

    #[serde(rename = "OutMulti_Index_3")]
    out_multi_index_3: SizeofArray,

    #[serde(rename = "OutSingle_Index_7")]
    out_single_index_7: SizeofArray,

    #[serde(rename = "OutMulti_Index_4")]
    out_multi_index_4: SizeofArray,

    #[serde(rename = "Condition_1")]
    condition_1: NitrogenandCarbonValue,

    #[serde(rename = "OutSingle_Index_1")]
    out_single_index_1: SizeofArray,

    #[serde(rename = "OutMulti_Index_2")]
    out_multi_index_2: SizeofArray,

    #[serde(rename = "Condition_2")]
    condition_2: DefaultIndex1_Value,

    #[serde(rename = "OutSingle_Index_4")]
    out_single_index_4: SizeofArray,

    #[serde(rename = "OutMulti_Index_7")]
    out_multi_index_7: SizeofArray,

    #[serde(rename = "OutMulti_Index_8")]
    out_multi_index_8: SizeofArray,

    #[serde(rename = "Condition_3")]
    condition_3: DefaultIndex1_Value,

    #[serde(rename = "Condition_4")]
    condition_4: DefaultIndex1_Value,
}

#[derive(Serialize, Deserialize)]
pub struct CanopyFracRadDiffuse {
    #[serde(rename = "type")]
    canopy_frac_rad_diffuse_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: CanopyFracRadDiffuseProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct CanopyFracRadDiffuseProperties {
    #[serde(rename = "OutMulti")]
    out_multi: SizeofArray,

    #[serde(rename = "Condition_3")]
    condition_3: DefaultIndex1_Value,

    #[serde(rename = "Condition_4")]
    condition_4: DefaultIndex1_Value,

    #[serde(rename = "OutSingle")]
    out_single: SizeofArray,

    #[serde(rename = "Condition_1")]
    condition_1: DefaultIndex1_Value,

    #[serde(rename = "Condition_2")]
    condition_2: DefaultIndex1_Value,

    #[serde(rename = "Condition_5")]
    condition_5: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct Driving {
    #[serde(rename = "type")]
    driving_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: DrivingProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct DrivingProperties {
    #[serde(rename = "PlantWaterProcesses")]
    plant_water_processes: NitrogenandCarbonValue,

    #[serde(rename = "AtmosphericRelatedProcesses")]
    atmospheric_related_processes: NitrogenandCarbonValue,

    #[serde(rename = "NitrogenandCarbon-BelowGround")]
    nitrogenand_carbon_below_ground: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct DrivingArrays {
    #[serde(rename = "type")]
    driving_arrays_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: DrivingArraysProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct DrivingArraysProperties {
    #[serde(rename = "AtmosphericRelatedProcesses")]
    atmospheric_related_processes: NitrogenandCarbonValue,

    #[serde(rename = "NitrogenandCarbon-BelowGround")]
    nitrogenand_carbon_below_ground: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct SAtmosphericRelatedProcesses {
    #[serde(rename = "type")]
    s_atmospheric_related_processes_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: DrivingArraysAtmosphericRelatedProcessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct DrivingArraysAtmosphericRelatedProcessesProperties {
    #[serde(rename = "MeteorologicalData")]
    meteorological_data: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct DrivingArraysNitrogenandCarbonBelowGroundClass {
    #[serde(rename = "type")]
    nitrogenand_carbon_below_ground_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: DrivingArraysNitrogenandCarbonBelowGroundProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct DrivingArraysNitrogenandCarbonBelowGroundProperties {
    #[serde(rename = "Abioticdrivingvariables")]
    abioticdrivingvariables: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct DrivingAtmosphericRelatedProcesses {
    #[serde(rename = "type")]
    driving_atmospheric_related_processes_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: DrivingAtmosphericRelatedProcessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct DrivingAtmosphericRelatedProcessesProperties {
    #[serde(rename = "SnowPack")]
    snow_pack: NitrogenandCarbonValue,

    #[serde(rename = "MeteorologicalData")]
    meteorological_data: SoilmineralNprocesses,
}

#[derive(Serialize, Deserialize)]
pub struct PlantWaterProcesses {
    #[serde(rename = "type")]
    plant_water_processes_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: DrivingPlantWaterProcessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct DrivingPlantWaterProcessesProperties {
    #[serde(rename = "SaltTracer")]
    salt_tracer: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct EvaporationMethod {
    #[serde(rename = "type")]
    evaporation_method_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: EvaporationMethodProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct EvaporationMethodProperties {
    #[serde(rename = "Opt_0")]
    opt_0: DefaultIndex1_Value,

    #[serde(rename = "Condition_3")]
    condition_3: DefaultIndex1_Value,

    #[serde(rename = "Opt_1")]
    opt_1: DefaultIndex1_Value,

    #[serde(rename = "Default")]
    properties_default: SizeofArray,

    #[serde(rename = "Opt_2")]
    opt_2: DefaultIndex1_Value,

    #[serde(rename = "Current")]
    current: DefaultIndex1_Value,

    #[serde(rename = "Opt_3")]
    opt_3: DefaultIndex1_Value,

    #[serde(rename = "Condition_1")]
    condition_1: NitrogenandCarbonValue,

    #[serde(rename = "Opt_4")]
    opt_4: DefaultIndex1_Value,

    #[serde(rename = "Condition_2")]
    condition_2: DefaultIndex1_Value,

    #[serde(rename = "Condition_4")]
    condition_4: DefaultIndex1_Value,

    #[serde(rename = "Max")]
    max: SizeofArray,

    #[serde(rename = "Min")]
    min: SizeofArray,
}

#[derive(Serialize, Deserialize)]
pub struct ArraysPlantWaterProcesses {
    #[serde(rename = "type")]
    arrays_plant_water_processes_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: FlowArraysPlantWaterProcessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct FlowArraysPlantWaterProcessesProperties {
    #[serde(rename = "Wateruptake")]
    wateruptake: NitrogenandCarbonValue,

    #[serde(rename = "SaltTracer")]
    salt_tracer: NitrogenandCarbonValue,

    #[serde(rename = "Interception")]
    interception: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct FlowAtmosphericRelatedProcesses {
    #[serde(rename = "type")]
    flow_atmospheric_related_processes_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: FlowAtmosphericRelatedProcessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct FlowAtmosphericRelatedProcessesProperties {
    #[serde(rename = "Soilevaporation")]
    soilevaporation: NitrogenandCarbonValue,

    #[serde(rename = "SnowPack")]
    snow_pack: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct ModelFacilities {
    #[serde(rename = "type")]
    model_facilities_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: FlowModelFacilitiesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct FlowModelFacilitiesProperties {
    #[serde(rename = "Irrigation")]
    irrigation: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct FlowNitrogenandCarbon {
    #[serde(rename = "type")]
    flow_nitrogenand_carbon_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: FlowNitrogenandCarbonProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct FlowNitrogenandCarbonProperties {
    #[serde(rename = "ExternalPInputs")]
    external_p_inputs: NitrogenandCarbonValue,

    #[serde(rename = "PlantGrowth")]
    plant_growth: SoilmineralNprocesses,

    #[serde(rename = "ExternalNinputs")]
    external_ninputs: SoilmineralNprocesses,
}

#[derive(Serialize, Deserialize)]
pub struct FlowNitrogenandCarbonBelowGroundClass {
    #[serde(rename = "type")]
    nitrogenand_carbon_below_ground_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: FlowNitrogenandCarbonBelowGroundProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct FlowNitrogenandCarbonBelowGroundProperties {
    #[serde(rename = "SoilmineralPProcesses")]
    soilmineral_p_processes: NitrogenandCarbonValue,

    #[serde(rename = "Gasprocesses")]
    gasprocesses: NitrogenandCarbonValue,

    #[serde(rename = "Soilorganicprocesses")]
    soilorganicprocesses: NitrogenandCarbonValue,

    #[serde(rename = "SoilmineralNprocesses")]
    soilmineral_nprocesses: Option<NitrogenandCarbonValue>,
}

#[derive(Serialize, Deserialize)]
pub struct FlowPlantWaterProcesses {
    #[serde(rename = "type")]
    flow_plant_water_processes_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: FlowPlantWaterProcessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct FlowPlantWaterProcessesProperties {
    #[serde(rename = "SaltTracer")]
    salt_tracer: SoilmineralNprocesses,
}

#[derive(Serialize, Deserialize)]
pub struct FlowSoilHeatProcesses {
    #[serde(rename = "type")]
    flow_soil_heat_processes_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: FlowSoilHeatProcessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct FlowSoilHeatProcessesProperties {
    #[serde(rename = "Soilheatflows")]
    soilheatflows: SoilmineralNprocesses,

    #[serde(rename = "Soilheatpump")]
    soilheatpump: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct FluffyAbioticdrivingvariables {
    #[serde(rename = "type")]
    fluffy_abioticdrivingvariables_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: FluffyAbioticdrivingvariablesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct FluffyAbioticdrivingvariablesProperties {
    #[serde(rename = "NDrivInfiltration")]
    n_driv_infiltration: NitrogenandCarbonValue,

    #[serde(rename = "GreenIndexChange")]
    green_index_change: NitrogenandCarbonValue,

    #[serde(rename = "NDrivDeepPercolation")]
    n_driv_deep_percolation: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct FluffyDrainageanddeeppercolation {
    #[serde(rename = "type")]
    fluffy_drainageanddeeppercolation_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: FluffyDrainageanddeeppercolationProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct FluffyDrainageanddeeppercolationProperties {
    #[serde(rename = "EmpiricalDrainEq")]
    empirical_drain_eq: NitrogenandCarbonValue,

    #[serde(rename = "PhysicalDrainEq")]
    physical_drain_eq: NitrogenandCarbonValue,

    #[serde(rename = "LateralGWSource")]
    lateral_gw_source: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct FluffyExternalNinputs {
    #[serde(rename = "type")]
    fluffy_external_ninputs_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: FluffyExternalNinputsProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct FluffyExternalNinputsProperties {
    #[serde(rename = "TotalDepositionNLeaf")]
    total_deposition_n_leaf: NitrogenandCarbonValue,

    #[serde(rename = "NIrrigApplRate")]
    n_irrig_appl_rate: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct FluffyExternalPInputs {
    #[serde(rename = "type")]
    fluffy_external_p_inputs_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: FluffyExternalPInputsProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct FluffyExternalPInputsProperties {
    #[serde(rename = "PFertilizer")]
    p_fertilizer: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct FluffyGasprocesses {
    #[serde(rename = "type")]
    fluffy_gasprocesses_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: FluffyGasprocessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct FluffyGasprocessesProperties {
    #[serde(rename = "CO2FluxOut")]
    co2_flux_out: NitrogenandCarbonValue,

    #[serde(rename = "N2emissionrate")]
    n2_emissionrate: NitrogenandCarbonValue,

    #[serde(rename = "NOemissionrate")]
    n_oemissionrate: NitrogenandCarbonValue,

    #[serde(rename = "CH4SurfaceEmission")]
    ch4_surface_emission: NitrogenandCarbonValue,

    #[serde(rename = "OxygenFluxInfil")]
    oxygen_flux_infil: NitrogenandCarbonValue,

    #[serde(rename = "N2Oemissionrate")]
    n2_oemissionrate: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct FluffyInterception {
    #[serde(rename = "type")]
    fluffy_interception_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: FluffyInterceptionProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct FluffyInterceptionProperties {
    #[serde(rename = "Throughfall")]
    throughfall: NitrogenandCarbonValue,

    #[serde(rename = "InterceptionStorage")]
    interception_storage: NitrogenandCarbonValue,

    #[serde(rename = "InterceptionActEva")]
    interception_act_eva: NitrogenandCarbonValue,

    #[serde(rename = "InterceptionRate")]
    interception_rate: NitrogenandCarbonValue,

    #[serde(rename = "InterceptedWaterThQ")]
    intercepted_water_th_q: NitrogenandCarbonValue,

    #[serde(rename = "InterceptionPotEva")]
    interception_pot_eva: NitrogenandCarbonValue,

    #[serde(rename = "InterceptionCapacity")]
    interception_capacity: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct FluffyIrrigation {
    #[serde(rename = "type")]
    fluffy_irrigation_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: FluffyIrrigationProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct FluffyIrrigationProperties {
    #[serde(rename = "DripContainer")]
    drip_container: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct FluffyMeteorologicalData {
    #[serde(rename = "type")]
    fluffy_meteorological_data_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: FluffyMeteorologicalDataProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct FluffyMeteorologicalDataProperties {
    #[serde(rename = "RadGlobInput")]
    rad_glob_input: NitrogenandCarbonValue,

    #[serde(rename = "PrecInput")]
    prec_input: NitrogenandCarbonValue,

    #[serde(rename = "TempAirInput")]
    temp_air_input: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct FluffyModelStructure {
    #[serde(rename = "type")]
    fluffy_model_structure_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: FluffyModelStructureProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct FluffyModelStructureProperties {
    #[serde(rename = "Timestep")]
    timestep: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct FluffyPlant {
    #[serde(rename = "type")]
    fluffy_plant_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: FluffyPlantProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct FluffyPlantProperties {
    #[serde(rename = "RootLength_Total")]
    root_length_total: NitrogenandCarbonValue,

    #[serde(rename = "LeafAreaIndexSum")]
    leaf_area_index_sum: NitrogenandCarbonValue,

    #[serde(rename = "TsumPlant")]
    tsum_plant: NitrogenandCarbonValue,

    #[serde(rename = "TotSoilCoverFraction")]
    tot_soil_cover_fraction: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct FluffyPlantGrowth {
    #[serde(rename = "type")]
    fluffy_plant_growth_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: HashMap<String, NitrogenandCarbonValue>,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct FluffyPotentialTranspiration {
    #[serde(rename = "type")]
    fluffy_potential_transpiration_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: FluffyPotentialTranspirationProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct FluffyPotentialTranspirationProperties {
    #[serde(rename = "ResistAirCanopy")]
    resist_air_canopy: NitrogenandCarbonValue,

    #[serde(rename = "PotMaxTranspiration")]
    pot_max_transpiration: NitrogenandCarbonValue,

    #[serde(rename = "ResistanceMinCanopy")]
    resistance_min_canopy: NitrogenandCarbonValue,

    #[serde(rename = "ResistanceCanopy")]
    resistance_canopy: NitrogenandCarbonValue,

    #[serde(rename = "ResponseTranspAtm")]
    response_transp_atm: NitrogenandCarbonValue,

    #[serde(rename = "PotTranspiration")]
    pot_transpiration: NitrogenandCarbonValue,

    #[serde(rename = "RoughnessLength")]
    roughness_length: NitrogenandCarbonValue,

    #[serde(rename = "DisplacementHeight")]
    displacement_height: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct FluffySaltTracer {
    #[serde(rename = "type")]
    fluffy_salt_tracer_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: FluffySaltTracerProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct FluffySaltTracerProperties {
    #[serde(rename = "OsmoticPressure")]
    osmotic_pressure: NitrogenandCarbonValue,

    #[serde(rename = "TECRatioLeaf")]
    tec_ratio_leaf: NitrogenandCarbonValue,

    #[serde(rename = "TECRatioOldStem")]
    tec_ratio_old_stem: NitrogenandCarbonValue,

    #[serde(rename = "SaltConc")]
    salt_conc: NitrogenandCarbonValue,

    #[serde(rename = "TECRatioRoots")]
    tec_ratio_roots: NitrogenandCarbonValue,

    #[serde(rename = "TECRatioStem")]
    tec_ratio_stem: NitrogenandCarbonValue,

    #[serde(rename = "TECRatioOldLeaf")]
    tec_ratio_old_leaf: NitrogenandCarbonValue,

    #[serde(rename = "TECRatioGrain")]
    tec_ratio_grain: NitrogenandCarbonValue,

    #[serde(rename = "TECRatioOldRoots")]
    tec_ratio_old_roots: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct FluffySnowPack {
    #[serde(rename = "type")]
    fluffy_snow_pack_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: FluffySnowPackProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct FluffySnowPackProperties {
    #[serde(rename = "SnowMeasured")]
    snow_measured: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct FluffySoilevaporation {
    #[serde(rename = "type")]
    fluffy_soilevaporation_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: FluffySoilevaporationProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct FluffySoilevaporationProperties {
    #[serde(rename = "SoilEvaporation")]
    soil_evaporation: NitrogenandCarbonValue,

    #[serde(rename = "SurfHeatFlow1")]
    surf_heat_flow1: NitrogenandCarbonValue,

    #[serde(rename = "SoilEvaporation2")]
    soil_evaporation2: NitrogenandCarbonValue,

    #[serde(rename = "SurfHeatFlow2")]
    surf_heat_flow2: NitrogenandCarbonValue,

    #[serde(rename = "SoilEvaporation1")]
    soil_evaporation1: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct FluffySoilfrost {
    #[serde(rename = "type")]
    fluffy_soilfrost_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: FluffySoilfrostProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct FluffySoilfrostProperties {
    #[serde(rename = "WaterflowLD_HD")]
    waterflow_ld_hd: NitrogenandCarbonValue,

    #[serde(rename = "InFreeze")]
    in_freeze: NitrogenandCarbonValue,

    #[serde(rename = "WaterflowHD_LD")]
    waterflow_hd_ld: NitrogenandCarbonValue,

    #[serde(rename = "WaterflowHFD")]
    waterflow_hfd: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct FluffySoilheatflows {
    #[serde(rename = "type")]
    fluffy_soilheatflows_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: FluffySoilheatflowsProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct FluffySoilheatflowsProperties {
    #[serde(rename = "ThermalConductivity")]
    thermal_conductivity: NitrogenandCarbonValue,

    #[serde(rename = "ThermalQualilty")]
    thermal_qualilty: NitrogenandCarbonValue,

    #[serde(rename = "TempOutPipe")]
    temp_out_pipe: NitrogenandCarbonValue,

    #[serde(rename = "Temperature")]
    temperature: NitrogenandCarbonValue,

    #[serde(rename = "TempColdPipe")]
    temp_cold_pipe: NitrogenandCarbonValue,

    #[serde(rename = "ExactTemperature")]
    exact_temperature: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct FluffySoilmineralPProcesses {
    #[serde(rename = "type")]
    fluffy_soilmineral_p_processes_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: FluffySoilmineralPProcessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct FluffySoilmineralPProcessesProperties {
    #[serde(rename = "SoilPSolution")]
    soil_p_solution: NitrogenandCarbonValue,

    #[serde(rename = "SoilPconc")]
    soil_pconc: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct FluffySoilorganicprocesses {
    #[serde(rename = "type")]
    fluffy_soilorganicprocesses_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: FluffySoilorganicprocessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct FluffySoilorganicprocessesProperties {
    #[serde(rename = "NSurfaceLitter2")]
    n_surface_litter2: NitrogenandCarbonValue,

    #[serde(rename = "CSurfaceLitter1")]
    c_surface_litter1: NitrogenandCarbonValue,

    #[serde(rename = "PSurfaceLitter2")]
    p_surface_litter2: NitrogenandCarbonValue,

    #[serde(rename = "NSurfaceLitter1")]
    n_surface_litter1: NitrogenandCarbonValue,

    #[serde(rename = "CSurfaceLitter2")]
    c_surface_litter2: NitrogenandCarbonValue,

    #[serde(rename = "PSurfaceLitter1")]
    p_surface_litter1: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct FluffySoilwaterflows {
    #[serde(rename = "type")]
    fluffy_soilwaterflows_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: FluffySoilwaterflowsProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct FluffySoilwaterflowsProperties {
    #[serde(rename = "WaterContent")]
    water_content: NitrogenandCarbonValue,

    #[serde(rename = "HysEffect")]
    hys_effect: NitrogenandCarbonValue,

    #[serde(rename = "MeanTransitTime")]
    mean_transit_time: NitrogenandCarbonValue,

    #[serde(rename = "ThetaB")]
    theta_b: NitrogenandCarbonValue,

    #[serde(rename = "TotalWaterContent")]
    total_water_content: NitrogenandCarbonValue,

    #[serde(rename = "WBypassflow")]
    w_bypassflow: NitrogenandCarbonValue,

    #[serde(rename = "PressureHead")]
    pressure_head: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct FluffySurfacewater {
    #[serde(rename = "type")]
    fluffy_surfacewater_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: FluffySurfacewaterProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct FluffySurfacewaterProperties {
    #[serde(rename = "SpoolCover")]
    spool_cover: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct FluffyTechnical {
    #[serde(rename = "type")]
    fluffy_technical_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: FluffyTechnicalProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct FluffyTechnicalProperties {
    #[serde(rename = "TypeOfDrivingFile")]
    type_of_driving_file: NitrogenandCarbonValue,

    #[serde(rename = "TimeResolution")]
    time_resolution: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct FluffyWateruptake {
    #[serde(rename = "type")]
    fluffy_wateruptake_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: FluffyWateruptakeProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct FluffyWateruptakeProperties {
    #[serde(rename = "RedCTotalallplant")]
    red_c_totalallplant: NitrogenandCarbonValue,

    #[serde(rename = "PotWaterUptake")]
    pot_water_uptake: NitrogenandCarbonValue,

    #[serde(rename = "WaterUptakeTrigTemp")]
    water_uptake_trig_temp: NitrogenandCarbonValue,

    #[serde(rename = "Transpirationallpl")]
    transpirationallpl: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct GeneralInformation {
    #[serde(rename = "type")]
    general_information_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: GeneralInformationProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct GeneralInformationProperties {
    #[serde(rename = "SimNumber")]
    sim_number: SizeofArray,

    #[serde(rename = "FileVersionNumber")]
    file_version_number: SizeofArray,

    #[serde(rename = "ExeFileDate")]
    exe_file_date: DefaultIndex1_Value,

    #[serde(rename = "Date_Modification")]
    date_modification: SizeofArray,

    #[serde(rename = "OriginalFileName")]
    original_file_name: DefaultIndex1_Value,

    #[serde(rename = "MBinFile")]
    m_bin_file: DefaultIndex1_Value,

    #[serde(rename = "Finished")]
    finished: SizeofArray,

    #[serde(rename = "RundId")]
    rund_id: DefaultIndex1_Value,

    #[serde(rename = "Comments")]
    comments: DefaultIndex1_Value,

    #[serde(rename = "MultiSimulaton")]
    multi_simulaton: SizeofArray,

    #[serde(rename = "Date_Created")]
    date_created: SizeofArray,
}

#[derive(Serialize, Deserialize)]
pub struct HeatBox {
    #[serde(rename = "type")]
    heat_box_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: HeatBoxProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct HeatBoxProperties {
    #[serde(rename = "SizeofArray")]
    sizeof_array: SizeofArray,

    #[serde(rename = "OutMulti_Index_1")]
    out_multi_index_1: SizeofArray,

    #[serde(rename = "OutSingle_Index_2")]
    out_single_index_2: SizeofArray,

    #[serde(rename = "ArrayName")]
    array_name: DefaultIndex1_Value,

    #[serde(rename = "OutSingle_Index_3")]
    out_single_index_3: SizeofArray,

    #[serde(rename = "OutMulti_Index_3")]
    out_multi_index_3: SizeofArray,

    #[serde(rename = "OutMulti_Index_4")]
    out_multi_index_4: SizeofArray,

    #[serde(rename = "Condition_1")]
    condition_1: NitrogenandCarbonValue,

    #[serde(rename = "OutSingle_Index_1")]
    out_single_index_1: SizeofArray,

    #[serde(rename = "OutMulti_Index_2")]
    out_multi_index_2: SizeofArray,

    #[serde(rename = "Condition_2")]
    condition_2: DefaultIndex1_Value,

    #[serde(rename = "OutSingle_Index_4")]
    out_single_index_4: SizeofArray,
}

#[derive(Serialize, Deserialize)]
pub struct HeatPumpdata {
    #[serde(rename = "type")]
    heat_pumpdata_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: HeatPumpdataProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct HeatPumpdataProperties {
    #[serde(rename = "PF_File")]
    pf_file: DefaultIndex1_Value,

    #[serde(rename = "Condition_1")]
    condition_1: DefaultIndex1_Value,

    #[serde(rename = "Condition_2")]
    condition_2: DefaultIndex1_Value,

    #[serde(rename = "Condition_3")]
    condition_3: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct HilariousDrainageanddeeppercolation {
    #[serde(rename = "type")]
    hilarious_drainageanddeeppercolation_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: HilariousDrainageanddeeppercolationProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct HilariousDrainageanddeeppercolationProperties {
    #[serde(rename = "EmpGFlowPeak")]
    emp_g_flow_peak: NitrogenandCarbonValue,

    #[serde(rename = "HFlowInputIndex")]
    h_flow_input_index: NitrogenandCarbonValue,

    #[serde(rename = "EmpGFLowbase")]
    emp_gf_lowbase: NitrogenandCarbonValue,

    #[serde(rename = "EmpGFLevBase")]
    emp_gf_lev_base: NitrogenandCarbonValue,

    #[serde(rename = "EmpGFLevPeak")]
    emp_gf_lev_peak: NitrogenandCarbonValue,

    #[serde(rename = "HFlowOutputIndex")]
    h_flow_output_index: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct HilariousSaltTracer {
    #[serde(rename = "type")]
    hilarious_salt_tracer_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: HilariousSaltTracerProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct HilariousSaltTracerProperties {
    #[serde(rename = "InitSaltConc")]
    init_salt_conc: NitrogenandCarbonValue,

    #[serde(rename = "Ad_c")]
    ad_c: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct HilariousSoilheatflows {
    #[serde(rename = "type")]
    hilarious_soilheatflows_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: HilariousSoilheatflowsProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct HilariousSoilheatflowsProperties {
    #[serde(rename = "ProdCoef_A2")]
    prod_coef_a2: NitrogenandCarbonValue,

    #[serde(rename = "Heatstorage")]
    heatstorage: NitrogenandCarbonValue,

    #[serde(rename = "Temperature")]
    temperature: NitrogenandCarbonValue,

    #[serde(rename = "WaterPipeBoxLayer")]
    water_pipe_box_layer: NitrogenandCarbonValue,

    #[serde(rename = "ProdCoef_A")]
    prod_coef_a: NitrogenandCarbonValue,

    #[serde(rename = "PipeSegmentLength")]
    pipe_segment_length: SoilmineralNprocesses,
}

#[derive(Serialize, Deserialize)]
pub struct HilariousSoilmineralPProcesses {
    #[serde(rename = "type")]
    hilarious_soilmineral_p_processes_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: HilariousSoilmineralPProcessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct HilariousSoilmineralPProcessesProperties {
    #[serde(rename = "ILabilePhosphateConc")]
    i_labile_phosphate_conc: NitrogenandCarbonValue,

    #[serde(rename = "InitalPcontent")]
    inital_pcontent: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct HilariousSoilwaterflows {
    #[serde(rename = "type")]
    hilarious_soilwaterflows_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: HilariousSoilwaterflowsProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct HilariousSoilwaterflowsProperties {
    #[serde(rename = "HysMaxEffCond")]
    hys_max_eff_cond: NitrogenandCarbonValue,

    #[serde(rename = "HysMaxEffRet")]
    hys_max_eff_ret: NitrogenandCarbonValue,

    #[serde(rename = "IniPressureHeads")]
    ini_pressure_heads: NitrogenandCarbonValue,

    #[serde(rename = "IniWaterContents")]
    ini_water_contents: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct IndecentDrainageanddeeppercolation {
    #[serde(rename = "type")]
    indecent_drainageanddeeppercolation_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: IndecentDrainageanddeeppercolationProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct IndecentDrainageanddeeppercolationProperties {
    #[serde(rename = "WaterDrainflow")]
    water_drainflow: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct IndecentInterception {
    #[serde(rename = "type")]
    indecent_interception_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: IndecentInterceptionProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct IndecentInterceptionProperties {
    #[serde(rename = "MaximalCover")]
    maximal_cover: NitrogenandCarbonValue,

    #[serde(rename = "LAICoverSensitivity")]
    lai_cover_sensitivity: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct IndecentSoilheatflows {
    #[serde(rename = "type")]
    indecent_soilheatflows_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: IndecentSoilheatflowsProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct IndecentSoilheatflowsProperties {
    #[serde(rename = "SoilInitTempConst")]
    soil_init_temp_const: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct IndecentSoilmineralPProcesses {
    #[serde(rename = "type")]
    indecent_soilmineral_p_processes_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: IndecentSoilmineralPProcessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct IndecentSoilmineralPProcessesProperties {
    #[serde(rename = "SoilmineralP")]
    soilmineral_p: NitrogenandCarbonValue,

    #[serde(rename = "SoilPhosphate")]
    soil_phosphate: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct IndecentSoilwaterflows {
    #[serde(rename = "type")]
    indecent_soilwaterflows_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: IndecentSoilwaterflowsProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct IndecentSoilwaterflowsProperties {
    #[serde(rename = "InitialGroundWater")]
    initial_ground_water: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct IndecentWateruptake {
    #[serde(rename = "type")]
    indecent_wateruptake_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: IndecentWateruptakeProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct IndecentWateruptakeProperties {
    #[serde(rename = "CritThresholdDry")]
    crit_threshold_dry: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct IndigoDrainageanddeeppercolation {
    #[serde(rename = "type")]
    indigo_drainageanddeeppercolation_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: IndigoDrainageanddeeppercolationProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct IndigoDrainageanddeeppercolationProperties {
    #[serde(rename = "NetEmpDrainage")]
    net_emp_drainage: NitrogenandCarbonValue,

    #[serde(rename = "NetPhysDrainage")]
    net_phys_drainage: NitrogenandCarbonValue,

    #[serde(rename = "TotalDrainage")]
    total_drainage: NitrogenandCarbonValue,

    #[serde(rename = "vDriveDrainLevel")]
    v_drive_drain_level: NitrogenandCarbonValue,

    #[serde(rename = "TotalRunoff")]
    total_runoff: NitrogenandCarbonValue,

    #[serde(rename = "DeepPerc")]
    deep_perc: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct IndigoGasprocesses {
    #[serde(rename = "type")]
    indigo_gasprocesses_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: IndigoGasprocessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct IndigoGasprocessesProperties {
    #[serde(rename = "InitCO2Conc")]
    init_co2_conc: NitrogenandCarbonValue,

    #[serde(rename = "pHvalue")]
    p_hvalue: NitrogenandCarbonValue,

    #[serde(rename = "InitOxygenConc")]
    init_oxygen_conc: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct IndigoInterception {
    #[serde(rename = "type")]
    indigo_interception_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: IndigoInterceptionProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct IndigoInterceptionProperties {
    #[serde(rename = "CanopyIntercStorage")]
    canopy_interc_storage: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct IndigoSaltTracer {
    #[serde(rename = "type")]
    indigo_salt_tracer_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: IndigoSaltTracerProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct IndigoSaltTracerProperties {
    #[serde(rename = "SaltCloseToRoad")]
    salt_close_to_road: NitrogenandCarbonValue,

    #[serde(rename = "AccSaltInput")]
    acc_salt_input: NitrogenandCarbonValue,

    #[serde(rename = "SaltOnRoad")]
    salt_on_road: NitrogenandCarbonValue,

    #[serde(rename = "AccSaltOutput")]
    acc_salt_output: NitrogenandCarbonValue,

    #[serde(rename = "TE_Balance")]
    te_balance: NitrogenandCarbonValue,

    #[serde(rename = "TESurfaceLitter")]
    te_surface_litter: NitrogenandCarbonValue,

    #[serde(rename = "SaltinSnowPack")]
    saltin_snow_pack: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct IndigoSnowPack {
    #[serde(rename = "type")]
    indigo_snow_pack_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: IndigoSnowPackProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct IndigoSnowPackProperties {
    #[serde(rename = "DensityCoefWater")]
    density_coef_water: NitrogenandCarbonValue,

    #[serde(rename = "DensityCoefMass")]
    density_coef_mass: NitrogenandCarbonValue,

    #[serde(rename = "MeltCoefGlobRadAge1")]
    melt_coef_glob_rad_age1: NitrogenandCarbonValue,

    #[serde(rename = "MeltCoefGlobRad")]
    melt_coef_glob_rad: NitrogenandCarbonValue,

    #[serde(rename = "MeltCoefAirTemp")]
    melt_coef_air_temp: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct IndigoSoilheatflows {
    #[serde(rename = "type")]
    indigo_soilheatflows_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: IndigoSoilheatflowsProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct IndigoSoilheatflowsProperties {
    #[serde(rename = "OutPipeHeat")]
    out_pipe_heat: NitrogenandCarbonValue,

    #[serde(rename = "ColdPipeHeat")]
    cold_pipe_heat: NitrogenandCarbonValue,

    #[serde(rename = "HeatBoxStorage")]
    heat_box_storage: NitrogenandCarbonValue,

    #[serde(rename = "SoilHeat")]
    soil_heat: NitrogenandCarbonValue,

    #[serde(rename = "HeatBoxTemp")]
    heat_box_temp: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct IndigoSoilmineralPProcesses {
    #[serde(rename = "type")]
    indigo_soilmineral_p_processes_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: IndigoSoilmineralPProcessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct IndigoSoilmineralPProcessesProperties {
    #[serde(rename = "PMinBalanceCheck")]
    p_min_balance_check: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct IndigoSoilwaterflows {
    #[serde(rename = "type")]
    indigo_soilwaterflows_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: IndigoSoilwaterflowsProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct IndigoSoilwaterflowsProperties {
    #[serde(rename = "WaterStorage")]
    water_storage: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct IndigoSurfacewater {
    #[serde(rename = "type")]
    indigo_surfacewater_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: IndigoSurfacewaterProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct IndigoSurfacewaterProperties {
    #[serde(rename = "SurfCoef")]
    surf_coef: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct IndigoWateruptake {
    #[serde(rename = "type")]
    indigo_wateruptake_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: IndigoWateruptakeProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct IndigoWateruptakeProperties {
    #[serde(rename = "PlantWater")]
    plant_water: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct InfilDistF {
    #[serde(rename = "type")]
    infil_dist_f_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: InfilDistFProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct InfilDistFProperties {
    #[serde(rename = "Default_Index_1")]
    default_index_1: DefaultIndex1_Value,

    #[serde(rename = "MinValue_Index_3")]
    min_value_index_3: DefaultIndex1_Value,

    #[serde(rename = "MinValue_Index_8")]
    min_value_index_8: DefaultIndex1_Value,

    #[serde(rename = "MaxValue_Index_6")]
    max_value_index_6: DefaultIndex1_Value,

    #[serde(rename = "Index_6")]
    index_6: DefaultIndex1_Value,

    #[serde(rename = "MinValue_Index_5")]
    min_value_index_5: DefaultIndex1_Value,

    #[serde(rename = "Default_Index_7")]
    default_index_7: DefaultIndex1_Value,

    #[serde(rename = "MinValue_Index_2")]
    min_value_index_2: DefaultIndex1_Value,

    #[serde(rename = "SizeofArray")]
    sizeof_array: SizeofArray,

    #[serde(rename = "Index_1")]
    index_1: DefaultIndex1_Value,

    #[serde(rename = "MaxValue_Index_1")]
    max_value_index_1: DefaultIndex1_Value,

    #[serde(rename = "Default_Index_6")]
    default_index_6: DefaultIndex1_Value,

    #[serde(rename = "MinValue_Index_4")]
    min_value_index_4: DefaultIndex1_Value,

    #[serde(rename = "ArrayName")]
    array_name: NitrogenandCarbonValue,

    #[serde(rename = "MinValue_Index_1")]
    min_value_index_1: DefaultIndex1_Value,

    #[serde(rename = "Default_Index_3")]
    default_index_3: DefaultIndex1_Value,

    #[serde(rename = "MaxValue_Index_5")]
    max_value_index_5: DefaultIndex1_Value,

    #[serde(rename = "Index_5")]
    index_5: DefaultIndex1_Value,

    #[serde(rename = "Default_Index_2")]
    default_index_2: DefaultIndex1_Value,

    #[serde(rename = "MaxValue_Index_3")]
    max_value_index_3: DefaultIndex1_Value,

    #[serde(rename = "Index_3")]
    index_3: DefaultIndex1_Value,

    #[serde(rename = "MaxValue_Index_4")]
    max_value_index_4: DefaultIndex1_Value,

    #[serde(rename = "Default_Index_8")]
    default_index_8: DefaultIndex1_Value,

    #[serde(rename = "Index_4")]
    index_4: DefaultIndex1_Value,

    #[serde(rename = "Condition_1")]
    condition_1: DefaultIndex1_Value,

    #[serde(rename = "MinValue_Index_7")]
    min_value_index_7: DefaultIndex1_Value,

    #[serde(rename = "Default_Index_5")]
    default_index_5: DefaultIndex1_Value,

    #[serde(rename = "MaxValue_Index_2")]
    max_value_index_2: DefaultIndex1_Value,

    #[serde(rename = "Index_2")]
    index_2: DefaultIndex1_Value,

    #[serde(rename = "Condition_2")]
    condition_2: DefaultIndex1_Value,

    #[serde(rename = "MaxValue_Index_7")]
    max_value_index_7: DefaultIndex1_Value,

    #[serde(rename = "Index_7")]
    index_7: DefaultIndex1_Value,

    #[serde(rename = "Default_Index_4")]
    default_index_4: DefaultIndex1_Value,

    #[serde(rename = "Index_8")]
    index_8: DefaultIndex1_Value,

    #[serde(rename = "MinValue_Index_6")]
    min_value_index_6: DefaultIndex1_Value,

    #[serde(rename = "MaxValue_Index_8")]
    max_value_index_8: DefaultIndex1_Value,

    #[serde(rename = "Condition_3")]
    condition_3: DefaultIndex1_Value,

    #[serde(rename = "Condition_4")]
    condition_4: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct KonzelmannCoef {
    #[serde(rename = "type")]
    konzelmann_coef_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: KonzelmannCoefProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct KonzelmannCoefProperties {
    #[serde(rename = "Default_Index_1")]
    default_index_1: DefaultIndex1_Value,

    #[serde(rename = "MinValue_Index_3")]
    min_value_index_3: DefaultIndex1_Value,

    #[serde(rename = "MinValue_Index_2")]
    min_value_index_2: DefaultIndex1_Value,

    #[serde(rename = "SizeofArray")]
    sizeof_array: SizeofArray,

    #[serde(rename = "Index_1")]
    index_1: DefaultIndex1_Value,

    #[serde(rename = "MaxValue_Index_1")]
    max_value_index_1: DefaultIndex1_Value,

    #[serde(rename = "ArrayName")]
    array_name: DefaultIndex1_Value,

    #[serde(rename = "MinValue_Index_1")]
    min_value_index_1: DefaultIndex1_Value,

    #[serde(rename = "Default_Index_3")]
    default_index_3: DefaultIndex1_Value,

    #[serde(rename = "Default_Index_2")]
    default_index_2: DefaultIndex1_Value,

    #[serde(rename = "MaxValue_Index_3")]
    max_value_index_3: DefaultIndex1_Value,

    #[serde(rename = "Index_3")]
    index_3: DefaultIndex1_Value,

    #[serde(rename = "Condition_1")]
    condition_1: NitrogenandCarbonValue,

    #[serde(rename = "MaxValue_Index_2")]
    max_value_index_2: DefaultIndex1_Value,

    #[serde(rename = "Index_2")]
    index_2: DefaultIndex1_Value,

    #[serde(rename = "Condition_3")]
    condition_3: DefaultIndex1_Value,

    #[serde(rename = "Condition_2")]
    condition_2: DefaultIndex1_Value,

    #[serde(rename = "Condition_4")]
    condition_4: DefaultIndex1_Value,

    #[serde(rename = "MinValue_Index_4")]
    min_value_index_4: SizeofArray,

    #[serde(rename = "MaxValue_Index_4")]
    max_value_index_4: SizeofArray,

    #[serde(rename = "Index_4")]
    index_4: SizeofArray,

    #[serde(rename = "Default_Index_4")]
    default_index_4: SizeofArray,
}

#[derive(Serialize, Deserialize)]
pub struct LaiAbovecanopy {
    #[serde(rename = "type")]
    lai_abovecanopy_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: LaiAbovecanopyProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct LaiAbovecanopyProperties {
    #[serde(rename = "SizeofArray")]
    sizeof_array: SizeofArray,

    #[serde(rename = "OutMulti_Index_1")]
    out_multi_index_1: SizeofArray,

    #[serde(rename = "ArrayName")]
    array_name: NitrogenandCarbonValue,

    #[serde(rename = "Condition_1")]
    condition_1: NitrogenandCarbonValue,

    #[serde(rename = "OutSingle_Index_1")]
    out_single_index_1: SizeofArray,

    #[serde(rename = "Condition_2")]
    condition_2: DefaultIndex1_Value,

    #[serde(rename = "Condition_3")]
    condition_3: DefaultIndex1_Value,

    #[serde(rename = "Condition_4")]
    condition_4: DefaultIndex1_Value,
}

#[derive(Serialize, Deserialize)]
pub struct Meteorologicaldata {
    #[serde(rename = "type")]
    meteorologicaldata_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: MeteorologicaldataProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct MeteorologicaldataProperties {
    #[serde(rename = "PF_File")]
    pf_file: DefaultIndex1_Value,

    #[serde(rename = "Condition_1")]
    condition_1: DefaultIndex1_Value,
}

#[derive(Serialize, Deserialize)]
pub struct ModelSModelFacilities {
    #[serde(rename = "type")]
    model_s_model_facilities_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: ModelFilesModelFacilitiesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct ModelFilesModelFacilitiesProperties {
    #[serde(rename = "Technical")]
    technical: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct ModelFilesNitrogenandCarbon {
    #[serde(rename = "type")]
    model_files_nitrogenand_carbon_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: ModelFilesNitrogenandCarbonProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct ModelFilesNitrogenandCarbonProperties {
    #[serde(rename = "PlantGrowth")]
    plant_growth: NitrogenandCarbonValue,

    #[serde(rename = "ExternalNinputs")]
    external_ninputs: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct ModelFilesPlantWaterProcesses {
    #[serde(rename = "type")]
    model_files_plant_water_processes_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: ModelFilesPlantWaterProcessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct ModelFilesPlantWaterProcessesProperties {
    #[serde(rename = "Plant")]
    plant: NitrogenandCarbonValue,

    #[serde(rename = "SaltTracer")]
    salt_tracer: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct ModelFilesSoilWaterProcesses {
    #[serde(rename = "type")]
    model_files_soil_water_processes_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: ModelFilesSoilWaterProcessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct ModelFilesSoilWaterProcessesProperties {
    #[serde(rename = "Drainageanddeeppercolation")]
    drainageanddeeppercolation: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct ModelOptions {
    #[serde(rename = "type")]
    model_options_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: ModelOptionsProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct ModelOptionsProperties {
    #[serde(rename = "ModelFacilities")]
    model_facilities: Option<NitrogenandCarbonValue>,

    #[serde(rename = "ModelStructure")]
    model_structure: NitrogenandCarbonValue,

    #[serde(rename = "SoilWaterProcesses")]
    soil_water_processes: NitrogenandCarbonValue,

    #[serde(rename = "PlantWaterProcesses")]
    plant_water_processes: NitrogenandCarbonValue,

    #[serde(rename = "AtmosphericRelatedProcesses")]
    atmospheric_related_processes: NitrogenandCarbonValue,

    #[serde(rename = "SoilHeatProcesses")]
    soil_heat_processes: Option<NitrogenandCarbonValue>,
}

#[derive(Serialize, Deserialize)]
pub struct ModelOptionsAtmosphericRelatedProcesses {
    #[serde(rename = "type")]
    model_options_atmospheric_related_processes_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: ModelOptionsAtmosphericRelatedProcessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct ModelOptionsAtmosphericRelatedProcessesProperties {
    #[serde(rename = "Soilevaporation")]
    soilevaporation: NitrogenandCarbonValue,

    #[serde(rename = "Radiationproperties")]
    radiationproperties: NitrogenandCarbonValue,

    #[serde(rename = "MeteorologicalData")]
    meteorological_data: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct ModelOptionsPlantWaterProcesses {
    #[serde(rename = "type")]
    model_options_plant_water_processes_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: ModelOptionsPlantWaterProcessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct ModelOptionsPlantWaterProcessesProperties {
    #[serde(rename = "Wateruptake")]
    wateruptake: NitrogenandCarbonValue,

    #[serde(rename = "Interception")]
    interception: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct ModelOptionsSoilWaterProcesses {
    #[serde(rename = "type")]
    model_options_soil_water_processes_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: ModelOptionsSoilWaterProcessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct ModelOptionsSoilWaterProcessesProperties {
    #[serde(rename = "Drainageanddeeppercolation")]
    drainageanddeeppercolation: NitrogenandCarbonValue,

    #[serde(rename = "Surfacewater")]
    surfacewater: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct Node {
    #[serde(rename = "type")]
    node_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: NodeProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct NodeProperties {
    #[serde(rename = "Parameters_Arrays")]
    parameters_arrays: NitrogenandCarbonValue,

    #[serde(rename = "Model_Files")]
    model_files: NitrogenandCarbonValue,

    #[serde(rename = "Model_Options")]
    model_options: NitrogenandCarbonValue,

    #[serde(rename = "Run_Info")]
    run_info: NitrogenandCarbonValue,

    #[serde(rename = "Parameters")]
    parameters: NitrogenandCarbonValue,

    #[serde(rename = "Output_Variables")]
    output_variables: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct NumericalOptions {
    #[serde(rename = "type")]
    numerical_options_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: NumericalOptionsProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct NumericalOptionsProperties {
    #[serde(rename = "NumberIterations")]
    number_iterations: SizeofArray,
}

#[derive(Serialize, Deserialize)]
pub struct OutputFile {
    #[serde(rename = "type")]
    output_file_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: OutputFileProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct OutputFileProperties {
    #[serde(rename = "PF_File")]
    pf_file: DefaultIndex1_Value,
}

#[derive(Serialize, Deserialize)]
pub struct OutputVariables {
    #[serde(rename = "type")]
    output_variables_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: OutputVariablesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct OutputVariablesProperties {
    #[serde(rename = "State")]
    state: NitrogenandCarbonValue,

    #[serde(rename = "Auxiliary_Arrays")]
    auxiliary_arrays: NitrogenandCarbonValue,

    #[serde(rename = "State_Arrays")]
    state_arrays: NitrogenandCarbonValue,

    #[serde(rename = "Flow")]
    flow: NitrogenandCarbonValue,

    #[serde(rename = "Driving_Arrays")]
    driving_arrays: NitrogenandCarbonValue,

    #[serde(rename = "Flow_Arrays")]
    flow_arrays: NitrogenandCarbonValue,

    #[serde(rename = "Auxiliary")]
    auxiliary: NitrogenandCarbonValue,

    #[serde(rename = "Driving")]
    driving: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct ParametersArraysAtmosphericRelatedProcesses {
    #[serde(rename = "type")]
    parameters_arrays_atmospheric_related_processes_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: ParametersArraysAtmosphericRelatedProcessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct ParametersArraysAtmosphericRelatedProcessesProperties {
    #[serde(rename = "Radiationproperties")]
    radiationproperties: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct ParametersArraysModelFacilities {
    #[serde(rename = "type")]
    parameters_arrays_model_facilities_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: ParametersArraysModelFacilitiesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct ParametersArraysModelFacilitiesProperties {
    #[serde(rename = "Technical")]
    technical: NitrogenandCarbonValue,

    #[serde(rename = "Irrigation")]
    irrigation: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct ParametersArraysNitrogenandCarbon {
    #[serde(rename = "type")]
    parameters_arrays_nitrogenand_carbon_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: ParametersArraysNitrogenandCarbonProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct ParametersArraysNitrogenandCarbonProperties {
    #[serde(rename = "ExternalPInputs")]
    external_p_inputs: NitrogenandCarbonValue,

    #[serde(rename = "PlantGrowth")]
    plant_growth: NitrogenandCarbonValue,

    #[serde(rename = "ExternalNinputs")]
    external_ninputs: SoilmineralNprocesses,
}

#[derive(Serialize, Deserialize)]
pub struct ParametersArraysPlantWaterProcesses {
    #[serde(rename = "type")]
    parameters_arrays_plant_water_processes_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: ParametersArraysPlantWaterProcessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct ParametersArraysPlantWaterProcessesProperties {
    #[serde(rename = "PotentialTranspiration")]
    potential_transpiration: NitrogenandCarbonValue,

    #[serde(rename = "Plant")]
    plant: NitrogenandCarbonValue,

    #[serde(rename = "Wateruptake")]
    wateruptake: SoilmineralNprocesses,

    #[serde(rename = "SaltTracer")]
    salt_tracer: NitrogenandCarbonValue,

    #[serde(rename = "Interception")]
    interception: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct ParametersArraysSoilHeatProcesses {
    #[serde(rename = "type")]
    parameters_arrays_soil_heat_processes_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: ParametersArraysSoilHeatProcessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct ParametersArraysSoilHeatProcessesProperties {
    #[serde(rename = "SoilThermal")]
    soil_thermal: SoilmineralNprocesses,

    #[serde(rename = "Soilheatflows")]
    soilheatflows: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct ParametersArraysSoilWaterProcesses {
    #[serde(rename = "type")]
    parameters_arrays_soil_water_processes_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: ParametersArraysSoilWaterProcessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct ParametersArraysSoilWaterProcessesProperties {
    #[serde(rename = "SoilHydraulic")]
    soil_hydraulic: NitrogenandCarbonValue,

    #[serde(rename = "Soilwaterflows")]
    soilwaterflows: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct AtmosphericRelatedProcesses {
    #[serde(rename = "type")]
    atmospheric_related_processes_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: ParametersAtmosphericRelatedProcessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct ParametersAtmosphericRelatedProcessesProperties {
    #[serde(rename = "SnowPack")]
    snow_pack: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct ParametersPlantWaterProcesses {
    #[serde(rename = "type")]
    parameters_plant_water_processes_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: ParametersPlantWaterProcessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct ParametersPlantWaterProcessesProperties {
    #[serde(rename = "Wateruptake")]
    wateruptake: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct ParametersSoilHeatProcesses {
    #[serde(rename = "type")]
    parameters_soil_heat_processes_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: ParametersSoilHeatProcessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct ParametersSoilHeatProcessesProperties {
    #[serde(rename = "SoilThermal")]
    soil_thermal: NitrogenandCarbonValue,

    #[serde(rename = "Soilfrost")]
    soilfrost: NitrogenandCarbonValue,

    #[serde(rename = "Soilheatflows")]
    soilheatflows: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct PipeSegmentLength {
    #[serde(rename = "anyOf")]
    any_of: Vec<AnyOf>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct AnyOf {
    #[serde(rename = "$ref")]
    any_of_ref: Option<String>,

    #[serde(rename = "type")]
    any_of_type: Option<ArrayNameType>,

    #[serde(rename = "format")]
    format: Option<Format>,
}

#[derive(Serialize, Deserialize)]
pub struct PrecInput {
    #[serde(rename = "type")]
    prec_input_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: HashMap<String, DefaultIndex1_Value>,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleAbioticdrivingvariables {
    #[serde(rename = "type")]
    purple_abioticdrivingvariables_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: PurpleAbioticdrivingvariablesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleAbioticdrivingvariablesProperties {
    #[serde(rename = "GreenIndex")]
    green_index: NitrogenandCarbonValue,

    #[serde(rename = "Abioticsoildata")]
    abioticsoildata: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleDrainageanddeeppercolation {
    #[serde(rename = "type")]
    purple_drainageanddeeppercolation_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: PurpleDrainageanddeeppercolationProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleDrainageanddeeppercolationProperties {
    #[serde(rename = "PressuredheadatLowerboundary")]
    pressuredheadat_lowerboundary: NitrogenandCarbonValue,

    #[serde(rename = "Groundwaterlevel")]
    groundwaterlevel: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleExternalNinputs {
    #[serde(rename = "type")]
    purple_external_ninputs_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: PurpleExternalNinputsProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleExternalNinputsProperties {
    #[serde(rename = "NDepositionFile")]
    n_deposition_file: NitrogenandCarbonValue,

    #[serde(rename = "Manure")]
    manure: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleExternalPInputs {
    #[serde(rename = "type")]
    purple_external_p_inputs_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: PurpleExternalPInputsProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleExternalPInputsProperties {
    #[serde(rename = "PFertSolutionRate")]
    p_fert_solution_rate: NitrogenandCarbonValue,

    #[serde(rename = "PFertApplRate")]
    p_fert_appl_rate: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleGasprocesses {
    #[serde(rename = "type")]
    purple_gasprocesses_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: PurpleGasprocessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleGasprocessesProperties {
    #[serde(rename = "An_VolFraction")]
    an_vol_fraction: NitrogenandCarbonValue,

    #[serde(rename = "CH4waterconc")]
    ch4_waterconc: NitrogenandCarbonValue,

    #[serde(rename = "CH4airconcentration")]
    ch4_airconcentration: NitrogenandCarbonValue,

    #[serde(rename = "AirPorosity")]
    air_porosity: NitrogenandCarbonValue,

    #[serde(rename = "CO2Concentration")]
    co2_concentration: NitrogenandCarbonValue,

    #[serde(rename = "CO2diffusioncoefficient")]
    co2_diffusioncoefficient: NitrogenandCarbonValue,

    #[serde(rename = "OxygenConcentration")]
    oxygen_concentration: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleInterception {
    #[serde(rename = "type")]
    purple_interception_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: PurpleInterceptionProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleInterceptionProperties {
    #[serde(rename = "PrecInterception")]
    prec_interception: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleIrrigation {
    #[serde(rename = "type")]
    purple_irrigation_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: PurpleIrrigationProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleIrrigationProperties {
    #[serde(rename = "DripOutlet")]
    drip_outlet: NitrogenandCarbonValue,

    #[serde(rename = "DripFill")]
    drip_fill: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleMeteorologicalData {
    #[serde(rename = "type")]
    purple_meteorological_data_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: PurpleMeteorologicalDataProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleMeteorologicalDataProperties {
    #[serde(rename = "HeatPumpdata")]
    heat_pumpdata: NitrogenandCarbonValue,

    #[serde(rename = "Snowdepths")]
    snowdepths: NitrogenandCarbonValue,

    #[serde(rename = "Saltconcentration")]
    saltconcentration: NitrogenandCarbonValue,

    #[serde(rename = "Meteorologicaldata")]
    meteorologicaldata: NitrogenandCarbonValue,

    #[serde(rename = "LateralWaterInflow")]
    lateral_water_inflow: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleModelStructure {
    #[serde(rename = "type")]
    purple_model_structure_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: PurpleModelStructureProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleModelStructureProperties {
    #[serde(rename = "Evaporation")]
    evaporation: NitrogenandCarbonValue,

    #[serde(rename = "LateralInput")]
    lateral_input: NitrogenandCarbonValue,

    #[serde(rename = "SnowPack")]
    snow_pack: NitrogenandCarbonValue,

    #[serde(rename = "PlantType")]
    plant_type: NitrogenandCarbonValue,

    #[serde(rename = "GroundWaterFlow")]
    ground_water_flow: NitrogenandCarbonValue,

    #[serde(rename = "WaterEq")]
    water_eq: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct PurplePlant {
    #[serde(rename = "type")]
    purple_plant_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: PurplePlantProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct PurplePlantProperties {
    #[serde(rename = "Cropdata")]
    cropdata: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct PurplePlantGrowth {
    #[serde(rename = "type")]
    purple_plant_growth_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: PurplePlantGrowthProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct PurplePlantGrowthProperties {
    #[serde(rename = "Harvestdatedata")]
    harvestdatedata: NitrogenandCarbonValue,

    #[serde(rename = "PlantBiomassdata")]
    plant_biomassdata: NitrogenandCarbonValue,

    #[serde(rename = "GrazingPeriods")]
    grazing_periods: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct PurplePotentialTranspiration {
    #[serde(rename = "type")]
    purple_potential_transpiration_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: PurplePotentialTranspirationProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct PurplePotentialTranspirationProperties {
    #[serde(rename = "RoughLength")]
    rough_length: NitrogenandCarbonValue,

    #[serde(rename = "ResSurfVegetation")]
    res_surf_vegetation: NitrogenandCarbonValue,

    #[serde(rename = "ResistAirMean")]
    resist_air_mean: NitrogenandCarbonValue,

    #[serde(rename = "CanopyHeight")]
    canopy_height: NitrogenandCarbonValue,

    #[serde(rename = "DisplacementHeight")]
    displacement_height: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleRadiationproperties {
    #[serde(rename = "type")]
    purple_radiationproperties_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: PurpleRadiationpropertiesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleRadiationpropertiesProperties {
    #[serde(rename = "RadiationInput")]
    radiation_input: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleSaltTracer {
    #[serde(rename = "type")]
    purple_salt_tracer_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: PurpleSaltTracerProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleSaltTracerProperties {
    #[serde(rename = "SaltRoadDeposition")]
    salt_road_deposition: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleSnowPack {
    #[serde(rename = "type")]
    purple_snow_pack_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: PurpleSnowPackProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleSnowPackProperties {
    #[serde(rename = "SnowReduceLAIFactor")]
    snow_reduce_lai_factor: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleSoilevaporation {
    #[serde(rename = "type")]
    purple_soilevaporation_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: PurpleSoilevaporationProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleSoilevaporationProperties {
    #[serde(rename = "EvaporationMethod")]
    evaporation_method: NitrogenandCarbonValue,

    #[serde(rename = "SurfaceTemperature")]
    surface_temperature: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleSoilfrost {
    #[serde(rename = "type")]
    purple_soilfrost_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: PurpleSoilfrostProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleSoilfrostProperties {
    #[serde(rename = "FrostUpperBoundary2")]
    frost_upper_boundary2: NitrogenandCarbonValue,

    #[serde(rename = "FrostLowerBoundary2")]
    frost_lower_boundary2: NitrogenandCarbonValue,

    #[serde(rename = "FrostLowerBoundary1")]
    frost_lower_boundary1: NitrogenandCarbonValue,

    #[serde(rename = "Swelling")]
    swelling: NitrogenandCarbonValue,

    #[serde(rename = "FrostUpperBoundary1")]
    frost_upper_boundary1: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleSoilheatflows {
    #[serde(rename = "type")]
    purple_soilheatflows_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: PurpleSoilheatflowsProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleSoilheatflowsProperties {
    #[serde(rename = "TempSoilSurf")]
    temp_soil_surf: NitrogenandCarbonValue,

    #[serde(rename = "TempSewage")]
    temp_sewage: NitrogenandCarbonValue,

    #[serde(rename = "HeatBoxEnhancer")]
    heat_box_enhancer: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleSoilmineralPProcesses {
    #[serde(rename = "type")]
    purple_soilmineral_p_processes_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: PurpleSoilmineralPProcessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleSoilmineralPProcessesProperties {
    #[serde(rename = "PConcPO4Drainage")]
    p_conc_po4_drainage: NitrogenandCarbonValue,

    #[serde(rename = "PTotPO4Drainage")]
    p_tot_po4_drainage: NitrogenandCarbonValue,

    #[serde(rename = "TotMinPDrainageConc")]
    tot_min_p_drainage_conc: NitrogenandCarbonValue,

    #[serde(rename = "PTotPhosphateSoil")]
    p_tot_phosphate_soil: NitrogenandCarbonValue,

    #[serde(rename = "PTotPO4PlantUptake")]
    p_tot_po4_plant_uptake: NitrogenandCarbonValue,

    #[serde(rename = "PTotWeatheringSoil")]
    p_tot_weathering_soil: NitrogenandCarbonValue,

    #[serde(rename = "PTotSolidPminerals")]
    p_tot_solid_pminerals: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleSoilorganicprocesses {
    #[serde(rename = "type")]
    purple_soilorganicprocesses_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: PurpleSoilorganicprocessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleSoilorganicprocessesProperties {
    #[serde(rename = "NSurfaceLLitter1")]
    n_surface_l_litter1: NitrogenandCarbonValue,

    #[serde(rename = "CSurfaceLLitter2")]
    c_surface_l_litter2: NitrogenandCarbonValue,

    #[serde(rename = "PSurfaceLLitter2")]
    p_surface_l_litter2: NitrogenandCarbonValue,

    #[serde(rename = "NSurfaceLLitter2")]
    n_surface_l_litter2: NitrogenandCarbonValue,

    #[serde(rename = "PSurfaceLLitter1")]
    p_surface_l_litter1: NitrogenandCarbonValue,

    #[serde(rename = "CSurfaceLLitter1")]
    c_surface_l_litter1: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleSoilwaterflows {
    #[serde(rename = "type")]
    purple_soilwaterflows_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: PurpleSoilwaterflowsProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleSoilwaterflowsProperties {
    #[serde(rename = "TotMeanTransitTime")]
    tot_mean_transit_time: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleSurfacewater {
    #[serde(rename = "type")]
    purple_surfacewater_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: PurpleSurfacewaterProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleSurfacewaterProperties {
    #[serde(rename = "RunOnInput")]
    run_on_input: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleWateruptake {
    #[serde(rename = "type")]
    purple_wateruptake_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: PurpleWateruptakeProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct PurpleWateruptakeProperties {
    #[serde(rename = "DemandRedistribution")]
    demand_redistribution: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct RntLaIv {
    #[serde(rename = "type")]
    rnt_la_iv_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: RntLaIvProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct RntLaIvProperties {
    #[serde(rename = "Default_Index_1")]
    default_index_1: DefaultIndex1_Value,

    #[serde(rename = "SizeofArray")]
    sizeof_array: SizeofArray,

    #[serde(rename = "Index_1")]
    index_1: DefaultIndex1_Value,

    #[serde(rename = "MaxValue_Index_1")]
    max_value_index_1: DefaultIndex1_Value,

    #[serde(rename = "ArrayName")]
    array_name: NitrogenandCarbonValue,

    #[serde(rename = "MinValue_Index_1")]
    min_value_index_1: DefaultIndex1_Value,

    #[serde(rename = "Condition_1")]
    condition_1: NitrogenandCarbonValue,

    #[serde(rename = "Condition_2")]
    condition_2: DefaultIndex1_Value,

    #[serde(rename = "Condition_3")]
    condition_3: DefaultIndex1_Value,

    #[serde(rename = "Condition_4")]
    condition_4: DefaultIndex1_Value,

    #[serde(rename = "Condition_5")]
    condition_5: DefaultIndex1_Value,
}

#[derive(Serialize, Deserialize)]
pub struct RunInfo {
    #[serde(rename = "type")]
    run_info_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: RunInfoProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct RunInfoProperties {
    #[serde(rename = "General_Information")]
    general_information: NitrogenandCarbonValue,

    #[serde(rename = "Simulation_Period")]
    simulation_period: NitrogenandCarbonValue,

    #[serde(rename = "Additional_Details")]
    additional_details: NitrogenandCarbonValue,

    #[serde(rename = "Time_Resolution")]
    time_resolution: NitrogenandCarbonValue,

    #[serde(rename = "Numerical_Options")]
    numerical_options: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct SaltRoadDeposition {
    #[serde(rename = "type")]
    salt_road_deposition_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: SaltRoadDepositionProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct SaltRoadDepositionProperties {
    #[serde(rename = "Condition_3")]
    condition_3: NitrogenandCarbonValue,

    #[serde(rename = "Condition_4")]
    condition_4: DefaultIndex1_Value,

    #[serde(rename = "PF_File")]
    pf_file: DefaultIndex1_Value,

    #[serde(rename = "Condition_1")]
    condition_1: NitrogenandCarbonValue,

    #[serde(rename = "Condition_2")]
    condition_2: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct Schema {
    #[serde(rename = "type")]
    schema_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: SchemaProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct SchemaProperties {
    #[serde(rename = "node")]
    node: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct SimulationPeriod {
    #[serde(rename = "type")]
    simulation_period_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: SimulationPeriodProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct SimulationPeriodProperties {
    #[serde(rename = "SimEndDate")]
    sim_end_date: DefaultIndex1_Value,

    #[serde(rename = "PriorSimTime")]
    prior_sim_time: SizeofArray,

    #[serde(rename = "SimEndMin")]
    sim_end_min: SizeofArray,

    #[serde(rename = "SimStartScaling")]
    sim_start_scaling: SizeofArray,

    #[serde(rename = "SimStartMin")]
    sim_start_min: SizeofArray,

    #[serde(rename = "LengthPostPeriod")]
    length_post_period: SizeofArray,

    #[serde(rename = "SimStartDate")]
    sim_start_date: DefaultIndex1_Value,
}

#[derive(Serialize, Deserialize)]
pub struct SnowReduceLaiFactor {
    #[serde(rename = "type")]
    snow_reduce_lai_factor_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: SnowReduceLaiFactorProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct SnowReduceLaiFactorProperties {
    #[serde(rename = "Condition_3")]
    condition_3: DefaultIndex1_Value,

    #[serde(rename = "SizeofArray")]
    sizeof_array: SizeofArray,

    #[serde(rename = "OutMulti_Index_1")]
    out_multi_index_1: SizeofArray,

    #[serde(rename = "Condition_4")]
    condition_4: DefaultIndex1_Value,

    #[serde(rename = "ArrayName")]
    array_name: NitrogenandCarbonValue,

    #[serde(rename = "Condition_5")]
    condition_5: NitrogenandCarbonValue,

    #[serde(rename = "Condition_1")]
    condition_1: NitrogenandCarbonValue,

    #[serde(rename = "OutSingle_Index_1")]
    out_single_index_1: SizeofArray,

    #[serde(rename = "Condition_2")]
    condition_2: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct SoilHydraulic {
    #[serde(rename = "type")]
    soil_hydraulic_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: SoilHydraulicProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct SoilHydraulicProperties {
    #[serde(rename = "ResidualWater")]
    residual_water: AirEntry,

    #[serde(rename = "nPowerSatRel")]
    n_power_sat_rel: AirEntry,

    #[serde(rename = "UpperValid")]
    upper_valid: AirEntry,

    #[serde(rename = "Saturation")]
    saturation: AirEntry,

    #[serde(rename = "mWiltingPoint")]
    m_wilting_point: NitrogenandCarbonValue,

    #[serde(rename = "b_nPowerSatEffective")]
    b_n_power_sat_effective: NitrogenandCarbonValue,

    #[serde(rename = "mMacroPore")]
    m_macro_pore: NitrogenandCarbonValue,

    #[serde(rename = "m_n-value")]
    m_n_value: NitrogenandCarbonValue,

    #[serde(rename = "UpperBoundary")]
    upper_boundary: AirEntry,

    #[serde(rename = "WiltingPoint")]
    wilting_point: AirEntry,

    #[serde(rename = "ProfileNo")]
    profile_no: AirEntry,

    #[serde(rename = "nPowerSatEffective")]
    n_power_sat_effective: AirEntry,

    #[serde(rename = "LowerValid")]
    lower_valid: AirEntry,

    #[serde(rename = "TotalConductivity")]
    total_conductivity: AirEntry,

    #[serde(rename = "ProfileRepNo")]
    profile_rep_no: AirEntry,

    #[serde(rename = "bLambda")]
    b_lambda: NitrogenandCarbonValue,

    #[serde(rename = "bMacroPore")]
    b_macro_pore: NitrogenandCarbonValue,

    #[serde(rename = "m_nPowerSatEffective")]
    m_n_power_sat_effective: NitrogenandCarbonValue,

    #[serde(rename = "n-value")]
    n_value: AirEntry,

    #[serde(rename = "ProfileLayer")]
    profile_layer: AirEntry,

    #[serde(rename = "mUpperBoundaryTheta")]
    m_upper_boundary_theta: NitrogenandCarbonValue,

    #[serde(rename = "mAirEntry")]
    m_air_entry: NitrogenandCarbonValue,

    #[serde(rename = "b_nTortuosity")]
    b_n_tortuosity: NitrogenandCarbonValue,

    #[serde(rename = "bSaturation")]
    b_saturation: NitrogenandCarbonValue,

    #[serde(rename = "ClayContent")]
    clay_content: AirEntry,

    #[serde(rename = "nTortuosity")]
    n_tortuosity: AirEntry,

    #[serde(rename = "bResidualWater")]
    b_residual_water: NitrogenandCarbonValue,

    #[serde(rename = "mAlpha")]
    m_alpha: NitrogenandCarbonValue,

    #[serde(rename = "b_nPowerSatRel")]
    b_n_power_sat_rel: NitrogenandCarbonValue,

    #[serde(rename = "bScalingpF")]
    b_scalingp_f: NitrogenandCarbonValue,

    #[serde(rename = "mSaturation")]
    m_saturation: NitrogenandCarbonValue,

    #[serde(rename = "SandContent")]
    sand_content: AirEntry,

    #[serde(rename = "bAirEntry")]
    b_air_entry: NitrogenandCarbonValue,

    #[serde(rename = "m_nTortuosity")]
    m_n_tortuosity: NitrogenandCarbonValue,

    #[serde(rename = "MatrixConductivity")]
    matrix_conductivity: AirEntry,

    #[serde(rename = "Alpha")]
    alpha: AirEntry,

    #[serde(rename = "mUpperBoundary")]
    m_upper_boundary: NitrogenandCarbonValue,

    #[serde(rename = "bTotalConductivity")]
    b_total_conductivity: NitrogenandCarbonValue,

    #[serde(rename = "Lambda")]
    lambda: AirEntry,

    #[serde(rename = "mLambda")]
    m_lambda: NitrogenandCarbonValue,

    #[serde(rename = "MacroPore")]
    macro_pore: AirEntry,

    #[serde(rename = "b_n-value")]
    b_n_value: NitrogenandCarbonValue,

    #[serde(rename = "bUpperBoundary")]
    b_upper_boundary: NitrogenandCarbonValue,

    #[serde(rename = "bWiltingPoint")]
    b_wilting_point: NitrogenandCarbonValue,

    #[serde(rename = "ReglineN")]
    regline_n: AirEntry,

    #[serde(rename = "mTotalConductivity")]
    m_total_conductivity: NitrogenandCarbonValue,

    #[serde(rename = "m-value")]
    m_value: AirEntry,

    #[serde(rename = "ScalingpF")]
    scalingp_f: AirEntry,

    #[serde(rename = "AirEntry")]
    air_entry: AirEntry,

    #[serde(rename = "b_m-value")]
    b_m_value: NitrogenandCarbonValue,

    #[serde(rename = "UpperBoundaryTheta")]
    upper_boundary_theta: NitrogenandCarbonValue,

    #[serde(rename = "bMatrixConductivity")]
    b_matrix_conductivity: NitrogenandCarbonValue,

    #[serde(rename = "UpperThetaBoundary")]
    upper_theta_boundary: AirEntry,

    #[serde(rename = "bAlpha")]
    b_alpha: NitrogenandCarbonValue,

    #[serde(rename = "m_nPowerSatRel")]
    m_n_power_sat_rel: NitrogenandCarbonValue,

    #[serde(rename = "ReglineR2")]
    regline_r2: AirEntry,

    #[serde(rename = "M_ScalingpF")]
    m_scalingp_f: NitrogenandCarbonValue,

    #[serde(rename = "mMatrixConductivity")]
    m_matrix_conductivity: NitrogenandCarbonValue,

    #[serde(rename = "mResidualWater")]
    m_residual_water: NitrogenandCarbonValue,

    #[serde(rename = "m_m-value")]
    m_m_value: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct AirEntry {
    #[serde(rename = "type")]
    air_entry_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: DefaultIndex1_Value,
}

#[derive(Serialize, Deserialize)]
pub struct SoilThermal {
    #[serde(rename = "type")]
    soil_thermal_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: SoilThermalProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct SoilThermalProperties {
    #[serde(rename = "ClayFrozenC1")]
    clay_frozen_c1: NitrogenandCarbonValue,

    #[serde(rename = "SandFrozenC1")]
    sand_frozen_c1: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct Soilheatpump {
    #[serde(rename = "type")]
    soilheatpump_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: SoilheatpumpProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct SoilheatpumpProperties {
    #[serde(rename = "HeatPumpFlow")]
    heat_pump_flow: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct DefinitionsSoilmineralNprocesses {
    #[serde(rename = "type")]
    soilmineral_nprocesses_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: SoilmineralNprocessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct SoilmineralNprocessesProperties {
    #[serde(rename = "DenitDistZ")]
    denit_dist_z: NitrogenandCarbonValue,

    #[serde(rename = "NH4AdsFrac")]
    nh4_ads_frac: NitrogenandCarbonValue,

    #[serde(rename = "RelScaleResponse")]
    rel_scale_response: NitrogenandCarbonValue,

    #[serde(rename = "FlexDegree")]
    flex_degree: NitrogenandCarbonValue,

    #[serde(rename = "INitrateConc")]
    i_nitrate_conc: NitrogenandCarbonValue,

    #[serde(rename = "IAmmoniumConc")]
    i_ammonium_conc: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct StateArraysNitrogenandCarbon {
    #[serde(rename = "type")]
    state_arrays_nitrogenand_carbon_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: StateArraysNitrogenandCarbonProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct StateArraysNitrogenandCarbonProperties {
    #[serde(rename = "PlantGrowth")]
    plant_growth: SoilmineralNprocesses,
}

#[derive(Serialize, Deserialize)]
pub struct StateArraysSoilWaterProcesses {
    #[serde(rename = "type")]
    state_arrays_soil_water_processes_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: StateArraysSoilWaterProcessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct StateArraysSoilWaterProcessesProperties {
    #[serde(rename = "Soilwaterflows")]
    soilwaterflows: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct StateNitrogenandCarbon {
    #[serde(rename = "type")]
    state_nitrogenand_carbon_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: StateNitrogenandCarbonProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct StateNitrogenandCarbonProperties {
    #[serde(rename = "ExternalPInputs")]
    external_p_inputs: NitrogenandCarbonValue,

    #[serde(rename = "PlantGrowth")]
    plant_growth: NitrogenandCarbonValue,

    #[serde(rename = "ExternalNinputs")]
    external_ninputs: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct StateSoilWaterProcesses {
    #[serde(rename = "type")]
    state_soil_water_processes_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: StateSoilWaterProcessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct StateSoilWaterProcessesProperties {
    #[serde(rename = "Surfacewater")]
    surfacewater: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct StickyDrainageanddeeppercolation {
    #[serde(rename = "type")]
    sticky_drainageanddeeppercolation_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: StickyDrainageanddeeppercolationProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct StickyDrainageanddeeppercolationProperties {
    #[serde(rename = "CorrHeightFactor")]
    corr_height_factor: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct StickyExternalNinputs {
    #[serde(rename = "type")]
    sticky_external_ninputs_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: StickyExternalNinputsProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct StickyExternalNinputsProperties {
    #[serde(rename = "NFertilizer")]
    n_fertilizer: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct StickyGasprocesses {
    #[serde(rename = "type")]
    sticky_gasprocesses_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: StickyGasprocessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct StickyGasprocessesProperties {
    #[serde(rename = "NitrousOxide")]
    nitrous_oxide: NitrogenandCarbonValue,

    #[serde(rename = "Methanecontent")]
    methanecontent: NitrogenandCarbonValue,

    #[serde(rename = "Oxygen")]
    oxygen: NitrogenandCarbonValue,

    #[serde(rename = "NitricOxide")]
    nitric_oxide: NitrogenandCarbonValue,

    #[serde(rename = "CO2Soil")]
    co2_soil: NitrogenandCarbonValue,

    #[serde(rename = "Nitrogengas")]
    nitrogengas: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct StickyInterception {
    #[serde(rename = "type")]
    sticky_interception_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: StickyInterceptionProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct StickyInterceptionProperties {
    #[serde(rename = "CanopyIntercActEva")]
    canopy_interc_act_eva: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct StickyRadiationproperties {
    #[serde(rename = "type")]
    sticky_radiationproperties_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: StickyRadiationpropertiesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct StickyRadiationpropertiesProperties {
    #[serde(rename = "RntLAIv")]
    rnt_la_iv: NitrogenandCarbonValue,

    #[serde(rename = "KonzelmannCoef")]
    konzelmann_coef: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct StickySnowPack {
    #[serde(rename = "type")]
    sticky_snow_pack_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: StickySnowPackProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct StickySnowPackProperties {
    #[serde(rename = "IceInSnowPack")]
    ice_in_snow_pack: NitrogenandCarbonValue,

    #[serde(rename = "TotalSnowMass")]
    total_snow_mass: NitrogenandCarbonValue,

    #[serde(rename = "WaterInSnowPack")]
    water_in_snow_pack: NitrogenandCarbonValue,

    #[serde(rename = "SnowDepth")]
    snow_depth: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct StickySoilfrost {
    #[serde(rename = "type")]
    sticky_soilfrost_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: StickySoilfrostProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct StickySoilfrostProperties {
    #[serde(rename = "FreezepointFWi")]
    freezepoint_f_wi: NitrogenandCarbonValue,

    #[serde(rename = "AlphaHeatCoef")]
    alpha_heat_coef: NitrogenandCarbonValue,

    #[serde(rename = "HighFlowDampC")]
    high_flow_damp_c: NitrogenandCarbonValue,

    #[serde(rename = "FreezepointF0")]
    freezepoint_f0: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct StickySoilheatflows {
    #[serde(rename = "type")]
    sticky_soilheatflows_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: StickySoilheatflowsProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct StickySoilheatflowsProperties {
    #[serde(rename = "SewageHeatStore")]
    sewage_heat_store: NitrogenandCarbonValue,

    #[serde(rename = "SewageWaterStore")]
    sewage_water_store: NitrogenandCarbonValue,

    #[serde(rename = "TravelDistance")]
    travel_distance: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct StickySoilmineralPProcesses {
    #[serde(rename = "type")]
    sticky_soilmineral_p_processes_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: StickySoilmineralPProcessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct StickySoilmineralPProcessesProperties {
    #[serde(rename = "WeatheringRate")]
    weathering_rate: NitrogenandCarbonValue,

    #[serde(rename = "SoilPhosphateUptake")]
    soil_phosphate_uptake: NitrogenandCarbonValue,

    #[serde(rename = "SoilPhosphateFlow")]
    soil_phosphate_flow: NitrogenandCarbonValue,

    #[serde(rename = "SoilPhosphateDrainage")]
    soil_phosphate_drainage: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct StickySoilwaterflows {
    #[serde(rename = "type")]
    sticky_soilwaterflows_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: StickySoilwaterflowsProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct StickySoilwaterflowsProperties {
    #[serde(rename = "Vapourflow")]
    vapourflow: NitrogenandCarbonValue,

    #[serde(rename = "Waterflow")]
    waterflow: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct StickySurfacewater {
    #[serde(rename = "type")]
    sticky_surfacewater_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: StickySurfacewaterProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct StickySurfacewaterProperties {
    #[serde(rename = "SurfacePool")]
    surface_pool: NitrogenandCarbonValue,

    #[serde(rename = "PumpPool")]
    pump_pool: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct StickyWateruptake {
    #[serde(rename = "type")]
    sticky_wateruptake_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: StickyWateruptakeProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct StickyWateruptakeProperties {
    #[serde(rename = "WUptakeRate")]
    w_uptake_rate: NitrogenandCarbonValue,

    #[serde(rename = "PlantWaterUptake")]
    plant_water_uptake: NitrogenandCarbonValue,

    #[serde(rename = "Transpiration")]
    transpiration: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct TempColdPipe {
    #[serde(rename = "type")]
    temp_cold_pipe_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: TempColdPipeProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct TempColdPipeProperties {
    #[serde(rename = "OutSingle_Index_17")]
    out_single_index_17: SizeofArray,

    #[serde(rename = "OutMulti_Index_17")]
    out_multi_index_17: SizeofArray,

    #[serde(rename = "OutSingle_Index_5")]
    out_single_index_5: SizeofArray,

    #[serde(rename = "OutMulti_Index_6")]
    out_multi_index_6: SizeofArray,

    #[serde(rename = "OutSingle_Index_8")]
    out_single_index_8: SizeofArray,

    #[serde(rename = "OutSingle_Index_11")]
    out_single_index_11: SizeofArray,

    #[serde(rename = "SizeofArray")]
    sizeof_array: SizeofArray,

    #[serde(rename = "OutSingle_Index_16")]
    out_single_index_16: SizeofArray,

    #[serde(rename = "OutMulti_Index_1")]
    out_multi_index_1: SizeofArray,

    #[serde(rename = "OutSingle_Index_20")]
    out_single_index_20: SizeofArray,

    #[serde(rename = "OutMulti_Index_10")]
    out_multi_index_10: SizeofArray,

    #[serde(rename = "OutSingle_Index_2")]
    out_single_index_2: SizeofArray,

    #[serde(rename = "OutSingle_Index_10")]
    out_single_index_10: SizeofArray,

    #[serde(rename = "OutMulti_Index_20")]
    out_multi_index_20: SizeofArray,

    #[serde(rename = "OutSingle_Index_9")]
    out_single_index_9: SizeofArray,

    #[serde(rename = "ArrayName")]
    array_name: NitrogenandCarbonValue,

    #[serde(rename = "OutSingle_Index_15")]
    out_single_index_15: SizeofArray,

    #[serde(rename = "OutMulti_Index_11")]
    out_multi_index_11: SizeofArray,

    #[serde(rename = "OutSingle_Index_3")]
    out_single_index_3: SizeofArray,

    #[serde(rename = "OutMulti_Index_14")]
    out_multi_index_14: SizeofArray,

    #[serde(rename = "OutSingle_Index_6")]
    out_single_index_6: SizeofArray,

    #[serde(rename = "OutMulti_Index_5")]
    out_multi_index_5: SizeofArray,

    #[serde(rename = "OutSingle_Index_14")]
    out_single_index_14: SizeofArray,

    #[serde(rename = "OutSingle_Index_19")]
    out_single_index_19: SizeofArray,

    #[serde(rename = "OutMulti_Index_3")]
    out_multi_index_3: SizeofArray,

    #[serde(rename = "OutMulti_Index_12")]
    out_multi_index_12: SizeofArray,

    #[serde(rename = "OutSingle_Index_7")]
    out_single_index_7: SizeofArray,

    #[serde(rename = "OutMulti_Index_4")]
    out_multi_index_4: SizeofArray,

    #[serde(rename = "Condition_1")]
    condition_1: NitrogenandCarbonValue,

    #[serde(rename = "OutMulti_Index_15")]
    out_multi_index_15: SizeofArray,

    #[serde(rename = "OutSingle_Index_13")]
    out_single_index_13: SizeofArray,

    #[serde(rename = "OutMulti_Index_9")]
    out_multi_index_9: SizeofArray,

    #[serde(rename = "OutMulti_Index_18")]
    out_multi_index_18: SizeofArray,

    #[serde(rename = "OutMulti_Index_13")]
    out_multi_index_13: SizeofArray,

    #[serde(rename = "OutSingle_Index_1")]
    out_single_index_1: SizeofArray,

    #[serde(rename = "OutSingle_Index_18")]
    out_single_index_18: SizeofArray,

    #[serde(rename = "OutMulti_Index_2")]
    out_multi_index_2: SizeofArray,

    #[serde(rename = "Condition_2")]
    condition_2: NitrogenandCarbonValue,

    #[serde(rename = "OutMulti_Index_16")]
    out_multi_index_16: SizeofArray,

    #[serde(rename = "OutSingle_Index_4")]
    out_single_index_4: SizeofArray,

    #[serde(rename = "OutMulti_Index_7")]
    out_multi_index_7: SizeofArray,

    #[serde(rename = "OutSingle_Index_12")]
    out_single_index_12: SizeofArray,

    #[serde(rename = "OutMulti_Index_8")]
    out_multi_index_8: SizeofArray,

    #[serde(rename = "OutMulti_Index_19")]
    out_multi_index_19: SizeofArray,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledAbioticdrivingvariables {
    #[serde(rename = "type")]
    tentacled_abioticdrivingvariables_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: TentacledAbioticdrivingvariablesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledAbioticdrivingvariablesProperties {
    #[serde(rename = "NDrivDrainage")]
    n_driv_drainage: NitrogenandCarbonValue,

    #[serde(rename = "NDrivSaltStress")]
    n_driv_salt_stress: NitrogenandCarbonValue,

    #[serde(rename = "NDrivTheta")]
    n_driv_theta: NitrogenandCarbonValue,

    #[serde(rename = "NDrivWaterStress")]
    n_driv_water_stress: NitrogenandCarbonValue,

    #[serde(rename = "NDrivWaterFlow")]
    n_driv_water_flow: NitrogenandCarbonValue,

    #[serde(rename = "NDrivTemperature")]
    n_driv_temperature: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledDrainageanddeeppercolation {
    #[serde(rename = "type")]
    tentacled_drainageanddeeppercolation_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: TentacledDrainageanddeeppercolationProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledDrainageanddeeppercolationProperties {
    #[serde(rename = "SaturationLevel")]
    saturation_level: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledExternalNinputs {
    #[serde(rename = "type")]
    tentacled_external_ninputs_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: TentacledExternalNinputsProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledExternalNinputsProperties {
    #[serde(rename = "DepositionNLeaf")]
    deposition_n_leaf: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledExternalPInputs {
    #[serde(rename = "type")]
    tentacled_external_p_inputs_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: TentacledExternalPInputsProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledExternalPInputsProperties {
    #[serde(rename = "PFertRate")]
    p_fert_rate: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledGasprocesses {
    #[serde(rename = "type")]
    tentacled_gasprocesses_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: TentacledGasprocessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledGasprocessesProperties {
    #[serde(rename = "AccCH4Emission")]
    acc_ch4_emission: NitrogenandCarbonValue,

    #[serde(rename = "AccCH4PlantEmission")]
    acc_ch4_plant_emission: NitrogenandCarbonValue,

    #[serde(rename = "DiffCH4Storage")]
    diff_ch4_storage: NitrogenandCarbonValue,

    #[serde(rename = "AccCH4Oxidation")]
    acc_ch4_oxidation: NitrogenandCarbonValue,

    #[serde(rename = "AccCH4Production")]
    acc_ch4_production: NitrogenandCarbonValue,

    #[serde(rename = "CH4MassbalanceCheck")]
    ch4_massbalance_check: NitrogenandCarbonValue,

    #[serde(rename = "AccCH4BubbleEmission")]
    acc_ch4_bubble_emission: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledInterception {
    #[serde(rename = "type")]
    tentacled_interception_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: TentacledInterceptionProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledInterceptionProperties {
    #[serde(rename = "CanopyIntercPotEva")]
    canopy_interc_pot_eva: NitrogenandCarbonValue,

    #[serde(rename = "CanopyIntercCapac")]
    canopy_interc_capac: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledIrrigation {
    #[serde(rename = "type")]
    tentacled_irrigation_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: TentacledIrrigationProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledIrrigationProperties {
    #[serde(rename = "InfilDistF")]
    infil_dist_f: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledMeteorologicalData {
    #[serde(rename = "type")]
    tentacled_meteorological_data_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: TentacledMeteorologicalDataProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledMeteorologicalDataProperties {
    #[serde(rename = "Wsource")]
    wsource: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledModelStructure {
    #[serde(rename = "type")]
    tentacled_model_structure_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: TentacledModelStructureProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledModelStructureProperties {
    #[serde(rename = "Xloop")]
    xloop: NitrogenandCarbonValue,

    #[serde(rename = "XNLev")]
    xn_lev: NitrogenandCarbonValue,

    #[serde(rename = "XADiv")]
    xa_div: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledPlantGrowth {
    #[serde(rename = "type")]
    tentacled_plant_growth_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: TentacledPlantGrowthProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledPlantGrowthProperties {
    #[serde(rename = "CWoodEater")]
    c_wood_eater: NitrogenandCarbonValue,

    #[serde(rename = "NGrazingOrganism")]
    n_grazing_organism: NitrogenandCarbonValue,

    #[serde(rename = "CGrazingOrganism")]
    c_grazing_organism: NitrogenandCarbonValue,

    #[serde(rename = "NWoodEater")]
    n_wood_eater: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledRadiationproperties {
    #[serde(rename = "type")]
    tentacled_radiationproperties_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: TentacledRadiationpropertiesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledRadiationpropertiesProperties {
    #[serde(rename = "MCTempCanopy")]
    mc_temp_canopy: NitrogenandCarbonValue,

    #[serde(rename = "LAIAbovecanopy")]
    lai_abovecanopy: NitrogenandCarbonValue,

    #[serde(rename = "NetradiationCanopy")]
    netradiation_canopy: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledSaltTracer {
    #[serde(rename = "type")]
    tentacled_salt_tracer_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: TentacledSaltTracerProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledSaltTracerProperties {
    #[serde(rename = "SaltRunOffDeposition")]
    salt_run_off_deposition: NitrogenandCarbonValue,

    #[serde(rename = "SaltInfilConc")]
    salt_infil_conc: NitrogenandCarbonValue,

    #[serde(rename = "SaltAirDeposition")]
    salt_air_deposition: NitrogenandCarbonValue,

    #[serde(rename = "SaltPloughDeposition")]
    salt_plough_deposition: NitrogenandCarbonValue,

    #[serde(rename = "SaltIrrigationConc")]
    salt_irrigation_conc: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledSnowPack {
    #[serde(rename = "type")]
    tentacled_snow_pack_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: TentacledSnowPackProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledSnowPackProperties {
    #[serde(rename = "Snowmassimport")]
    snowmassimport: NitrogenandCarbonValue,

    #[serde(rename = "SnowEvaporation")]
    snow_evaporation: NitrogenandCarbonValue,

    #[serde(rename = "SnowInflow")]
    snow_inflow: NitrogenandCarbonValue,

    #[serde(rename = "SnowWaterOutflow")]
    snow_water_outflow: NitrogenandCarbonValue,

    #[serde(rename = "Snowmassexport")]
    snowmassexport: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledSoilfrost {
    #[serde(rename = "type")]
    tentacled_soilfrost_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: TentacledSoilfrostProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledSoilfrostProperties {
    #[serde(rename = "WaterHFD")]
    water_hfd: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledSoilmineralPProcesses {
    #[serde(rename = "type")]
    tentacled_soilmineral_p_processes_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: TentacledSoilmineralPProcessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledSoilmineralPProcessesProperties {
    #[serde(rename = "PSurfaceRunoff")]
    p_surface_runoff: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledSoilorganicprocesses {
    #[serde(rename = "type")]
    tentacled_soilorganicprocesses_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: TentacledSoilorganicprocessesProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledSoilorganicprocessesProperties {
    #[serde(rename = "InitFracLitter2")]
    init_frac_litter2: AirEntry,

    #[serde(rename = "InitL1C")]
    init_l1_c: NitrogenandCarbonValue,

    #[serde(rename = "InitMCP")]
    init_mcp: NitrogenandCarbonValue,

    #[serde(rename = "InitHN")]
    init_hn: NitrogenandCarbonValue,

    #[serde(rename = "InitFP")]
    init_fp: NitrogenandCarbonValue,

    #[serde(rename = "InitL1CP")]
    init_l1_cp: NitrogenandCarbonValue,

    #[serde(rename = "InitMC")]
    init_mc: NitrogenandCarbonValue,

    #[serde(rename = "InitCCont")]
    init_c_cont: AirEntry,

    #[serde(rename = "InitL2C")]
    init_l2_c: NitrogenandCarbonValue,

    #[serde(rename = "InitFCP")]
    init_fcp: NitrogenandCarbonValue,

    #[serde(rename = "InitHCN")]
    init_hcn: NitrogenandCarbonValue,

    #[serde(rename = "InitL2N")]
    init_l2_n: NitrogenandCarbonValue,

    #[serde(rename = "InitNCont")]
    init_n_cont: AirEntry,

    #[serde(rename = "InitMN")]
    init_mn: NitrogenandCarbonValue,

    #[serde(rename = "InitCNHumus")]
    init_cn_humus: AirEntry,

    #[serde(rename = "InitL2CN")]
    init_l2_cn: NitrogenandCarbonValue,

    #[serde(rename = "InitL1N")]
    init_l1_n: NitrogenandCarbonValue,

    #[serde(rename = "InitHC")]
    init_hc: NitrogenandCarbonValue,

    #[serde(rename = "RateCoefDissolved")]
    rate_coef_dissolved: NitrogenandCarbonValue,

    #[serde(rename = "InitL2P")]
    init_l2_p: NitrogenandCarbonValue,

    #[serde(rename = "InitL1P")]
    init_l1_p: NitrogenandCarbonValue,

    #[serde(rename = "InitL2CP")]
    init_l2_cp: NitrogenandCarbonValue,

    #[serde(rename = "InitMP")]
    init_mp: NitrogenandCarbonValue,

    #[serde(rename = "InitFC")]
    init_fc: NitrogenandCarbonValue,

    #[serde(rename = "InitMCN")]
    init_mcn: NitrogenandCarbonValue,

    #[serde(rename = "InitHP")]
    init_hp: NitrogenandCarbonValue,

    #[serde(rename = "InitBulkDensity")]
    init_bulk_density: AirEntry,

    #[serde(rename = "InitFN")]
    init_fn: NitrogenandCarbonValue,

    #[serde(rename = "InitL1CN")]
    init_l1_cn: NitrogenandCarbonValue,

    #[serde(rename = "InitCNLitter")]
    init_cn_litter: AirEntry,

    #[serde(rename = "InitHCP")]
    init_hcp: NitrogenandCarbonValue,

    #[serde(rename = "InitFCN")]
    init_fcn: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledSoilwaterflows {
    #[serde(rename = "type")]
    tentacled_soilwaterflows_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: TentacledSoilwaterflowsProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledSoilwaterflowsProperties {
    #[serde(rename = "VapourflowSurf")]
    vapourflow_surf: NitrogenandCarbonValue,

    #[serde(rename = "SurfaceOutFlow")]
    surface_out_flow: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledSurfacewater {
    #[serde(rename = "type")]
    tentacled_surfacewater_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: TentacledSurfacewaterProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledSurfacewaterProperties {
    #[serde(rename = "SpoolDelayRunoff")]
    spool_delay_runoff: NitrogenandCarbonValue,

    #[serde(rename = "PumpOutFlow")]
    pump_out_flow: NitrogenandCarbonValue,

    #[serde(rename = "FurrowInfil")]
    furrow_infil: NitrogenandCarbonValue,

    #[serde(rename = "SoilInfil")]
    soil_infil: NitrogenandCarbonValue,

    #[serde(rename = "SpoolRunoff")]
    spool_runoff: NitrogenandCarbonValue,

    #[serde(rename = "FurrowPrec")]
    furrow_prec: NitrogenandCarbonValue,

    #[serde(rename = "SpoolSoilInfil")]
    spool_soil_infil: NitrogenandCarbonValue,

    #[serde(rename = "Spoolinflow")]
    spoolinflow: NitrogenandCarbonValue,

    #[serde(rename = "PumpInFlow")]
    pump_in_flow: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledTechnical {
    #[serde(rename = "type")]
    tentacled_technical_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: TentacledTechnicalProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledTechnicalProperties {
    #[serde(rename = "AbsError")]
    abs_error: NitrogenandCarbonValue,

    #[serde(rename = "RelError")]
    rel_error: NitrogenandCarbonValue,

    #[serde(rename = "ScalingIndex")]
    scaling_index: NitrogenandCarbonValue,

    #[serde(rename = "BoxCoxpower")]
    box_coxpower: NitrogenandCarbonValue,

    #[serde(rename = "KeyIndex")]
    key_index: NitrogenandCarbonValue,

    #[serde(rename = "BoxCoxoffset")]
    box_coxoffset: NitrogenandCarbonValue,

    #[serde(rename = "ScalingObserved")]
    scaling_observed: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledWateruptake {
    #[serde(rename = "type")]
    tentacled_wateruptake_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: TentacledWateruptakeProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct TentacledWateruptakeProperties {
    #[serde(rename = "PlantPotWaterUptake")]
    plant_pot_water_uptake: NitrogenandCarbonValue,

    #[serde(rename = "ResistPlant")]
    resist_plant: NitrogenandCarbonValue,

    #[serde(rename = "RedCMoisture")]
    red_c_moisture: NitrogenandCarbonValue,

    #[serde(rename = "RedCTemperature")]
    red_c_temperature: NitrogenandCarbonValue,

    #[serde(rename = "PlantWaterPotential")]
    plant_water_potential: NitrogenandCarbonValue,

    #[serde(rename = "RedCTotal")]
    red_c_total: NitrogenandCarbonValue,

    #[serde(rename = "ResistSoil_Plant")]
    resist_soil_plant: NitrogenandCarbonValue,
}

#[derive(Serialize, Deserialize)]
pub struct TimeResolution {
    #[serde(rename = "type")]
    time_resolution_type: AbsErrorType,

    #[serde(rename = "additionalProperties")]
    additional_properties: bool,

    #[serde(rename = "properties")]
    properties: TimeResolutionProperties,

    #[serde(rename = "required")]
    required: Vec<String>,

    #[serde(rename = "title")]
    title: String,
}

#[derive(Serialize, Deserialize)]
pub struct TimeResolutionProperties {
    #[serde(rename = "OutputInterval_Minutes")]
    output_interval_minutes: SizeofArray,

    #[serde(rename = "TimeResoluton")]
    time_resoluton: SizeofArray,

    #[serde(rename = "OutputInterval_Days")]
    output_interval_days: SizeofArray,
}

#[derive(Serialize, Deserialize)]
pub enum AbsErrorType {
    #[serde(rename = "object")]
    Object,
}

#[derive(Serialize, Deserialize)]
pub enum ArrayNameType {
    #[serde(rename = "string")]
    String,
}

#[derive(Serialize, Deserialize)]
pub enum Format {
    #[serde(rename = "boolean")]
    Boolean,

    #[serde(rename = "integer")]
    Integer,
}
