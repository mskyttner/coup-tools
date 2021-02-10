//  To parse this JSON data, first install
//
//      Boost     http://www.boost.org
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     Coup data = nlohmann::json::parse(jsonString);

#pragma once

#include "json.hpp"

#include <boost/optional.hpp>
#include <stdexcept>
#include <regex>
#include <unordered_map>

#ifndef NLOHMANN_OPT_HELPER
#define NLOHMANN_OPT_HELPER
namespace nlohmann {
    template <typename T>
    struct adl_serializer<std::shared_ptr<T>> {
        static void to_json(json & j, const std::shared_ptr<T> & opt) {
            if (!opt) j = nullptr; else j = *opt;
        }

        static std::shared_ptr<T> from_json(const json & j) {
            if (j.is_null()) return std::unique_ptr<T>(); else return std::unique_ptr<T>(new T(j.get<T>()));
        }
    };
}
#endif

namespace coup {
    using nlohmann::json;

    inline json get_untyped(const json & j, const char * property) {
        if (j.find(property) != j.end()) {
            return j.at(property).get<json>();
        }
        return json();
    }

    inline json get_untyped(const json & j, std::string property) {
        return get_untyped(j, property.data());
    }

    template <typename T>
    inline std::shared_ptr<T> get_optional(const json & j, const char * property) {
        if (j.find(property) != j.end()) {
            return j.at(property).get<std::shared_ptr<T>>();
        }
        return std::shared_ptr<T>();
    }

    template <typename T>
    inline std::shared_ptr<T> get_optional(const json & j, std::string property) {
        return get_optional<T>(j, property.data());
    }

    enum class Condition3Enum : int { EVAPORATION_0_IS_TRUE, HEAT_EQ_0_IS_TRUE, HEAT_PUMP_1_IS_FALSE, NITROGEN_AND_CARBON_0_IS_FALSE, NITROGEN_AND_CARBON_1_IS_FALSE, ONLY_NC_1_IS_TRUE, PHOSPHORUS_0_IS_FALSE, PLANT_TYPE_0_IS_TRUE, PLANT_TYPE_2_IS_TRUE, RADIATION_INPUT_0_IS_TRUE, SALT_TRACER_0_IS_FALSE, SNOW_PACK_0_IS_TRUE, SOIL_DRAINAGE_INPUT_0_IS_FALSE, TERMINATING_HARVEST_0_IS_FALSE, WATER_EQ_0_IS_TRUE, WATER_EQ_1_IS_TRUE };

    class HeatPumpdata {
        public:
        HeatPumpdata() = default;
        virtual ~HeatPumpdata() = default;

        private:
        std::string condition_1;
        std::string condition_2;
        std::shared_ptr<Condition3Enum> condition_3;
        std::string pf_file;

        public:
        const std::string & get_condition_1() const { return condition_1; }
        std::string & get_mutable_condition_1() { return condition_1; }
        void set_condition_1(const std::string & value) { this->condition_1 = value; }

        const std::string & get_condition_2() const { return condition_2; }
        std::string & get_mutable_condition_2() { return condition_2; }
        void set_condition_2(const std::string & value) { this->condition_2 = value; }

        std::shared_ptr<Condition3Enum> get_condition_3() const { return condition_3; }
        void set_condition_3(std::shared_ptr<Condition3Enum> value) { this->condition_3 = value; }

        const std::string & get_pf_file() const { return pf_file; }
        std::string & get_mutable_pf_file() { return pf_file; }
        void set_pf_file(const std::string & value) { this->pf_file = value; }
    };

    class Meteorologicaldata {
        public:
        Meteorologicaldata() = default;
        virtual ~Meteorologicaldata() = default;

        private:
        std::string condition_1;
        std::string pf_file;

        public:
        const std::string & get_condition_1() const { return condition_1; }
        std::string & get_mutable_condition_1() { return condition_1; }
        void set_condition_1(const std::string & value) { this->condition_1 = value; }

        const std::string & get_pf_file() const { return pf_file; }
        std::string & get_mutable_pf_file() { return pf_file; }
        void set_pf_file(const std::string & value) { this->pf_file = value; }
    };

    class PurpleMeteorologicalData {
        public:
        PurpleMeteorologicalData() = default;
        virtual ~PurpleMeteorologicalData() = default;

        private:
        HeatPumpdata heat_pumpdata;
        HeatPumpdata lateral_water_inflow;
        Meteorologicaldata meteorologicaldata;
        HeatPumpdata saltconcentration;
        HeatPumpdata snowdepths;

        public:
        const HeatPumpdata & get_heat_pumpdata() const { return heat_pumpdata; }
        HeatPumpdata & get_mutable_heat_pumpdata() { return heat_pumpdata; }
        void set_heat_pumpdata(const HeatPumpdata & value) { this->heat_pumpdata = value; }

        const HeatPumpdata & get_lateral_water_inflow() const { return lateral_water_inflow; }
        HeatPumpdata & get_mutable_lateral_water_inflow() { return lateral_water_inflow; }
        void set_lateral_water_inflow(const HeatPumpdata & value) { this->lateral_water_inflow = value; }

        const Meteorologicaldata & get_meteorologicaldata() const { return meteorologicaldata; }
        Meteorologicaldata & get_mutable_meteorologicaldata() { return meteorologicaldata; }
        void set_meteorologicaldata(const Meteorologicaldata & value) { this->meteorologicaldata = value; }

        const HeatPumpdata & get_saltconcentration() const { return saltconcentration; }
        HeatPumpdata & get_mutable_saltconcentration() { return saltconcentration; }
        void set_saltconcentration(const HeatPumpdata & value) { this->saltconcentration = value; }

        const HeatPumpdata & get_snowdepths() const { return snowdepths; }
        HeatPumpdata & get_mutable_snowdepths() { return snowdepths; }
        void set_snowdepths(const HeatPumpdata & value) { this->snowdepths = value; }
    };

    class ModelFilesAtmosphericRelatedProcesses {
        public:
        ModelFilesAtmosphericRelatedProcesses() = default;
        virtual ~ModelFilesAtmosphericRelatedProcesses() = default;

        private:
        PurpleMeteorologicalData meteorological_data;

        public:
        const PurpleMeteorologicalData & get_meteorological_data() const { return meteorological_data; }
        PurpleMeteorologicalData & get_mutable_meteorological_data() { return meteorological_data; }
        void set_meteorological_data(const PurpleMeteorologicalData & value) { this->meteorological_data = value; }
    };

    class OutputFile {
        public:
        OutputFile() = default;
        virtual ~OutputFile() = default;

        private:
        std::string pf_file;

        public:
        const std::string & get_pf_file() const { return pf_file; }
        std::string & get_mutable_pf_file() { return pf_file; }
        void set_pf_file(const std::string & value) { this->pf_file = value; }
    };

    class PurpleTechnical {
        public:
        PurpleTechnical() = default;
        virtual ~PurpleTechnical() = default;

        private:
        OutputFile output_file;
        Meteorologicaldata validation_file1;
        Meteorologicaldata validation_file10;
        Meteorologicaldata validation_file11;
        Meteorologicaldata validation_file12;
        Meteorologicaldata validation_file13;
        Meteorologicaldata validation_file14;
        Meteorologicaldata validation_file15;
        Meteorologicaldata validation_file16;
        Meteorologicaldata validation_file2;
        Meteorologicaldata validation_file3;
        Meteorologicaldata validation_file4;
        Meteorologicaldata validation_file5;
        Meteorologicaldata validation_file6;
        Meteorologicaldata validation_file7;
        Meteorologicaldata validation_file8;
        Meteorologicaldata validation_file9;

        public:
        const OutputFile & get_output_file() const { return output_file; }
        OutputFile & get_mutable_output_file() { return output_file; }
        void set_output_file(const OutputFile & value) { this->output_file = value; }

        const Meteorologicaldata & get_validation_file1() const { return validation_file1; }
        Meteorologicaldata & get_mutable_validation_file1() { return validation_file1; }
        void set_validation_file1(const Meteorologicaldata & value) { this->validation_file1 = value; }

        const Meteorologicaldata & get_validation_file10() const { return validation_file10; }
        Meteorologicaldata & get_mutable_validation_file10() { return validation_file10; }
        void set_validation_file10(const Meteorologicaldata & value) { this->validation_file10 = value; }

        const Meteorologicaldata & get_validation_file11() const { return validation_file11; }
        Meteorologicaldata & get_mutable_validation_file11() { return validation_file11; }
        void set_validation_file11(const Meteorologicaldata & value) { this->validation_file11 = value; }

        const Meteorologicaldata & get_validation_file12() const { return validation_file12; }
        Meteorologicaldata & get_mutable_validation_file12() { return validation_file12; }
        void set_validation_file12(const Meteorologicaldata & value) { this->validation_file12 = value; }

        const Meteorologicaldata & get_validation_file13() const { return validation_file13; }
        Meteorologicaldata & get_mutable_validation_file13() { return validation_file13; }
        void set_validation_file13(const Meteorologicaldata & value) { this->validation_file13 = value; }

        const Meteorologicaldata & get_validation_file14() const { return validation_file14; }
        Meteorologicaldata & get_mutable_validation_file14() { return validation_file14; }
        void set_validation_file14(const Meteorologicaldata & value) { this->validation_file14 = value; }

        const Meteorologicaldata & get_validation_file15() const { return validation_file15; }
        Meteorologicaldata & get_mutable_validation_file15() { return validation_file15; }
        void set_validation_file15(const Meteorologicaldata & value) { this->validation_file15 = value; }

        const Meteorologicaldata & get_validation_file16() const { return validation_file16; }
        Meteorologicaldata & get_mutable_validation_file16() { return validation_file16; }
        void set_validation_file16(const Meteorologicaldata & value) { this->validation_file16 = value; }

        const Meteorologicaldata & get_validation_file2() const { return validation_file2; }
        Meteorologicaldata & get_mutable_validation_file2() { return validation_file2; }
        void set_validation_file2(const Meteorologicaldata & value) { this->validation_file2 = value; }

        const Meteorologicaldata & get_validation_file3() const { return validation_file3; }
        Meteorologicaldata & get_mutable_validation_file3() { return validation_file3; }
        void set_validation_file3(const Meteorologicaldata & value) { this->validation_file3 = value; }

        const Meteorologicaldata & get_validation_file4() const { return validation_file4; }
        Meteorologicaldata & get_mutable_validation_file4() { return validation_file4; }
        void set_validation_file4(const Meteorologicaldata & value) { this->validation_file4 = value; }

        const Meteorologicaldata & get_validation_file5() const { return validation_file5; }
        Meteorologicaldata & get_mutable_validation_file5() { return validation_file5; }
        void set_validation_file5(const Meteorologicaldata & value) { this->validation_file5 = value; }

        const Meteorologicaldata & get_validation_file6() const { return validation_file6; }
        Meteorologicaldata & get_mutable_validation_file6() { return validation_file6; }
        void set_validation_file6(const Meteorologicaldata & value) { this->validation_file6 = value; }

        const Meteorologicaldata & get_validation_file7() const { return validation_file7; }
        Meteorologicaldata & get_mutable_validation_file7() { return validation_file7; }
        void set_validation_file7(const Meteorologicaldata & value) { this->validation_file7 = value; }

        const Meteorologicaldata & get_validation_file8() const { return validation_file8; }
        Meteorologicaldata & get_mutable_validation_file8() { return validation_file8; }
        void set_validation_file8(const Meteorologicaldata & value) { this->validation_file8 = value; }

        const Meteorologicaldata & get_validation_file9() const { return validation_file9; }
        Meteorologicaldata & get_mutable_validation_file9() { return validation_file9; }
        void set_validation_file9(const Meteorologicaldata & value) { this->validation_file9 = value; }
    };

    class ModelFilesModelFacilities {
        public:
        ModelFilesModelFacilities() = default;
        virtual ~ModelFilesModelFacilities() = default;

        private:
        PurpleTechnical technical;

        public:
        const PurpleTechnical & get_technical() const { return technical; }
        PurpleTechnical & get_mutable_technical() { return technical; }
        void set_technical(const PurpleTechnical & value) { this->technical = value; }
    };

    class PurpleExternalNinputs {
        public:
        PurpleExternalNinputs() = default;
        virtual ~PurpleExternalNinputs() = default;

        private:
        Meteorologicaldata manure;
        Meteorologicaldata n_deposition_file;

        public:
        const Meteorologicaldata & get_manure() const { return manure; }
        Meteorologicaldata & get_mutable_manure() { return manure; }
        void set_manure(const Meteorologicaldata & value) { this->manure = value; }

        const Meteorologicaldata & get_n_deposition_file() const { return n_deposition_file; }
        Meteorologicaldata & get_mutable_n_deposition_file() { return n_deposition_file; }
        void set_n_deposition_file(const Meteorologicaldata & value) { this->n_deposition_file = value; }
    };

    class PurplePlantGrowth {
        public:
        PurplePlantGrowth() = default;
        virtual ~PurplePlantGrowth() = default;

        private:
        Meteorologicaldata grazing_periods;
        Meteorologicaldata harvestdatedata;
        Meteorologicaldata plant_biomassdata;

        public:
        const Meteorologicaldata & get_grazing_periods() const { return grazing_periods; }
        Meteorologicaldata & get_mutable_grazing_periods() { return grazing_periods; }
        void set_grazing_periods(const Meteorologicaldata & value) { this->grazing_periods = value; }

        const Meteorologicaldata & get_harvestdatedata() const { return harvestdatedata; }
        Meteorologicaldata & get_mutable_harvestdatedata() { return harvestdatedata; }
        void set_harvestdatedata(const Meteorologicaldata & value) { this->harvestdatedata = value; }

        const Meteorologicaldata & get_plant_biomassdata() const { return plant_biomassdata; }
        Meteorologicaldata & get_mutable_plant_biomassdata() { return plant_biomassdata; }
        void set_plant_biomassdata(const Meteorologicaldata & value) { this->plant_biomassdata = value; }
    };

    class ModelFilesNitrogenandCarbon {
        public:
        ModelFilesNitrogenandCarbon() = default;
        virtual ~ModelFilesNitrogenandCarbon() = default;

        private:
        PurpleExternalNinputs external_ninputs;
        PurplePlantGrowth plant_growth;

        public:
        const PurpleExternalNinputs & get_external_ninputs() const { return external_ninputs; }
        PurpleExternalNinputs & get_mutable_external_ninputs() { return external_ninputs; }
        void set_external_ninputs(const PurpleExternalNinputs & value) { this->external_ninputs = value; }

        const PurplePlantGrowth & get_plant_growth() const { return plant_growth; }
        PurplePlantGrowth & get_mutable_plant_growth() { return plant_growth; }
        void set_plant_growth(const PurplePlantGrowth & value) { this->plant_growth = value; }
    };

    class PurpleAbioticdrivingvariables {
        public:
        PurpleAbioticdrivingvariables() = default;
        virtual ~PurpleAbioticdrivingvariables() = default;

        private:
        Meteorologicaldata abioticsoildata;
        HeatPumpdata green_index;

        public:
        const Meteorologicaldata & get_abioticsoildata() const { return abioticsoildata; }
        Meteorologicaldata & get_mutable_abioticsoildata() { return abioticsoildata; }
        void set_abioticsoildata(const Meteorologicaldata & value) { this->abioticsoildata = value; }

        const HeatPumpdata & get_green_index() const { return green_index; }
        HeatPumpdata & get_mutable_green_index() { return green_index; }
        void set_green_index(const HeatPumpdata & value) { this->green_index = value; }
    };

    class ModelFilesNitrogenandCarbonBelowGround {
        public:
        ModelFilesNitrogenandCarbonBelowGround() = default;
        virtual ~ModelFilesNitrogenandCarbonBelowGround() = default;

        private:
        PurpleAbioticdrivingvariables abioticdrivingvariables;

        public:
        const PurpleAbioticdrivingvariables & get_abioticdrivingvariables() const { return abioticdrivingvariables; }
        PurpleAbioticdrivingvariables & get_mutable_abioticdrivingvariables() { return abioticdrivingvariables; }
        void set_abioticdrivingvariables(const PurpleAbioticdrivingvariables & value) { this->abioticdrivingvariables = value; }
    };

    class PurplePlant {
        public:
        PurplePlant() = default;
        virtual ~PurplePlant() = default;

        private:
        HeatPumpdata cropdata;

        public:
        const HeatPumpdata & get_cropdata() const { return cropdata; }
        HeatPumpdata & get_mutable_cropdata() { return cropdata; }
        void set_cropdata(const HeatPumpdata & value) { this->cropdata = value; }
    };

    enum class Condition2Enum : int { GRAZING_0_IS_FALSE, GROWTH_0_IS_FALSE, GROWTH_2_IS_FALSE, GROWTH_4_IS_FALSE, NITROGEN_AND_CARBON_1_IS_FALSE, PLANT_TYPE_0_IS_TRUE, PLANT_WATER_STORAGE_0_IS_FALSE, PREC_INTERCEPTION_0_IS_TRUE, SALINITY_STRESS_0_IS_FALSE, SNOW_PACK_1_IS_TRUE, WATER_EQ_1_IS_TRUE, WOOD_EATING_0_IS_FALSE };

    class SaltRoadDeposition {
        public:
        SaltRoadDeposition() = default;
        virtual ~SaltRoadDeposition() = default;

        private:
        Condition3Enum condition_1;
        Condition2Enum condition_2;
        Condition3Enum condition_3;
        std::string condition_4;
        std::string pf_file;

        public:
        const Condition3Enum & get_condition_1() const { return condition_1; }
        Condition3Enum & get_mutable_condition_1() { return condition_1; }
        void set_condition_1(const Condition3Enum & value) { this->condition_1 = value; }

        const Condition2Enum & get_condition_2() const { return condition_2; }
        Condition2Enum & get_mutable_condition_2() { return condition_2; }
        void set_condition_2(const Condition2Enum & value) { this->condition_2 = value; }

        const Condition3Enum & get_condition_3() const { return condition_3; }
        Condition3Enum & get_mutable_condition_3() { return condition_3; }
        void set_condition_3(const Condition3Enum & value) { this->condition_3 = value; }

        const std::string & get_condition_4() const { return condition_4; }
        std::string & get_mutable_condition_4() { return condition_4; }
        void set_condition_4(const std::string & value) { this->condition_4 = value; }

        const std::string & get_pf_file() const { return pf_file; }
        std::string & get_mutable_pf_file() { return pf_file; }
        void set_pf_file(const std::string & value) { this->pf_file = value; }
    };

    class PurpleSaltTracer {
        public:
        PurpleSaltTracer() = default;
        virtual ~PurpleSaltTracer() = default;

        private:
        SaltRoadDeposition salt_road_deposition;

        public:
        const SaltRoadDeposition & get_salt_road_deposition() const { return salt_road_deposition; }
        SaltRoadDeposition & get_mutable_salt_road_deposition() { return salt_road_deposition; }
        void set_salt_road_deposition(const SaltRoadDeposition & value) { this->salt_road_deposition = value; }
    };

    class ModelFilesPlantWaterProcesses {
        public:
        ModelFilesPlantWaterProcesses() = default;
        virtual ~ModelFilesPlantWaterProcesses() = default;

        private:
        PurplePlant plant;
        PurpleSaltTracer salt_tracer;

        public:
        const PurplePlant & get_plant() const { return plant; }
        PurplePlant & get_mutable_plant() { return plant; }
        void set_plant(const PurplePlant & value) { this->plant = value; }

        const PurpleSaltTracer & get_salt_tracer() const { return salt_tracer; }
        PurpleSaltTracer & get_mutable_salt_tracer() { return salt_tracer; }
        void set_salt_tracer(const PurpleSaltTracer & value) { this->salt_tracer = value; }
    };

    class PurpleDrainageanddeeppercolation {
        public:
        PurpleDrainageanddeeppercolation() = default;
        virtual ~PurpleDrainageanddeeppercolation() = default;

        private:
        HeatPumpdata groundwaterlevel;
        HeatPumpdata pressuredheadat_lowerboundary;

        public:
        const HeatPumpdata & get_groundwaterlevel() const { return groundwaterlevel; }
        HeatPumpdata & get_mutable_groundwaterlevel() { return groundwaterlevel; }
        void set_groundwaterlevel(const HeatPumpdata & value) { this->groundwaterlevel = value; }

        const HeatPumpdata & get_pressuredheadat_lowerboundary() const { return pressuredheadat_lowerboundary; }
        HeatPumpdata & get_mutable_pressuredheadat_lowerboundary() { return pressuredheadat_lowerboundary; }
        void set_pressuredheadat_lowerboundary(const HeatPumpdata & value) { this->pressuredheadat_lowerboundary = value; }
    };

    class ModelFilesSoilWaterProcesses {
        public:
        ModelFilesSoilWaterProcesses() = default;
        virtual ~ModelFilesSoilWaterProcesses() = default;

        private:
        PurpleDrainageanddeeppercolation drainageanddeeppercolation;

        public:
        const PurpleDrainageanddeeppercolation & get_drainageanddeeppercolation() const { return drainageanddeeppercolation; }
        PurpleDrainageanddeeppercolation & get_mutable_drainageanddeeppercolation() { return drainageanddeeppercolation; }
        void set_drainageanddeeppercolation(const PurpleDrainageanddeeppercolation & value) { this->drainageanddeeppercolation = value; }
    };

    class ModelFiles {
        public:
        ModelFiles() = default;
        virtual ~ModelFiles() = default;

        private:
        ModelFilesAtmosphericRelatedProcesses atmospheric_related_processes;
        ModelFilesModelFacilities model_facilities;
        ModelFilesNitrogenandCarbon nitrogenand_carbon;
        ModelFilesNitrogenandCarbonBelowGround nitrogenand_carbon_below_ground;
        ModelFilesPlantWaterProcesses plant_water_processes;
        ModelFilesSoilWaterProcesses soil_water_processes;

        public:
        const ModelFilesAtmosphericRelatedProcesses & get_atmospheric_related_processes() const { return atmospheric_related_processes; }
        ModelFilesAtmosphericRelatedProcesses & get_mutable_atmospheric_related_processes() { return atmospheric_related_processes; }
        void set_atmospheric_related_processes(const ModelFilesAtmosphericRelatedProcesses & value) { this->atmospheric_related_processes = value; }

        const ModelFilesModelFacilities & get_model_facilities() const { return model_facilities; }
        ModelFilesModelFacilities & get_mutable_model_facilities() { return model_facilities; }
        void set_model_facilities(const ModelFilesModelFacilities & value) { this->model_facilities = value; }

        const ModelFilesNitrogenandCarbon & get_nitrogenand_carbon() const { return nitrogenand_carbon; }
        ModelFilesNitrogenandCarbon & get_mutable_nitrogenand_carbon() { return nitrogenand_carbon; }
        void set_nitrogenand_carbon(const ModelFilesNitrogenandCarbon & value) { this->nitrogenand_carbon = value; }

        const ModelFilesNitrogenandCarbonBelowGround & get_nitrogenand_carbon_below_ground() const { return nitrogenand_carbon_below_ground; }
        ModelFilesNitrogenandCarbonBelowGround & get_mutable_nitrogenand_carbon_below_ground() { return nitrogenand_carbon_below_ground; }
        void set_nitrogenand_carbon_below_ground(const ModelFilesNitrogenandCarbonBelowGround & value) { this->nitrogenand_carbon_below_ground = value; }

        const ModelFilesPlantWaterProcesses & get_plant_water_processes() const { return plant_water_processes; }
        ModelFilesPlantWaterProcesses & get_mutable_plant_water_processes() { return plant_water_processes; }
        void set_plant_water_processes(const ModelFilesPlantWaterProcesses & value) { this->plant_water_processes = value; }

        const ModelFilesSoilWaterProcesses & get_soil_water_processes() const { return soil_water_processes; }
        ModelFilesSoilWaterProcesses & get_mutable_soil_water_processes() { return soil_water_processes; }
        void set_soil_water_processes(const ModelFilesSoilWaterProcesses & value) { this->soil_water_processes = value; }
    };

    class PrecInput {
        public:
        PrecInput() = default;
        virtual ~PrecInput() = default;

        private:
        std::shared_ptr<std::string> condition_1;
        std::shared_ptr<std::string> condition_2;
        std::shared_ptr<std::string> condition_3;
        std::shared_ptr<std::string> condition_4;
        std::shared_ptr<std::string> condition_5;
        std::string current;
        std::string prec_input_default;
        std::shared_ptr<std::string> max;
        std::shared_ptr<std::string> min;
        std::shared_ptr<std::string> opt_0;
        std::shared_ptr<std::string> opt_1;
        std::shared_ptr<std::string> opt_2;
        std::shared_ptr<std::string> opt_3;

        public:
        std::shared_ptr<std::string> get_condition_1() const { return condition_1; }
        void set_condition_1(std::shared_ptr<std::string> value) { this->condition_1 = value; }

        std::shared_ptr<std::string> get_condition_2() const { return condition_2; }
        void set_condition_2(std::shared_ptr<std::string> value) { this->condition_2 = value; }

        std::shared_ptr<std::string> get_condition_3() const { return condition_3; }
        void set_condition_3(std::shared_ptr<std::string> value) { this->condition_3 = value; }

        std::shared_ptr<std::string> get_condition_4() const { return condition_4; }
        void set_condition_4(std::shared_ptr<std::string> value) { this->condition_4 = value; }

        std::shared_ptr<std::string> get_condition_5() const { return condition_5; }
        void set_condition_5(std::shared_ptr<std::string> value) { this->condition_5 = value; }

        const std::string & get_current() const { return current; }
        std::string & get_mutable_current() { return current; }
        void set_current(const std::string & value) { this->current = value; }

        const std::string & get_prec_input_default() const { return prec_input_default; }
        std::string & get_mutable_prec_input_default() { return prec_input_default; }
        void set_prec_input_default(const std::string & value) { this->prec_input_default = value; }

        std::shared_ptr<std::string> get_max() const { return max; }
        void set_max(std::shared_ptr<std::string> value) { this->max = value; }

        std::shared_ptr<std::string> get_min() const { return min; }
        void set_min(std::shared_ptr<std::string> value) { this->min = value; }

        std::shared_ptr<std::string> get_opt_0() const { return opt_0; }
        void set_opt_0(std::shared_ptr<std::string> value) { this->opt_0 = value; }

        std::shared_ptr<std::string> get_opt_1() const { return opt_1; }
        void set_opt_1(std::shared_ptr<std::string> value) { this->opt_1 = value; }

        std::shared_ptr<std::string> get_opt_2() const { return opt_2; }
        void set_opt_2(std::shared_ptr<std::string> value) { this->opt_2 = value; }

        std::shared_ptr<std::string> get_opt_3() const { return opt_3; }
        void set_opt_3(std::shared_ptr<std::string> value) { this->opt_3 = value; }
    };

    class FluffyMeteorologicalData {
        public:
        FluffyMeteorologicalData() = default;
        virtual ~FluffyMeteorologicalData() = default;

        private:
        PrecInput prec_input;
        PrecInput rad_glob_input;
        PrecInput temp_air_input;

        public:
        const PrecInput & get_prec_input() const { return prec_input; }
        PrecInput & get_mutable_prec_input() { return prec_input; }
        void set_prec_input(const PrecInput & value) { this->prec_input = value; }

        const PrecInput & get_rad_glob_input() const { return rad_glob_input; }
        PrecInput & get_mutable_rad_glob_input() { return rad_glob_input; }
        void set_rad_glob_input(const PrecInput & value) { this->rad_glob_input = value; }

        const PrecInput & get_temp_air_input() const { return temp_air_input; }
        PrecInput & get_mutable_temp_air_input() { return temp_air_input; }
        void set_temp_air_input(const PrecInput & value) { this->temp_air_input = value; }
    };

    class PurpleRadiationproperties {
        public:
        PurpleRadiationproperties() = default;
        virtual ~PurpleRadiationproperties() = default;

        private:
        PrecInput radiation_input;

        public:
        const PrecInput & get_radiation_input() const { return radiation_input; }
        PrecInput & get_mutable_radiation_input() { return radiation_input; }
        void set_radiation_input(const PrecInput & value) { this->radiation_input = value; }
    };

    class EvaporationMethod {
        public:
        EvaporationMethod() = default;
        virtual ~EvaporationMethod() = default;

        private:
        std::shared_ptr<Condition3Enum> condition_1;
        std::shared_ptr<std::string> condition_2;
        std::shared_ptr<std::string> condition_3;
        std::shared_ptr<std::string> condition_4;
        std::string current;
        std::string evaporation_method_default;
        std::shared_ptr<std::string> max;
        std::shared_ptr<std::string> min;
        std::shared_ptr<std::string> opt_0;
        std::shared_ptr<std::string> opt_1;
        std::shared_ptr<std::string> opt_2;
        std::shared_ptr<std::string> opt_3;
        std::shared_ptr<std::string> opt_4;

        public:
        std::shared_ptr<Condition3Enum> get_condition_1() const { return condition_1; }
        void set_condition_1(std::shared_ptr<Condition3Enum> value) { this->condition_1 = value; }

        std::shared_ptr<std::string> get_condition_2() const { return condition_2; }
        void set_condition_2(std::shared_ptr<std::string> value) { this->condition_2 = value; }

        std::shared_ptr<std::string> get_condition_3() const { return condition_3; }
        void set_condition_3(std::shared_ptr<std::string> value) { this->condition_3 = value; }

        std::shared_ptr<std::string> get_condition_4() const { return condition_4; }
        void set_condition_4(std::shared_ptr<std::string> value) { this->condition_4 = value; }

        const std::string & get_current() const { return current; }
        std::string & get_mutable_current() { return current; }
        void set_current(const std::string & value) { this->current = value; }

        const std::string & get_evaporation_method_default() const { return evaporation_method_default; }
        std::string & get_mutable_evaporation_method_default() { return evaporation_method_default; }
        void set_evaporation_method_default(const std::string & value) { this->evaporation_method_default = value; }

        std::shared_ptr<std::string> get_max() const { return max; }
        void set_max(std::shared_ptr<std::string> value) { this->max = value; }

        std::shared_ptr<std::string> get_min() const { return min; }
        void set_min(std::shared_ptr<std::string> value) { this->min = value; }

        std::shared_ptr<std::string> get_opt_0() const { return opt_0; }
        void set_opt_0(std::shared_ptr<std::string> value) { this->opt_0 = value; }

        std::shared_ptr<std::string> get_opt_1() const { return opt_1; }
        void set_opt_1(std::shared_ptr<std::string> value) { this->opt_1 = value; }

        std::shared_ptr<std::string> get_opt_2() const { return opt_2; }
        void set_opt_2(std::shared_ptr<std::string> value) { this->opt_2 = value; }

        std::shared_ptr<std::string> get_opt_3() const { return opt_3; }
        void set_opt_3(std::shared_ptr<std::string> value) { this->opt_3 = value; }

        std::shared_ptr<std::string> get_opt_4() const { return opt_4; }
        void set_opt_4(std::shared_ptr<std::string> value) { this->opt_4 = value; }
    };

    class PurpleSoilevaporation {
        public:
        PurpleSoilevaporation() = default;
        virtual ~PurpleSoilevaporation() = default;

        private:
        EvaporationMethod evaporation_method;
        EvaporationMethod surface_temperature;

        public:
        const EvaporationMethod & get_evaporation_method() const { return evaporation_method; }
        EvaporationMethod & get_mutable_evaporation_method() { return evaporation_method; }
        void set_evaporation_method(const EvaporationMethod & value) { this->evaporation_method = value; }

        const EvaporationMethod & get_surface_temperature() const { return surface_temperature; }
        EvaporationMethod & get_mutable_surface_temperature() { return surface_temperature; }
        void set_surface_temperature(const EvaporationMethod & value) { this->surface_temperature = value; }
    };

    class ModelOptionsAtmosphericRelatedProcesses {
        public:
        ModelOptionsAtmosphericRelatedProcesses() = default;
        virtual ~ModelOptionsAtmosphericRelatedProcesses() = default;

        private:
        FluffyMeteorologicalData meteorological_data;
        PurpleRadiationproperties radiationproperties;
        PurpleSoilevaporation soilevaporation;

        public:
        const FluffyMeteorologicalData & get_meteorological_data() const { return meteorological_data; }
        FluffyMeteorologicalData & get_mutable_meteorological_data() { return meteorological_data; }
        void set_meteorological_data(const FluffyMeteorologicalData & value) { this->meteorological_data = value; }

        const PurpleRadiationproperties & get_radiationproperties() const { return radiationproperties; }
        PurpleRadiationproperties & get_mutable_radiationproperties() { return radiationproperties; }
        void set_radiationproperties(const PurpleRadiationproperties & value) { this->radiationproperties = value; }

        const PurpleSoilevaporation & get_soilevaporation() const { return soilevaporation; }
        PurpleSoilevaporation & get_mutable_soilevaporation() { return soilevaporation; }
        void set_soilevaporation(const PurpleSoilevaporation & value) { this->soilevaporation = value; }
    };

    class FluffyTechnical {
        public:
        FluffyTechnical() = default;
        virtual ~FluffyTechnical() = default;

        private:
        PrecInput time_resolution;
        PrecInput type_of_driving_file;

        public:
        const PrecInput & get_time_resolution() const { return time_resolution; }
        PrecInput & get_mutable_time_resolution() { return time_resolution; }
        void set_time_resolution(const PrecInput & value) { this->time_resolution = value; }

        const PrecInput & get_type_of_driving_file() const { return type_of_driving_file; }
        PrecInput & get_mutable_type_of_driving_file() { return type_of_driving_file; }
        void set_type_of_driving_file(const PrecInput & value) { this->type_of_driving_file = value; }
    };

    class ModelOptionsModelFacilities {
        public:
        ModelOptionsModelFacilities() = default;
        virtual ~ModelOptionsModelFacilities() = default;

        private:
        FluffyTechnical technical;

        public:
        const FluffyTechnical & get_technical() const { return technical; }
        FluffyTechnical & get_mutable_technical() { return technical; }
        void set_technical(const FluffyTechnical & value) { this->technical = value; }
    };

    class PurpleModelStructure {
        public:
        PurpleModelStructure() = default;
        virtual ~PurpleModelStructure() = default;

        private:
        EvaporationMethod evaporation;
        EvaporationMethod ground_water_flow;
        EvaporationMethod lateral_input;
        EvaporationMethod plant_type;
        EvaporationMethod snow_pack;
        EvaporationMethod water_eq;

        public:
        const EvaporationMethod & get_evaporation() const { return evaporation; }
        EvaporationMethod & get_mutable_evaporation() { return evaporation; }
        void set_evaporation(const EvaporationMethod & value) { this->evaporation = value; }

        const EvaporationMethod & get_ground_water_flow() const { return ground_water_flow; }
        EvaporationMethod & get_mutable_ground_water_flow() { return ground_water_flow; }
        void set_ground_water_flow(const EvaporationMethod & value) { this->ground_water_flow = value; }

        const EvaporationMethod & get_lateral_input() const { return lateral_input; }
        EvaporationMethod & get_mutable_lateral_input() { return lateral_input; }
        void set_lateral_input(const EvaporationMethod & value) { this->lateral_input = value; }

        const EvaporationMethod & get_plant_type() const { return plant_type; }
        EvaporationMethod & get_mutable_plant_type() { return plant_type; }
        void set_plant_type(const EvaporationMethod & value) { this->plant_type = value; }

        const EvaporationMethod & get_snow_pack() const { return snow_pack; }
        EvaporationMethod & get_mutable_snow_pack() { return snow_pack; }
        void set_snow_pack(const EvaporationMethod & value) { this->snow_pack = value; }

        const EvaporationMethod & get_water_eq() const { return water_eq; }
        EvaporationMethod & get_mutable_water_eq() { return water_eq; }
        void set_water_eq(const EvaporationMethod & value) { this->water_eq = value; }
    };

    class ModelOptionsModelStructure {
        public:
        ModelOptionsModelStructure() = default;
        virtual ~ModelOptionsModelStructure() = default;

        private:
        PurpleModelStructure model_structure;

        public:
        const PurpleModelStructure & get_model_structure() const { return model_structure; }
        PurpleModelStructure & get_mutable_model_structure() { return model_structure; }
        void set_model_structure(const PurpleModelStructure & value) { this->model_structure = value; }
    };

    class PurpleInterception {
        public:
        PurpleInterception() = default;
        virtual ~PurpleInterception() = default;

        private:
        PrecInput prec_interception;

        public:
        const PrecInput & get_prec_interception() const { return prec_interception; }
        PrecInput & get_mutable_prec_interception() { return prec_interception; }
        void set_prec_interception(const PrecInput & value) { this->prec_interception = value; }
    };

    class PurpleWateruptake {
        public:
        PurpleWateruptake() = default;
        virtual ~PurpleWateruptake() = default;

        private:
        EvaporationMethod demand_redistribution;

        public:
        const EvaporationMethod & get_demand_redistribution() const { return demand_redistribution; }
        EvaporationMethod & get_mutable_demand_redistribution() { return demand_redistribution; }
        void set_demand_redistribution(const EvaporationMethod & value) { this->demand_redistribution = value; }
    };

    class ModelOptionsPlantWaterProcesses {
        public:
        ModelOptionsPlantWaterProcesses() = default;
        virtual ~ModelOptionsPlantWaterProcesses() = default;

        private:
        PurpleInterception interception;
        PurpleWateruptake wateruptake;

        public:
        const PurpleInterception & get_interception() const { return interception; }
        PurpleInterception & get_mutable_interception() { return interception; }
        void set_interception(const PurpleInterception & value) { this->interception = value; }

        const PurpleWateruptake & get_wateruptake() const { return wateruptake; }
        PurpleWateruptake & get_mutable_wateruptake() { return wateruptake; }
        void set_wateruptake(const PurpleWateruptake & value) { this->wateruptake = value; }
    };

    class FluffyDrainageanddeeppercolation {
        public:
        FluffyDrainageanddeeppercolation() = default;
        virtual ~FluffyDrainageanddeeppercolation() = default;

        private:
        PrecInput empirical_drain_eq;
        PrecInput lateral_gw_source;
        PrecInput physical_drain_eq;

        public:
        const PrecInput & get_empirical_drain_eq() const { return empirical_drain_eq; }
        PrecInput & get_mutable_empirical_drain_eq() { return empirical_drain_eq; }
        void set_empirical_drain_eq(const PrecInput & value) { this->empirical_drain_eq = value; }

        const PrecInput & get_lateral_gw_source() const { return lateral_gw_source; }
        PrecInput & get_mutable_lateral_gw_source() { return lateral_gw_source; }
        void set_lateral_gw_source(const PrecInput & value) { this->lateral_gw_source = value; }

        const PrecInput & get_physical_drain_eq() const { return physical_drain_eq; }
        PrecInput & get_mutable_physical_drain_eq() { return physical_drain_eq; }
        void set_physical_drain_eq(const PrecInput & value) { this->physical_drain_eq = value; }
    };

    class PurpleSurfacewater {
        public:
        PurpleSurfacewater() = default;
        virtual ~PurpleSurfacewater() = default;

        private:
        EvaporationMethod run_on_input;

        public:
        const EvaporationMethod & get_run_on_input() const { return run_on_input; }
        EvaporationMethod & get_mutable_run_on_input() { return run_on_input; }
        void set_run_on_input(const EvaporationMethod & value) { this->run_on_input = value; }
    };

    class ModelOptionsSoilWaterProcesses {
        public:
        ModelOptionsSoilWaterProcesses() = default;
        virtual ~ModelOptionsSoilWaterProcesses() = default;

        private:
        FluffyDrainageanddeeppercolation drainageanddeeppercolation;
        PurpleSurfacewater surfacewater;

        public:
        const FluffyDrainageanddeeppercolation & get_drainageanddeeppercolation() const { return drainageanddeeppercolation; }
        FluffyDrainageanddeeppercolation & get_mutable_drainageanddeeppercolation() { return drainageanddeeppercolation; }
        void set_drainageanddeeppercolation(const FluffyDrainageanddeeppercolation & value) { this->drainageanddeeppercolation = value; }

        const PurpleSurfacewater & get_surfacewater() const { return surfacewater; }
        PurpleSurfacewater & get_mutable_surfacewater() { return surfacewater; }
        void set_surfacewater(const PurpleSurfacewater & value) { this->surfacewater = value; }
    };

    class ModelOptions {
        public:
        ModelOptions() = default;
        virtual ~ModelOptions() = default;

        private:
        ModelOptionsAtmosphericRelatedProcesses atmospheric_related_processes;
        ModelOptionsModelFacilities model_facilities;
        ModelOptionsModelStructure model_structure;
        ModelOptionsPlantWaterProcesses plant_water_processes;
        ModelOptionsSoilWaterProcesses soil_water_processes;

        public:
        const ModelOptionsAtmosphericRelatedProcesses & get_atmospheric_related_processes() const { return atmospheric_related_processes; }
        ModelOptionsAtmosphericRelatedProcesses & get_mutable_atmospheric_related_processes() { return atmospheric_related_processes; }
        void set_atmospheric_related_processes(const ModelOptionsAtmosphericRelatedProcesses & value) { this->atmospheric_related_processes = value; }

        const ModelOptionsModelFacilities & get_model_facilities() const { return model_facilities; }
        ModelOptionsModelFacilities & get_mutable_model_facilities() { return model_facilities; }
        void set_model_facilities(const ModelOptionsModelFacilities & value) { this->model_facilities = value; }

        const ModelOptionsModelStructure & get_model_structure() const { return model_structure; }
        ModelOptionsModelStructure & get_mutable_model_structure() { return model_structure; }
        void set_model_structure(const ModelOptionsModelStructure & value) { this->model_structure = value; }

        const ModelOptionsPlantWaterProcesses & get_plant_water_processes() const { return plant_water_processes; }
        ModelOptionsPlantWaterProcesses & get_mutable_plant_water_processes() { return plant_water_processes; }
        void set_plant_water_processes(const ModelOptionsPlantWaterProcesses & value) { this->plant_water_processes = value; }

        const ModelOptionsSoilWaterProcesses & get_soil_water_processes() const { return soil_water_processes; }
        ModelOptionsSoilWaterProcesses & get_mutable_soil_water_processes() { return soil_water_processes; }
        void set_soil_water_processes(const ModelOptionsSoilWaterProcesses & value) { this->soil_water_processes = value; }
    };

    class AlbedoVar {
        public:
        AlbedoVar() = default;
        virtual ~AlbedoVar() = default;

        private:
        Condition3Enum condition_1;
        std::shared_ptr<std::string> condition_2;
        std::shared_ptr<std::string> condition_3;
        std::shared_ptr<std::string> condition_4;
        std::shared_ptr<std::string> condition_5;
        std::shared_ptr<std::string> condition_6;
        std::string out_multi;
        std::string out_single;

        public:
        const Condition3Enum & get_condition_1() const { return condition_1; }
        Condition3Enum & get_mutable_condition_1() { return condition_1; }
        void set_condition_1(const Condition3Enum & value) { this->condition_1 = value; }

        std::shared_ptr<std::string> get_condition_2() const { return condition_2; }
        void set_condition_2(std::shared_ptr<std::string> value) { this->condition_2 = value; }

        std::shared_ptr<std::string> get_condition_3() const { return condition_3; }
        void set_condition_3(std::shared_ptr<std::string> value) { this->condition_3 = value; }

        std::shared_ptr<std::string> get_condition_4() const { return condition_4; }
        void set_condition_4(std::shared_ptr<std::string> value) { this->condition_4 = value; }

        std::shared_ptr<std::string> get_condition_5() const { return condition_5; }
        void set_condition_5(std::shared_ptr<std::string> value) { this->condition_5 = value; }

        std::shared_ptr<std::string> get_condition_6() const { return condition_6; }
        void set_condition_6(std::shared_ptr<std::string> value) { this->condition_6 = value; }

        const std::string & get_out_multi() const { return out_multi; }
        std::string & get_mutable_out_multi() { return out_multi; }
        void set_out_multi(const std::string & value) { this->out_multi = value; }

        const std::string & get_out_single() const { return out_single; }
        std::string & get_mutable_out_single() { return out_single; }
        void set_out_single(const std::string & value) { this->out_single = value; }
    };

    class CanopyFracRadDiffuse {
        public:
        CanopyFracRadDiffuse() = default;
        virtual ~CanopyFracRadDiffuse() = default;

        private:
        std::string condition_1;
        std::shared_ptr<std::string> condition_2;
        std::shared_ptr<std::string> condition_3;
        std::shared_ptr<std::string> condition_4;
        std::shared_ptr<Condition2Enum> condition_5;
        std::string out_multi;
        std::string out_single;

        public:
        const std::string & get_condition_1() const { return condition_1; }
        std::string & get_mutable_condition_1() { return condition_1; }
        void set_condition_1(const std::string & value) { this->condition_1 = value; }

        std::shared_ptr<std::string> get_condition_2() const { return condition_2; }
        void set_condition_2(std::shared_ptr<std::string> value) { this->condition_2 = value; }

        std::shared_ptr<std::string> get_condition_3() const { return condition_3; }
        void set_condition_3(std::shared_ptr<std::string> value) { this->condition_3 = value; }

        std::shared_ptr<std::string> get_condition_4() const { return condition_4; }
        void set_condition_4(std::shared_ptr<std::string> value) { this->condition_4 = value; }

        std::shared_ptr<Condition2Enum> get_condition_5() const { return condition_5; }
        void set_condition_5(std::shared_ptr<Condition2Enum> value) { this->condition_5 = value; }

        const std::string & get_out_multi() const { return out_multi; }
        std::string & get_mutable_out_multi() { return out_multi; }
        void set_out_multi(const std::string & value) { this->out_multi = value; }

        const std::string & get_out_single() const { return out_single; }
        std::string & get_mutable_out_single() { return out_single; }
        void set_out_single(const std::string & value) { this->out_single = value; }
    };

    class FluffyRadiationproperties {
        public:
        FluffyRadiationproperties() = default;
        virtual ~FluffyRadiationproperties() = default;

        private:
        AlbedoVar albedo_var;
        AlbedoVar canopy_frac_rad;
        AlbedoVar canopy_frac_rad1;
        AlbedoVar canopy_frac_rad2;
        CanopyFracRadDiffuse canopy_frac_rad_diffuse;
        CanopyFracRadDiffuse canopy_frac_rad_direct;
        CanopyFracRadDiffuse canopy_frac_rad_long;
        AlbedoVar ground_albedo;
        AlbedoVar rad_in_diffuse;
        AlbedoVar rad_in_direct;
        AlbedoVar rad_in_long_ground;
        AlbedoVar rad_in_long_ground1;
        AlbedoVar rad_in_long_ground2;
        AlbedoVar rad_in_short_ground;
        AlbedoVar rad_long_out;
        AlbedoVar rad_net_canopy;
        AlbedoVar rad_net_ground;
        AlbedoVar rad_net_ground1;
        AlbedoVar rad_net_ground2;
        AlbedoVar rad_net_long_canopy;
        AlbedoVar rad_net_long_ground;
        AlbedoVar rad_net_short;
        AlbedoVar rad_net_short_canopy;
        AlbedoVar rad_net_short_ground;
        AlbedoVar rad_short_out;
        AlbedoVar snow_albedo;
        AlbedoVar soil_albedo;

        public:
        const AlbedoVar & get_albedo_var() const { return albedo_var; }
        AlbedoVar & get_mutable_albedo_var() { return albedo_var; }
        void set_albedo_var(const AlbedoVar & value) { this->albedo_var = value; }

        const AlbedoVar & get_canopy_frac_rad() const { return canopy_frac_rad; }
        AlbedoVar & get_mutable_canopy_frac_rad() { return canopy_frac_rad; }
        void set_canopy_frac_rad(const AlbedoVar & value) { this->canopy_frac_rad = value; }

        const AlbedoVar & get_canopy_frac_rad1() const { return canopy_frac_rad1; }
        AlbedoVar & get_mutable_canopy_frac_rad1() { return canopy_frac_rad1; }
        void set_canopy_frac_rad1(const AlbedoVar & value) { this->canopy_frac_rad1 = value; }

        const AlbedoVar & get_canopy_frac_rad2() const { return canopy_frac_rad2; }
        AlbedoVar & get_mutable_canopy_frac_rad2() { return canopy_frac_rad2; }
        void set_canopy_frac_rad2(const AlbedoVar & value) { this->canopy_frac_rad2 = value; }

        const CanopyFracRadDiffuse & get_canopy_frac_rad_diffuse() const { return canopy_frac_rad_diffuse; }
        CanopyFracRadDiffuse & get_mutable_canopy_frac_rad_diffuse() { return canopy_frac_rad_diffuse; }
        void set_canopy_frac_rad_diffuse(const CanopyFracRadDiffuse & value) { this->canopy_frac_rad_diffuse = value; }

        const CanopyFracRadDiffuse & get_canopy_frac_rad_direct() const { return canopy_frac_rad_direct; }
        CanopyFracRadDiffuse & get_mutable_canopy_frac_rad_direct() { return canopy_frac_rad_direct; }
        void set_canopy_frac_rad_direct(const CanopyFracRadDiffuse & value) { this->canopy_frac_rad_direct = value; }

        const CanopyFracRadDiffuse & get_canopy_frac_rad_long() const { return canopy_frac_rad_long; }
        CanopyFracRadDiffuse & get_mutable_canopy_frac_rad_long() { return canopy_frac_rad_long; }
        void set_canopy_frac_rad_long(const CanopyFracRadDiffuse & value) { this->canopy_frac_rad_long = value; }

        const AlbedoVar & get_ground_albedo() const { return ground_albedo; }
        AlbedoVar & get_mutable_ground_albedo() { return ground_albedo; }
        void set_ground_albedo(const AlbedoVar & value) { this->ground_albedo = value; }

        const AlbedoVar & get_rad_in_diffuse() const { return rad_in_diffuse; }
        AlbedoVar & get_mutable_rad_in_diffuse() { return rad_in_diffuse; }
        void set_rad_in_diffuse(const AlbedoVar & value) { this->rad_in_diffuse = value; }

        const AlbedoVar & get_rad_in_direct() const { return rad_in_direct; }
        AlbedoVar & get_mutable_rad_in_direct() { return rad_in_direct; }
        void set_rad_in_direct(const AlbedoVar & value) { this->rad_in_direct = value; }

        const AlbedoVar & get_rad_in_long_ground() const { return rad_in_long_ground; }
        AlbedoVar & get_mutable_rad_in_long_ground() { return rad_in_long_ground; }
        void set_rad_in_long_ground(const AlbedoVar & value) { this->rad_in_long_ground = value; }

        const AlbedoVar & get_rad_in_long_ground1() const { return rad_in_long_ground1; }
        AlbedoVar & get_mutable_rad_in_long_ground1() { return rad_in_long_ground1; }
        void set_rad_in_long_ground1(const AlbedoVar & value) { this->rad_in_long_ground1 = value; }

        const AlbedoVar & get_rad_in_long_ground2() const { return rad_in_long_ground2; }
        AlbedoVar & get_mutable_rad_in_long_ground2() { return rad_in_long_ground2; }
        void set_rad_in_long_ground2(const AlbedoVar & value) { this->rad_in_long_ground2 = value; }

        const AlbedoVar & get_rad_in_short_ground() const { return rad_in_short_ground; }
        AlbedoVar & get_mutable_rad_in_short_ground() { return rad_in_short_ground; }
        void set_rad_in_short_ground(const AlbedoVar & value) { this->rad_in_short_ground = value; }

        const AlbedoVar & get_rad_long_out() const { return rad_long_out; }
        AlbedoVar & get_mutable_rad_long_out() { return rad_long_out; }
        void set_rad_long_out(const AlbedoVar & value) { this->rad_long_out = value; }

        const AlbedoVar & get_rad_net_canopy() const { return rad_net_canopy; }
        AlbedoVar & get_mutable_rad_net_canopy() { return rad_net_canopy; }
        void set_rad_net_canopy(const AlbedoVar & value) { this->rad_net_canopy = value; }

        const AlbedoVar & get_rad_net_ground() const { return rad_net_ground; }
        AlbedoVar & get_mutable_rad_net_ground() { return rad_net_ground; }
        void set_rad_net_ground(const AlbedoVar & value) { this->rad_net_ground = value; }

        const AlbedoVar & get_rad_net_ground1() const { return rad_net_ground1; }
        AlbedoVar & get_mutable_rad_net_ground1() { return rad_net_ground1; }
        void set_rad_net_ground1(const AlbedoVar & value) { this->rad_net_ground1 = value; }

        const AlbedoVar & get_rad_net_ground2() const { return rad_net_ground2; }
        AlbedoVar & get_mutable_rad_net_ground2() { return rad_net_ground2; }
        void set_rad_net_ground2(const AlbedoVar & value) { this->rad_net_ground2 = value; }

        const AlbedoVar & get_rad_net_long_canopy() const { return rad_net_long_canopy; }
        AlbedoVar & get_mutable_rad_net_long_canopy() { return rad_net_long_canopy; }
        void set_rad_net_long_canopy(const AlbedoVar & value) { this->rad_net_long_canopy = value; }

        const AlbedoVar & get_rad_net_long_ground() const { return rad_net_long_ground; }
        AlbedoVar & get_mutable_rad_net_long_ground() { return rad_net_long_ground; }
        void set_rad_net_long_ground(const AlbedoVar & value) { this->rad_net_long_ground = value; }

        const AlbedoVar & get_rad_net_short() const { return rad_net_short; }
        AlbedoVar & get_mutable_rad_net_short() { return rad_net_short; }
        void set_rad_net_short(const AlbedoVar & value) { this->rad_net_short = value; }

        const AlbedoVar & get_rad_net_short_canopy() const { return rad_net_short_canopy; }
        AlbedoVar & get_mutable_rad_net_short_canopy() { return rad_net_short_canopy; }
        void set_rad_net_short_canopy(const AlbedoVar & value) { this->rad_net_short_canopy = value; }

        const AlbedoVar & get_rad_net_short_ground() const { return rad_net_short_ground; }
        AlbedoVar & get_mutable_rad_net_short_ground() { return rad_net_short_ground; }
        void set_rad_net_short_ground(const AlbedoVar & value) { this->rad_net_short_ground = value; }

        const AlbedoVar & get_rad_short_out() const { return rad_short_out; }
        AlbedoVar & get_mutable_rad_short_out() { return rad_short_out; }
        void set_rad_short_out(const AlbedoVar & value) { this->rad_short_out = value; }

        const AlbedoVar & get_snow_albedo() const { return snow_albedo; }
        AlbedoVar & get_mutable_snow_albedo() { return snow_albedo; }
        void set_snow_albedo(const AlbedoVar & value) { this->snow_albedo = value; }

        const AlbedoVar & get_soil_albedo() const { return soil_albedo; }
        AlbedoVar & get_mutable_soil_albedo() { return soil_albedo; }
        void set_soil_albedo(const AlbedoVar & value) { this->soil_albedo = value; }
    };

    class AuxiliaryAtmosphericRelatedProcesses {
        public:
        AuxiliaryAtmosphericRelatedProcesses() = default;
        virtual ~AuxiliaryAtmosphericRelatedProcesses() = default;

        private:
        FluffyRadiationproperties radiationproperties;
        std::map<std::string, AlbedoVar> snow_pack;
        std::map<std::string, CanopyFracRadDiffuse> soilevaporation;

        public:
        const FluffyRadiationproperties & get_radiationproperties() const { return radiationproperties; }
        FluffyRadiationproperties & get_mutable_radiationproperties() { return radiationproperties; }
        void set_radiationproperties(const FluffyRadiationproperties & value) { this->radiationproperties = value; }

        const std::map<std::string, AlbedoVar> & get_snow_pack() const { return snow_pack; }
        std::map<std::string, AlbedoVar> & get_mutable_snow_pack() { return snow_pack; }
        void set_snow_pack(const std::map<std::string, AlbedoVar> & value) { this->snow_pack = value; }

        const std::map<std::string, CanopyFracRadDiffuse> & get_soilevaporation() const { return soilevaporation; }
        std::map<std::string, CanopyFracRadDiffuse> & get_mutable_soilevaporation() { return soilevaporation; }
        void set_soilevaporation(const std::map<std::string, CanopyFracRadDiffuse> & value) { this->soilevaporation = value; }
    };

    class FluffyModelStructure {
        public:
        FluffyModelStructure() = default;
        virtual ~FluffyModelStructure() = default;

        private:
        AlbedoVar timestep;

        public:
        const AlbedoVar & get_timestep() const { return timestep; }
        AlbedoVar & get_mutable_timestep() { return timestep; }
        void set_timestep(const AlbedoVar & value) { this->timestep = value; }
    };

    class AuxiliaryModelStructure {
        public:
        AuxiliaryModelStructure() = default;
        virtual ~AuxiliaryModelStructure() = default;

        private:
        FluffyModelStructure model_structure;

        public:
        const FluffyModelStructure & get_model_structure() const { return model_structure; }
        FluffyModelStructure & get_mutable_model_structure() { return model_structure; }
        void set_model_structure(const FluffyModelStructure & value) { this->model_structure = value; }
    };

    class FluffyExternalNinputs {
        public:
        FluffyExternalNinputs() = default;
        virtual ~FluffyExternalNinputs() = default;

        private:
        CanopyFracRadDiffuse n_irrig_appl_rate;
        CanopyFracRadDiffuse total_deposition_n_leaf;

        public:
        const CanopyFracRadDiffuse & get_n_irrig_appl_rate() const { return n_irrig_appl_rate; }
        CanopyFracRadDiffuse & get_mutable_n_irrig_appl_rate() { return n_irrig_appl_rate; }
        void set_n_irrig_appl_rate(const CanopyFracRadDiffuse & value) { this->n_irrig_appl_rate = value; }

        const CanopyFracRadDiffuse & get_total_deposition_n_leaf() const { return total_deposition_n_leaf; }
        CanopyFracRadDiffuse & get_mutable_total_deposition_n_leaf() { return total_deposition_n_leaf; }
        void set_total_deposition_n_leaf(const CanopyFracRadDiffuse & value) { this->total_deposition_n_leaf = value; }
    };

    class AuxiliaryNitrogenandCarbon {
        public:
        AuxiliaryNitrogenandCarbon() = default;
        virtual ~AuxiliaryNitrogenandCarbon() = default;

        private:
        FluffyExternalNinputs external_ninputs;
        std::map<std::string, AlbedoVar> plant_growth;

        public:
        const FluffyExternalNinputs & get_external_ninputs() const { return external_ninputs; }
        FluffyExternalNinputs & get_mutable_external_ninputs() { return external_ninputs; }
        void set_external_ninputs(const FluffyExternalNinputs & value) { this->external_ninputs = value; }

        const std::map<std::string, AlbedoVar> & get_plant_growth() const { return plant_growth; }
        std::map<std::string, AlbedoVar> & get_mutable_plant_growth() { return plant_growth; }
        void set_plant_growth(const std::map<std::string, AlbedoVar> & value) { this->plant_growth = value; }
    };

    class PurpleSoilmineralPProcesses {
        public:
        PurpleSoilmineralPProcesses() = default;
        virtual ~PurpleSoilmineralPProcesses() = default;

        private:
        CanopyFracRadDiffuse p_conc_po4_drainage;
        CanopyFracRadDiffuse p_tot_phosphate_soil;
        CanopyFracRadDiffuse p_tot_po4_drainage;
        CanopyFracRadDiffuse p_tot_po4_plant_uptake;
        CanopyFracRadDiffuse p_tot_solid_pminerals;
        CanopyFracRadDiffuse p_tot_weathering_soil;
        CanopyFracRadDiffuse tot_min_p_drainage_conc;

        public:
        const CanopyFracRadDiffuse & get_p_conc_po4_drainage() const { return p_conc_po4_drainage; }
        CanopyFracRadDiffuse & get_mutable_p_conc_po4_drainage() { return p_conc_po4_drainage; }
        void set_p_conc_po4_drainage(const CanopyFracRadDiffuse & value) { this->p_conc_po4_drainage = value; }

        const CanopyFracRadDiffuse & get_p_tot_phosphate_soil() const { return p_tot_phosphate_soil; }
        CanopyFracRadDiffuse & get_mutable_p_tot_phosphate_soil() { return p_tot_phosphate_soil; }
        void set_p_tot_phosphate_soil(const CanopyFracRadDiffuse & value) { this->p_tot_phosphate_soil = value; }

        const CanopyFracRadDiffuse & get_p_tot_po4_drainage() const { return p_tot_po4_drainage; }
        CanopyFracRadDiffuse & get_mutable_p_tot_po4_drainage() { return p_tot_po4_drainage; }
        void set_p_tot_po4_drainage(const CanopyFracRadDiffuse & value) { this->p_tot_po4_drainage = value; }

        const CanopyFracRadDiffuse & get_p_tot_po4_plant_uptake() const { return p_tot_po4_plant_uptake; }
        CanopyFracRadDiffuse & get_mutable_p_tot_po4_plant_uptake() { return p_tot_po4_plant_uptake; }
        void set_p_tot_po4_plant_uptake(const CanopyFracRadDiffuse & value) { this->p_tot_po4_plant_uptake = value; }

        const CanopyFracRadDiffuse & get_p_tot_solid_pminerals() const { return p_tot_solid_pminerals; }
        CanopyFracRadDiffuse & get_mutable_p_tot_solid_pminerals() { return p_tot_solid_pminerals; }
        void set_p_tot_solid_pminerals(const CanopyFracRadDiffuse & value) { this->p_tot_solid_pminerals = value; }

        const CanopyFracRadDiffuse & get_p_tot_weathering_soil() const { return p_tot_weathering_soil; }
        CanopyFracRadDiffuse & get_mutable_p_tot_weathering_soil() { return p_tot_weathering_soil; }
        void set_p_tot_weathering_soil(const CanopyFracRadDiffuse & value) { this->p_tot_weathering_soil = value; }

        const CanopyFracRadDiffuse & get_tot_min_p_drainage_conc() const { return tot_min_p_drainage_conc; }
        CanopyFracRadDiffuse & get_mutable_tot_min_p_drainage_conc() { return tot_min_p_drainage_conc; }
        void set_tot_min_p_drainage_conc(const CanopyFracRadDiffuse & value) { this->tot_min_p_drainage_conc = value; }
    };

    class AuxiliaryNitrogenandCarbonBelowGround {
        public:
        AuxiliaryNitrogenandCarbonBelowGround() = default;
        virtual ~AuxiliaryNitrogenandCarbonBelowGround() = default;

        private:
        std::map<std::string, CanopyFracRadDiffuse> gasprocesses;
        std::map<std::string, AlbedoVar> soilmineral_nprocesses;
        PurpleSoilmineralPProcesses soilmineral_p_processes;
        std::map<std::string, AlbedoVar> soilorganicprocesses;

        public:
        const std::map<std::string, CanopyFracRadDiffuse> & get_gasprocesses() const { return gasprocesses; }
        std::map<std::string, CanopyFracRadDiffuse> & get_mutable_gasprocesses() { return gasprocesses; }
        void set_gasprocesses(const std::map<std::string, CanopyFracRadDiffuse> & value) { this->gasprocesses = value; }

        const std::map<std::string, AlbedoVar> & get_soilmineral_nprocesses() const { return soilmineral_nprocesses; }
        std::map<std::string, AlbedoVar> & get_mutable_soilmineral_nprocesses() { return soilmineral_nprocesses; }
        void set_soilmineral_nprocesses(const std::map<std::string, AlbedoVar> & value) { this->soilmineral_nprocesses = value; }

        const PurpleSoilmineralPProcesses & get_soilmineral_p_processes() const { return soilmineral_p_processes; }
        PurpleSoilmineralPProcesses & get_mutable_soilmineral_p_processes() { return soilmineral_p_processes; }
        void set_soilmineral_p_processes(const PurpleSoilmineralPProcesses & value) { this->soilmineral_p_processes = value; }

        const std::map<std::string, AlbedoVar> & get_soilorganicprocesses() const { return soilorganicprocesses; }
        std::map<std::string, AlbedoVar> & get_mutable_soilorganicprocesses() { return soilorganicprocesses; }
        void set_soilorganicprocesses(const std::map<std::string, AlbedoVar> & value) { this->soilorganicprocesses = value; }
    };

    class FluffyInterception {
        public:
        FluffyInterception() = default;
        virtual ~FluffyInterception() = default;

        private:
        CanopyFracRadDiffuse intercepted_water_th_q;
        CanopyFracRadDiffuse interception_act_eva;
        CanopyFracRadDiffuse interception_capacity;
        CanopyFracRadDiffuse interception_pot_eva;
        CanopyFracRadDiffuse interception_rate;
        CanopyFracRadDiffuse interception_storage;
        CanopyFracRadDiffuse throughfall;

        public:
        const CanopyFracRadDiffuse & get_intercepted_water_th_q() const { return intercepted_water_th_q; }
        CanopyFracRadDiffuse & get_mutable_intercepted_water_th_q() { return intercepted_water_th_q; }
        void set_intercepted_water_th_q(const CanopyFracRadDiffuse & value) { this->intercepted_water_th_q = value; }

        const CanopyFracRadDiffuse & get_interception_act_eva() const { return interception_act_eva; }
        CanopyFracRadDiffuse & get_mutable_interception_act_eva() { return interception_act_eva; }
        void set_interception_act_eva(const CanopyFracRadDiffuse & value) { this->interception_act_eva = value; }

        const CanopyFracRadDiffuse & get_interception_capacity() const { return interception_capacity; }
        CanopyFracRadDiffuse & get_mutable_interception_capacity() { return interception_capacity; }
        void set_interception_capacity(const CanopyFracRadDiffuse & value) { this->interception_capacity = value; }

        const CanopyFracRadDiffuse & get_interception_pot_eva() const { return interception_pot_eva; }
        CanopyFracRadDiffuse & get_mutable_interception_pot_eva() { return interception_pot_eva; }
        void set_interception_pot_eva(const CanopyFracRadDiffuse & value) { this->interception_pot_eva = value; }

        const CanopyFracRadDiffuse & get_interception_rate() const { return interception_rate; }
        CanopyFracRadDiffuse & get_mutable_interception_rate() { return interception_rate; }
        void set_interception_rate(const CanopyFracRadDiffuse & value) { this->interception_rate = value; }

        const CanopyFracRadDiffuse & get_interception_storage() const { return interception_storage; }
        CanopyFracRadDiffuse & get_mutable_interception_storage() { return interception_storage; }
        void set_interception_storage(const CanopyFracRadDiffuse & value) { this->interception_storage = value; }

        const CanopyFracRadDiffuse & get_throughfall() const { return throughfall; }
        CanopyFracRadDiffuse & get_mutable_throughfall() { return throughfall; }
        void set_throughfall(const CanopyFracRadDiffuse & value) { this->throughfall = value; }
    };

    class FluffyPlant {
        public:
        FluffyPlant() = default;
        virtual ~FluffyPlant() = default;

        private:
        AlbedoVar leaf_area_index_sum;
        AlbedoVar root_length_total;
        AlbedoVar tot_soil_cover_fraction;
        AlbedoVar tsum_plant;

        public:
        const AlbedoVar & get_leaf_area_index_sum() const { return leaf_area_index_sum; }
        AlbedoVar & get_mutable_leaf_area_index_sum() { return leaf_area_index_sum; }
        void set_leaf_area_index_sum(const AlbedoVar & value) { this->leaf_area_index_sum = value; }

        const AlbedoVar & get_root_length_total() const { return root_length_total; }
        AlbedoVar & get_mutable_root_length_total() { return root_length_total; }
        void set_root_length_total(const AlbedoVar & value) { this->root_length_total = value; }

        const AlbedoVar & get_tot_soil_cover_fraction() const { return tot_soil_cover_fraction; }
        AlbedoVar & get_mutable_tot_soil_cover_fraction() { return tot_soil_cover_fraction; }
        void set_tot_soil_cover_fraction(const AlbedoVar & value) { this->tot_soil_cover_fraction = value; }

        const AlbedoVar & get_tsum_plant() const { return tsum_plant; }
        AlbedoVar & get_mutable_tsum_plant() { return tsum_plant; }
        void set_tsum_plant(const AlbedoVar & value) { this->tsum_plant = value; }
    };

    class PurplePotentialTranspiration {
        public:
        PurplePotentialTranspiration() = default;
        virtual ~PurplePotentialTranspiration() = default;

        private:
        CanopyFracRadDiffuse canopy_height;
        CanopyFracRadDiffuse displacement_height;
        CanopyFracRadDiffuse resist_air_mean;
        CanopyFracRadDiffuse res_surf_vegetation;
        CanopyFracRadDiffuse rough_length;

        public:
        const CanopyFracRadDiffuse & get_canopy_height() const { return canopy_height; }
        CanopyFracRadDiffuse & get_mutable_canopy_height() { return canopy_height; }
        void set_canopy_height(const CanopyFracRadDiffuse & value) { this->canopy_height = value; }

        const CanopyFracRadDiffuse & get_displacement_height() const { return displacement_height; }
        CanopyFracRadDiffuse & get_mutable_displacement_height() { return displacement_height; }
        void set_displacement_height(const CanopyFracRadDiffuse & value) { this->displacement_height = value; }

        const CanopyFracRadDiffuse & get_resist_air_mean() const { return resist_air_mean; }
        CanopyFracRadDiffuse & get_mutable_resist_air_mean() { return resist_air_mean; }
        void set_resist_air_mean(const CanopyFracRadDiffuse & value) { this->resist_air_mean = value; }

        const CanopyFracRadDiffuse & get_res_surf_vegetation() const { return res_surf_vegetation; }
        CanopyFracRadDiffuse & get_mutable_res_surf_vegetation() { return res_surf_vegetation; }
        void set_res_surf_vegetation(const CanopyFracRadDiffuse & value) { this->res_surf_vegetation = value; }

        const CanopyFracRadDiffuse & get_rough_length() const { return rough_length; }
        CanopyFracRadDiffuse & get_mutable_rough_length() { return rough_length; }
        void set_rough_length(const CanopyFracRadDiffuse & value) { this->rough_length = value; }
    };

    class FluffyWateruptake {
        public:
        FluffyWateruptake() = default;
        virtual ~FluffyWateruptake() = default;

        private:
        CanopyFracRadDiffuse pot_water_uptake;
        CanopyFracRadDiffuse red_c_totalallplant;
        CanopyFracRadDiffuse transpirationallpl;
        CanopyFracRadDiffuse water_uptake_trig_temp;

        public:
        const CanopyFracRadDiffuse & get_pot_water_uptake() const { return pot_water_uptake; }
        CanopyFracRadDiffuse & get_mutable_pot_water_uptake() { return pot_water_uptake; }
        void set_pot_water_uptake(const CanopyFracRadDiffuse & value) { this->pot_water_uptake = value; }

        const CanopyFracRadDiffuse & get_red_c_totalallplant() const { return red_c_totalallplant; }
        CanopyFracRadDiffuse & get_mutable_red_c_totalallplant() { return red_c_totalallplant; }
        void set_red_c_totalallplant(const CanopyFracRadDiffuse & value) { this->red_c_totalallplant = value; }

        const CanopyFracRadDiffuse & get_transpirationallpl() const { return transpirationallpl; }
        CanopyFracRadDiffuse & get_mutable_transpirationallpl() { return transpirationallpl; }
        void set_transpirationallpl(const CanopyFracRadDiffuse & value) { this->transpirationallpl = value; }

        const CanopyFracRadDiffuse & get_water_uptake_trig_temp() const { return water_uptake_trig_temp; }
        CanopyFracRadDiffuse & get_mutable_water_uptake_trig_temp() { return water_uptake_trig_temp; }
        void set_water_uptake_trig_temp(const CanopyFracRadDiffuse & value) { this->water_uptake_trig_temp = value; }
    };

    class AuxiliaryPlantWaterProcesses {
        public:
        AuxiliaryPlantWaterProcesses() = default;
        virtual ~AuxiliaryPlantWaterProcesses() = default;

        private:
        FluffyInterception interception;
        FluffyPlant plant;
        PurplePotentialTranspiration potential_transpiration;
        std::map<std::string, AlbedoVar> salt_tracer;
        FluffyWateruptake wateruptake;

        public:
        const FluffyInterception & get_interception() const { return interception; }
        FluffyInterception & get_mutable_interception() { return interception; }
        void set_interception(const FluffyInterception & value) { this->interception = value; }

        const FluffyPlant & get_plant() const { return plant; }
        FluffyPlant & get_mutable_plant() { return plant; }
        void set_plant(const FluffyPlant & value) { this->plant = value; }

        const PurplePotentialTranspiration & get_potential_transpiration() const { return potential_transpiration; }
        PurplePotentialTranspiration & get_mutable_potential_transpiration() { return potential_transpiration; }
        void set_potential_transpiration(const PurplePotentialTranspiration & value) { this->potential_transpiration = value; }

        const std::map<std::string, AlbedoVar> & get_salt_tracer() const { return salt_tracer; }
        std::map<std::string, AlbedoVar> & get_mutable_salt_tracer() { return salt_tracer; }
        void set_salt_tracer(const std::map<std::string, AlbedoVar> & value) { this->salt_tracer = value; }

        const FluffyWateruptake & get_wateruptake() const { return wateruptake; }
        FluffyWateruptake & get_mutable_wateruptake() { return wateruptake; }
        void set_wateruptake(const FluffyWateruptake & value) { this->wateruptake = value; }
    };

    class PurpleSoilfrost {
        public:
        PurpleSoilfrost() = default;
        virtual ~PurpleSoilfrost() = default;

        private:
        AlbedoVar frost_lower_boundary1;
        AlbedoVar frost_lower_boundary2;
        AlbedoVar frost_upper_boundary1;
        AlbedoVar frost_upper_boundary2;
        AlbedoVar swelling;

        public:
        const AlbedoVar & get_frost_lower_boundary1() const { return frost_lower_boundary1; }
        AlbedoVar & get_mutable_frost_lower_boundary1() { return frost_lower_boundary1; }
        void set_frost_lower_boundary1(const AlbedoVar & value) { this->frost_lower_boundary1 = value; }

        const AlbedoVar & get_frost_lower_boundary2() const { return frost_lower_boundary2; }
        AlbedoVar & get_mutable_frost_lower_boundary2() { return frost_lower_boundary2; }
        void set_frost_lower_boundary2(const AlbedoVar & value) { this->frost_lower_boundary2 = value; }

        const AlbedoVar & get_frost_upper_boundary1() const { return frost_upper_boundary1; }
        AlbedoVar & get_mutable_frost_upper_boundary1() { return frost_upper_boundary1; }
        void set_frost_upper_boundary1(const AlbedoVar & value) { this->frost_upper_boundary1 = value; }

        const AlbedoVar & get_frost_upper_boundary2() const { return frost_upper_boundary2; }
        AlbedoVar & get_mutable_frost_upper_boundary2() { return frost_upper_boundary2; }
        void set_frost_upper_boundary2(const AlbedoVar & value) { this->frost_upper_boundary2 = value; }

        const AlbedoVar & get_swelling() const { return swelling; }
        AlbedoVar & get_mutable_swelling() { return swelling; }
        void set_swelling(const AlbedoVar & value) { this->swelling = value; }
    };

    class PurpleSoilheatflows {
        public:
        PurpleSoilheatflows() = default;
        virtual ~PurpleSoilheatflows() = default;

        private:
        CanopyFracRadDiffuse heat_box_enhancer;
        CanopyFracRadDiffuse temp_sewage;
        CanopyFracRadDiffuse temp_soil_surf;

        public:
        const CanopyFracRadDiffuse & get_heat_box_enhancer() const { return heat_box_enhancer; }
        CanopyFracRadDiffuse & get_mutable_heat_box_enhancer() { return heat_box_enhancer; }
        void set_heat_box_enhancer(const CanopyFracRadDiffuse & value) { this->heat_box_enhancer = value; }

        const CanopyFracRadDiffuse & get_temp_sewage() const { return temp_sewage; }
        CanopyFracRadDiffuse & get_mutable_temp_sewage() { return temp_sewage; }
        void set_temp_sewage(const CanopyFracRadDiffuse & value) { this->temp_sewage = value; }

        const CanopyFracRadDiffuse & get_temp_soil_surf() const { return temp_soil_surf; }
        CanopyFracRadDiffuse & get_mutable_temp_soil_surf() { return temp_soil_surf; }
        void set_temp_soil_surf(const CanopyFracRadDiffuse & value) { this->temp_soil_surf = value; }
    };

    class AuxiliarySoilHeatProcesses {
        public:
        AuxiliarySoilHeatProcesses() = default;
        virtual ~AuxiliarySoilHeatProcesses() = default;

        private:
        PurpleSoilfrost soilfrost;
        PurpleSoilheatflows soilheatflows;

        public:
        const PurpleSoilfrost & get_soilfrost() const { return soilfrost; }
        PurpleSoilfrost & get_mutable_soilfrost() { return soilfrost; }
        void set_soilfrost(const PurpleSoilfrost & value) { this->soilfrost = value; }

        const PurpleSoilheatflows & get_soilheatflows() const { return soilheatflows; }
        PurpleSoilheatflows & get_mutable_soilheatflows() { return soilheatflows; }
        void set_soilheatflows(const PurpleSoilheatflows & value) { this->soilheatflows = value; }
    };

    class TentacledDrainageanddeeppercolation {
        public:
        TentacledDrainageanddeeppercolation() = default;
        virtual ~TentacledDrainageanddeeppercolation() = default;

        private:
        AlbedoVar saturation_level;

        public:
        const AlbedoVar & get_saturation_level() const { return saturation_level; }
        AlbedoVar & get_mutable_saturation_level() { return saturation_level; }
        void set_saturation_level(const AlbedoVar & value) { this->saturation_level = value; }
    };

    class PurpleSoilwaterflows {
        public:
        PurpleSoilwaterflows() = default;
        virtual ~PurpleSoilwaterflows() = default;

        private:
        CanopyFracRadDiffuse tot_mean_transit_time;

        public:
        const CanopyFracRadDiffuse & get_tot_mean_transit_time() const { return tot_mean_transit_time; }
        CanopyFracRadDiffuse & get_mutable_tot_mean_transit_time() { return tot_mean_transit_time; }
        void set_tot_mean_transit_time(const CanopyFracRadDiffuse & value) { this->tot_mean_transit_time = value; }
    };

    class FluffySurfacewater {
        public:
        FluffySurfacewater() = default;
        virtual ~FluffySurfacewater() = default;

        private:
        AlbedoVar spool_cover;

        public:
        const AlbedoVar & get_spool_cover() const { return spool_cover; }
        AlbedoVar & get_mutable_spool_cover() { return spool_cover; }
        void set_spool_cover(const AlbedoVar & value) { this->spool_cover = value; }
    };

    class AuxiliarySoilWaterProcesses {
        public:
        AuxiliarySoilWaterProcesses() = default;
        virtual ~AuxiliarySoilWaterProcesses() = default;

        private:
        TentacledDrainageanddeeppercolation drainageanddeeppercolation;
        PurpleSoilwaterflows soilwaterflows;
        FluffySurfacewater surfacewater;

        public:
        const TentacledDrainageanddeeppercolation & get_drainageanddeeppercolation() const { return drainageanddeeppercolation; }
        TentacledDrainageanddeeppercolation & get_mutable_drainageanddeeppercolation() { return drainageanddeeppercolation; }
        void set_drainageanddeeppercolation(const TentacledDrainageanddeeppercolation & value) { this->drainageanddeeppercolation = value; }

        const PurpleSoilwaterflows & get_soilwaterflows() const { return soilwaterflows; }
        PurpleSoilwaterflows & get_mutable_soilwaterflows() { return soilwaterflows; }
        void set_soilwaterflows(const PurpleSoilwaterflows & value) { this->soilwaterflows = value; }

        const FluffySurfacewater & get_surfacewater() const { return surfacewater; }
        FluffySurfacewater & get_mutable_surfacewater() { return surfacewater; }
        void set_surfacewater(const FluffySurfacewater & value) { this->surfacewater = value; }
    };

    class Auxiliary {
        public:
        Auxiliary() = default;
        virtual ~Auxiliary() = default;

        private:
        AuxiliaryAtmosphericRelatedProcesses atmospheric_related_processes;
        AuxiliaryModelStructure model_structure;
        AuxiliaryNitrogenandCarbon nitrogenand_carbon;
        AuxiliaryNitrogenandCarbonBelowGround nitrogenand_carbon_below_ground;
        AuxiliaryPlantWaterProcesses plant_water_processes;
        AuxiliarySoilHeatProcesses soil_heat_processes;
        AuxiliarySoilWaterProcesses soil_water_processes;

        public:
        const AuxiliaryAtmosphericRelatedProcesses & get_atmospheric_related_processes() const { return atmospheric_related_processes; }
        AuxiliaryAtmosphericRelatedProcesses & get_mutable_atmospheric_related_processes() { return atmospheric_related_processes; }
        void set_atmospheric_related_processes(const AuxiliaryAtmosphericRelatedProcesses & value) { this->atmospheric_related_processes = value; }

        const AuxiliaryModelStructure & get_model_structure() const { return model_structure; }
        AuxiliaryModelStructure & get_mutable_model_structure() { return model_structure; }
        void set_model_structure(const AuxiliaryModelStructure & value) { this->model_structure = value; }

        const AuxiliaryNitrogenandCarbon & get_nitrogenand_carbon() const { return nitrogenand_carbon; }
        AuxiliaryNitrogenandCarbon & get_mutable_nitrogenand_carbon() { return nitrogenand_carbon; }
        void set_nitrogenand_carbon(const AuxiliaryNitrogenandCarbon & value) { this->nitrogenand_carbon = value; }

        const AuxiliaryNitrogenandCarbonBelowGround & get_nitrogenand_carbon_below_ground() const { return nitrogenand_carbon_below_ground; }
        AuxiliaryNitrogenandCarbonBelowGround & get_mutable_nitrogenand_carbon_below_ground() { return nitrogenand_carbon_below_ground; }
        void set_nitrogenand_carbon_below_ground(const AuxiliaryNitrogenandCarbonBelowGround & value) { this->nitrogenand_carbon_below_ground = value; }

        const AuxiliaryPlantWaterProcesses & get_plant_water_processes() const { return plant_water_processes; }
        AuxiliaryPlantWaterProcesses & get_mutable_plant_water_processes() { return plant_water_processes; }
        void set_plant_water_processes(const AuxiliaryPlantWaterProcesses & value) { this->plant_water_processes = value; }

        const AuxiliarySoilHeatProcesses & get_soil_heat_processes() const { return soil_heat_processes; }
        AuxiliarySoilHeatProcesses & get_mutable_soil_heat_processes() { return soil_heat_processes; }
        void set_soil_heat_processes(const AuxiliarySoilHeatProcesses & value) { this->soil_heat_processes = value; }

        const AuxiliarySoilWaterProcesses & get_soil_water_processes() const { return soil_water_processes; }
        AuxiliarySoilWaterProcesses & get_mutable_soil_water_processes() { return soil_water_processes; }
        void set_soil_water_processes(const AuxiliarySoilWaterProcesses & value) { this->soil_water_processes = value; }
    };

    enum class LaiAbovecanopyArrayName : int { EMPTY, NUMBEROF_PLANTS, NUMOF_FERT_DAYS, NUMOF_FERT_STAGES, NUMOF_FERT_YEARS, NUMOF_MANURE_DAYS };

    enum class LaiAbovecanopyCondition1 : int { EVAPORATION_1_IS_TRUE, NITROGEN_AND_CARBON_1_IS_FALSE, PLANT_TYPE_0_IS_TRUE, PLANT_TYPE_3_IS_FALSE, SALT_TRACER_0_IS_FALSE };

    class LaiAbovecanopy {
        public:
        LaiAbovecanopy() = default;
        virtual ~LaiAbovecanopy() = default;

        private:
        LaiAbovecanopyArrayName array_name;
        LaiAbovecanopyCondition1 condition_1;
        std::shared_ptr<std::string> condition_2;
        std::shared_ptr<std::string> condition_3;
        std::shared_ptr<std::string> condition_4;
        std::string out_multi_index_1;
        std::string out_single_index_1;
        std::string sizeof_array;

        public:
        const LaiAbovecanopyArrayName & get_array_name() const { return array_name; }
        LaiAbovecanopyArrayName & get_mutable_array_name() { return array_name; }
        void set_array_name(const LaiAbovecanopyArrayName & value) { this->array_name = value; }

        const LaiAbovecanopyCondition1 & get_condition_1() const { return condition_1; }
        LaiAbovecanopyCondition1 & get_mutable_condition_1() { return condition_1; }
        void set_condition_1(const LaiAbovecanopyCondition1 & value) { this->condition_1 = value; }

        std::shared_ptr<std::string> get_condition_2() const { return condition_2; }
        void set_condition_2(std::shared_ptr<std::string> value) { this->condition_2 = value; }

        std::shared_ptr<std::string> get_condition_3() const { return condition_3; }
        void set_condition_3(std::shared_ptr<std::string> value) { this->condition_3 = value; }

        std::shared_ptr<std::string> get_condition_4() const { return condition_4; }
        void set_condition_4(std::shared_ptr<std::string> value) { this->condition_4 = value; }

        const std::string & get_out_multi_index_1() const { return out_multi_index_1; }
        std::string & get_mutable_out_multi_index_1() { return out_multi_index_1; }
        void set_out_multi_index_1(const std::string & value) { this->out_multi_index_1 = value; }

        const std::string & get_out_single_index_1() const { return out_single_index_1; }
        std::string & get_mutable_out_single_index_1() { return out_single_index_1; }
        void set_out_single_index_1(const std::string & value) { this->out_single_index_1 = value; }

        const std::string & get_sizeof_array() const { return sizeof_array; }
        std::string & get_mutable_sizeof_array() { return sizeof_array; }
        void set_sizeof_array(const std::string & value) { this->sizeof_array = value; }
    };

    class TentacledRadiationproperties {
        public:
        TentacledRadiationproperties() = default;
        virtual ~TentacledRadiationproperties() = default;

        private:
        LaiAbovecanopy lai_abovecanopy;
        LaiAbovecanopy mc_temp_canopy;
        LaiAbovecanopy netradiation_canopy;

        public:
        const LaiAbovecanopy & get_lai_abovecanopy() const { return lai_abovecanopy; }
        LaiAbovecanopy & get_mutable_lai_abovecanopy() { return lai_abovecanopy; }
        void set_lai_abovecanopy(const LaiAbovecanopy & value) { this->lai_abovecanopy = value; }

        const LaiAbovecanopy & get_mc_temp_canopy() const { return mc_temp_canopy; }
        LaiAbovecanopy & get_mutable_mc_temp_canopy() { return mc_temp_canopy; }
        void set_mc_temp_canopy(const LaiAbovecanopy & value) { this->mc_temp_canopy = value; }

        const LaiAbovecanopy & get_netradiation_canopy() const { return netradiation_canopy; }
        LaiAbovecanopy & get_mutable_netradiation_canopy() { return netradiation_canopy; }
        void set_netradiation_canopy(const LaiAbovecanopy & value) { this->netradiation_canopy = value; }
    };

    class SnowReduceLaiFactor {
        public:
        SnowReduceLaiFactor() = default;
        virtual ~SnowReduceLaiFactor() = default;

        private:
        LaiAbovecanopyArrayName array_name;
        Condition3Enum condition_1;
        std::shared_ptr<Condition2Enum> condition_2;
        std::shared_ptr<std::string> condition_3;
        std::shared_ptr<std::string> condition_4;
        std::shared_ptr<Condition3Enum> condition_5;
        std::string out_multi_index_1;
        std::string out_single_index_1;
        std::string sizeof_array;

        public:
        const LaiAbovecanopyArrayName & get_array_name() const { return array_name; }
        LaiAbovecanopyArrayName & get_mutable_array_name() { return array_name; }
        void set_array_name(const LaiAbovecanopyArrayName & value) { this->array_name = value; }

        const Condition3Enum & get_condition_1() const { return condition_1; }
        Condition3Enum & get_mutable_condition_1() { return condition_1; }
        void set_condition_1(const Condition3Enum & value) { this->condition_1 = value; }

        std::shared_ptr<Condition2Enum> get_condition_2() const { return condition_2; }
        void set_condition_2(std::shared_ptr<Condition2Enum> value) { this->condition_2 = value; }

        std::shared_ptr<std::string> get_condition_3() const { return condition_3; }
        void set_condition_3(std::shared_ptr<std::string> value) { this->condition_3 = value; }

        std::shared_ptr<std::string> get_condition_4() const { return condition_4; }
        void set_condition_4(std::shared_ptr<std::string> value) { this->condition_4 = value; }

        std::shared_ptr<Condition3Enum> get_condition_5() const { return condition_5; }
        void set_condition_5(std::shared_ptr<Condition3Enum> value) { this->condition_5 = value; }

        const std::string & get_out_multi_index_1() const { return out_multi_index_1; }
        std::string & get_mutable_out_multi_index_1() { return out_multi_index_1; }
        void set_out_multi_index_1(const std::string & value) { this->out_multi_index_1 = value; }

        const std::string & get_out_single_index_1() const { return out_single_index_1; }
        std::string & get_mutable_out_single_index_1() { return out_single_index_1; }
        void set_out_single_index_1(const std::string & value) { this->out_single_index_1 = value; }

        const std::string & get_sizeof_array() const { return sizeof_array; }
        std::string & get_mutable_sizeof_array() { return sizeof_array; }
        void set_sizeof_array(const std::string & value) { this->sizeof_array = value; }
    };

    class PurpleSnowPack {
        public:
        PurpleSnowPack() = default;
        virtual ~PurpleSnowPack() = default;

        private:
        SnowReduceLaiFactor snow_reduce_lai_factor;

        public:
        const SnowReduceLaiFactor & get_snow_reduce_lai_factor() const { return snow_reduce_lai_factor; }
        SnowReduceLaiFactor & get_mutable_snow_reduce_lai_factor() { return snow_reduce_lai_factor; }
        void set_snow_reduce_lai_factor(const SnowReduceLaiFactor & value) { this->snow_reduce_lai_factor = value; }
    };

    class AuxiliaryArraysAtmosphericRelatedProcesses {
        public:
        AuxiliaryArraysAtmosphericRelatedProcesses() = default;
        virtual ~AuxiliaryArraysAtmosphericRelatedProcesses() = default;

        private:
        TentacledRadiationproperties radiationproperties;
        PurpleSnowPack snow_pack;

        public:
        const TentacledRadiationproperties & get_radiationproperties() const { return radiationproperties; }
        TentacledRadiationproperties & get_mutable_radiationproperties() { return radiationproperties; }
        void set_radiationproperties(const TentacledRadiationproperties & value) { this->radiationproperties = value; }

        const PurpleSnowPack & get_snow_pack() const { return snow_pack; }
        PurpleSnowPack & get_mutable_snow_pack() { return snow_pack; }
        void set_snow_pack(const PurpleSnowPack & value) { this->snow_pack = value; }
    };

    enum class CCoarseRootsAtmLayerArrayName : int { NUMBEROF_LAYERS };

    class CCoarseRootsAtmLayer {
        public:
        CCoarseRootsAtmLayer() = default;
        virtual ~CCoarseRootsAtmLayer() = default;

        private:
        CCoarseRootsAtmLayerArrayName array_name;
        Condition3Enum condition_1;
        std::shared_ptr<std::string> condition_2;
        std::shared_ptr<std::string> condition_3;
        std::shared_ptr<std::string> condition_4;
        std::string out_multi_index_1;
        std::string out_multi_index_2;
        std::string out_multi_index_3;
        std::string out_multi_index_4;
        std::string out_multi_index_5;
        std::string out_multi_index_6;
        std::string out_multi_index_7;
        std::string out_multi_index_8;
        std::string out_single_index_1;
        std::string out_single_index_2;
        std::string out_single_index_3;
        std::string out_single_index_4;
        std::string out_single_index_5;
        std::string out_single_index_6;
        std::string out_single_index_7;
        std::string out_single_index_8;
        std::string sizeof_array;

        public:
        const CCoarseRootsAtmLayerArrayName & get_array_name() const { return array_name; }
        CCoarseRootsAtmLayerArrayName & get_mutable_array_name() { return array_name; }
        void set_array_name(const CCoarseRootsAtmLayerArrayName & value) { this->array_name = value; }

        const Condition3Enum & get_condition_1() const { return condition_1; }
        Condition3Enum & get_mutable_condition_1() { return condition_1; }
        void set_condition_1(const Condition3Enum & value) { this->condition_1 = value; }

        std::shared_ptr<std::string> get_condition_2() const { return condition_2; }
        void set_condition_2(std::shared_ptr<std::string> value) { this->condition_2 = value; }

        std::shared_ptr<std::string> get_condition_3() const { return condition_3; }
        void set_condition_3(std::shared_ptr<std::string> value) { this->condition_3 = value; }

        std::shared_ptr<std::string> get_condition_4() const { return condition_4; }
        void set_condition_4(std::shared_ptr<std::string> value) { this->condition_4 = value; }

        const std::string & get_out_multi_index_1() const { return out_multi_index_1; }
        std::string & get_mutable_out_multi_index_1() { return out_multi_index_1; }
        void set_out_multi_index_1(const std::string & value) { this->out_multi_index_1 = value; }

        const std::string & get_out_multi_index_2() const { return out_multi_index_2; }
        std::string & get_mutable_out_multi_index_2() { return out_multi_index_2; }
        void set_out_multi_index_2(const std::string & value) { this->out_multi_index_2 = value; }

        const std::string & get_out_multi_index_3() const { return out_multi_index_3; }
        std::string & get_mutable_out_multi_index_3() { return out_multi_index_3; }
        void set_out_multi_index_3(const std::string & value) { this->out_multi_index_3 = value; }

        const std::string & get_out_multi_index_4() const { return out_multi_index_4; }
        std::string & get_mutable_out_multi_index_4() { return out_multi_index_4; }
        void set_out_multi_index_4(const std::string & value) { this->out_multi_index_4 = value; }

        const std::string & get_out_multi_index_5() const { return out_multi_index_5; }
        std::string & get_mutable_out_multi_index_5() { return out_multi_index_5; }
        void set_out_multi_index_5(const std::string & value) { this->out_multi_index_5 = value; }

        const std::string & get_out_multi_index_6() const { return out_multi_index_6; }
        std::string & get_mutable_out_multi_index_6() { return out_multi_index_6; }
        void set_out_multi_index_6(const std::string & value) { this->out_multi_index_6 = value; }

        const std::string & get_out_multi_index_7() const { return out_multi_index_7; }
        std::string & get_mutable_out_multi_index_7() { return out_multi_index_7; }
        void set_out_multi_index_7(const std::string & value) { this->out_multi_index_7 = value; }

        const std::string & get_out_multi_index_8() const { return out_multi_index_8; }
        std::string & get_mutable_out_multi_index_8() { return out_multi_index_8; }
        void set_out_multi_index_8(const std::string & value) { this->out_multi_index_8 = value; }

        const std::string & get_out_single_index_1() const { return out_single_index_1; }
        std::string & get_mutable_out_single_index_1() { return out_single_index_1; }
        void set_out_single_index_1(const std::string & value) { this->out_single_index_1 = value; }

        const std::string & get_out_single_index_2() const { return out_single_index_2; }
        std::string & get_mutable_out_single_index_2() { return out_single_index_2; }
        void set_out_single_index_2(const std::string & value) { this->out_single_index_2 = value; }

        const std::string & get_out_single_index_3() const { return out_single_index_3; }
        std::string & get_mutable_out_single_index_3() { return out_single_index_3; }
        void set_out_single_index_3(const std::string & value) { this->out_single_index_3 = value; }

        const std::string & get_out_single_index_4() const { return out_single_index_4; }
        std::string & get_mutable_out_single_index_4() { return out_single_index_4; }
        void set_out_single_index_4(const std::string & value) { this->out_single_index_4 = value; }

        const std::string & get_out_single_index_5() const { return out_single_index_5; }
        std::string & get_mutable_out_single_index_5() { return out_single_index_5; }
        void set_out_single_index_5(const std::string & value) { this->out_single_index_5 = value; }

        const std::string & get_out_single_index_6() const { return out_single_index_6; }
        std::string & get_mutable_out_single_index_6() { return out_single_index_6; }
        void set_out_single_index_6(const std::string & value) { this->out_single_index_6 = value; }

        const std::string & get_out_single_index_7() const { return out_single_index_7; }
        std::string & get_mutable_out_single_index_7() { return out_single_index_7; }
        void set_out_single_index_7(const std::string & value) { this->out_single_index_7 = value; }

        const std::string & get_out_single_index_8() const { return out_single_index_8; }
        std::string & get_mutable_out_single_index_8() { return out_single_index_8; }
        void set_out_single_index_8(const std::string & value) { this->out_single_index_8 = value; }

        const std::string & get_sizeof_array() const { return sizeof_array; }
        std::string & get_mutable_sizeof_array() { return sizeof_array; }
        void set_sizeof_array(const std::string & value) { this->sizeof_array = value; }
    };

    class FluffyPlantGrowth {
        public:
        FluffyPlantGrowth() = default;
        virtual ~FluffyPlantGrowth() = default;

        private:
        LaiAbovecanopy annual_change_c_plant;
        LaiAbovecanopy c_acc_npp_coarse_root;
        LaiAbovecanopy c_acc_npp_leaf;
        LaiAbovecanopy c_acc_npp_plant;
        LaiAbovecanopy c_acc_npp_root;
        LaiAbovecanopy c_acc_npp_stem;
        CCoarseRootsAtmLayer c_coarse_roots_atm_layer;
        CCoarseRootsAtmLayer c_fungi_atmlayer;
        SnowReduceLaiFactor c_mobile_plant_flux;
        SnowReduceLaiFactor cnpp_coarse_root;
        SnowReduceLaiFactor cnpp_leaf;
        SnowReduceLaiFactor cnpp_plant;
        SnowReduceLaiFactor cnpp_root;
        SnowReduceLaiFactor cnpp_stem;
        SnowReduceLaiFactor cn_ratio_coarse_roots;
        SnowReduceLaiFactor cn_ratio_fungi;
        SnowReduceLaiFactor cn_ratio_grain;
        SnowReduceLaiFactor cn_ratio_leaf;
        SnowReduceLaiFactor cn_ratio_roots;
        SnowReduceLaiFactor cn_ratio_stem;
        SnowReduceLaiFactor c_plant;
        SnowReduceLaiFactor c_plant_above_g;
        SnowReduceLaiFactor c_plant_litter_fall;
        SnowReduceLaiFactor c_plant_resp;
        SnowReduceLaiFactor c_plant_resp_above_g;
        SnowReduceLaiFactor cp_ratio_coarse_roots;
        SnowReduceLaiFactor cp_ratio_fungi;
        SnowReduceLaiFactor cp_ratio_grain;
        SnowReduceLaiFactor cp_ratio_leaf;
        SnowReduceLaiFactor cp_ratio_roots;
        SnowReduceLaiFactor cp_ratio_stem;
        SnowReduceLaiFactor c_roots;
        CCoarseRootsAtmLayer c_roots_atm_layer;
        SnowReduceLaiFactor c_total_leaf;
        SnowReduceLaiFactor dorming_temp_sum;
        SnowReduceLaiFactor fact_cn_fungi;
        SnowReduceLaiFactor fact_cp_fungi;
        SnowReduceLaiFactor fact_navail_fungi;
        SnowReduceLaiFactor fact_ndemand_fungi;
        SnowReduceLaiFactor fact_nsupply_fungi;
        SnowReduceLaiFactor fact_pavail_fungi;
        SnowReduceLaiFactor fact_pdemand_fungi;
        SnowReduceLaiFactor fact_psupply_fungi;
        SnowReduceLaiFactor fungi_ammoniauptpot;
        SnowReduceLaiFactor fungi_nitrateuptpot;
        SnowReduceLaiFactor fungi_organic_nuptpot;
        SnowReduceLaiFactor fungi_organic_puptpot;
        SnowReduceLaiFactor fungi_phosphateuptpot;
        SnowReduceLaiFactor fungi_root_cover;
        SnowReduceLaiFactor growth_temp_sum;
        SnowReduceLaiFactor n_fungi_available;
        SnowReduceLaiFactor n_fungi_demand;
        SnowReduceLaiFactor n_mobile_plant_flux;
        SnowReduceLaiFactor n_plant;
        SnowReduceLaiFactor n_plant_above_g;
        SnowReduceLaiFactor n_plant_demand;
        SnowReduceLaiFactor n_plant_litter_fall;
        SnowReduceLaiFactor n_plant_org_uptake;
        SnowReduceLaiFactor n_plant_soil_demand;
        SnowReduceLaiFactor n_roots;
        SnowReduceLaiFactor n_total_leaf;
        SnowReduceLaiFactor n_uptake_deficit1;
        SnowReduceLaiFactor n_uptake_deficit2;
        SnowReduceLaiFactor n_upt_fungi_deficit1;
        SnowReduceLaiFactor n_upt_fungi_deficit2;
        SnowReduceLaiFactor pco2_stomata;
        SnowReduceLaiFactor pco2_surface;
        SnowReduceLaiFactor p_fungi_available;
        SnowReduceLaiFactor p_fungi_demand;
        SnowReduceLaiFactor p_light;
        SnowReduceLaiFactor p_mobile_plant_flux;
        SnowReduceLaiFactor p_plant;
        SnowReduceLaiFactor p_plant_above_g;
        SnowReduceLaiFactor p_plant_demand;
        SnowReduceLaiFactor p_plant_litter_fall;
        SnowReduceLaiFactor p_plant_org_uptake;
        SnowReduceLaiFactor p_plant_soil_demand;
        SnowReduceLaiFactor p_roots;
        SnowReduceLaiFactor p_rubisco;
        SnowReduceLaiFactor p_sink;
        SnowReduceLaiFactor p_total_leaf;
        SnowReduceLaiFactor p_uptake_deficit1;
        SnowReduceLaiFactor p_uptake_deficit2;
        SnowReduceLaiFactor p_upt_fungi_deficit1;
        SnowReduceLaiFactor p_upt_fungi_deficit2;
        SnowReduceLaiFactor radiationadsorbed;
        SnowReduceLaiFactor response_light;
        SnowReduceLaiFactor response_n;
        SnowReduceLaiFactor response_n_water;
        SnowReduceLaiFactor response_phosphorus;
        SnowReduceLaiFactor response_salt;
        SnowReduceLaiFactor response_temp;
        SnowReduceLaiFactor response_water;
        SnowReduceLaiFactor sim_plant_year_age;
        SnowReduceLaiFactor zadok_day_num_shift;
        SnowReduceLaiFactor zadok_index;

        public:
        const LaiAbovecanopy & get_annual_change_c_plant() const { return annual_change_c_plant; }
        LaiAbovecanopy & get_mutable_annual_change_c_plant() { return annual_change_c_plant; }
        void set_annual_change_c_plant(const LaiAbovecanopy & value) { this->annual_change_c_plant = value; }

        const LaiAbovecanopy & get_c_acc_npp_coarse_root() const { return c_acc_npp_coarse_root; }
        LaiAbovecanopy & get_mutable_c_acc_npp_coarse_root() { return c_acc_npp_coarse_root; }
        void set_c_acc_npp_coarse_root(const LaiAbovecanopy & value) { this->c_acc_npp_coarse_root = value; }

        const LaiAbovecanopy & get_c_acc_npp_leaf() const { return c_acc_npp_leaf; }
        LaiAbovecanopy & get_mutable_c_acc_npp_leaf() { return c_acc_npp_leaf; }
        void set_c_acc_npp_leaf(const LaiAbovecanopy & value) { this->c_acc_npp_leaf = value; }

        const LaiAbovecanopy & get_c_acc_npp_plant() const { return c_acc_npp_plant; }
        LaiAbovecanopy & get_mutable_c_acc_npp_plant() { return c_acc_npp_plant; }
        void set_c_acc_npp_plant(const LaiAbovecanopy & value) { this->c_acc_npp_plant = value; }

        const LaiAbovecanopy & get_c_acc_npp_root() const { return c_acc_npp_root; }
        LaiAbovecanopy & get_mutable_c_acc_npp_root() { return c_acc_npp_root; }
        void set_c_acc_npp_root(const LaiAbovecanopy & value) { this->c_acc_npp_root = value; }

        const LaiAbovecanopy & get_c_acc_npp_stem() const { return c_acc_npp_stem; }
        LaiAbovecanopy & get_mutable_c_acc_npp_stem() { return c_acc_npp_stem; }
        void set_c_acc_npp_stem(const LaiAbovecanopy & value) { this->c_acc_npp_stem = value; }

        const CCoarseRootsAtmLayer & get_c_coarse_roots_atm_layer() const { return c_coarse_roots_atm_layer; }
        CCoarseRootsAtmLayer & get_mutable_c_coarse_roots_atm_layer() { return c_coarse_roots_atm_layer; }
        void set_c_coarse_roots_atm_layer(const CCoarseRootsAtmLayer & value) { this->c_coarse_roots_atm_layer = value; }

        const CCoarseRootsAtmLayer & get_c_fungi_atmlayer() const { return c_fungi_atmlayer; }
        CCoarseRootsAtmLayer & get_mutable_c_fungi_atmlayer() { return c_fungi_atmlayer; }
        void set_c_fungi_atmlayer(const CCoarseRootsAtmLayer & value) { this->c_fungi_atmlayer = value; }

        const SnowReduceLaiFactor & get_c_mobile_plant_flux() const { return c_mobile_plant_flux; }
        SnowReduceLaiFactor & get_mutable_c_mobile_plant_flux() { return c_mobile_plant_flux; }
        void set_c_mobile_plant_flux(const SnowReduceLaiFactor & value) { this->c_mobile_plant_flux = value; }

        const SnowReduceLaiFactor & get_cnpp_coarse_root() const { return cnpp_coarse_root; }
        SnowReduceLaiFactor & get_mutable_cnpp_coarse_root() { return cnpp_coarse_root; }
        void set_cnpp_coarse_root(const SnowReduceLaiFactor & value) { this->cnpp_coarse_root = value; }

        const SnowReduceLaiFactor & get_cnpp_leaf() const { return cnpp_leaf; }
        SnowReduceLaiFactor & get_mutable_cnpp_leaf() { return cnpp_leaf; }
        void set_cnpp_leaf(const SnowReduceLaiFactor & value) { this->cnpp_leaf = value; }

        const SnowReduceLaiFactor & get_cnpp_plant() const { return cnpp_plant; }
        SnowReduceLaiFactor & get_mutable_cnpp_plant() { return cnpp_plant; }
        void set_cnpp_plant(const SnowReduceLaiFactor & value) { this->cnpp_plant = value; }

        const SnowReduceLaiFactor & get_cnpp_root() const { return cnpp_root; }
        SnowReduceLaiFactor & get_mutable_cnpp_root() { return cnpp_root; }
        void set_cnpp_root(const SnowReduceLaiFactor & value) { this->cnpp_root = value; }

        const SnowReduceLaiFactor & get_cnpp_stem() const { return cnpp_stem; }
        SnowReduceLaiFactor & get_mutable_cnpp_stem() { return cnpp_stem; }
        void set_cnpp_stem(const SnowReduceLaiFactor & value) { this->cnpp_stem = value; }

        const SnowReduceLaiFactor & get_cn_ratio_coarse_roots() const { return cn_ratio_coarse_roots; }
        SnowReduceLaiFactor & get_mutable_cn_ratio_coarse_roots() { return cn_ratio_coarse_roots; }
        void set_cn_ratio_coarse_roots(const SnowReduceLaiFactor & value) { this->cn_ratio_coarse_roots = value; }

        const SnowReduceLaiFactor & get_cn_ratio_fungi() const { return cn_ratio_fungi; }
        SnowReduceLaiFactor & get_mutable_cn_ratio_fungi() { return cn_ratio_fungi; }
        void set_cn_ratio_fungi(const SnowReduceLaiFactor & value) { this->cn_ratio_fungi = value; }

        const SnowReduceLaiFactor & get_cn_ratio_grain() const { return cn_ratio_grain; }
        SnowReduceLaiFactor & get_mutable_cn_ratio_grain() { return cn_ratio_grain; }
        void set_cn_ratio_grain(const SnowReduceLaiFactor & value) { this->cn_ratio_grain = value; }

        const SnowReduceLaiFactor & get_cn_ratio_leaf() const { return cn_ratio_leaf; }
        SnowReduceLaiFactor & get_mutable_cn_ratio_leaf() { return cn_ratio_leaf; }
        void set_cn_ratio_leaf(const SnowReduceLaiFactor & value) { this->cn_ratio_leaf = value; }

        const SnowReduceLaiFactor & get_cn_ratio_roots() const { return cn_ratio_roots; }
        SnowReduceLaiFactor & get_mutable_cn_ratio_roots() { return cn_ratio_roots; }
        void set_cn_ratio_roots(const SnowReduceLaiFactor & value) { this->cn_ratio_roots = value; }

        const SnowReduceLaiFactor & get_cn_ratio_stem() const { return cn_ratio_stem; }
        SnowReduceLaiFactor & get_mutable_cn_ratio_stem() { return cn_ratio_stem; }
        void set_cn_ratio_stem(const SnowReduceLaiFactor & value) { this->cn_ratio_stem = value; }

        const SnowReduceLaiFactor & get_c_plant() const { return c_plant; }
        SnowReduceLaiFactor & get_mutable_c_plant() { return c_plant; }
        void set_c_plant(const SnowReduceLaiFactor & value) { this->c_plant = value; }

        const SnowReduceLaiFactor & get_c_plant_above_g() const { return c_plant_above_g; }
        SnowReduceLaiFactor & get_mutable_c_plant_above_g() { return c_plant_above_g; }
        void set_c_plant_above_g(const SnowReduceLaiFactor & value) { this->c_plant_above_g = value; }

        const SnowReduceLaiFactor & get_c_plant_litter_fall() const { return c_plant_litter_fall; }
        SnowReduceLaiFactor & get_mutable_c_plant_litter_fall() { return c_plant_litter_fall; }
        void set_c_plant_litter_fall(const SnowReduceLaiFactor & value) { this->c_plant_litter_fall = value; }

        const SnowReduceLaiFactor & get_c_plant_resp() const { return c_plant_resp; }
        SnowReduceLaiFactor & get_mutable_c_plant_resp() { return c_plant_resp; }
        void set_c_plant_resp(const SnowReduceLaiFactor & value) { this->c_plant_resp = value; }

        const SnowReduceLaiFactor & get_c_plant_resp_above_g() const { return c_plant_resp_above_g; }
        SnowReduceLaiFactor & get_mutable_c_plant_resp_above_g() { return c_plant_resp_above_g; }
        void set_c_plant_resp_above_g(const SnowReduceLaiFactor & value) { this->c_plant_resp_above_g = value; }

        const SnowReduceLaiFactor & get_cp_ratio_coarse_roots() const { return cp_ratio_coarse_roots; }
        SnowReduceLaiFactor & get_mutable_cp_ratio_coarse_roots() { return cp_ratio_coarse_roots; }
        void set_cp_ratio_coarse_roots(const SnowReduceLaiFactor & value) { this->cp_ratio_coarse_roots = value; }

        const SnowReduceLaiFactor & get_cp_ratio_fungi() const { return cp_ratio_fungi; }
        SnowReduceLaiFactor & get_mutable_cp_ratio_fungi() { return cp_ratio_fungi; }
        void set_cp_ratio_fungi(const SnowReduceLaiFactor & value) { this->cp_ratio_fungi = value; }

        const SnowReduceLaiFactor & get_cp_ratio_grain() const { return cp_ratio_grain; }
        SnowReduceLaiFactor & get_mutable_cp_ratio_grain() { return cp_ratio_grain; }
        void set_cp_ratio_grain(const SnowReduceLaiFactor & value) { this->cp_ratio_grain = value; }

        const SnowReduceLaiFactor & get_cp_ratio_leaf() const { return cp_ratio_leaf; }
        SnowReduceLaiFactor & get_mutable_cp_ratio_leaf() { return cp_ratio_leaf; }
        void set_cp_ratio_leaf(const SnowReduceLaiFactor & value) { this->cp_ratio_leaf = value; }

        const SnowReduceLaiFactor & get_cp_ratio_roots() const { return cp_ratio_roots; }
        SnowReduceLaiFactor & get_mutable_cp_ratio_roots() { return cp_ratio_roots; }
        void set_cp_ratio_roots(const SnowReduceLaiFactor & value) { this->cp_ratio_roots = value; }

        const SnowReduceLaiFactor & get_cp_ratio_stem() const { return cp_ratio_stem; }
        SnowReduceLaiFactor & get_mutable_cp_ratio_stem() { return cp_ratio_stem; }
        void set_cp_ratio_stem(const SnowReduceLaiFactor & value) { this->cp_ratio_stem = value; }

        const SnowReduceLaiFactor & get_c_roots() const { return c_roots; }
        SnowReduceLaiFactor & get_mutable_c_roots() { return c_roots; }
        void set_c_roots(const SnowReduceLaiFactor & value) { this->c_roots = value; }

        const CCoarseRootsAtmLayer & get_c_roots_atm_layer() const { return c_roots_atm_layer; }
        CCoarseRootsAtmLayer & get_mutable_c_roots_atm_layer() { return c_roots_atm_layer; }
        void set_c_roots_atm_layer(const CCoarseRootsAtmLayer & value) { this->c_roots_atm_layer = value; }

        const SnowReduceLaiFactor & get_c_total_leaf() const { return c_total_leaf; }
        SnowReduceLaiFactor & get_mutable_c_total_leaf() { return c_total_leaf; }
        void set_c_total_leaf(const SnowReduceLaiFactor & value) { this->c_total_leaf = value; }

        const SnowReduceLaiFactor & get_dorming_temp_sum() const { return dorming_temp_sum; }
        SnowReduceLaiFactor & get_mutable_dorming_temp_sum() { return dorming_temp_sum; }
        void set_dorming_temp_sum(const SnowReduceLaiFactor & value) { this->dorming_temp_sum = value; }

        const SnowReduceLaiFactor & get_fact_cn_fungi() const { return fact_cn_fungi; }
        SnowReduceLaiFactor & get_mutable_fact_cn_fungi() { return fact_cn_fungi; }
        void set_fact_cn_fungi(const SnowReduceLaiFactor & value) { this->fact_cn_fungi = value; }

        const SnowReduceLaiFactor & get_fact_cp_fungi() const { return fact_cp_fungi; }
        SnowReduceLaiFactor & get_mutable_fact_cp_fungi() { return fact_cp_fungi; }
        void set_fact_cp_fungi(const SnowReduceLaiFactor & value) { this->fact_cp_fungi = value; }

        const SnowReduceLaiFactor & get_fact_navail_fungi() const { return fact_navail_fungi; }
        SnowReduceLaiFactor & get_mutable_fact_navail_fungi() { return fact_navail_fungi; }
        void set_fact_navail_fungi(const SnowReduceLaiFactor & value) { this->fact_navail_fungi = value; }

        const SnowReduceLaiFactor & get_fact_ndemand_fungi() const { return fact_ndemand_fungi; }
        SnowReduceLaiFactor & get_mutable_fact_ndemand_fungi() { return fact_ndemand_fungi; }
        void set_fact_ndemand_fungi(const SnowReduceLaiFactor & value) { this->fact_ndemand_fungi = value; }

        const SnowReduceLaiFactor & get_fact_nsupply_fungi() const { return fact_nsupply_fungi; }
        SnowReduceLaiFactor & get_mutable_fact_nsupply_fungi() { return fact_nsupply_fungi; }
        void set_fact_nsupply_fungi(const SnowReduceLaiFactor & value) { this->fact_nsupply_fungi = value; }

        const SnowReduceLaiFactor & get_fact_pavail_fungi() const { return fact_pavail_fungi; }
        SnowReduceLaiFactor & get_mutable_fact_pavail_fungi() { return fact_pavail_fungi; }
        void set_fact_pavail_fungi(const SnowReduceLaiFactor & value) { this->fact_pavail_fungi = value; }

        const SnowReduceLaiFactor & get_fact_pdemand_fungi() const { return fact_pdemand_fungi; }
        SnowReduceLaiFactor & get_mutable_fact_pdemand_fungi() { return fact_pdemand_fungi; }
        void set_fact_pdemand_fungi(const SnowReduceLaiFactor & value) { this->fact_pdemand_fungi = value; }

        const SnowReduceLaiFactor & get_fact_psupply_fungi() const { return fact_psupply_fungi; }
        SnowReduceLaiFactor & get_mutable_fact_psupply_fungi() { return fact_psupply_fungi; }
        void set_fact_psupply_fungi(const SnowReduceLaiFactor & value) { this->fact_psupply_fungi = value; }

        const SnowReduceLaiFactor & get_fungi_ammoniauptpot() const { return fungi_ammoniauptpot; }
        SnowReduceLaiFactor & get_mutable_fungi_ammoniauptpot() { return fungi_ammoniauptpot; }
        void set_fungi_ammoniauptpot(const SnowReduceLaiFactor & value) { this->fungi_ammoniauptpot = value; }

        const SnowReduceLaiFactor & get_fungi_nitrateuptpot() const { return fungi_nitrateuptpot; }
        SnowReduceLaiFactor & get_mutable_fungi_nitrateuptpot() { return fungi_nitrateuptpot; }
        void set_fungi_nitrateuptpot(const SnowReduceLaiFactor & value) { this->fungi_nitrateuptpot = value; }

        const SnowReduceLaiFactor & get_fungi_organic_nuptpot() const { return fungi_organic_nuptpot; }
        SnowReduceLaiFactor & get_mutable_fungi_organic_nuptpot() { return fungi_organic_nuptpot; }
        void set_fungi_organic_nuptpot(const SnowReduceLaiFactor & value) { this->fungi_organic_nuptpot = value; }

        const SnowReduceLaiFactor & get_fungi_organic_puptpot() const { return fungi_organic_puptpot; }
        SnowReduceLaiFactor & get_mutable_fungi_organic_puptpot() { return fungi_organic_puptpot; }
        void set_fungi_organic_puptpot(const SnowReduceLaiFactor & value) { this->fungi_organic_puptpot = value; }

        const SnowReduceLaiFactor & get_fungi_phosphateuptpot() const { return fungi_phosphateuptpot; }
        SnowReduceLaiFactor & get_mutable_fungi_phosphateuptpot() { return fungi_phosphateuptpot; }
        void set_fungi_phosphateuptpot(const SnowReduceLaiFactor & value) { this->fungi_phosphateuptpot = value; }

        const SnowReduceLaiFactor & get_fungi_root_cover() const { return fungi_root_cover; }
        SnowReduceLaiFactor & get_mutable_fungi_root_cover() { return fungi_root_cover; }
        void set_fungi_root_cover(const SnowReduceLaiFactor & value) { this->fungi_root_cover = value; }

        const SnowReduceLaiFactor & get_growth_temp_sum() const { return growth_temp_sum; }
        SnowReduceLaiFactor & get_mutable_growth_temp_sum() { return growth_temp_sum; }
        void set_growth_temp_sum(const SnowReduceLaiFactor & value) { this->growth_temp_sum = value; }

        const SnowReduceLaiFactor & get_n_fungi_available() const { return n_fungi_available; }
        SnowReduceLaiFactor & get_mutable_n_fungi_available() { return n_fungi_available; }
        void set_n_fungi_available(const SnowReduceLaiFactor & value) { this->n_fungi_available = value; }

        const SnowReduceLaiFactor & get_n_fungi_demand() const { return n_fungi_demand; }
        SnowReduceLaiFactor & get_mutable_n_fungi_demand() { return n_fungi_demand; }
        void set_n_fungi_demand(const SnowReduceLaiFactor & value) { this->n_fungi_demand = value; }

        const SnowReduceLaiFactor & get_n_mobile_plant_flux() const { return n_mobile_plant_flux; }
        SnowReduceLaiFactor & get_mutable_n_mobile_plant_flux() { return n_mobile_plant_flux; }
        void set_n_mobile_plant_flux(const SnowReduceLaiFactor & value) { this->n_mobile_plant_flux = value; }

        const SnowReduceLaiFactor & get_n_plant() const { return n_plant; }
        SnowReduceLaiFactor & get_mutable_n_plant() { return n_plant; }
        void set_n_plant(const SnowReduceLaiFactor & value) { this->n_plant = value; }

        const SnowReduceLaiFactor & get_n_plant_above_g() const { return n_plant_above_g; }
        SnowReduceLaiFactor & get_mutable_n_plant_above_g() { return n_plant_above_g; }
        void set_n_plant_above_g(const SnowReduceLaiFactor & value) { this->n_plant_above_g = value; }

        const SnowReduceLaiFactor & get_n_plant_demand() const { return n_plant_demand; }
        SnowReduceLaiFactor & get_mutable_n_plant_demand() { return n_plant_demand; }
        void set_n_plant_demand(const SnowReduceLaiFactor & value) { this->n_plant_demand = value; }

        const SnowReduceLaiFactor & get_n_plant_litter_fall() const { return n_plant_litter_fall; }
        SnowReduceLaiFactor & get_mutable_n_plant_litter_fall() { return n_plant_litter_fall; }
        void set_n_plant_litter_fall(const SnowReduceLaiFactor & value) { this->n_plant_litter_fall = value; }

        const SnowReduceLaiFactor & get_n_plant_org_uptake() const { return n_plant_org_uptake; }
        SnowReduceLaiFactor & get_mutable_n_plant_org_uptake() { return n_plant_org_uptake; }
        void set_n_plant_org_uptake(const SnowReduceLaiFactor & value) { this->n_plant_org_uptake = value; }

        const SnowReduceLaiFactor & get_n_plant_soil_demand() const { return n_plant_soil_demand; }
        SnowReduceLaiFactor & get_mutable_n_plant_soil_demand() { return n_plant_soil_demand; }
        void set_n_plant_soil_demand(const SnowReduceLaiFactor & value) { this->n_plant_soil_demand = value; }

        const SnowReduceLaiFactor & get_n_roots() const { return n_roots; }
        SnowReduceLaiFactor & get_mutable_n_roots() { return n_roots; }
        void set_n_roots(const SnowReduceLaiFactor & value) { this->n_roots = value; }

        const SnowReduceLaiFactor & get_n_total_leaf() const { return n_total_leaf; }
        SnowReduceLaiFactor & get_mutable_n_total_leaf() { return n_total_leaf; }
        void set_n_total_leaf(const SnowReduceLaiFactor & value) { this->n_total_leaf = value; }

        const SnowReduceLaiFactor & get_n_uptake_deficit1() const { return n_uptake_deficit1; }
        SnowReduceLaiFactor & get_mutable_n_uptake_deficit1() { return n_uptake_deficit1; }
        void set_n_uptake_deficit1(const SnowReduceLaiFactor & value) { this->n_uptake_deficit1 = value; }

        const SnowReduceLaiFactor & get_n_uptake_deficit2() const { return n_uptake_deficit2; }
        SnowReduceLaiFactor & get_mutable_n_uptake_deficit2() { return n_uptake_deficit2; }
        void set_n_uptake_deficit2(const SnowReduceLaiFactor & value) { this->n_uptake_deficit2 = value; }

        const SnowReduceLaiFactor & get_n_upt_fungi_deficit1() const { return n_upt_fungi_deficit1; }
        SnowReduceLaiFactor & get_mutable_n_upt_fungi_deficit1() { return n_upt_fungi_deficit1; }
        void set_n_upt_fungi_deficit1(const SnowReduceLaiFactor & value) { this->n_upt_fungi_deficit1 = value; }

        const SnowReduceLaiFactor & get_n_upt_fungi_deficit2() const { return n_upt_fungi_deficit2; }
        SnowReduceLaiFactor & get_mutable_n_upt_fungi_deficit2() { return n_upt_fungi_deficit2; }
        void set_n_upt_fungi_deficit2(const SnowReduceLaiFactor & value) { this->n_upt_fungi_deficit2 = value; }

        const SnowReduceLaiFactor & get_pco2_stomata() const { return pco2_stomata; }
        SnowReduceLaiFactor & get_mutable_pco2_stomata() { return pco2_stomata; }
        void set_pco2_stomata(const SnowReduceLaiFactor & value) { this->pco2_stomata = value; }

        const SnowReduceLaiFactor & get_pco2_surface() const { return pco2_surface; }
        SnowReduceLaiFactor & get_mutable_pco2_surface() { return pco2_surface; }
        void set_pco2_surface(const SnowReduceLaiFactor & value) { this->pco2_surface = value; }

        const SnowReduceLaiFactor & get_p_fungi_available() const { return p_fungi_available; }
        SnowReduceLaiFactor & get_mutable_p_fungi_available() { return p_fungi_available; }
        void set_p_fungi_available(const SnowReduceLaiFactor & value) { this->p_fungi_available = value; }

        const SnowReduceLaiFactor & get_p_fungi_demand() const { return p_fungi_demand; }
        SnowReduceLaiFactor & get_mutable_p_fungi_demand() { return p_fungi_demand; }
        void set_p_fungi_demand(const SnowReduceLaiFactor & value) { this->p_fungi_demand = value; }

        const SnowReduceLaiFactor & get_p_light() const { return p_light; }
        SnowReduceLaiFactor & get_mutable_p_light() { return p_light; }
        void set_p_light(const SnowReduceLaiFactor & value) { this->p_light = value; }

        const SnowReduceLaiFactor & get_p_mobile_plant_flux() const { return p_mobile_plant_flux; }
        SnowReduceLaiFactor & get_mutable_p_mobile_plant_flux() { return p_mobile_plant_flux; }
        void set_p_mobile_plant_flux(const SnowReduceLaiFactor & value) { this->p_mobile_plant_flux = value; }

        const SnowReduceLaiFactor & get_p_plant() const { return p_plant; }
        SnowReduceLaiFactor & get_mutable_p_plant() { return p_plant; }
        void set_p_plant(const SnowReduceLaiFactor & value) { this->p_plant = value; }

        const SnowReduceLaiFactor & get_p_plant_above_g() const { return p_plant_above_g; }
        SnowReduceLaiFactor & get_mutable_p_plant_above_g() { return p_plant_above_g; }
        void set_p_plant_above_g(const SnowReduceLaiFactor & value) { this->p_plant_above_g = value; }

        const SnowReduceLaiFactor & get_p_plant_demand() const { return p_plant_demand; }
        SnowReduceLaiFactor & get_mutable_p_plant_demand() { return p_plant_demand; }
        void set_p_plant_demand(const SnowReduceLaiFactor & value) { this->p_plant_demand = value; }

        const SnowReduceLaiFactor & get_p_plant_litter_fall() const { return p_plant_litter_fall; }
        SnowReduceLaiFactor & get_mutable_p_plant_litter_fall() { return p_plant_litter_fall; }
        void set_p_plant_litter_fall(const SnowReduceLaiFactor & value) { this->p_plant_litter_fall = value; }

        const SnowReduceLaiFactor & get_p_plant_org_uptake() const { return p_plant_org_uptake; }
        SnowReduceLaiFactor & get_mutable_p_plant_org_uptake() { return p_plant_org_uptake; }
        void set_p_plant_org_uptake(const SnowReduceLaiFactor & value) { this->p_plant_org_uptake = value; }

        const SnowReduceLaiFactor & get_p_plant_soil_demand() const { return p_plant_soil_demand; }
        SnowReduceLaiFactor & get_mutable_p_plant_soil_demand() { return p_plant_soil_demand; }
        void set_p_plant_soil_demand(const SnowReduceLaiFactor & value) { this->p_plant_soil_demand = value; }

        const SnowReduceLaiFactor & get_p_roots() const { return p_roots; }
        SnowReduceLaiFactor & get_mutable_p_roots() { return p_roots; }
        void set_p_roots(const SnowReduceLaiFactor & value) { this->p_roots = value; }

        const SnowReduceLaiFactor & get_p_rubisco() const { return p_rubisco; }
        SnowReduceLaiFactor & get_mutable_p_rubisco() { return p_rubisco; }
        void set_p_rubisco(const SnowReduceLaiFactor & value) { this->p_rubisco = value; }

        const SnowReduceLaiFactor & get_p_sink() const { return p_sink; }
        SnowReduceLaiFactor & get_mutable_p_sink() { return p_sink; }
        void set_p_sink(const SnowReduceLaiFactor & value) { this->p_sink = value; }

        const SnowReduceLaiFactor & get_p_total_leaf() const { return p_total_leaf; }
        SnowReduceLaiFactor & get_mutable_p_total_leaf() { return p_total_leaf; }
        void set_p_total_leaf(const SnowReduceLaiFactor & value) { this->p_total_leaf = value; }

        const SnowReduceLaiFactor & get_p_uptake_deficit1() const { return p_uptake_deficit1; }
        SnowReduceLaiFactor & get_mutable_p_uptake_deficit1() { return p_uptake_deficit1; }
        void set_p_uptake_deficit1(const SnowReduceLaiFactor & value) { this->p_uptake_deficit1 = value; }

        const SnowReduceLaiFactor & get_p_uptake_deficit2() const { return p_uptake_deficit2; }
        SnowReduceLaiFactor & get_mutable_p_uptake_deficit2() { return p_uptake_deficit2; }
        void set_p_uptake_deficit2(const SnowReduceLaiFactor & value) { this->p_uptake_deficit2 = value; }

        const SnowReduceLaiFactor & get_p_upt_fungi_deficit1() const { return p_upt_fungi_deficit1; }
        SnowReduceLaiFactor & get_mutable_p_upt_fungi_deficit1() { return p_upt_fungi_deficit1; }
        void set_p_upt_fungi_deficit1(const SnowReduceLaiFactor & value) { this->p_upt_fungi_deficit1 = value; }

        const SnowReduceLaiFactor & get_p_upt_fungi_deficit2() const { return p_upt_fungi_deficit2; }
        SnowReduceLaiFactor & get_mutable_p_upt_fungi_deficit2() { return p_upt_fungi_deficit2; }
        void set_p_upt_fungi_deficit2(const SnowReduceLaiFactor & value) { this->p_upt_fungi_deficit2 = value; }

        const SnowReduceLaiFactor & get_radiationadsorbed() const { return radiationadsorbed; }
        SnowReduceLaiFactor & get_mutable_radiationadsorbed() { return radiationadsorbed; }
        void set_radiationadsorbed(const SnowReduceLaiFactor & value) { this->radiationadsorbed = value; }

        const SnowReduceLaiFactor & get_response_light() const { return response_light; }
        SnowReduceLaiFactor & get_mutable_response_light() { return response_light; }
        void set_response_light(const SnowReduceLaiFactor & value) { this->response_light = value; }

        const SnowReduceLaiFactor & get_response_n() const { return response_n; }
        SnowReduceLaiFactor & get_mutable_response_n() { return response_n; }
        void set_response_n(const SnowReduceLaiFactor & value) { this->response_n = value; }

        const SnowReduceLaiFactor & get_response_n_water() const { return response_n_water; }
        SnowReduceLaiFactor & get_mutable_response_n_water() { return response_n_water; }
        void set_response_n_water(const SnowReduceLaiFactor & value) { this->response_n_water = value; }

        const SnowReduceLaiFactor & get_response_phosphorus() const { return response_phosphorus; }
        SnowReduceLaiFactor & get_mutable_response_phosphorus() { return response_phosphorus; }
        void set_response_phosphorus(const SnowReduceLaiFactor & value) { this->response_phosphorus = value; }

        const SnowReduceLaiFactor & get_response_salt() const { return response_salt; }
        SnowReduceLaiFactor & get_mutable_response_salt() { return response_salt; }
        void set_response_salt(const SnowReduceLaiFactor & value) { this->response_salt = value; }

        const SnowReduceLaiFactor & get_response_temp() const { return response_temp; }
        SnowReduceLaiFactor & get_mutable_response_temp() { return response_temp; }
        void set_response_temp(const SnowReduceLaiFactor & value) { this->response_temp = value; }

        const SnowReduceLaiFactor & get_response_water() const { return response_water; }
        SnowReduceLaiFactor & get_mutable_response_water() { return response_water; }
        void set_response_water(const SnowReduceLaiFactor & value) { this->response_water = value; }

        const SnowReduceLaiFactor & get_sim_plant_year_age() const { return sim_plant_year_age; }
        SnowReduceLaiFactor & get_mutable_sim_plant_year_age() { return sim_plant_year_age; }
        void set_sim_plant_year_age(const SnowReduceLaiFactor & value) { this->sim_plant_year_age = value; }

        const SnowReduceLaiFactor & get_zadok_day_num_shift() const { return zadok_day_num_shift; }
        SnowReduceLaiFactor & get_mutable_zadok_day_num_shift() { return zadok_day_num_shift; }
        void set_zadok_day_num_shift(const SnowReduceLaiFactor & value) { this->zadok_day_num_shift = value; }

        const SnowReduceLaiFactor & get_zadok_index() const { return zadok_index; }
        SnowReduceLaiFactor & get_mutable_zadok_index() { return zadok_index; }
        void set_zadok_index(const SnowReduceLaiFactor & value) { this->zadok_index = value; }
    };

    class AuxiliaryArraysNitrogenandCarbon {
        public:
        AuxiliaryArraysNitrogenandCarbon() = default;
        virtual ~AuxiliaryArraysNitrogenandCarbon() = default;

        private:
        FluffyPlantGrowth plant_growth;

        public:
        const FluffyPlantGrowth & get_plant_growth() const { return plant_growth; }
        FluffyPlantGrowth & get_mutable_plant_growth() { return plant_growth; }
        void set_plant_growth(const FluffyPlantGrowth & value) { this->plant_growth = value; }
    };

    class PurpleGasprocesses {
        public:
        PurpleGasprocesses() = default;
        virtual ~PurpleGasprocesses() = default;

        private:
        CCoarseRootsAtmLayer air_porosity;
        CCoarseRootsAtmLayer an_vol_fraction;
        CCoarseRootsAtmLayer ch4_airconcentration;
        CCoarseRootsAtmLayer ch4_waterconc;
        CCoarseRootsAtmLayer co2_concentration;
        CCoarseRootsAtmLayer co2_diffusioncoefficient;
        CCoarseRootsAtmLayer oxygen_concentration;

        public:
        const CCoarseRootsAtmLayer & get_air_porosity() const { return air_porosity; }
        CCoarseRootsAtmLayer & get_mutable_air_porosity() { return air_porosity; }
        void set_air_porosity(const CCoarseRootsAtmLayer & value) { this->air_porosity = value; }

        const CCoarseRootsAtmLayer & get_an_vol_fraction() const { return an_vol_fraction; }
        CCoarseRootsAtmLayer & get_mutable_an_vol_fraction() { return an_vol_fraction; }
        void set_an_vol_fraction(const CCoarseRootsAtmLayer & value) { this->an_vol_fraction = value; }

        const CCoarseRootsAtmLayer & get_ch4_airconcentration() const { return ch4_airconcentration; }
        CCoarseRootsAtmLayer & get_mutable_ch4_airconcentration() { return ch4_airconcentration; }
        void set_ch4_airconcentration(const CCoarseRootsAtmLayer & value) { this->ch4_airconcentration = value; }

        const CCoarseRootsAtmLayer & get_ch4_waterconc() const { return ch4_waterconc; }
        CCoarseRootsAtmLayer & get_mutable_ch4_waterconc() { return ch4_waterconc; }
        void set_ch4_waterconc(const CCoarseRootsAtmLayer & value) { this->ch4_waterconc = value; }

        const CCoarseRootsAtmLayer & get_co2_concentration() const { return co2_concentration; }
        CCoarseRootsAtmLayer & get_mutable_co2_concentration() { return co2_concentration; }
        void set_co2_concentration(const CCoarseRootsAtmLayer & value) { this->co2_concentration = value; }

        const CCoarseRootsAtmLayer & get_co2_diffusioncoefficient() const { return co2_diffusioncoefficient; }
        CCoarseRootsAtmLayer & get_mutable_co2_diffusioncoefficient() { return co2_diffusioncoefficient; }
        void set_co2_diffusioncoefficient(const CCoarseRootsAtmLayer & value) { this->co2_diffusioncoefficient = value; }

        const CCoarseRootsAtmLayer & get_oxygen_concentration() const { return oxygen_concentration; }
        CCoarseRootsAtmLayer & get_mutable_oxygen_concentration() { return oxygen_concentration; }
        void set_oxygen_concentration(const CCoarseRootsAtmLayer & value) { this->oxygen_concentration = value; }
    };

    class FluffySoilmineralPProcesses {
        public:
        FluffySoilmineralPProcesses() = default;
        virtual ~FluffySoilmineralPProcesses() = default;

        private:
        CCoarseRootsAtmLayer soil_pconc;
        CCoarseRootsAtmLayer soil_p_solution;

        public:
        const CCoarseRootsAtmLayer & get_soil_pconc() const { return soil_pconc; }
        CCoarseRootsAtmLayer & get_mutable_soil_pconc() { return soil_pconc; }
        void set_soil_pconc(const CCoarseRootsAtmLayer & value) { this->soil_pconc = value; }

        const CCoarseRootsAtmLayer & get_soil_p_solution() const { return soil_p_solution; }
        CCoarseRootsAtmLayer & get_mutable_soil_p_solution() { return soil_p_solution; }
        void set_soil_p_solution(const CCoarseRootsAtmLayer & value) { this->soil_p_solution = value; }
    };

    class AuxiliaryArraysNitrogenandCarbonBelowGround {
        public:
        AuxiliaryArraysNitrogenandCarbonBelowGround() = default;
        virtual ~AuxiliaryArraysNitrogenandCarbonBelowGround() = default;

        private:
        PurpleGasprocesses gasprocesses;
        std::map<std::string, CCoarseRootsAtmLayer> soilmineral_nprocesses;
        FluffySoilmineralPProcesses soilmineral_p_processes;
        std::map<std::string, CCoarseRootsAtmLayer> soilorganicprocesses;

        public:
        const PurpleGasprocesses & get_gasprocesses() const { return gasprocesses; }
        PurpleGasprocesses & get_mutable_gasprocesses() { return gasprocesses; }
        void set_gasprocesses(const PurpleGasprocesses & value) { this->gasprocesses = value; }

        const std::map<std::string, CCoarseRootsAtmLayer> & get_soilmineral_nprocesses() const { return soilmineral_nprocesses; }
        std::map<std::string, CCoarseRootsAtmLayer> & get_mutable_soilmineral_nprocesses() { return soilmineral_nprocesses; }
        void set_soilmineral_nprocesses(const std::map<std::string, CCoarseRootsAtmLayer> & value) { this->soilmineral_nprocesses = value; }

        const FluffySoilmineralPProcesses & get_soilmineral_p_processes() const { return soilmineral_p_processes; }
        FluffySoilmineralPProcesses & get_mutable_soilmineral_p_processes() { return soilmineral_p_processes; }
        void set_soilmineral_p_processes(const FluffySoilmineralPProcesses & value) { this->soilmineral_p_processes = value; }

        const std::map<std::string, CCoarseRootsAtmLayer> & get_soilorganicprocesses() const { return soilorganicprocesses; }
        std::map<std::string, CCoarseRootsAtmLayer> & get_mutable_soilorganicprocesses() { return soilorganicprocesses; }
        void set_soilorganicprocesses(const std::map<std::string, CCoarseRootsAtmLayer> & value) { this->soilorganicprocesses = value; }
    };

    class TentacledInterception {
        public:
        TentacledInterception() = default;
        virtual ~TentacledInterception() = default;

        private:
        LaiAbovecanopy canopy_interc_capac;
        LaiAbovecanopy canopy_interc_pot_eva;

        public:
        const LaiAbovecanopy & get_canopy_interc_capac() const { return canopy_interc_capac; }
        LaiAbovecanopy & get_mutable_canopy_interc_capac() { return canopy_interc_capac; }
        void set_canopy_interc_capac(const LaiAbovecanopy & value) { this->canopy_interc_capac = value; }

        const LaiAbovecanopy & get_canopy_interc_pot_eva() const { return canopy_interc_pot_eva; }
        LaiAbovecanopy & get_mutable_canopy_interc_pot_eva() { return canopy_interc_pot_eva; }
        void set_canopy_interc_pot_eva(const LaiAbovecanopy & value) { this->canopy_interc_pot_eva = value; }
    };

    class TentacledPlant {
        public:
        TentacledPlant() = default;
        virtual ~TentacledPlant() = default;

        private:
        SnowReduceLaiFactor canopy_height;
        SnowReduceLaiFactor leaf_area_index;
        SnowReduceLaiFactor plant_albedo;
        SnowReduceLaiFactor root_depth;
        CCoarseRootsAtmLayer root_depth_distribution;
        SnowReduceLaiFactor root_length;
        SnowReduceLaiFactor sim_leaf_area_index;
        SnowReduceLaiFactor sim_plant_albedo;
        SnowReduceLaiFactor sim_plant_height;
        SnowReduceLaiFactor sim_root_depth;
        SnowReduceLaiFactor sim_root_length;
        SnowReduceLaiFactor soil_cover_fraction;

        public:
        const SnowReduceLaiFactor & get_canopy_height() const { return canopy_height; }
        SnowReduceLaiFactor & get_mutable_canopy_height() { return canopy_height; }
        void set_canopy_height(const SnowReduceLaiFactor & value) { this->canopy_height = value; }

        const SnowReduceLaiFactor & get_leaf_area_index() const { return leaf_area_index; }
        SnowReduceLaiFactor & get_mutable_leaf_area_index() { return leaf_area_index; }
        void set_leaf_area_index(const SnowReduceLaiFactor & value) { this->leaf_area_index = value; }

        const SnowReduceLaiFactor & get_plant_albedo() const { return plant_albedo; }
        SnowReduceLaiFactor & get_mutable_plant_albedo() { return plant_albedo; }
        void set_plant_albedo(const SnowReduceLaiFactor & value) { this->plant_albedo = value; }

        const SnowReduceLaiFactor & get_root_depth() const { return root_depth; }
        SnowReduceLaiFactor & get_mutable_root_depth() { return root_depth; }
        void set_root_depth(const SnowReduceLaiFactor & value) { this->root_depth = value; }

        const CCoarseRootsAtmLayer & get_root_depth_distribution() const { return root_depth_distribution; }
        CCoarseRootsAtmLayer & get_mutable_root_depth_distribution() { return root_depth_distribution; }
        void set_root_depth_distribution(const CCoarseRootsAtmLayer & value) { this->root_depth_distribution = value; }

        const SnowReduceLaiFactor & get_root_length() const { return root_length; }
        SnowReduceLaiFactor & get_mutable_root_length() { return root_length; }
        void set_root_length(const SnowReduceLaiFactor & value) { this->root_length = value; }

        const SnowReduceLaiFactor & get_sim_leaf_area_index() const { return sim_leaf_area_index; }
        SnowReduceLaiFactor & get_mutable_sim_leaf_area_index() { return sim_leaf_area_index; }
        void set_sim_leaf_area_index(const SnowReduceLaiFactor & value) { this->sim_leaf_area_index = value; }

        const SnowReduceLaiFactor & get_sim_plant_albedo() const { return sim_plant_albedo; }
        SnowReduceLaiFactor & get_mutable_sim_plant_albedo() { return sim_plant_albedo; }
        void set_sim_plant_albedo(const SnowReduceLaiFactor & value) { this->sim_plant_albedo = value; }

        const SnowReduceLaiFactor & get_sim_plant_height() const { return sim_plant_height; }
        SnowReduceLaiFactor & get_mutable_sim_plant_height() { return sim_plant_height; }
        void set_sim_plant_height(const SnowReduceLaiFactor & value) { this->sim_plant_height = value; }

        const SnowReduceLaiFactor & get_sim_root_depth() const { return sim_root_depth; }
        SnowReduceLaiFactor & get_mutable_sim_root_depth() { return sim_root_depth; }
        void set_sim_root_depth(const SnowReduceLaiFactor & value) { this->sim_root_depth = value; }

        const SnowReduceLaiFactor & get_sim_root_length() const { return sim_root_length; }
        SnowReduceLaiFactor & get_mutable_sim_root_length() { return sim_root_length; }
        void set_sim_root_length(const SnowReduceLaiFactor & value) { this->sim_root_length = value; }

        const SnowReduceLaiFactor & get_soil_cover_fraction() const { return soil_cover_fraction; }
        SnowReduceLaiFactor & get_mutable_soil_cover_fraction() { return soil_cover_fraction; }
        void set_soil_cover_fraction(const SnowReduceLaiFactor & value) { this->soil_cover_fraction = value; }
    };

    class FluffyPotentialTranspiration {
        public:
        FluffyPotentialTranspiration() = default;
        virtual ~FluffyPotentialTranspiration() = default;

        private:
        LaiAbovecanopy displacement_height;
        LaiAbovecanopy pot_max_transpiration;
        LaiAbovecanopy pot_transpiration;
        LaiAbovecanopy resist_air_canopy;
        LaiAbovecanopy resistance_canopy;
        LaiAbovecanopy resistance_min_canopy;
        LaiAbovecanopy response_transp_atm;
        LaiAbovecanopy roughness_length;

        public:
        const LaiAbovecanopy & get_displacement_height() const { return displacement_height; }
        LaiAbovecanopy & get_mutable_displacement_height() { return displacement_height; }
        void set_displacement_height(const LaiAbovecanopy & value) { this->displacement_height = value; }

        const LaiAbovecanopy & get_pot_max_transpiration() const { return pot_max_transpiration; }
        LaiAbovecanopy & get_mutable_pot_max_transpiration() { return pot_max_transpiration; }
        void set_pot_max_transpiration(const LaiAbovecanopy & value) { this->pot_max_transpiration = value; }

        const LaiAbovecanopy & get_pot_transpiration() const { return pot_transpiration; }
        LaiAbovecanopy & get_mutable_pot_transpiration() { return pot_transpiration; }
        void set_pot_transpiration(const LaiAbovecanopy & value) { this->pot_transpiration = value; }

        const LaiAbovecanopy & get_resist_air_canopy() const { return resist_air_canopy; }
        LaiAbovecanopy & get_mutable_resist_air_canopy() { return resist_air_canopy; }
        void set_resist_air_canopy(const LaiAbovecanopy & value) { this->resist_air_canopy = value; }

        const LaiAbovecanopy & get_resistance_canopy() const { return resistance_canopy; }
        LaiAbovecanopy & get_mutable_resistance_canopy() { return resistance_canopy; }
        void set_resistance_canopy(const LaiAbovecanopy & value) { this->resistance_canopy = value; }

        const LaiAbovecanopy & get_resistance_min_canopy() const { return resistance_min_canopy; }
        LaiAbovecanopy & get_mutable_resistance_min_canopy() { return resistance_min_canopy; }
        void set_resistance_min_canopy(const LaiAbovecanopy & value) { this->resistance_min_canopy = value; }

        const LaiAbovecanopy & get_response_transp_atm() const { return response_transp_atm; }
        LaiAbovecanopy & get_mutable_response_transp_atm() { return response_transp_atm; }
        void set_response_transp_atm(const LaiAbovecanopy & value) { this->response_transp_atm = value; }

        const LaiAbovecanopy & get_roughness_length() const { return roughness_length; }
        LaiAbovecanopy & get_mutable_roughness_length() { return roughness_length; }
        void set_roughness_length(const LaiAbovecanopy & value) { this->roughness_length = value; }
    };

    class FluffySaltTracer {
        public:
        FluffySaltTracer() = default;
        virtual ~FluffySaltTracer() = default;

        private:
        CCoarseRootsAtmLayer osmotic_pressure;
        CCoarseRootsAtmLayer salt_conc;
        SnowReduceLaiFactor tec_ratio_grain;
        SnowReduceLaiFactor tec_ratio_leaf;
        SnowReduceLaiFactor tec_ratio_old_leaf;
        SnowReduceLaiFactor tec_ratio_old_roots;
        SnowReduceLaiFactor tec_ratio_old_stem;
        SnowReduceLaiFactor tec_ratio_roots;
        SnowReduceLaiFactor tec_ratio_stem;

        public:
        const CCoarseRootsAtmLayer & get_osmotic_pressure() const { return osmotic_pressure; }
        CCoarseRootsAtmLayer & get_mutable_osmotic_pressure() { return osmotic_pressure; }
        void set_osmotic_pressure(const CCoarseRootsAtmLayer & value) { this->osmotic_pressure = value; }

        const CCoarseRootsAtmLayer & get_salt_conc() const { return salt_conc; }
        CCoarseRootsAtmLayer & get_mutable_salt_conc() { return salt_conc; }
        void set_salt_conc(const CCoarseRootsAtmLayer & value) { this->salt_conc = value; }

        const SnowReduceLaiFactor & get_tec_ratio_grain() const { return tec_ratio_grain; }
        SnowReduceLaiFactor & get_mutable_tec_ratio_grain() { return tec_ratio_grain; }
        void set_tec_ratio_grain(const SnowReduceLaiFactor & value) { this->tec_ratio_grain = value; }

        const SnowReduceLaiFactor & get_tec_ratio_leaf() const { return tec_ratio_leaf; }
        SnowReduceLaiFactor & get_mutable_tec_ratio_leaf() { return tec_ratio_leaf; }
        void set_tec_ratio_leaf(const SnowReduceLaiFactor & value) { this->tec_ratio_leaf = value; }

        const SnowReduceLaiFactor & get_tec_ratio_old_leaf() const { return tec_ratio_old_leaf; }
        SnowReduceLaiFactor & get_mutable_tec_ratio_old_leaf() { return tec_ratio_old_leaf; }
        void set_tec_ratio_old_leaf(const SnowReduceLaiFactor & value) { this->tec_ratio_old_leaf = value; }

        const SnowReduceLaiFactor & get_tec_ratio_old_roots() const { return tec_ratio_old_roots; }
        SnowReduceLaiFactor & get_mutable_tec_ratio_old_roots() { return tec_ratio_old_roots; }
        void set_tec_ratio_old_roots(const SnowReduceLaiFactor & value) { this->tec_ratio_old_roots = value; }

        const SnowReduceLaiFactor & get_tec_ratio_old_stem() const { return tec_ratio_old_stem; }
        SnowReduceLaiFactor & get_mutable_tec_ratio_old_stem() { return tec_ratio_old_stem; }
        void set_tec_ratio_old_stem(const SnowReduceLaiFactor & value) { this->tec_ratio_old_stem = value; }

        const SnowReduceLaiFactor & get_tec_ratio_roots() const { return tec_ratio_roots; }
        SnowReduceLaiFactor & get_mutable_tec_ratio_roots() { return tec_ratio_roots; }
        void set_tec_ratio_roots(const SnowReduceLaiFactor & value) { this->tec_ratio_roots = value; }

        const SnowReduceLaiFactor & get_tec_ratio_stem() const { return tec_ratio_stem; }
        SnowReduceLaiFactor & get_mutable_tec_ratio_stem() { return tec_ratio_stem; }
        void set_tec_ratio_stem(const SnowReduceLaiFactor & value) { this->tec_ratio_stem = value; }
    };

    class TentacledWateruptake {
        public:
        TentacledWateruptake() = default;
        virtual ~TentacledWateruptake() = default;

        private:
        LaiAbovecanopy plant_pot_water_uptake;
        LaiAbovecanopy plant_water_potential;
        LaiAbovecanopy red_c_moisture;
        LaiAbovecanopy red_c_temperature;
        LaiAbovecanopy red_c_total;
        LaiAbovecanopy resist_plant;
        LaiAbovecanopy resist_soil_plant;

        public:
        const LaiAbovecanopy & get_plant_pot_water_uptake() const { return plant_pot_water_uptake; }
        LaiAbovecanopy & get_mutable_plant_pot_water_uptake() { return plant_pot_water_uptake; }
        void set_plant_pot_water_uptake(const LaiAbovecanopy & value) { this->plant_pot_water_uptake = value; }

        const LaiAbovecanopy & get_plant_water_potential() const { return plant_water_potential; }
        LaiAbovecanopy & get_mutable_plant_water_potential() { return plant_water_potential; }
        void set_plant_water_potential(const LaiAbovecanopy & value) { this->plant_water_potential = value; }

        const LaiAbovecanopy & get_red_c_moisture() const { return red_c_moisture; }
        LaiAbovecanopy & get_mutable_red_c_moisture() { return red_c_moisture; }
        void set_red_c_moisture(const LaiAbovecanopy & value) { this->red_c_moisture = value; }

        const LaiAbovecanopy & get_red_c_temperature() const { return red_c_temperature; }
        LaiAbovecanopy & get_mutable_red_c_temperature() { return red_c_temperature; }
        void set_red_c_temperature(const LaiAbovecanopy & value) { this->red_c_temperature = value; }

        const LaiAbovecanopy & get_red_c_total() const { return red_c_total; }
        LaiAbovecanopy & get_mutable_red_c_total() { return red_c_total; }
        void set_red_c_total(const LaiAbovecanopy & value) { this->red_c_total = value; }

        const LaiAbovecanopy & get_resist_plant() const { return resist_plant; }
        LaiAbovecanopy & get_mutable_resist_plant() { return resist_plant; }
        void set_resist_plant(const LaiAbovecanopy & value) { this->resist_plant = value; }

        const LaiAbovecanopy & get_resist_soil_plant() const { return resist_soil_plant; }
        LaiAbovecanopy & get_mutable_resist_soil_plant() { return resist_soil_plant; }
        void set_resist_soil_plant(const LaiAbovecanopy & value) { this->resist_soil_plant = value; }
    };

    class AuxiliaryArraysPlantWaterProcesses {
        public:
        AuxiliaryArraysPlantWaterProcesses() = default;
        virtual ~AuxiliaryArraysPlantWaterProcesses() = default;

        private:
        TentacledInterception interception;
        TentacledPlant plant;
        FluffyPotentialTranspiration potential_transpiration;
        FluffySaltTracer salt_tracer;
        TentacledWateruptake wateruptake;

        public:
        const TentacledInterception & get_interception() const { return interception; }
        TentacledInterception & get_mutable_interception() { return interception; }
        void set_interception(const TentacledInterception & value) { this->interception = value; }

        const TentacledPlant & get_plant() const { return plant; }
        TentacledPlant & get_mutable_plant() { return plant; }
        void set_plant(const TentacledPlant & value) { this->plant = value; }

        const FluffyPotentialTranspiration & get_potential_transpiration() const { return potential_transpiration; }
        FluffyPotentialTranspiration & get_mutable_potential_transpiration() { return potential_transpiration; }
        void set_potential_transpiration(const FluffyPotentialTranspiration & value) { this->potential_transpiration = value; }

        const FluffySaltTracer & get_salt_tracer() const { return salt_tracer; }
        FluffySaltTracer & get_mutable_salt_tracer() { return salt_tracer; }
        void set_salt_tracer(const FluffySaltTracer & value) { this->salt_tracer = value; }

        const TentacledWateruptake & get_wateruptake() const { return wateruptake; }
        TentacledWateruptake & get_mutable_wateruptake() { return wateruptake; }
        void set_wateruptake(const TentacledWateruptake & value) { this->wateruptake = value; }
    };

    enum class ArrayName : int { HEAT_EQ_0_IS_TRUE, INSULATED_WATER_PIPE_0_IS_FALSE, NUMBEROF_WATER_PIPESEGMENTS, THE_010000000000000001 };

    class TempColdPipe {
        public:
        TempColdPipe() = default;
        virtual ~TempColdPipe() = default;

        private:
        ArrayName array_name;
        Condition3Enum condition_1;
        ArrayName condition_2;
        std::string out_multi_index_1;
        std::string out_multi_index_10;
        std::string out_multi_index_11;
        std::string out_multi_index_12;
        std::string out_multi_index_13;
        std::string out_multi_index_14;
        std::string out_multi_index_15;
        std::string out_multi_index_16;
        std::string out_multi_index_17;
        std::string out_multi_index_18;
        std::string out_multi_index_19;
        std::string out_multi_index_2;
        std::string out_multi_index_20;
        std::string out_multi_index_3;
        std::string out_multi_index_4;
        std::string out_multi_index_5;
        std::string out_multi_index_6;
        std::string out_multi_index_7;
        std::string out_multi_index_8;
        std::string out_multi_index_9;
        std::string out_single_index_1;
        std::string out_single_index_10;
        std::string out_single_index_11;
        std::string out_single_index_12;
        std::string out_single_index_13;
        std::string out_single_index_14;
        std::string out_single_index_15;
        std::string out_single_index_16;
        std::string out_single_index_17;
        std::string out_single_index_18;
        std::string out_single_index_19;
        std::string out_single_index_2;
        std::string out_single_index_20;
        std::string out_single_index_3;
        std::string out_single_index_4;
        std::string out_single_index_5;
        std::string out_single_index_6;
        std::string out_single_index_7;
        std::string out_single_index_8;
        std::string out_single_index_9;
        std::string sizeof_array;

        public:
        const ArrayName & get_array_name() const { return array_name; }
        ArrayName & get_mutable_array_name() { return array_name; }
        void set_array_name(const ArrayName & value) { this->array_name = value; }

        const Condition3Enum & get_condition_1() const { return condition_1; }
        Condition3Enum & get_mutable_condition_1() { return condition_1; }
        void set_condition_1(const Condition3Enum & value) { this->condition_1 = value; }

        const ArrayName & get_condition_2() const { return condition_2; }
        ArrayName & get_mutable_condition_2() { return condition_2; }
        void set_condition_2(const ArrayName & value) { this->condition_2 = value; }

        const std::string & get_out_multi_index_1() const { return out_multi_index_1; }
        std::string & get_mutable_out_multi_index_1() { return out_multi_index_1; }
        void set_out_multi_index_1(const std::string & value) { this->out_multi_index_1 = value; }

        const std::string & get_out_multi_index_10() const { return out_multi_index_10; }
        std::string & get_mutable_out_multi_index_10() { return out_multi_index_10; }
        void set_out_multi_index_10(const std::string & value) { this->out_multi_index_10 = value; }

        const std::string & get_out_multi_index_11() const { return out_multi_index_11; }
        std::string & get_mutable_out_multi_index_11() { return out_multi_index_11; }
        void set_out_multi_index_11(const std::string & value) { this->out_multi_index_11 = value; }

        const std::string & get_out_multi_index_12() const { return out_multi_index_12; }
        std::string & get_mutable_out_multi_index_12() { return out_multi_index_12; }
        void set_out_multi_index_12(const std::string & value) { this->out_multi_index_12 = value; }

        const std::string & get_out_multi_index_13() const { return out_multi_index_13; }
        std::string & get_mutable_out_multi_index_13() { return out_multi_index_13; }
        void set_out_multi_index_13(const std::string & value) { this->out_multi_index_13 = value; }

        const std::string & get_out_multi_index_14() const { return out_multi_index_14; }
        std::string & get_mutable_out_multi_index_14() { return out_multi_index_14; }
        void set_out_multi_index_14(const std::string & value) { this->out_multi_index_14 = value; }

        const std::string & get_out_multi_index_15() const { return out_multi_index_15; }
        std::string & get_mutable_out_multi_index_15() { return out_multi_index_15; }
        void set_out_multi_index_15(const std::string & value) { this->out_multi_index_15 = value; }

        const std::string & get_out_multi_index_16() const { return out_multi_index_16; }
        std::string & get_mutable_out_multi_index_16() { return out_multi_index_16; }
        void set_out_multi_index_16(const std::string & value) { this->out_multi_index_16 = value; }

        const std::string & get_out_multi_index_17() const { return out_multi_index_17; }
        std::string & get_mutable_out_multi_index_17() { return out_multi_index_17; }
        void set_out_multi_index_17(const std::string & value) { this->out_multi_index_17 = value; }

        const std::string & get_out_multi_index_18() const { return out_multi_index_18; }
        std::string & get_mutable_out_multi_index_18() { return out_multi_index_18; }
        void set_out_multi_index_18(const std::string & value) { this->out_multi_index_18 = value; }

        const std::string & get_out_multi_index_19() const { return out_multi_index_19; }
        std::string & get_mutable_out_multi_index_19() { return out_multi_index_19; }
        void set_out_multi_index_19(const std::string & value) { this->out_multi_index_19 = value; }

        const std::string & get_out_multi_index_2() const { return out_multi_index_2; }
        std::string & get_mutable_out_multi_index_2() { return out_multi_index_2; }
        void set_out_multi_index_2(const std::string & value) { this->out_multi_index_2 = value; }

        const std::string & get_out_multi_index_20() const { return out_multi_index_20; }
        std::string & get_mutable_out_multi_index_20() { return out_multi_index_20; }
        void set_out_multi_index_20(const std::string & value) { this->out_multi_index_20 = value; }

        const std::string & get_out_multi_index_3() const { return out_multi_index_3; }
        std::string & get_mutable_out_multi_index_3() { return out_multi_index_3; }
        void set_out_multi_index_3(const std::string & value) { this->out_multi_index_3 = value; }

        const std::string & get_out_multi_index_4() const { return out_multi_index_4; }
        std::string & get_mutable_out_multi_index_4() { return out_multi_index_4; }
        void set_out_multi_index_4(const std::string & value) { this->out_multi_index_4 = value; }

        const std::string & get_out_multi_index_5() const { return out_multi_index_5; }
        std::string & get_mutable_out_multi_index_5() { return out_multi_index_5; }
        void set_out_multi_index_5(const std::string & value) { this->out_multi_index_5 = value; }

        const std::string & get_out_multi_index_6() const { return out_multi_index_6; }
        std::string & get_mutable_out_multi_index_6() { return out_multi_index_6; }
        void set_out_multi_index_6(const std::string & value) { this->out_multi_index_6 = value; }

        const std::string & get_out_multi_index_7() const { return out_multi_index_7; }
        std::string & get_mutable_out_multi_index_7() { return out_multi_index_7; }
        void set_out_multi_index_7(const std::string & value) { this->out_multi_index_7 = value; }

        const std::string & get_out_multi_index_8() const { return out_multi_index_8; }
        std::string & get_mutable_out_multi_index_8() { return out_multi_index_8; }
        void set_out_multi_index_8(const std::string & value) { this->out_multi_index_8 = value; }

        const std::string & get_out_multi_index_9() const { return out_multi_index_9; }
        std::string & get_mutable_out_multi_index_9() { return out_multi_index_9; }
        void set_out_multi_index_9(const std::string & value) { this->out_multi_index_9 = value; }

        const std::string & get_out_single_index_1() const { return out_single_index_1; }
        std::string & get_mutable_out_single_index_1() { return out_single_index_1; }
        void set_out_single_index_1(const std::string & value) { this->out_single_index_1 = value; }

        const std::string & get_out_single_index_10() const { return out_single_index_10; }
        std::string & get_mutable_out_single_index_10() { return out_single_index_10; }
        void set_out_single_index_10(const std::string & value) { this->out_single_index_10 = value; }

        const std::string & get_out_single_index_11() const { return out_single_index_11; }
        std::string & get_mutable_out_single_index_11() { return out_single_index_11; }
        void set_out_single_index_11(const std::string & value) { this->out_single_index_11 = value; }

        const std::string & get_out_single_index_12() const { return out_single_index_12; }
        std::string & get_mutable_out_single_index_12() { return out_single_index_12; }
        void set_out_single_index_12(const std::string & value) { this->out_single_index_12 = value; }

        const std::string & get_out_single_index_13() const { return out_single_index_13; }
        std::string & get_mutable_out_single_index_13() { return out_single_index_13; }
        void set_out_single_index_13(const std::string & value) { this->out_single_index_13 = value; }

        const std::string & get_out_single_index_14() const { return out_single_index_14; }
        std::string & get_mutable_out_single_index_14() { return out_single_index_14; }
        void set_out_single_index_14(const std::string & value) { this->out_single_index_14 = value; }

        const std::string & get_out_single_index_15() const { return out_single_index_15; }
        std::string & get_mutable_out_single_index_15() { return out_single_index_15; }
        void set_out_single_index_15(const std::string & value) { this->out_single_index_15 = value; }

        const std::string & get_out_single_index_16() const { return out_single_index_16; }
        std::string & get_mutable_out_single_index_16() { return out_single_index_16; }
        void set_out_single_index_16(const std::string & value) { this->out_single_index_16 = value; }

        const std::string & get_out_single_index_17() const { return out_single_index_17; }
        std::string & get_mutable_out_single_index_17() { return out_single_index_17; }
        void set_out_single_index_17(const std::string & value) { this->out_single_index_17 = value; }

        const std::string & get_out_single_index_18() const { return out_single_index_18; }
        std::string & get_mutable_out_single_index_18() { return out_single_index_18; }
        void set_out_single_index_18(const std::string & value) { this->out_single_index_18 = value; }

        const std::string & get_out_single_index_19() const { return out_single_index_19; }
        std::string & get_mutable_out_single_index_19() { return out_single_index_19; }
        void set_out_single_index_19(const std::string & value) { this->out_single_index_19 = value; }

        const std::string & get_out_single_index_2() const { return out_single_index_2; }
        std::string & get_mutable_out_single_index_2() { return out_single_index_2; }
        void set_out_single_index_2(const std::string & value) { this->out_single_index_2 = value; }

        const std::string & get_out_single_index_20() const { return out_single_index_20; }
        std::string & get_mutable_out_single_index_20() { return out_single_index_20; }
        void set_out_single_index_20(const std::string & value) { this->out_single_index_20 = value; }

        const std::string & get_out_single_index_3() const { return out_single_index_3; }
        std::string & get_mutable_out_single_index_3() { return out_single_index_3; }
        void set_out_single_index_3(const std::string & value) { this->out_single_index_3 = value; }

        const std::string & get_out_single_index_4() const { return out_single_index_4; }
        std::string & get_mutable_out_single_index_4() { return out_single_index_4; }
        void set_out_single_index_4(const std::string & value) { this->out_single_index_4 = value; }

        const std::string & get_out_single_index_5() const { return out_single_index_5; }
        std::string & get_mutable_out_single_index_5() { return out_single_index_5; }
        void set_out_single_index_5(const std::string & value) { this->out_single_index_5 = value; }

        const std::string & get_out_single_index_6() const { return out_single_index_6; }
        std::string & get_mutable_out_single_index_6() { return out_single_index_6; }
        void set_out_single_index_6(const std::string & value) { this->out_single_index_6 = value; }

        const std::string & get_out_single_index_7() const { return out_single_index_7; }
        std::string & get_mutable_out_single_index_7() { return out_single_index_7; }
        void set_out_single_index_7(const std::string & value) { this->out_single_index_7 = value; }

        const std::string & get_out_single_index_8() const { return out_single_index_8; }
        std::string & get_mutable_out_single_index_8() { return out_single_index_8; }
        void set_out_single_index_8(const std::string & value) { this->out_single_index_8 = value; }

        const std::string & get_out_single_index_9() const { return out_single_index_9; }
        std::string & get_mutable_out_single_index_9() { return out_single_index_9; }
        void set_out_single_index_9(const std::string & value) { this->out_single_index_9 = value; }

        const std::string & get_sizeof_array() const { return sizeof_array; }
        std::string & get_mutable_sizeof_array() { return sizeof_array; }
        void set_sizeof_array(const std::string & value) { this->sizeof_array = value; }
    };

    class FluffySoilheatflows {
        public:
        FluffySoilheatflows() = default;
        virtual ~FluffySoilheatflows() = default;

        private:
        CCoarseRootsAtmLayer exact_temperature;
        TempColdPipe temp_cold_pipe;
        CCoarseRootsAtmLayer temperature;
        TempColdPipe temp_out_pipe;
        CCoarseRootsAtmLayer thermal_conductivity;
        CCoarseRootsAtmLayer thermal_qualilty;

        public:
        const CCoarseRootsAtmLayer & get_exact_temperature() const { return exact_temperature; }
        CCoarseRootsAtmLayer & get_mutable_exact_temperature() { return exact_temperature; }
        void set_exact_temperature(const CCoarseRootsAtmLayer & value) { this->exact_temperature = value; }

        const TempColdPipe & get_temp_cold_pipe() const { return temp_cold_pipe; }
        TempColdPipe & get_mutable_temp_cold_pipe() { return temp_cold_pipe; }
        void set_temp_cold_pipe(const TempColdPipe & value) { this->temp_cold_pipe = value; }

        const CCoarseRootsAtmLayer & get_temperature() const { return temperature; }
        CCoarseRootsAtmLayer & get_mutable_temperature() { return temperature; }
        void set_temperature(const CCoarseRootsAtmLayer & value) { this->temperature = value; }

        const TempColdPipe & get_temp_out_pipe() const { return temp_out_pipe; }
        TempColdPipe & get_mutable_temp_out_pipe() { return temp_out_pipe; }
        void set_temp_out_pipe(const TempColdPipe & value) { this->temp_out_pipe = value; }

        const CCoarseRootsAtmLayer & get_thermal_conductivity() const { return thermal_conductivity; }
        CCoarseRootsAtmLayer & get_mutable_thermal_conductivity() { return thermal_conductivity; }
        void set_thermal_conductivity(const CCoarseRootsAtmLayer & value) { this->thermal_conductivity = value; }

        const CCoarseRootsAtmLayer & get_thermal_qualilty() const { return thermal_qualilty; }
        CCoarseRootsAtmLayer & get_mutable_thermal_qualilty() { return thermal_qualilty; }
        void set_thermal_qualilty(const CCoarseRootsAtmLayer & value) { this->thermal_qualilty = value; }
    };

    class AuxiliaryArraysSoilHeatProcesses {
        public:
        AuxiliaryArraysSoilHeatProcesses() = default;
        virtual ~AuxiliaryArraysSoilHeatProcesses() = default;

        private:
        FluffySoilheatflows soilheatflows;

        public:
        const FluffySoilheatflows & get_soilheatflows() const { return soilheatflows; }
        FluffySoilheatflows & get_mutable_soilheatflows() { return soilheatflows; }
        void set_soilheatflows(const FluffySoilheatflows & value) { this->soilheatflows = value; }
    };

    class StickyDrainageanddeeppercolation {
        public:
        StickyDrainageanddeeppercolation() = default;
        virtual ~StickyDrainageanddeeppercolation() = default;

        private:
        CCoarseRootsAtmLayer corr_height_factor;

        public:
        const CCoarseRootsAtmLayer & get_corr_height_factor() const { return corr_height_factor; }
        CCoarseRootsAtmLayer & get_mutable_corr_height_factor() { return corr_height_factor; }
        void set_corr_height_factor(const CCoarseRootsAtmLayer & value) { this->corr_height_factor = value; }
    };

    class FluffySoilwaterflows {
        public:
        FluffySoilwaterflows() = default;
        virtual ~FluffySoilwaterflows() = default;

        private:
        CCoarseRootsAtmLayer hys_effect;
        CCoarseRootsAtmLayer mean_transit_time;
        CCoarseRootsAtmLayer pressure_head;
        CCoarseRootsAtmLayer theta_b;
        CCoarseRootsAtmLayer total_water_content;
        CCoarseRootsAtmLayer water_content;
        CCoarseRootsAtmLayer w_bypassflow;

        public:
        const CCoarseRootsAtmLayer & get_hys_effect() const { return hys_effect; }
        CCoarseRootsAtmLayer & get_mutable_hys_effect() { return hys_effect; }
        void set_hys_effect(const CCoarseRootsAtmLayer & value) { this->hys_effect = value; }

        const CCoarseRootsAtmLayer & get_mean_transit_time() const { return mean_transit_time; }
        CCoarseRootsAtmLayer & get_mutable_mean_transit_time() { return mean_transit_time; }
        void set_mean_transit_time(const CCoarseRootsAtmLayer & value) { this->mean_transit_time = value; }

        const CCoarseRootsAtmLayer & get_pressure_head() const { return pressure_head; }
        CCoarseRootsAtmLayer & get_mutable_pressure_head() { return pressure_head; }
        void set_pressure_head(const CCoarseRootsAtmLayer & value) { this->pressure_head = value; }

        const CCoarseRootsAtmLayer & get_theta_b() const { return theta_b; }
        CCoarseRootsAtmLayer & get_mutable_theta_b() { return theta_b; }
        void set_theta_b(const CCoarseRootsAtmLayer & value) { this->theta_b = value; }

        const CCoarseRootsAtmLayer & get_total_water_content() const { return total_water_content; }
        CCoarseRootsAtmLayer & get_mutable_total_water_content() { return total_water_content; }
        void set_total_water_content(const CCoarseRootsAtmLayer & value) { this->total_water_content = value; }

        const CCoarseRootsAtmLayer & get_water_content() const { return water_content; }
        CCoarseRootsAtmLayer & get_mutable_water_content() { return water_content; }
        void set_water_content(const CCoarseRootsAtmLayer & value) { this->water_content = value; }

        const CCoarseRootsAtmLayer & get_w_bypassflow() const { return w_bypassflow; }
        CCoarseRootsAtmLayer & get_mutable_w_bypassflow() { return w_bypassflow; }
        void set_w_bypassflow(const CCoarseRootsAtmLayer & value) { this->w_bypassflow = value; }
    };

    class AuxiliaryArraysSoilWaterProcesses {
        public:
        AuxiliaryArraysSoilWaterProcesses() = default;
        virtual ~AuxiliaryArraysSoilWaterProcesses() = default;

        private:
        StickyDrainageanddeeppercolation drainageanddeeppercolation;
        FluffySoilwaterflows soilwaterflows;

        public:
        const StickyDrainageanddeeppercolation & get_drainageanddeeppercolation() const { return drainageanddeeppercolation; }
        StickyDrainageanddeeppercolation & get_mutable_drainageanddeeppercolation() { return drainageanddeeppercolation; }
        void set_drainageanddeeppercolation(const StickyDrainageanddeeppercolation & value) { this->drainageanddeeppercolation = value; }

        const FluffySoilwaterflows & get_soilwaterflows() const { return soilwaterflows; }
        FluffySoilwaterflows & get_mutable_soilwaterflows() { return soilwaterflows; }
        void set_soilwaterflows(const FluffySoilwaterflows & value) { this->soilwaterflows = value; }
    };

    class AuxiliaryArrays {
        public:
        AuxiliaryArrays() = default;
        virtual ~AuxiliaryArrays() = default;

        private:
        AuxiliaryArraysAtmosphericRelatedProcesses atmospheric_related_processes;
        AuxiliaryArraysNitrogenandCarbon nitrogenand_carbon;
        AuxiliaryArraysNitrogenandCarbonBelowGround nitrogenand_carbon_below_ground;
        AuxiliaryArraysPlantWaterProcesses plant_water_processes;
        AuxiliaryArraysSoilHeatProcesses soil_heat_processes;
        AuxiliaryArraysSoilWaterProcesses soil_water_processes;

        public:
        const AuxiliaryArraysAtmosphericRelatedProcesses & get_atmospheric_related_processes() const { return atmospheric_related_processes; }
        AuxiliaryArraysAtmosphericRelatedProcesses & get_mutable_atmospheric_related_processes() { return atmospheric_related_processes; }
        void set_atmospheric_related_processes(const AuxiliaryArraysAtmosphericRelatedProcesses & value) { this->atmospheric_related_processes = value; }

        const AuxiliaryArraysNitrogenandCarbon & get_nitrogenand_carbon() const { return nitrogenand_carbon; }
        AuxiliaryArraysNitrogenandCarbon & get_mutable_nitrogenand_carbon() { return nitrogenand_carbon; }
        void set_nitrogenand_carbon(const AuxiliaryArraysNitrogenandCarbon & value) { this->nitrogenand_carbon = value; }

        const AuxiliaryArraysNitrogenandCarbonBelowGround & get_nitrogenand_carbon_below_ground() const { return nitrogenand_carbon_below_ground; }
        AuxiliaryArraysNitrogenandCarbonBelowGround & get_mutable_nitrogenand_carbon_below_ground() { return nitrogenand_carbon_below_ground; }
        void set_nitrogenand_carbon_below_ground(const AuxiliaryArraysNitrogenandCarbonBelowGround & value) { this->nitrogenand_carbon_below_ground = value; }

        const AuxiliaryArraysPlantWaterProcesses & get_plant_water_processes() const { return plant_water_processes; }
        AuxiliaryArraysPlantWaterProcesses & get_mutable_plant_water_processes() { return plant_water_processes; }
        void set_plant_water_processes(const AuxiliaryArraysPlantWaterProcesses & value) { this->plant_water_processes = value; }

        const AuxiliaryArraysSoilHeatProcesses & get_soil_heat_processes() const { return soil_heat_processes; }
        AuxiliaryArraysSoilHeatProcesses & get_mutable_soil_heat_processes() { return soil_heat_processes; }
        void set_soil_heat_processes(const AuxiliaryArraysSoilHeatProcesses & value) { this->soil_heat_processes = value; }

        const AuxiliaryArraysSoilWaterProcesses & get_soil_water_processes() const { return soil_water_processes; }
        AuxiliaryArraysSoilWaterProcesses & get_mutable_soil_water_processes() { return soil_water_processes; }
        void set_soil_water_processes(const AuxiliaryArraysSoilWaterProcesses & value) { this->soil_water_processes = value; }
    };

    class FluffySnowPack {
        public:
        FluffySnowPack() = default;
        virtual ~FluffySnowPack() = default;

        private:
        AlbedoVar snow_measured;

        public:
        const AlbedoVar & get_snow_measured() const { return snow_measured; }
        AlbedoVar & get_mutable_snow_measured() { return snow_measured; }
        void set_snow_measured(const AlbedoVar & value) { this->snow_measured = value; }
    };

    class DrivingAtmosphericRelatedProcesses {
        public:
        DrivingAtmosphericRelatedProcesses() = default;
        virtual ~DrivingAtmosphericRelatedProcesses() = default;

        private:
        std::map<std::string, CanopyFracRadDiffuse> meteorological_data;
        FluffySnowPack snow_pack;

        public:
        const std::map<std::string, CanopyFracRadDiffuse> & get_meteorological_data() const { return meteorological_data; }
        std::map<std::string, CanopyFracRadDiffuse> & get_mutable_meteorological_data() { return meteorological_data; }
        void set_meteorological_data(const std::map<std::string, CanopyFracRadDiffuse> & value) { this->meteorological_data = value; }

        const FluffySnowPack & get_snow_pack() const { return snow_pack; }
        FluffySnowPack & get_mutable_snow_pack() { return snow_pack; }
        void set_snow_pack(const FluffySnowPack & value) { this->snow_pack = value; }
    };

    class FluffyAbioticdrivingvariables {
        public:
        FluffyAbioticdrivingvariables() = default;
        virtual ~FluffyAbioticdrivingvariables() = default;

        private:
        CanopyFracRadDiffuse green_index_change;
        CanopyFracRadDiffuse n_driv_deep_percolation;
        CanopyFracRadDiffuse n_driv_infiltration;

        public:
        const CanopyFracRadDiffuse & get_green_index_change() const { return green_index_change; }
        CanopyFracRadDiffuse & get_mutable_green_index_change() { return green_index_change; }
        void set_green_index_change(const CanopyFracRadDiffuse & value) { this->green_index_change = value; }

        const CanopyFracRadDiffuse & get_n_driv_deep_percolation() const { return n_driv_deep_percolation; }
        CanopyFracRadDiffuse & get_mutable_n_driv_deep_percolation() { return n_driv_deep_percolation; }
        void set_n_driv_deep_percolation(const CanopyFracRadDiffuse & value) { this->n_driv_deep_percolation = value; }

        const CanopyFracRadDiffuse & get_n_driv_infiltration() const { return n_driv_infiltration; }
        CanopyFracRadDiffuse & get_mutable_n_driv_infiltration() { return n_driv_infiltration; }
        void set_n_driv_infiltration(const CanopyFracRadDiffuse & value) { this->n_driv_infiltration = value; }
    };

    class DrivingNitrogenandCarbonBelowGround {
        public:
        DrivingNitrogenandCarbonBelowGround() = default;
        virtual ~DrivingNitrogenandCarbonBelowGround() = default;

        private:
        FluffyAbioticdrivingvariables abioticdrivingvariables;

        public:
        const FluffyAbioticdrivingvariables & get_abioticdrivingvariables() const { return abioticdrivingvariables; }
        FluffyAbioticdrivingvariables & get_mutable_abioticdrivingvariables() { return abioticdrivingvariables; }
        void set_abioticdrivingvariables(const FluffyAbioticdrivingvariables & value) { this->abioticdrivingvariables = value; }
    };

    class TentacledSaltTracer {
        public:
        TentacledSaltTracer() = default;
        virtual ~TentacledSaltTracer() = default;

        private:
        AlbedoVar salt_air_deposition;
        AlbedoVar salt_infil_conc;
        AlbedoVar salt_irrigation_conc;
        AlbedoVar salt_plough_deposition;
        AlbedoVar salt_run_off_deposition;

        public:
        const AlbedoVar & get_salt_air_deposition() const { return salt_air_deposition; }
        AlbedoVar & get_mutable_salt_air_deposition() { return salt_air_deposition; }
        void set_salt_air_deposition(const AlbedoVar & value) { this->salt_air_deposition = value; }

        const AlbedoVar & get_salt_infil_conc() const { return salt_infil_conc; }
        AlbedoVar & get_mutable_salt_infil_conc() { return salt_infil_conc; }
        void set_salt_infil_conc(const AlbedoVar & value) { this->salt_infil_conc = value; }

        const AlbedoVar & get_salt_irrigation_conc() const { return salt_irrigation_conc; }
        AlbedoVar & get_mutable_salt_irrigation_conc() { return salt_irrigation_conc; }
        void set_salt_irrigation_conc(const AlbedoVar & value) { this->salt_irrigation_conc = value; }

        const AlbedoVar & get_salt_plough_deposition() const { return salt_plough_deposition; }
        AlbedoVar & get_mutable_salt_plough_deposition() { return salt_plough_deposition; }
        void set_salt_plough_deposition(const AlbedoVar & value) { this->salt_plough_deposition = value; }

        const AlbedoVar & get_salt_run_off_deposition() const { return salt_run_off_deposition; }
        AlbedoVar & get_mutable_salt_run_off_deposition() { return salt_run_off_deposition; }
        void set_salt_run_off_deposition(const AlbedoVar & value) { this->salt_run_off_deposition = value; }
    };

    class DrivingPlantWaterProcesses {
        public:
        DrivingPlantWaterProcesses() = default;
        virtual ~DrivingPlantWaterProcesses() = default;

        private:
        TentacledSaltTracer salt_tracer;

        public:
        const TentacledSaltTracer & get_salt_tracer() const { return salt_tracer; }
        TentacledSaltTracer & get_mutable_salt_tracer() { return salt_tracer; }
        void set_salt_tracer(const TentacledSaltTracer & value) { this->salt_tracer = value; }
    };

    class Driving {
        public:
        Driving() = default;
        virtual ~Driving() = default;

        private:
        DrivingAtmosphericRelatedProcesses atmospheric_related_processes;
        DrivingNitrogenandCarbonBelowGround nitrogenand_carbon_below_ground;
        DrivingPlantWaterProcesses plant_water_processes;

        public:
        const DrivingAtmosphericRelatedProcesses & get_atmospheric_related_processes() const { return atmospheric_related_processes; }
        DrivingAtmosphericRelatedProcesses & get_mutable_atmospheric_related_processes() { return atmospheric_related_processes; }
        void set_atmospheric_related_processes(const DrivingAtmosphericRelatedProcesses & value) { this->atmospheric_related_processes = value; }

        const DrivingNitrogenandCarbonBelowGround & get_nitrogenand_carbon_below_ground() const { return nitrogenand_carbon_below_ground; }
        DrivingNitrogenandCarbonBelowGround & get_mutable_nitrogenand_carbon_below_ground() { return nitrogenand_carbon_below_ground; }
        void set_nitrogenand_carbon_below_ground(const DrivingNitrogenandCarbonBelowGround & value) { this->nitrogenand_carbon_below_ground = value; }

        const DrivingPlantWaterProcesses & get_plant_water_processes() const { return plant_water_processes; }
        DrivingPlantWaterProcesses & get_mutable_plant_water_processes() { return plant_water_processes; }
        void set_plant_water_processes(const DrivingPlantWaterProcesses & value) { this->plant_water_processes = value; }
    };

    class TentacledMeteorologicalData {
        public:
        TentacledMeteorologicalData() = default;
        virtual ~TentacledMeteorologicalData() = default;

        private:
        CCoarseRootsAtmLayer wsource;

        public:
        const CCoarseRootsAtmLayer & get_wsource() const { return wsource; }
        CCoarseRootsAtmLayer & get_mutable_wsource() { return wsource; }
        void set_wsource(const CCoarseRootsAtmLayer & value) { this->wsource = value; }
    };

    class DrivingArraysAtmosphericRelatedProcesses {
        public:
        DrivingArraysAtmosphericRelatedProcesses() = default;
        virtual ~DrivingArraysAtmosphericRelatedProcesses() = default;

        private:
        TentacledMeteorologicalData meteorological_data;

        public:
        const TentacledMeteorologicalData & get_meteorological_data() const { return meteorological_data; }
        TentacledMeteorologicalData & get_mutable_meteorological_data() { return meteorological_data; }
        void set_meteorological_data(const TentacledMeteorologicalData & value) { this->meteorological_data = value; }
    };

    class TentacledAbioticdrivingvariables {
        public:
        TentacledAbioticdrivingvariables() = default;
        virtual ~TentacledAbioticdrivingvariables() = default;

        private:
        CCoarseRootsAtmLayer n_driv_drainage;
        SnowReduceLaiFactor n_driv_salt_stress;
        CCoarseRootsAtmLayer n_driv_temperature;
        CCoarseRootsAtmLayer n_driv_theta;
        CCoarseRootsAtmLayer n_driv_water_flow;
        SnowReduceLaiFactor n_driv_water_stress;

        public:
        const CCoarseRootsAtmLayer & get_n_driv_drainage() const { return n_driv_drainage; }
        CCoarseRootsAtmLayer & get_mutable_n_driv_drainage() { return n_driv_drainage; }
        void set_n_driv_drainage(const CCoarseRootsAtmLayer & value) { this->n_driv_drainage = value; }

        const SnowReduceLaiFactor & get_n_driv_salt_stress() const { return n_driv_salt_stress; }
        SnowReduceLaiFactor & get_mutable_n_driv_salt_stress() { return n_driv_salt_stress; }
        void set_n_driv_salt_stress(const SnowReduceLaiFactor & value) { this->n_driv_salt_stress = value; }

        const CCoarseRootsAtmLayer & get_n_driv_temperature() const { return n_driv_temperature; }
        CCoarseRootsAtmLayer & get_mutable_n_driv_temperature() { return n_driv_temperature; }
        void set_n_driv_temperature(const CCoarseRootsAtmLayer & value) { this->n_driv_temperature = value; }

        const CCoarseRootsAtmLayer & get_n_driv_theta() const { return n_driv_theta; }
        CCoarseRootsAtmLayer & get_mutable_n_driv_theta() { return n_driv_theta; }
        void set_n_driv_theta(const CCoarseRootsAtmLayer & value) { this->n_driv_theta = value; }

        const CCoarseRootsAtmLayer & get_n_driv_water_flow() const { return n_driv_water_flow; }
        CCoarseRootsAtmLayer & get_mutable_n_driv_water_flow() { return n_driv_water_flow; }
        void set_n_driv_water_flow(const CCoarseRootsAtmLayer & value) { this->n_driv_water_flow = value; }

        const SnowReduceLaiFactor & get_n_driv_water_stress() const { return n_driv_water_stress; }
        SnowReduceLaiFactor & get_mutable_n_driv_water_stress() { return n_driv_water_stress; }
        void set_n_driv_water_stress(const SnowReduceLaiFactor & value) { this->n_driv_water_stress = value; }
    };

    class DrivingArraysNitrogenandCarbonBelowGround {
        public:
        DrivingArraysNitrogenandCarbonBelowGround() = default;
        virtual ~DrivingArraysNitrogenandCarbonBelowGround() = default;

        private:
        TentacledAbioticdrivingvariables abioticdrivingvariables;

        public:
        const TentacledAbioticdrivingvariables & get_abioticdrivingvariables() const { return abioticdrivingvariables; }
        TentacledAbioticdrivingvariables & get_mutable_abioticdrivingvariables() { return abioticdrivingvariables; }
        void set_abioticdrivingvariables(const TentacledAbioticdrivingvariables & value) { this->abioticdrivingvariables = value; }
    };

    class DrivingArrays {
        public:
        DrivingArrays() = default;
        virtual ~DrivingArrays() = default;

        private:
        DrivingArraysAtmosphericRelatedProcesses atmospheric_related_processes;
        DrivingArraysNitrogenandCarbonBelowGround nitrogenand_carbon_below_ground;

        public:
        const DrivingArraysAtmosphericRelatedProcesses & get_atmospheric_related_processes() const { return atmospheric_related_processes; }
        DrivingArraysAtmosphericRelatedProcesses & get_mutable_atmospheric_related_processes() { return atmospheric_related_processes; }
        void set_atmospheric_related_processes(const DrivingArraysAtmosphericRelatedProcesses & value) { this->atmospheric_related_processes = value; }

        const DrivingArraysNitrogenandCarbonBelowGround & get_nitrogenand_carbon_below_ground() const { return nitrogenand_carbon_below_ground; }
        DrivingArraysNitrogenandCarbonBelowGround & get_mutable_nitrogenand_carbon_below_ground() { return nitrogenand_carbon_below_ground; }
        void set_nitrogenand_carbon_below_ground(const DrivingArraysNitrogenandCarbonBelowGround & value) { this->nitrogenand_carbon_below_ground = value; }
    };

    class TentacledSnowPack {
        public:
        TentacledSnowPack() = default;
        virtual ~TentacledSnowPack() = default;

        private:
        CanopyFracRadDiffuse snow_evaporation;
        CanopyFracRadDiffuse snow_inflow;
        CanopyFracRadDiffuse snowmassexport;
        CanopyFracRadDiffuse snowmassimport;
        CanopyFracRadDiffuse snow_water_outflow;

        public:
        const CanopyFracRadDiffuse & get_snow_evaporation() const { return snow_evaporation; }
        CanopyFracRadDiffuse & get_mutable_snow_evaporation() { return snow_evaporation; }
        void set_snow_evaporation(const CanopyFracRadDiffuse & value) { this->snow_evaporation = value; }

        const CanopyFracRadDiffuse & get_snow_inflow() const { return snow_inflow; }
        CanopyFracRadDiffuse & get_mutable_snow_inflow() { return snow_inflow; }
        void set_snow_inflow(const CanopyFracRadDiffuse & value) { this->snow_inflow = value; }

        const CanopyFracRadDiffuse & get_snowmassexport() const { return snowmassexport; }
        CanopyFracRadDiffuse & get_mutable_snowmassexport() { return snowmassexport; }
        void set_snowmassexport(const CanopyFracRadDiffuse & value) { this->snowmassexport = value; }

        const CanopyFracRadDiffuse & get_snowmassimport() const { return snowmassimport; }
        CanopyFracRadDiffuse & get_mutable_snowmassimport() { return snowmassimport; }
        void set_snowmassimport(const CanopyFracRadDiffuse & value) { this->snowmassimport = value; }

        const CanopyFracRadDiffuse & get_snow_water_outflow() const { return snow_water_outflow; }
        CanopyFracRadDiffuse & get_mutable_snow_water_outflow() { return snow_water_outflow; }
        void set_snow_water_outflow(const CanopyFracRadDiffuse & value) { this->snow_water_outflow = value; }
    };

    class FluffySoilevaporation {
        public:
        FluffySoilevaporation() = default;
        virtual ~FluffySoilevaporation() = default;

        private:
        AlbedoVar soil_evaporation;
        AlbedoVar soil_evaporation1;
        AlbedoVar soil_evaporation2;
        AlbedoVar surf_heat_flow1;
        AlbedoVar surf_heat_flow2;

        public:
        const AlbedoVar & get_soil_evaporation() const { return soil_evaporation; }
        AlbedoVar & get_mutable_soil_evaporation() { return soil_evaporation; }
        void set_soil_evaporation(const AlbedoVar & value) { this->soil_evaporation = value; }

        const AlbedoVar & get_soil_evaporation1() const { return soil_evaporation1; }
        AlbedoVar & get_mutable_soil_evaporation1() { return soil_evaporation1; }
        void set_soil_evaporation1(const AlbedoVar & value) { this->soil_evaporation1 = value; }

        const AlbedoVar & get_soil_evaporation2() const { return soil_evaporation2; }
        AlbedoVar & get_mutable_soil_evaporation2() { return soil_evaporation2; }
        void set_soil_evaporation2(const AlbedoVar & value) { this->soil_evaporation2 = value; }

        const AlbedoVar & get_surf_heat_flow1() const { return surf_heat_flow1; }
        AlbedoVar & get_mutable_surf_heat_flow1() { return surf_heat_flow1; }
        void set_surf_heat_flow1(const AlbedoVar & value) { this->surf_heat_flow1 = value; }

        const AlbedoVar & get_surf_heat_flow2() const { return surf_heat_flow2; }
        AlbedoVar & get_mutable_surf_heat_flow2() { return surf_heat_flow2; }
        void set_surf_heat_flow2(const AlbedoVar & value) { this->surf_heat_flow2 = value; }
    };

    class FlowAtmosphericRelatedProcesses {
        public:
        FlowAtmosphericRelatedProcesses() = default;
        virtual ~FlowAtmosphericRelatedProcesses() = default;

        private:
        TentacledSnowPack snow_pack;
        FluffySoilevaporation soilevaporation;

        public:
        const TentacledSnowPack & get_snow_pack() const { return snow_pack; }
        TentacledSnowPack & get_mutable_snow_pack() { return snow_pack; }
        void set_snow_pack(const TentacledSnowPack & value) { this->snow_pack = value; }

        const FluffySoilevaporation & get_soilevaporation() const { return soilevaporation; }
        FluffySoilevaporation & get_mutable_soilevaporation() { return soilevaporation; }
        void set_soilevaporation(const FluffySoilevaporation & value) { this->soilevaporation = value; }
    };

    class PurpleIrrigation {
        public:
        PurpleIrrigation() = default;
        virtual ~PurpleIrrigation() = default;

        private:
        CanopyFracRadDiffuse drip_fill;
        CanopyFracRadDiffuse drip_outlet;

        public:
        const CanopyFracRadDiffuse & get_drip_fill() const { return drip_fill; }
        CanopyFracRadDiffuse & get_mutable_drip_fill() { return drip_fill; }
        void set_drip_fill(const CanopyFracRadDiffuse & value) { this->drip_fill = value; }

        const CanopyFracRadDiffuse & get_drip_outlet() const { return drip_outlet; }
        CanopyFracRadDiffuse & get_mutable_drip_outlet() { return drip_outlet; }
        void set_drip_outlet(const CanopyFracRadDiffuse & value) { this->drip_outlet = value; }
    };

    class FlowModelFacilities {
        public:
        FlowModelFacilities() = default;
        virtual ~FlowModelFacilities() = default;

        private:
        PurpleIrrigation irrigation;

        public:
        const PurpleIrrigation & get_irrigation() const { return irrigation; }
        PurpleIrrigation & get_mutable_irrigation() { return irrigation; }
        void set_irrigation(const PurpleIrrigation & value) { this->irrigation = value; }
    };

    class PurpleExternalPInputs {
        public:
        PurpleExternalPInputs() = default;
        virtual ~PurpleExternalPInputs() = default;

        private:
        CanopyFracRadDiffuse p_fert_appl_rate;
        CanopyFracRadDiffuse p_fert_solution_rate;

        public:
        const CanopyFracRadDiffuse & get_p_fert_appl_rate() const { return p_fert_appl_rate; }
        CanopyFracRadDiffuse & get_mutable_p_fert_appl_rate() { return p_fert_appl_rate; }
        void set_p_fert_appl_rate(const CanopyFracRadDiffuse & value) { this->p_fert_appl_rate = value; }

        const CanopyFracRadDiffuse & get_p_fert_solution_rate() const { return p_fert_solution_rate; }
        CanopyFracRadDiffuse & get_mutable_p_fert_solution_rate() { return p_fert_solution_rate; }
        void set_p_fert_solution_rate(const CanopyFracRadDiffuse & value) { this->p_fert_solution_rate = value; }
    };

    class FlowNitrogenandCarbon {
        public:
        FlowNitrogenandCarbon() = default;
        virtual ~FlowNitrogenandCarbon() = default;

        private:
        std::map<std::string, AlbedoVar> external_ninputs;
        PurpleExternalPInputs external_p_inputs;
        std::map<std::string, AlbedoVar> plant_growth;

        public:
        const std::map<std::string, AlbedoVar> & get_external_ninputs() const { return external_ninputs; }
        std::map<std::string, AlbedoVar> & get_mutable_external_ninputs() { return external_ninputs; }
        void set_external_ninputs(const std::map<std::string, AlbedoVar> & value) { this->external_ninputs = value; }

        const PurpleExternalPInputs & get_external_p_inputs() const { return external_p_inputs; }
        PurpleExternalPInputs & get_mutable_external_p_inputs() { return external_p_inputs; }
        void set_external_p_inputs(const PurpleExternalPInputs & value) { this->external_p_inputs = value; }

        const std::map<std::string, AlbedoVar> & get_plant_growth() const { return plant_growth; }
        std::map<std::string, AlbedoVar> & get_mutable_plant_growth() { return plant_growth; }
        void set_plant_growth(const std::map<std::string, AlbedoVar> & value) { this->plant_growth = value; }
    };

    class FluffyGasprocesses {
        public:
        FluffyGasprocesses() = default;
        virtual ~FluffyGasprocesses() = default;

        private:
        CanopyFracRadDiffuse ch4_surface_emission;
        CanopyFracRadDiffuse co2_flux_out;
        CanopyFracRadDiffuse n2_emissionrate;
        CanopyFracRadDiffuse n2_oemissionrate;
        CanopyFracRadDiffuse n_oemissionrate;
        CanopyFracRadDiffuse oxygen_flux_infil;

        public:
        const CanopyFracRadDiffuse & get_ch4_surface_emission() const { return ch4_surface_emission; }
        CanopyFracRadDiffuse & get_mutable_ch4_surface_emission() { return ch4_surface_emission; }
        void set_ch4_surface_emission(const CanopyFracRadDiffuse & value) { this->ch4_surface_emission = value; }

        const CanopyFracRadDiffuse & get_co2_flux_out() const { return co2_flux_out; }
        CanopyFracRadDiffuse & get_mutable_co2_flux_out() { return co2_flux_out; }
        void set_co2_flux_out(const CanopyFracRadDiffuse & value) { this->co2_flux_out = value; }

        const CanopyFracRadDiffuse & get_n2_emissionrate() const { return n2_emissionrate; }
        CanopyFracRadDiffuse & get_mutable_n2_emissionrate() { return n2_emissionrate; }
        void set_n2_emissionrate(const CanopyFracRadDiffuse & value) { this->n2_emissionrate = value; }

        const CanopyFracRadDiffuse & get_n2_oemissionrate() const { return n2_oemissionrate; }
        CanopyFracRadDiffuse & get_mutable_n2_oemissionrate() { return n2_oemissionrate; }
        void set_n2_oemissionrate(const CanopyFracRadDiffuse & value) { this->n2_oemissionrate = value; }

        const CanopyFracRadDiffuse & get_n_oemissionrate() const { return n_oemissionrate; }
        CanopyFracRadDiffuse & get_mutable_n_oemissionrate() { return n_oemissionrate; }
        void set_n_oemissionrate(const CanopyFracRadDiffuse & value) { this->n_oemissionrate = value; }

        const CanopyFracRadDiffuse & get_oxygen_flux_infil() const { return oxygen_flux_infil; }
        CanopyFracRadDiffuse & get_mutable_oxygen_flux_infil() { return oxygen_flux_infil; }
        void set_oxygen_flux_infil(const CanopyFracRadDiffuse & value) { this->oxygen_flux_infil = value; }
    };

    class TentacledSoilmineralPProcesses {
        public:
        TentacledSoilmineralPProcesses() = default;
        virtual ~TentacledSoilmineralPProcesses() = default;

        private:
        AlbedoVar p_surface_runoff;

        public:
        const AlbedoVar & get_p_surface_runoff() const { return p_surface_runoff; }
        AlbedoVar & get_mutable_p_surface_runoff() { return p_surface_runoff; }
        void set_p_surface_runoff(const AlbedoVar & value) { this->p_surface_runoff = value; }
    };

    class PurpleSoilorganicprocesses {
        public:
        PurpleSoilorganicprocesses() = default;
        virtual ~PurpleSoilorganicprocesses() = default;

        private:
        CanopyFracRadDiffuse c_surface_l_litter1;
        CanopyFracRadDiffuse c_surface_l_litter2;
        CanopyFracRadDiffuse n_surface_l_litter1;
        CanopyFracRadDiffuse n_surface_l_litter2;
        CanopyFracRadDiffuse p_surface_l_litter1;
        CanopyFracRadDiffuse p_surface_l_litter2;

        public:
        const CanopyFracRadDiffuse & get_c_surface_l_litter1() const { return c_surface_l_litter1; }
        CanopyFracRadDiffuse & get_mutable_c_surface_l_litter1() { return c_surface_l_litter1; }
        void set_c_surface_l_litter1(const CanopyFracRadDiffuse & value) { this->c_surface_l_litter1 = value; }

        const CanopyFracRadDiffuse & get_c_surface_l_litter2() const { return c_surface_l_litter2; }
        CanopyFracRadDiffuse & get_mutable_c_surface_l_litter2() { return c_surface_l_litter2; }
        void set_c_surface_l_litter2(const CanopyFracRadDiffuse & value) { this->c_surface_l_litter2 = value; }

        const CanopyFracRadDiffuse & get_n_surface_l_litter1() const { return n_surface_l_litter1; }
        CanopyFracRadDiffuse & get_mutable_n_surface_l_litter1() { return n_surface_l_litter1; }
        void set_n_surface_l_litter1(const CanopyFracRadDiffuse & value) { this->n_surface_l_litter1 = value; }

        const CanopyFracRadDiffuse & get_n_surface_l_litter2() const { return n_surface_l_litter2; }
        CanopyFracRadDiffuse & get_mutable_n_surface_l_litter2() { return n_surface_l_litter2; }
        void set_n_surface_l_litter2(const CanopyFracRadDiffuse & value) { this->n_surface_l_litter2 = value; }

        const CanopyFracRadDiffuse & get_p_surface_l_litter1() const { return p_surface_l_litter1; }
        CanopyFracRadDiffuse & get_mutable_p_surface_l_litter1() { return p_surface_l_litter1; }
        void set_p_surface_l_litter1(const CanopyFracRadDiffuse & value) { this->p_surface_l_litter1 = value; }

        const CanopyFracRadDiffuse & get_p_surface_l_litter2() const { return p_surface_l_litter2; }
        CanopyFracRadDiffuse & get_mutable_p_surface_l_litter2() { return p_surface_l_litter2; }
        void set_p_surface_l_litter2(const CanopyFracRadDiffuse & value) { this->p_surface_l_litter2 = value; }
    };

    class FlowNitrogenandCarbonBelowGround {
        public:
        FlowNitrogenandCarbonBelowGround() = default;
        virtual ~FlowNitrogenandCarbonBelowGround() = default;

        private:
        FluffyGasprocesses gasprocesses;
        TentacledSoilmineralPProcesses soilmineral_p_processes;
        PurpleSoilorganicprocesses soilorganicprocesses;

        public:
        const FluffyGasprocesses & get_gasprocesses() const { return gasprocesses; }
        FluffyGasprocesses & get_mutable_gasprocesses() { return gasprocesses; }
        void set_gasprocesses(const FluffyGasprocesses & value) { this->gasprocesses = value; }

        const TentacledSoilmineralPProcesses & get_soilmineral_p_processes() const { return soilmineral_p_processes; }
        TentacledSoilmineralPProcesses & get_mutable_soilmineral_p_processes() { return soilmineral_p_processes; }
        void set_soilmineral_p_processes(const TentacledSoilmineralPProcesses & value) { this->soilmineral_p_processes = value; }

        const PurpleSoilorganicprocesses & get_soilorganicprocesses() const { return soilorganicprocesses; }
        PurpleSoilorganicprocesses & get_mutable_soilorganicprocesses() { return soilorganicprocesses; }
        void set_soilorganicprocesses(const PurpleSoilorganicprocesses & value) { this->soilorganicprocesses = value; }
    };

    class FlowPlantWaterProcesses {
        public:
        FlowPlantWaterProcesses() = default;
        virtual ~FlowPlantWaterProcesses() = default;

        private:
        std::map<std::string, AlbedoVar> salt_tracer;

        public:
        const std::map<std::string, AlbedoVar> & get_salt_tracer() const { return salt_tracer; }
        std::map<std::string, AlbedoVar> & get_mutable_salt_tracer() { return salt_tracer; }
        void set_salt_tracer(const std::map<std::string, AlbedoVar> & value) { this->salt_tracer = value; }
    };

    class Soilheatpump {
        public:
        Soilheatpump() = default;
        virtual ~Soilheatpump() = default;

        private:
        AlbedoVar heat_pump_flow;

        public:
        const AlbedoVar & get_heat_pump_flow() const { return heat_pump_flow; }
        AlbedoVar & get_mutable_heat_pump_flow() { return heat_pump_flow; }
        void set_heat_pump_flow(const AlbedoVar & value) { this->heat_pump_flow = value; }
    };

    class FlowSoilHeatProcesses {
        public:
        FlowSoilHeatProcesses() = default;
        virtual ~FlowSoilHeatProcesses() = default;

        private:
        std::map<std::string, CanopyFracRadDiffuse> soilheatflows;
        Soilheatpump soilheatpump;

        public:
        const std::map<std::string, CanopyFracRadDiffuse> & get_soilheatflows() const { return soilheatflows; }
        std::map<std::string, CanopyFracRadDiffuse> & get_mutable_soilheatflows() { return soilheatflows; }
        void set_soilheatflows(const std::map<std::string, CanopyFracRadDiffuse> & value) { this->soilheatflows = value; }

        const Soilheatpump & get_soilheatpump() const { return soilheatpump; }
        Soilheatpump & get_mutable_soilheatpump() { return soilheatpump; }
        void set_soilheatpump(const Soilheatpump & value) { this->soilheatpump = value; }
    };

    class IndigoDrainageanddeeppercolation {
        public:
        IndigoDrainageanddeeppercolation() = default;
        virtual ~IndigoDrainageanddeeppercolation() = default;

        private:
        CanopyFracRadDiffuse deep_perc;
        CanopyFracRadDiffuse net_emp_drainage;
        CanopyFracRadDiffuse net_phys_drainage;
        CanopyFracRadDiffuse total_drainage;
        CanopyFracRadDiffuse total_runoff;
        CanopyFracRadDiffuse v_drive_drain_level;

        public:
        const CanopyFracRadDiffuse & get_deep_perc() const { return deep_perc; }
        CanopyFracRadDiffuse & get_mutable_deep_perc() { return deep_perc; }
        void set_deep_perc(const CanopyFracRadDiffuse & value) { this->deep_perc = value; }

        const CanopyFracRadDiffuse & get_net_emp_drainage() const { return net_emp_drainage; }
        CanopyFracRadDiffuse & get_mutable_net_emp_drainage() { return net_emp_drainage; }
        void set_net_emp_drainage(const CanopyFracRadDiffuse & value) { this->net_emp_drainage = value; }

        const CanopyFracRadDiffuse & get_net_phys_drainage() const { return net_phys_drainage; }
        CanopyFracRadDiffuse & get_mutable_net_phys_drainage() { return net_phys_drainage; }
        void set_net_phys_drainage(const CanopyFracRadDiffuse & value) { this->net_phys_drainage = value; }

        const CanopyFracRadDiffuse & get_total_drainage() const { return total_drainage; }
        CanopyFracRadDiffuse & get_mutable_total_drainage() { return total_drainage; }
        void set_total_drainage(const CanopyFracRadDiffuse & value) { this->total_drainage = value; }

        const CanopyFracRadDiffuse & get_total_runoff() const { return total_runoff; }
        CanopyFracRadDiffuse & get_mutable_total_runoff() { return total_runoff; }
        void set_total_runoff(const CanopyFracRadDiffuse & value) { this->total_runoff = value; }

        const CanopyFracRadDiffuse & get_v_drive_drain_level() const { return v_drive_drain_level; }
        CanopyFracRadDiffuse & get_mutable_v_drive_drain_level() { return v_drive_drain_level; }
        void set_v_drive_drain_level(const CanopyFracRadDiffuse & value) { this->v_drive_drain_level = value; }
    };

    class TentacledSoilwaterflows {
        public:
        TentacledSoilwaterflows() = default;
        virtual ~TentacledSoilwaterflows() = default;

        private:
        AlbedoVar surface_out_flow;
        AlbedoVar vapourflow_surf;

        public:
        const AlbedoVar & get_surface_out_flow() const { return surface_out_flow; }
        AlbedoVar & get_mutable_surface_out_flow() { return surface_out_flow; }
        void set_surface_out_flow(const AlbedoVar & value) { this->surface_out_flow = value; }

        const AlbedoVar & get_vapourflow_surf() const { return vapourflow_surf; }
        AlbedoVar & get_mutable_vapourflow_surf() { return vapourflow_surf; }
        void set_vapourflow_surf(const AlbedoVar & value) { this->vapourflow_surf = value; }
    };

    class TentacledSurfacewater {
        public:
        TentacledSurfacewater() = default;
        virtual ~TentacledSurfacewater() = default;

        private:
        CanopyFracRadDiffuse furrow_infil;
        CanopyFracRadDiffuse furrow_prec;
        CanopyFracRadDiffuse pump_in_flow;
        CanopyFracRadDiffuse pump_out_flow;
        CanopyFracRadDiffuse soil_infil;
        CanopyFracRadDiffuse spool_delay_runoff;
        CanopyFracRadDiffuse spoolinflow;
        CanopyFracRadDiffuse spool_runoff;
        CanopyFracRadDiffuse spool_soil_infil;

        public:
        const CanopyFracRadDiffuse & get_furrow_infil() const { return furrow_infil; }
        CanopyFracRadDiffuse & get_mutable_furrow_infil() { return furrow_infil; }
        void set_furrow_infil(const CanopyFracRadDiffuse & value) { this->furrow_infil = value; }

        const CanopyFracRadDiffuse & get_furrow_prec() const { return furrow_prec; }
        CanopyFracRadDiffuse & get_mutable_furrow_prec() { return furrow_prec; }
        void set_furrow_prec(const CanopyFracRadDiffuse & value) { this->furrow_prec = value; }

        const CanopyFracRadDiffuse & get_pump_in_flow() const { return pump_in_flow; }
        CanopyFracRadDiffuse & get_mutable_pump_in_flow() { return pump_in_flow; }
        void set_pump_in_flow(const CanopyFracRadDiffuse & value) { this->pump_in_flow = value; }

        const CanopyFracRadDiffuse & get_pump_out_flow() const { return pump_out_flow; }
        CanopyFracRadDiffuse & get_mutable_pump_out_flow() { return pump_out_flow; }
        void set_pump_out_flow(const CanopyFracRadDiffuse & value) { this->pump_out_flow = value; }

        const CanopyFracRadDiffuse & get_soil_infil() const { return soil_infil; }
        CanopyFracRadDiffuse & get_mutable_soil_infil() { return soil_infil; }
        void set_soil_infil(const CanopyFracRadDiffuse & value) { this->soil_infil = value; }

        const CanopyFracRadDiffuse & get_spool_delay_runoff() const { return spool_delay_runoff; }
        CanopyFracRadDiffuse & get_mutable_spool_delay_runoff() { return spool_delay_runoff; }
        void set_spool_delay_runoff(const CanopyFracRadDiffuse & value) { this->spool_delay_runoff = value; }

        const CanopyFracRadDiffuse & get_spoolinflow() const { return spoolinflow; }
        CanopyFracRadDiffuse & get_mutable_spoolinflow() { return spoolinflow; }
        void set_spoolinflow(const CanopyFracRadDiffuse & value) { this->spoolinflow = value; }

        const CanopyFracRadDiffuse & get_spool_runoff() const { return spool_runoff; }
        CanopyFracRadDiffuse & get_mutable_spool_runoff() { return spool_runoff; }
        void set_spool_runoff(const CanopyFracRadDiffuse & value) { this->spool_runoff = value; }

        const CanopyFracRadDiffuse & get_spool_soil_infil() const { return spool_soil_infil; }
        CanopyFracRadDiffuse & get_mutable_spool_soil_infil() { return spool_soil_infil; }
        void set_spool_soil_infil(const CanopyFracRadDiffuse & value) { this->spool_soil_infil = value; }
    };

    class FlowSoilWaterProcesses {
        public:
        FlowSoilWaterProcesses() = default;
        virtual ~FlowSoilWaterProcesses() = default;

        private:
        IndigoDrainageanddeeppercolation drainageanddeeppercolation;
        TentacledSoilwaterflows soilwaterflows;
        TentacledSurfacewater surfacewater;

        public:
        const IndigoDrainageanddeeppercolation & get_drainageanddeeppercolation() const { return drainageanddeeppercolation; }
        IndigoDrainageanddeeppercolation & get_mutable_drainageanddeeppercolation() { return drainageanddeeppercolation; }
        void set_drainageanddeeppercolation(const IndigoDrainageanddeeppercolation & value) { this->drainageanddeeppercolation = value; }

        const TentacledSoilwaterflows & get_soilwaterflows() const { return soilwaterflows; }
        TentacledSoilwaterflows & get_mutable_soilwaterflows() { return soilwaterflows; }
        void set_soilwaterflows(const TentacledSoilwaterflows & value) { this->soilwaterflows = value; }

        const TentacledSurfacewater & get_surfacewater() const { return surfacewater; }
        TentacledSurfacewater & get_mutable_surfacewater() { return surfacewater; }
        void set_surfacewater(const TentacledSurfacewater & value) { this->surfacewater = value; }
    };

    class Flow {
        public:
        Flow() = default;
        virtual ~Flow() = default;

        private:
        FlowAtmosphericRelatedProcesses atmospheric_related_processes;
        FlowModelFacilities model_facilities;
        FlowNitrogenandCarbon nitrogenand_carbon;
        FlowNitrogenandCarbonBelowGround nitrogenand_carbon_below_ground;
        FlowPlantWaterProcesses plant_water_processes;
        FlowSoilHeatProcesses soil_heat_processes;
        FlowSoilWaterProcesses soil_water_processes;

        public:
        const FlowAtmosphericRelatedProcesses & get_atmospheric_related_processes() const { return atmospheric_related_processes; }
        FlowAtmosphericRelatedProcesses & get_mutable_atmospheric_related_processes() { return atmospheric_related_processes; }
        void set_atmospheric_related_processes(const FlowAtmosphericRelatedProcesses & value) { this->atmospheric_related_processes = value; }

        const FlowModelFacilities & get_model_facilities() const { return model_facilities; }
        FlowModelFacilities & get_mutable_model_facilities() { return model_facilities; }
        void set_model_facilities(const FlowModelFacilities & value) { this->model_facilities = value; }

        const FlowNitrogenandCarbon & get_nitrogenand_carbon() const { return nitrogenand_carbon; }
        FlowNitrogenandCarbon & get_mutable_nitrogenand_carbon() { return nitrogenand_carbon; }
        void set_nitrogenand_carbon(const FlowNitrogenandCarbon & value) { this->nitrogenand_carbon = value; }

        const FlowNitrogenandCarbonBelowGround & get_nitrogenand_carbon_below_ground() const { return nitrogenand_carbon_below_ground; }
        FlowNitrogenandCarbonBelowGround & get_mutable_nitrogenand_carbon_below_ground() { return nitrogenand_carbon_below_ground; }
        void set_nitrogenand_carbon_below_ground(const FlowNitrogenandCarbonBelowGround & value) { this->nitrogenand_carbon_below_ground = value; }

        const FlowPlantWaterProcesses & get_plant_water_processes() const { return plant_water_processes; }
        FlowPlantWaterProcesses & get_mutable_plant_water_processes() { return plant_water_processes; }
        void set_plant_water_processes(const FlowPlantWaterProcesses & value) { this->plant_water_processes = value; }

        const FlowSoilHeatProcesses & get_soil_heat_processes() const { return soil_heat_processes; }
        FlowSoilHeatProcesses & get_mutable_soil_heat_processes() { return soil_heat_processes; }
        void set_soil_heat_processes(const FlowSoilHeatProcesses & value) { this->soil_heat_processes = value; }

        const FlowSoilWaterProcesses & get_soil_water_processes() const { return soil_water_processes; }
        FlowSoilWaterProcesses & get_mutable_soil_water_processes() { return soil_water_processes; }
        void set_soil_water_processes(const FlowSoilWaterProcesses & value) { this->soil_water_processes = value; }
    };

    class TentacledExternalNinputs {
        public:
        TentacledExternalNinputs() = default;
        virtual ~TentacledExternalNinputs() = default;

        private:
        LaiAbovecanopy deposition_n_leaf;

        public:
        const LaiAbovecanopy & get_deposition_n_leaf() const { return deposition_n_leaf; }
        LaiAbovecanopy & get_mutable_deposition_n_leaf() { return deposition_n_leaf; }
        void set_deposition_n_leaf(const LaiAbovecanopy & value) { this->deposition_n_leaf = value; }
    };

    class FlowArraysNitrogenandCarbon {
        public:
        FlowArraysNitrogenandCarbon() = default;
        virtual ~FlowArraysNitrogenandCarbon() = default;

        private:
        TentacledExternalNinputs external_ninputs;
        std::map<std::string, SnowReduceLaiFactor> plant_growth;

        public:
        const TentacledExternalNinputs & get_external_ninputs() const { return external_ninputs; }
        TentacledExternalNinputs & get_mutable_external_ninputs() { return external_ninputs; }
        void set_external_ninputs(const TentacledExternalNinputs & value) { this->external_ninputs = value; }

        const std::map<std::string, SnowReduceLaiFactor> & get_plant_growth() const { return plant_growth; }
        std::map<std::string, SnowReduceLaiFactor> & get_mutable_plant_growth() { return plant_growth; }
        void set_plant_growth(const std::map<std::string, SnowReduceLaiFactor> & value) { this->plant_growth = value; }
    };

    class StickySoilmineralPProcesses {
        public:
        StickySoilmineralPProcesses() = default;
        virtual ~StickySoilmineralPProcesses() = default;

        private:
        CCoarseRootsAtmLayer soil_phosphate_drainage;
        CCoarseRootsAtmLayer soil_phosphate_flow;
        CCoarseRootsAtmLayer soil_phosphate_uptake;
        CCoarseRootsAtmLayer weathering_rate;

        public:
        const CCoarseRootsAtmLayer & get_soil_phosphate_drainage() const { return soil_phosphate_drainage; }
        CCoarseRootsAtmLayer & get_mutable_soil_phosphate_drainage() { return soil_phosphate_drainage; }
        void set_soil_phosphate_drainage(const CCoarseRootsAtmLayer & value) { this->soil_phosphate_drainage = value; }

        const CCoarseRootsAtmLayer & get_soil_phosphate_flow() const { return soil_phosphate_flow; }
        CCoarseRootsAtmLayer & get_mutable_soil_phosphate_flow() { return soil_phosphate_flow; }
        void set_soil_phosphate_flow(const CCoarseRootsAtmLayer & value) { this->soil_phosphate_flow = value; }

        const CCoarseRootsAtmLayer & get_soil_phosphate_uptake() const { return soil_phosphate_uptake; }
        CCoarseRootsAtmLayer & get_mutable_soil_phosphate_uptake() { return soil_phosphate_uptake; }
        void set_soil_phosphate_uptake(const CCoarseRootsAtmLayer & value) { this->soil_phosphate_uptake = value; }

        const CCoarseRootsAtmLayer & get_weathering_rate() const { return weathering_rate; }
        CCoarseRootsAtmLayer & get_mutable_weathering_rate() { return weathering_rate; }
        void set_weathering_rate(const CCoarseRootsAtmLayer & value) { this->weathering_rate = value; }
    };

    class FlowArraysNitrogenandCarbonBelowGround {
        public:
        FlowArraysNitrogenandCarbonBelowGround() = default;
        virtual ~FlowArraysNitrogenandCarbonBelowGround() = default;

        private:
        std::map<std::string, CCoarseRootsAtmLayer> gasprocesses;
        std::map<std::string, CCoarseRootsAtmLayer> soilmineral_nprocesses;
        StickySoilmineralPProcesses soilmineral_p_processes;
        std::map<std::string, CCoarseRootsAtmLayer> soilorganicprocesses;

        public:
        const std::map<std::string, CCoarseRootsAtmLayer> & get_gasprocesses() const { return gasprocesses; }
        std::map<std::string, CCoarseRootsAtmLayer> & get_mutable_gasprocesses() { return gasprocesses; }
        void set_gasprocesses(const std::map<std::string, CCoarseRootsAtmLayer> & value) { this->gasprocesses = value; }

        const std::map<std::string, CCoarseRootsAtmLayer> & get_soilmineral_nprocesses() const { return soilmineral_nprocesses; }
        std::map<std::string, CCoarseRootsAtmLayer> & get_mutable_soilmineral_nprocesses() { return soilmineral_nprocesses; }
        void set_soilmineral_nprocesses(const std::map<std::string, CCoarseRootsAtmLayer> & value) { this->soilmineral_nprocesses = value; }

        const StickySoilmineralPProcesses & get_soilmineral_p_processes() const { return soilmineral_p_processes; }
        StickySoilmineralPProcesses & get_mutable_soilmineral_p_processes() { return soilmineral_p_processes; }
        void set_soilmineral_p_processes(const StickySoilmineralPProcesses & value) { this->soilmineral_p_processes = value; }

        const std::map<std::string, CCoarseRootsAtmLayer> & get_soilorganicprocesses() const { return soilorganicprocesses; }
        std::map<std::string, CCoarseRootsAtmLayer> & get_mutable_soilorganicprocesses() { return soilorganicprocesses; }
        void set_soilorganicprocesses(const std::map<std::string, CCoarseRootsAtmLayer> & value) { this->soilorganicprocesses = value; }
    };

    class StickyInterception {
        public:
        StickyInterception() = default;
        virtual ~StickyInterception() = default;

        private:
        LaiAbovecanopy canopy_interc_act_eva;

        public:
        const LaiAbovecanopy & get_canopy_interc_act_eva() const { return canopy_interc_act_eva; }
        LaiAbovecanopy & get_mutable_canopy_interc_act_eva() { return canopy_interc_act_eva; }
        void set_canopy_interc_act_eva(const LaiAbovecanopy & value) { this->canopy_interc_act_eva = value; }
    };

    class StickySaltTracer {
        public:
        StickySaltTracer() = default;
        virtual ~StickySaltTracer() = default;

        private:
        CCoarseRootsAtmLayer salt_drain_flow;
        CCoarseRootsAtmLayer salt_flow;
        CCoarseRootsAtmLayer salt_plant_uptake;
        CCoarseRootsAtmLayer salt_source_flow;
        CCoarseRootsAtmLayer soil_resistivity;
        SnowReduceLaiFactor te_grain_surface_litter;
        CCoarseRootsAtmLayer te_humus_min_rate;
        SnowReduceLaiFactor te_leaf_grain;
        SnowReduceLaiFactor te_leaf_old_leaf;
        SnowReduceLaiFactor te_leaf_surface_litter;
        CCoarseRootsAtmLayer te_litter1_humus_rate;
        CCoarseRootsAtmLayer te_litter1_min_rate;
        SnowReduceLaiFactor te_old_leaf_surface_litter;
        SnowReduceLaiFactor te_old_roots_litter;
        SnowReduceLaiFactor te_old_stem_surface_litter;
        SnowReduceLaiFactor te_plant_leaf_uptake;
        SnowReduceLaiFactor te_plant_root_uptake;
        SnowReduceLaiFactor te_plant_stem_uptake;
        SnowReduceLaiFactor te_roots_grain;
        SnowReduceLaiFactor te_roots_litter;
        CCoarseRootsAtmLayer te_roots_litter1;
        SnowReduceLaiFactor te_roots_old_roots;
        SnowReduceLaiFactor te_stem_grain;
        SnowReduceLaiFactor te_stem_old_stem;
        SnowReduceLaiFactor te_stem_surface_litter;
        CCoarseRootsAtmLayer water_resistivity;

        public:
        const CCoarseRootsAtmLayer & get_salt_drain_flow() const { return salt_drain_flow; }
        CCoarseRootsAtmLayer & get_mutable_salt_drain_flow() { return salt_drain_flow; }
        void set_salt_drain_flow(const CCoarseRootsAtmLayer & value) { this->salt_drain_flow = value; }

        const CCoarseRootsAtmLayer & get_salt_flow() const { return salt_flow; }
        CCoarseRootsAtmLayer & get_mutable_salt_flow() { return salt_flow; }
        void set_salt_flow(const CCoarseRootsAtmLayer & value) { this->salt_flow = value; }

        const CCoarseRootsAtmLayer & get_salt_plant_uptake() const { return salt_plant_uptake; }
        CCoarseRootsAtmLayer & get_mutable_salt_plant_uptake() { return salt_plant_uptake; }
        void set_salt_plant_uptake(const CCoarseRootsAtmLayer & value) { this->salt_plant_uptake = value; }

        const CCoarseRootsAtmLayer & get_salt_source_flow() const { return salt_source_flow; }
        CCoarseRootsAtmLayer & get_mutable_salt_source_flow() { return salt_source_flow; }
        void set_salt_source_flow(const CCoarseRootsAtmLayer & value) { this->salt_source_flow = value; }

        const CCoarseRootsAtmLayer & get_soil_resistivity() const { return soil_resistivity; }
        CCoarseRootsAtmLayer & get_mutable_soil_resistivity() { return soil_resistivity; }
        void set_soil_resistivity(const CCoarseRootsAtmLayer & value) { this->soil_resistivity = value; }

        const SnowReduceLaiFactor & get_te_grain_surface_litter() const { return te_grain_surface_litter; }
        SnowReduceLaiFactor & get_mutable_te_grain_surface_litter() { return te_grain_surface_litter; }
        void set_te_grain_surface_litter(const SnowReduceLaiFactor & value) { this->te_grain_surface_litter = value; }

        const CCoarseRootsAtmLayer & get_te_humus_min_rate() const { return te_humus_min_rate; }
        CCoarseRootsAtmLayer & get_mutable_te_humus_min_rate() { return te_humus_min_rate; }
        void set_te_humus_min_rate(const CCoarseRootsAtmLayer & value) { this->te_humus_min_rate = value; }

        const SnowReduceLaiFactor & get_te_leaf_grain() const { return te_leaf_grain; }
        SnowReduceLaiFactor & get_mutable_te_leaf_grain() { return te_leaf_grain; }
        void set_te_leaf_grain(const SnowReduceLaiFactor & value) { this->te_leaf_grain = value; }

        const SnowReduceLaiFactor & get_te_leaf_old_leaf() const { return te_leaf_old_leaf; }
        SnowReduceLaiFactor & get_mutable_te_leaf_old_leaf() { return te_leaf_old_leaf; }
        void set_te_leaf_old_leaf(const SnowReduceLaiFactor & value) { this->te_leaf_old_leaf = value; }

        const SnowReduceLaiFactor & get_te_leaf_surface_litter() const { return te_leaf_surface_litter; }
        SnowReduceLaiFactor & get_mutable_te_leaf_surface_litter() { return te_leaf_surface_litter; }
        void set_te_leaf_surface_litter(const SnowReduceLaiFactor & value) { this->te_leaf_surface_litter = value; }

        const CCoarseRootsAtmLayer & get_te_litter1_humus_rate() const { return te_litter1_humus_rate; }
        CCoarseRootsAtmLayer & get_mutable_te_litter1_humus_rate() { return te_litter1_humus_rate; }
        void set_te_litter1_humus_rate(const CCoarseRootsAtmLayer & value) { this->te_litter1_humus_rate = value; }

        const CCoarseRootsAtmLayer & get_te_litter1_min_rate() const { return te_litter1_min_rate; }
        CCoarseRootsAtmLayer & get_mutable_te_litter1_min_rate() { return te_litter1_min_rate; }
        void set_te_litter1_min_rate(const CCoarseRootsAtmLayer & value) { this->te_litter1_min_rate = value; }

        const SnowReduceLaiFactor & get_te_old_leaf_surface_litter() const { return te_old_leaf_surface_litter; }
        SnowReduceLaiFactor & get_mutable_te_old_leaf_surface_litter() { return te_old_leaf_surface_litter; }
        void set_te_old_leaf_surface_litter(const SnowReduceLaiFactor & value) { this->te_old_leaf_surface_litter = value; }

        const SnowReduceLaiFactor & get_te_old_roots_litter() const { return te_old_roots_litter; }
        SnowReduceLaiFactor & get_mutable_te_old_roots_litter() { return te_old_roots_litter; }
        void set_te_old_roots_litter(const SnowReduceLaiFactor & value) { this->te_old_roots_litter = value; }

        const SnowReduceLaiFactor & get_te_old_stem_surface_litter() const { return te_old_stem_surface_litter; }
        SnowReduceLaiFactor & get_mutable_te_old_stem_surface_litter() { return te_old_stem_surface_litter; }
        void set_te_old_stem_surface_litter(const SnowReduceLaiFactor & value) { this->te_old_stem_surface_litter = value; }

        const SnowReduceLaiFactor & get_te_plant_leaf_uptake() const { return te_plant_leaf_uptake; }
        SnowReduceLaiFactor & get_mutable_te_plant_leaf_uptake() { return te_plant_leaf_uptake; }
        void set_te_plant_leaf_uptake(const SnowReduceLaiFactor & value) { this->te_plant_leaf_uptake = value; }

        const SnowReduceLaiFactor & get_te_plant_root_uptake() const { return te_plant_root_uptake; }
        SnowReduceLaiFactor & get_mutable_te_plant_root_uptake() { return te_plant_root_uptake; }
        void set_te_plant_root_uptake(const SnowReduceLaiFactor & value) { this->te_plant_root_uptake = value; }

        const SnowReduceLaiFactor & get_te_plant_stem_uptake() const { return te_plant_stem_uptake; }
        SnowReduceLaiFactor & get_mutable_te_plant_stem_uptake() { return te_plant_stem_uptake; }
        void set_te_plant_stem_uptake(const SnowReduceLaiFactor & value) { this->te_plant_stem_uptake = value; }

        const SnowReduceLaiFactor & get_te_roots_grain() const { return te_roots_grain; }
        SnowReduceLaiFactor & get_mutable_te_roots_grain() { return te_roots_grain; }
        void set_te_roots_grain(const SnowReduceLaiFactor & value) { this->te_roots_grain = value; }

        const SnowReduceLaiFactor & get_te_roots_litter() const { return te_roots_litter; }
        SnowReduceLaiFactor & get_mutable_te_roots_litter() { return te_roots_litter; }
        void set_te_roots_litter(const SnowReduceLaiFactor & value) { this->te_roots_litter = value; }

        const CCoarseRootsAtmLayer & get_te_roots_litter1() const { return te_roots_litter1; }
        CCoarseRootsAtmLayer & get_mutable_te_roots_litter1() { return te_roots_litter1; }
        void set_te_roots_litter1(const CCoarseRootsAtmLayer & value) { this->te_roots_litter1 = value; }

        const SnowReduceLaiFactor & get_te_roots_old_roots() const { return te_roots_old_roots; }
        SnowReduceLaiFactor & get_mutable_te_roots_old_roots() { return te_roots_old_roots; }
        void set_te_roots_old_roots(const SnowReduceLaiFactor & value) { this->te_roots_old_roots = value; }

        const SnowReduceLaiFactor & get_te_stem_grain() const { return te_stem_grain; }
        SnowReduceLaiFactor & get_mutable_te_stem_grain() { return te_stem_grain; }
        void set_te_stem_grain(const SnowReduceLaiFactor & value) { this->te_stem_grain = value; }

        const SnowReduceLaiFactor & get_te_stem_old_stem() const { return te_stem_old_stem; }
        SnowReduceLaiFactor & get_mutable_te_stem_old_stem() { return te_stem_old_stem; }
        void set_te_stem_old_stem(const SnowReduceLaiFactor & value) { this->te_stem_old_stem = value; }

        const SnowReduceLaiFactor & get_te_stem_surface_litter() const { return te_stem_surface_litter; }
        SnowReduceLaiFactor & get_mutable_te_stem_surface_litter() { return te_stem_surface_litter; }
        void set_te_stem_surface_litter(const SnowReduceLaiFactor & value) { this->te_stem_surface_litter = value; }

        const CCoarseRootsAtmLayer & get_water_resistivity() const { return water_resistivity; }
        CCoarseRootsAtmLayer & get_mutable_water_resistivity() { return water_resistivity; }
        void set_water_resistivity(const CCoarseRootsAtmLayer & value) { this->water_resistivity = value; }
    };

    class StickyWateruptake {
        public:
        StickyWateruptake() = default;
        virtual ~StickyWateruptake() = default;

        private:
        SnowReduceLaiFactor plant_water_uptake;
        SnowReduceLaiFactor transpiration;
        CCoarseRootsAtmLayer w_uptake_rate;

        public:
        const SnowReduceLaiFactor & get_plant_water_uptake() const { return plant_water_uptake; }
        SnowReduceLaiFactor & get_mutable_plant_water_uptake() { return plant_water_uptake; }
        void set_plant_water_uptake(const SnowReduceLaiFactor & value) { this->plant_water_uptake = value; }

        const SnowReduceLaiFactor & get_transpiration() const { return transpiration; }
        SnowReduceLaiFactor & get_mutable_transpiration() { return transpiration; }
        void set_transpiration(const SnowReduceLaiFactor & value) { this->transpiration = value; }

        const CCoarseRootsAtmLayer & get_w_uptake_rate() const { return w_uptake_rate; }
        CCoarseRootsAtmLayer & get_mutable_w_uptake_rate() { return w_uptake_rate; }
        void set_w_uptake_rate(const CCoarseRootsAtmLayer & value) { this->w_uptake_rate = value; }
    };

    class FlowArraysPlantWaterProcesses {
        public:
        FlowArraysPlantWaterProcesses() = default;
        virtual ~FlowArraysPlantWaterProcesses() = default;

        private:
        StickyInterception interception;
        StickySaltTracer salt_tracer;
        StickyWateruptake wateruptake;

        public:
        const StickyInterception & get_interception() const { return interception; }
        StickyInterception & get_mutable_interception() { return interception; }
        void set_interception(const StickyInterception & value) { this->interception = value; }

        const StickySaltTracer & get_salt_tracer() const { return salt_tracer; }
        StickySaltTracer & get_mutable_salt_tracer() { return salt_tracer; }
        void set_salt_tracer(const StickySaltTracer & value) { this->salt_tracer = value; }

        const StickyWateruptake & get_wateruptake() const { return wateruptake; }
        StickyWateruptake & get_mutable_wateruptake() { return wateruptake; }
        void set_wateruptake(const StickyWateruptake & value) { this->wateruptake = value; }
    };

    class FluffySoilfrost {
        public:
        FluffySoilfrost() = default;
        virtual ~FluffySoilfrost() = default;

        private:
        CCoarseRootsAtmLayer in_freeze;
        CCoarseRootsAtmLayer waterflow_hd_ld;
        CCoarseRootsAtmLayer waterflow_hfd;
        CCoarseRootsAtmLayer waterflow_ld_hd;

        public:
        const CCoarseRootsAtmLayer & get_in_freeze() const { return in_freeze; }
        CCoarseRootsAtmLayer & get_mutable_in_freeze() { return in_freeze; }
        void set_in_freeze(const CCoarseRootsAtmLayer & value) { this->in_freeze = value; }

        const CCoarseRootsAtmLayer & get_waterflow_hd_ld() const { return waterflow_hd_ld; }
        CCoarseRootsAtmLayer & get_mutable_waterflow_hd_ld() { return waterflow_hd_ld; }
        void set_waterflow_hd_ld(const CCoarseRootsAtmLayer & value) { this->waterflow_hd_ld = value; }

        const CCoarseRootsAtmLayer & get_waterflow_hfd() const { return waterflow_hfd; }
        CCoarseRootsAtmLayer & get_mutable_waterflow_hfd() { return waterflow_hfd; }
        void set_waterflow_hfd(const CCoarseRootsAtmLayer & value) { this->waterflow_hfd = value; }

        const CCoarseRootsAtmLayer & get_waterflow_ld_hd() const { return waterflow_ld_hd; }
        CCoarseRootsAtmLayer & get_mutable_waterflow_ld_hd() { return waterflow_ld_hd; }
        void set_waterflow_ld_hd(const CCoarseRootsAtmLayer & value) { this->waterflow_ld_hd = value; }
    };

    class HeatBox {
        public:
        HeatBox() = default;
        virtual ~HeatBox() = default;

        private:
        std::string array_name;
        Condition3Enum condition_1;
        std::string condition_2;
        std::string out_multi_index_1;
        std::string out_multi_index_2;
        std::string out_multi_index_3;
        std::string out_multi_index_4;
        std::string out_single_index_1;
        std::string out_single_index_2;
        std::string out_single_index_3;
        std::string out_single_index_4;
        std::string sizeof_array;

        public:
        const std::string & get_array_name() const { return array_name; }
        std::string & get_mutable_array_name() { return array_name; }
        void set_array_name(const std::string & value) { this->array_name = value; }

        const Condition3Enum & get_condition_1() const { return condition_1; }
        Condition3Enum & get_mutable_condition_1() { return condition_1; }
        void set_condition_1(const Condition3Enum & value) { this->condition_1 = value; }

        const std::string & get_condition_2() const { return condition_2; }
        std::string & get_mutable_condition_2() { return condition_2; }
        void set_condition_2(const std::string & value) { this->condition_2 = value; }

        const std::string & get_out_multi_index_1() const { return out_multi_index_1; }
        std::string & get_mutable_out_multi_index_1() { return out_multi_index_1; }
        void set_out_multi_index_1(const std::string & value) { this->out_multi_index_1 = value; }

        const std::string & get_out_multi_index_2() const { return out_multi_index_2; }
        std::string & get_mutable_out_multi_index_2() { return out_multi_index_2; }
        void set_out_multi_index_2(const std::string & value) { this->out_multi_index_2 = value; }

        const std::string & get_out_multi_index_3() const { return out_multi_index_3; }
        std::string & get_mutable_out_multi_index_3() { return out_multi_index_3; }
        void set_out_multi_index_3(const std::string & value) { this->out_multi_index_3 = value; }

        const std::string & get_out_multi_index_4() const { return out_multi_index_4; }
        std::string & get_mutable_out_multi_index_4() { return out_multi_index_4; }
        void set_out_multi_index_4(const std::string & value) { this->out_multi_index_4 = value; }

        const std::string & get_out_single_index_1() const { return out_single_index_1; }
        std::string & get_mutable_out_single_index_1() { return out_single_index_1; }
        void set_out_single_index_1(const std::string & value) { this->out_single_index_1 = value; }

        const std::string & get_out_single_index_2() const { return out_single_index_2; }
        std::string & get_mutable_out_single_index_2() { return out_single_index_2; }
        void set_out_single_index_2(const std::string & value) { this->out_single_index_2 = value; }

        const std::string & get_out_single_index_3() const { return out_single_index_3; }
        std::string & get_mutable_out_single_index_3() { return out_single_index_3; }
        void set_out_single_index_3(const std::string & value) { this->out_single_index_3 = value; }

        const std::string & get_out_single_index_4() const { return out_single_index_4; }
        std::string & get_mutable_out_single_index_4() { return out_single_index_4; }
        void set_out_single_index_4(const std::string & value) { this->out_single_index_4 = value; }

        const std::string & get_sizeof_array() const { return sizeof_array; }
        std::string & get_mutable_sizeof_array() { return sizeof_array; }
        void set_sizeof_array(const std::string & value) { this->sizeof_array = value; }
    };

    class TentacledSoilheatflows {
        public:
        TentacledSoilheatflows() = default;
        virtual ~TentacledSoilheatflows() = default;

        private:
        TempColdPipe cold_pipe_flux;
        TempColdPipe cold_pipe_sink_flux;
        HeatBox heat_box_boundary_flux;
        HeatBox heat_box_heater_flux;
        TempColdPipe out_pipe_flux;
        TempColdPipe out_pipe_sink_flux;
        CCoarseRootsAtmLayer soil_heat_flow;
        CCoarseRootsAtmLayer soil_heat_sink;
        CCoarseRootsAtmLayer soil_heat_source;

        public:
        const TempColdPipe & get_cold_pipe_flux() const { return cold_pipe_flux; }
        TempColdPipe & get_mutable_cold_pipe_flux() { return cold_pipe_flux; }
        void set_cold_pipe_flux(const TempColdPipe & value) { this->cold_pipe_flux = value; }

        const TempColdPipe & get_cold_pipe_sink_flux() const { return cold_pipe_sink_flux; }
        TempColdPipe & get_mutable_cold_pipe_sink_flux() { return cold_pipe_sink_flux; }
        void set_cold_pipe_sink_flux(const TempColdPipe & value) { this->cold_pipe_sink_flux = value; }

        const HeatBox & get_heat_box_boundary_flux() const { return heat_box_boundary_flux; }
        HeatBox & get_mutable_heat_box_boundary_flux() { return heat_box_boundary_flux; }
        void set_heat_box_boundary_flux(const HeatBox & value) { this->heat_box_boundary_flux = value; }

        const HeatBox & get_heat_box_heater_flux() const { return heat_box_heater_flux; }
        HeatBox & get_mutable_heat_box_heater_flux() { return heat_box_heater_flux; }
        void set_heat_box_heater_flux(const HeatBox & value) { this->heat_box_heater_flux = value; }

        const TempColdPipe & get_out_pipe_flux() const { return out_pipe_flux; }
        TempColdPipe & get_mutable_out_pipe_flux() { return out_pipe_flux; }
        void set_out_pipe_flux(const TempColdPipe & value) { this->out_pipe_flux = value; }

        const TempColdPipe & get_out_pipe_sink_flux() const { return out_pipe_sink_flux; }
        TempColdPipe & get_mutable_out_pipe_sink_flux() { return out_pipe_sink_flux; }
        void set_out_pipe_sink_flux(const TempColdPipe & value) { this->out_pipe_sink_flux = value; }

        const CCoarseRootsAtmLayer & get_soil_heat_flow() const { return soil_heat_flow; }
        CCoarseRootsAtmLayer & get_mutable_soil_heat_flow() { return soil_heat_flow; }
        void set_soil_heat_flow(const CCoarseRootsAtmLayer & value) { this->soil_heat_flow = value; }

        const CCoarseRootsAtmLayer & get_soil_heat_sink() const { return soil_heat_sink; }
        CCoarseRootsAtmLayer & get_mutable_soil_heat_sink() { return soil_heat_sink; }
        void set_soil_heat_sink(const CCoarseRootsAtmLayer & value) { this->soil_heat_sink = value; }

        const CCoarseRootsAtmLayer & get_soil_heat_source() const { return soil_heat_source; }
        CCoarseRootsAtmLayer & get_mutable_soil_heat_source() { return soil_heat_source; }
        void set_soil_heat_source(const CCoarseRootsAtmLayer & value) { this->soil_heat_source = value; }
    };

    class FlowArraysSoilHeatProcesses {
        public:
        FlowArraysSoilHeatProcesses() = default;
        virtual ~FlowArraysSoilHeatProcesses() = default;

        private:
        FluffySoilfrost soilfrost;
        TentacledSoilheatflows soilheatflows;

        public:
        const FluffySoilfrost & get_soilfrost() const { return soilfrost; }
        FluffySoilfrost & get_mutable_soilfrost() { return soilfrost; }
        void set_soilfrost(const FluffySoilfrost & value) { this->soilfrost = value; }

        const TentacledSoilheatflows & get_soilheatflows() const { return soilheatflows; }
        TentacledSoilheatflows & get_mutable_soilheatflows() { return soilheatflows; }
        void set_soilheatflows(const TentacledSoilheatflows & value) { this->soilheatflows = value; }
    };

    class IndecentDrainageanddeeppercolation {
        public:
        IndecentDrainageanddeeppercolation() = default;
        virtual ~IndecentDrainageanddeeppercolation() = default;

        private:
        CCoarseRootsAtmLayer water_drainflow;

        public:
        const CCoarseRootsAtmLayer & get_water_drainflow() const { return water_drainflow; }
        CCoarseRootsAtmLayer & get_mutable_water_drainflow() { return water_drainflow; }
        void set_water_drainflow(const CCoarseRootsAtmLayer & value) { this->water_drainflow = value; }
    };

    class StickySoilwaterflows {
        public:
        StickySoilwaterflows() = default;
        virtual ~StickySoilwaterflows() = default;

        private:
        CCoarseRootsAtmLayer vapourflow;
        CCoarseRootsAtmLayer waterflow;

        public:
        const CCoarseRootsAtmLayer & get_vapourflow() const { return vapourflow; }
        CCoarseRootsAtmLayer & get_mutable_vapourflow() { return vapourflow; }
        void set_vapourflow(const CCoarseRootsAtmLayer & value) { this->vapourflow = value; }

        const CCoarseRootsAtmLayer & get_waterflow() const { return waterflow; }
        CCoarseRootsAtmLayer & get_mutable_waterflow() { return waterflow; }
        void set_waterflow(const CCoarseRootsAtmLayer & value) { this->waterflow = value; }
    };

    class FlowArraysSoilWaterProcesses {
        public:
        FlowArraysSoilWaterProcesses() = default;
        virtual ~FlowArraysSoilWaterProcesses() = default;

        private:
        IndecentDrainageanddeeppercolation drainageanddeeppercolation;
        StickySoilwaterflows soilwaterflows;

        public:
        const IndecentDrainageanddeeppercolation & get_drainageanddeeppercolation() const { return drainageanddeeppercolation; }
        IndecentDrainageanddeeppercolation & get_mutable_drainageanddeeppercolation() { return drainageanddeeppercolation; }
        void set_drainageanddeeppercolation(const IndecentDrainageanddeeppercolation & value) { this->drainageanddeeppercolation = value; }

        const StickySoilwaterflows & get_soilwaterflows() const { return soilwaterflows; }
        StickySoilwaterflows & get_mutable_soilwaterflows() { return soilwaterflows; }
        void set_soilwaterflows(const StickySoilwaterflows & value) { this->soilwaterflows = value; }
    };

    class FlowArrays {
        public:
        FlowArrays() = default;
        virtual ~FlowArrays() = default;

        private:
        FlowArraysNitrogenandCarbon nitrogenand_carbon;
        FlowArraysNitrogenandCarbonBelowGround nitrogenand_carbon_below_ground;
        FlowArraysPlantWaterProcesses plant_water_processes;
        FlowArraysSoilHeatProcesses soil_heat_processes;
        FlowArraysSoilWaterProcesses soil_water_processes;

        public:
        const FlowArraysNitrogenandCarbon & get_nitrogenand_carbon() const { return nitrogenand_carbon; }
        FlowArraysNitrogenandCarbon & get_mutable_nitrogenand_carbon() { return nitrogenand_carbon; }
        void set_nitrogenand_carbon(const FlowArraysNitrogenandCarbon & value) { this->nitrogenand_carbon = value; }

        const FlowArraysNitrogenandCarbonBelowGround & get_nitrogenand_carbon_below_ground() const { return nitrogenand_carbon_below_ground; }
        FlowArraysNitrogenandCarbonBelowGround & get_mutable_nitrogenand_carbon_below_ground() { return nitrogenand_carbon_below_ground; }
        void set_nitrogenand_carbon_below_ground(const FlowArraysNitrogenandCarbonBelowGround & value) { this->nitrogenand_carbon_below_ground = value; }

        const FlowArraysPlantWaterProcesses & get_plant_water_processes() const { return plant_water_processes; }
        FlowArraysPlantWaterProcesses & get_mutable_plant_water_processes() { return plant_water_processes; }
        void set_plant_water_processes(const FlowArraysPlantWaterProcesses & value) { this->plant_water_processes = value; }

        const FlowArraysSoilHeatProcesses & get_soil_heat_processes() const { return soil_heat_processes; }
        FlowArraysSoilHeatProcesses & get_mutable_soil_heat_processes() { return soil_heat_processes; }
        void set_soil_heat_processes(const FlowArraysSoilHeatProcesses & value) { this->soil_heat_processes = value; }

        const FlowArraysSoilWaterProcesses & get_soil_water_processes() const { return soil_water_processes; }
        FlowArraysSoilWaterProcesses & get_mutable_soil_water_processes() { return soil_water_processes; }
        void set_soil_water_processes(const FlowArraysSoilWaterProcesses & value) { this->soil_water_processes = value; }
    };

    class StickySnowPack {
        public:
        StickySnowPack() = default;
        virtual ~StickySnowPack() = default;

        private:
        AlbedoVar ice_in_snow_pack;
        AlbedoVar snow_depth;
        AlbedoVar total_snow_mass;
        AlbedoVar water_in_snow_pack;

        public:
        const AlbedoVar & get_ice_in_snow_pack() const { return ice_in_snow_pack; }
        AlbedoVar & get_mutable_ice_in_snow_pack() { return ice_in_snow_pack; }
        void set_ice_in_snow_pack(const AlbedoVar & value) { this->ice_in_snow_pack = value; }

        const AlbedoVar & get_snow_depth() const { return snow_depth; }
        AlbedoVar & get_mutable_snow_depth() { return snow_depth; }
        void set_snow_depth(const AlbedoVar & value) { this->snow_depth = value; }

        const AlbedoVar & get_total_snow_mass() const { return total_snow_mass; }
        AlbedoVar & get_mutable_total_snow_mass() { return total_snow_mass; }
        void set_total_snow_mass(const AlbedoVar & value) { this->total_snow_mass = value; }

        const AlbedoVar & get_water_in_snow_pack() const { return water_in_snow_pack; }
        AlbedoVar & get_mutable_water_in_snow_pack() { return water_in_snow_pack; }
        void set_water_in_snow_pack(const AlbedoVar & value) { this->water_in_snow_pack = value; }
    };

    class StateAtmosphericRelatedProcesses {
        public:
        StateAtmosphericRelatedProcesses() = default;
        virtual ~StateAtmosphericRelatedProcesses() = default;

        private:
        StickySnowPack snow_pack;

        public:
        const StickySnowPack & get_snow_pack() const { return snow_pack; }
        StickySnowPack & get_mutable_snow_pack() { return snow_pack; }
        void set_snow_pack(const StickySnowPack & value) { this->snow_pack = value; }
    };

    class FluffyIrrigation {
        public:
        FluffyIrrigation() = default;
        virtual ~FluffyIrrigation() = default;

        private:
        CanopyFracRadDiffuse drip_container;

        public:
        const CanopyFracRadDiffuse & get_drip_container() const { return drip_container; }
        CanopyFracRadDiffuse & get_mutable_drip_container() { return drip_container; }
        void set_drip_container(const CanopyFracRadDiffuse & value) { this->drip_container = value; }
    };

    class StateModelFacilities {
        public:
        StateModelFacilities() = default;
        virtual ~StateModelFacilities() = default;

        private:
        FluffyIrrigation irrigation;

        public:
        const FluffyIrrigation & get_irrigation() const { return irrigation; }
        FluffyIrrigation & get_mutable_irrigation() { return irrigation; }
        void set_irrigation(const FluffyIrrigation & value) { this->irrigation = value; }
    };

    class StickyExternalNinputs {
        public:
        StickyExternalNinputs() = default;
        virtual ~StickyExternalNinputs() = default;

        private:
        AlbedoVar n_fertilizer;

        public:
        const AlbedoVar & get_n_fertilizer() const { return n_fertilizer; }
        AlbedoVar & get_mutable_n_fertilizer() { return n_fertilizer; }
        void set_n_fertilizer(const AlbedoVar & value) { this->n_fertilizer = value; }
    };

    class FluffyExternalPInputs {
        public:
        FluffyExternalPInputs() = default;
        virtual ~FluffyExternalPInputs() = default;

        private:
        CanopyFracRadDiffuse p_fertilizer;

        public:
        const CanopyFracRadDiffuse & get_p_fertilizer() const { return p_fertilizer; }
        CanopyFracRadDiffuse & get_mutable_p_fertilizer() { return p_fertilizer; }
        void set_p_fertilizer(const CanopyFracRadDiffuse & value) { this->p_fertilizer = value; }
    };

    class TentacledPlantGrowth {
        public:
        TentacledPlantGrowth() = default;
        virtual ~TentacledPlantGrowth() = default;

        private:
        AlbedoVar c_grazing_organism;
        AlbedoVar c_wood_eater;
        AlbedoVar n_grazing_organism;
        AlbedoVar n_wood_eater;

        public:
        const AlbedoVar & get_c_grazing_organism() const { return c_grazing_organism; }
        AlbedoVar & get_mutable_c_grazing_organism() { return c_grazing_organism; }
        void set_c_grazing_organism(const AlbedoVar & value) { this->c_grazing_organism = value; }

        const AlbedoVar & get_c_wood_eater() const { return c_wood_eater; }
        AlbedoVar & get_mutable_c_wood_eater() { return c_wood_eater; }
        void set_c_wood_eater(const AlbedoVar & value) { this->c_wood_eater = value; }

        const AlbedoVar & get_n_grazing_organism() const { return n_grazing_organism; }
        AlbedoVar & get_mutable_n_grazing_organism() { return n_grazing_organism; }
        void set_n_grazing_organism(const AlbedoVar & value) { this->n_grazing_organism = value; }

        const AlbedoVar & get_n_wood_eater() const { return n_wood_eater; }
        AlbedoVar & get_mutable_n_wood_eater() { return n_wood_eater; }
        void set_n_wood_eater(const AlbedoVar & value) { this->n_wood_eater = value; }
    };

    class StateNitrogenandCarbon {
        public:
        StateNitrogenandCarbon() = default;
        virtual ~StateNitrogenandCarbon() = default;

        private:
        StickyExternalNinputs external_ninputs;
        FluffyExternalPInputs external_p_inputs;
        TentacledPlantGrowth plant_growth;

        public:
        const StickyExternalNinputs & get_external_ninputs() const { return external_ninputs; }
        StickyExternalNinputs & get_mutable_external_ninputs() { return external_ninputs; }
        void set_external_ninputs(const StickyExternalNinputs & value) { this->external_ninputs = value; }

        const FluffyExternalPInputs & get_external_p_inputs() const { return external_p_inputs; }
        FluffyExternalPInputs & get_mutable_external_p_inputs() { return external_p_inputs; }
        void set_external_p_inputs(const FluffyExternalPInputs & value) { this->external_p_inputs = value; }

        const TentacledPlantGrowth & get_plant_growth() const { return plant_growth; }
        TentacledPlantGrowth & get_mutable_plant_growth() { return plant_growth; }
        void set_plant_growth(const TentacledPlantGrowth & value) { this->plant_growth = value; }
    };

    class TentacledGasprocesses {
        public:
        TentacledGasprocesses() = default;
        virtual ~TentacledGasprocesses() = default;

        private:
        CanopyFracRadDiffuse acc_ch4_bubble_emission;
        CanopyFracRadDiffuse acc_ch4_emission;
        CanopyFracRadDiffuse acc_ch4_oxidation;
        CanopyFracRadDiffuse acc_ch4_plant_emission;
        CanopyFracRadDiffuse acc_ch4_production;
        CanopyFracRadDiffuse ch4_massbalance_check;
        CanopyFracRadDiffuse diff_ch4_storage;

        public:
        const CanopyFracRadDiffuse & get_acc_ch4_bubble_emission() const { return acc_ch4_bubble_emission; }
        CanopyFracRadDiffuse & get_mutable_acc_ch4_bubble_emission() { return acc_ch4_bubble_emission; }
        void set_acc_ch4_bubble_emission(const CanopyFracRadDiffuse & value) { this->acc_ch4_bubble_emission = value; }

        const CanopyFracRadDiffuse & get_acc_ch4_emission() const { return acc_ch4_emission; }
        CanopyFracRadDiffuse & get_mutable_acc_ch4_emission() { return acc_ch4_emission; }
        void set_acc_ch4_emission(const CanopyFracRadDiffuse & value) { this->acc_ch4_emission = value; }

        const CanopyFracRadDiffuse & get_acc_ch4_oxidation() const { return acc_ch4_oxidation; }
        CanopyFracRadDiffuse & get_mutable_acc_ch4_oxidation() { return acc_ch4_oxidation; }
        void set_acc_ch4_oxidation(const CanopyFracRadDiffuse & value) { this->acc_ch4_oxidation = value; }

        const CanopyFracRadDiffuse & get_acc_ch4_plant_emission() const { return acc_ch4_plant_emission; }
        CanopyFracRadDiffuse & get_mutable_acc_ch4_plant_emission() { return acc_ch4_plant_emission; }
        void set_acc_ch4_plant_emission(const CanopyFracRadDiffuse & value) { this->acc_ch4_plant_emission = value; }

        const CanopyFracRadDiffuse & get_acc_ch4_production() const { return acc_ch4_production; }
        CanopyFracRadDiffuse & get_mutable_acc_ch4_production() { return acc_ch4_production; }
        void set_acc_ch4_production(const CanopyFracRadDiffuse & value) { this->acc_ch4_production = value; }

        const CanopyFracRadDiffuse & get_ch4_massbalance_check() const { return ch4_massbalance_check; }
        CanopyFracRadDiffuse & get_mutable_ch4_massbalance_check() { return ch4_massbalance_check; }
        void set_ch4_massbalance_check(const CanopyFracRadDiffuse & value) { this->ch4_massbalance_check = value; }

        const CanopyFracRadDiffuse & get_diff_ch4_storage() const { return diff_ch4_storage; }
        CanopyFracRadDiffuse & get_mutable_diff_ch4_storage() { return diff_ch4_storage; }
        void set_diff_ch4_storage(const CanopyFracRadDiffuse & value) { this->diff_ch4_storage = value; }
    };

    class IndigoSoilmineralPProcesses {
        public:
        IndigoSoilmineralPProcesses() = default;
        virtual ~IndigoSoilmineralPProcesses() = default;

        private:
        AlbedoVar p_min_balance_check;

        public:
        const AlbedoVar & get_p_min_balance_check() const { return p_min_balance_check; }
        AlbedoVar & get_mutable_p_min_balance_check() { return p_min_balance_check; }
        void set_p_min_balance_check(const AlbedoVar & value) { this->p_min_balance_check = value; }
    };

    class FluffySoilorganicprocesses {
        public:
        FluffySoilorganicprocesses() = default;
        virtual ~FluffySoilorganicprocesses() = default;

        private:
        CanopyFracRadDiffuse c_surface_litter1;
        CanopyFracRadDiffuse c_surface_litter2;
        CanopyFracRadDiffuse n_surface_litter1;
        CanopyFracRadDiffuse n_surface_litter2;
        CanopyFracRadDiffuse p_surface_litter1;
        CanopyFracRadDiffuse p_surface_litter2;

        public:
        const CanopyFracRadDiffuse & get_c_surface_litter1() const { return c_surface_litter1; }
        CanopyFracRadDiffuse & get_mutable_c_surface_litter1() { return c_surface_litter1; }
        void set_c_surface_litter1(const CanopyFracRadDiffuse & value) { this->c_surface_litter1 = value; }

        const CanopyFracRadDiffuse & get_c_surface_litter2() const { return c_surface_litter2; }
        CanopyFracRadDiffuse & get_mutable_c_surface_litter2() { return c_surface_litter2; }
        void set_c_surface_litter2(const CanopyFracRadDiffuse & value) { this->c_surface_litter2 = value; }

        const CanopyFracRadDiffuse & get_n_surface_litter1() const { return n_surface_litter1; }
        CanopyFracRadDiffuse & get_mutable_n_surface_litter1() { return n_surface_litter1; }
        void set_n_surface_litter1(const CanopyFracRadDiffuse & value) { this->n_surface_litter1 = value; }

        const CanopyFracRadDiffuse & get_n_surface_litter2() const { return n_surface_litter2; }
        CanopyFracRadDiffuse & get_mutable_n_surface_litter2() { return n_surface_litter2; }
        void set_n_surface_litter2(const CanopyFracRadDiffuse & value) { this->n_surface_litter2 = value; }

        const CanopyFracRadDiffuse & get_p_surface_litter1() const { return p_surface_litter1; }
        CanopyFracRadDiffuse & get_mutable_p_surface_litter1() { return p_surface_litter1; }
        void set_p_surface_litter1(const CanopyFracRadDiffuse & value) { this->p_surface_litter1 = value; }

        const CanopyFracRadDiffuse & get_p_surface_litter2() const { return p_surface_litter2; }
        CanopyFracRadDiffuse & get_mutable_p_surface_litter2() { return p_surface_litter2; }
        void set_p_surface_litter2(const CanopyFracRadDiffuse & value) { this->p_surface_litter2 = value; }
    };

    class StateNitrogenandCarbonBelowGround {
        public:
        StateNitrogenandCarbonBelowGround() = default;
        virtual ~StateNitrogenandCarbonBelowGround() = default;

        private:
        TentacledGasprocesses gasprocesses;
        IndigoSoilmineralPProcesses soilmineral_p_processes;
        FluffySoilorganicprocesses soilorganicprocesses;

        public:
        const TentacledGasprocesses & get_gasprocesses() const { return gasprocesses; }
        TentacledGasprocesses & get_mutable_gasprocesses() { return gasprocesses; }
        void set_gasprocesses(const TentacledGasprocesses & value) { this->gasprocesses = value; }

        const IndigoSoilmineralPProcesses & get_soilmineral_p_processes() const { return soilmineral_p_processes; }
        IndigoSoilmineralPProcesses & get_mutable_soilmineral_p_processes() { return soilmineral_p_processes; }
        void set_soilmineral_p_processes(const IndigoSoilmineralPProcesses & value) { this->soilmineral_p_processes = value; }

        const FluffySoilorganicprocesses & get_soilorganicprocesses() const { return soilorganicprocesses; }
        FluffySoilorganicprocesses & get_mutable_soilorganicprocesses() { return soilorganicprocesses; }
        void set_soilorganicprocesses(const FluffySoilorganicprocesses & value) { this->soilorganicprocesses = value; }
    };

    class IndigoSaltTracer {
        public:
        IndigoSaltTracer() = default;
        virtual ~IndigoSaltTracer() = default;

        private:
        AlbedoVar acc_salt_input;
        AlbedoVar acc_salt_output;
        AlbedoVar salt_close_to_road;
        AlbedoVar saltin_snow_pack;
        AlbedoVar salt_on_road;
        AlbedoVar te_balance;
        AlbedoVar te_surface_litter;

        public:
        const AlbedoVar & get_acc_salt_input() const { return acc_salt_input; }
        AlbedoVar & get_mutable_acc_salt_input() { return acc_salt_input; }
        void set_acc_salt_input(const AlbedoVar & value) { this->acc_salt_input = value; }

        const AlbedoVar & get_acc_salt_output() const { return acc_salt_output; }
        AlbedoVar & get_mutable_acc_salt_output() { return acc_salt_output; }
        void set_acc_salt_output(const AlbedoVar & value) { this->acc_salt_output = value; }

        const AlbedoVar & get_salt_close_to_road() const { return salt_close_to_road; }
        AlbedoVar & get_mutable_salt_close_to_road() { return salt_close_to_road; }
        void set_salt_close_to_road(const AlbedoVar & value) { this->salt_close_to_road = value; }

        const AlbedoVar & get_saltin_snow_pack() const { return saltin_snow_pack; }
        AlbedoVar & get_mutable_saltin_snow_pack() { return saltin_snow_pack; }
        void set_saltin_snow_pack(const AlbedoVar & value) { this->saltin_snow_pack = value; }

        const AlbedoVar & get_salt_on_road() const { return salt_on_road; }
        AlbedoVar & get_mutable_salt_on_road() { return salt_on_road; }
        void set_salt_on_road(const AlbedoVar & value) { this->salt_on_road = value; }

        const AlbedoVar & get_te_balance() const { return te_balance; }
        AlbedoVar & get_mutable_te_balance() { return te_balance; }
        void set_te_balance(const AlbedoVar & value) { this->te_balance = value; }

        const AlbedoVar & get_te_surface_litter() const { return te_surface_litter; }
        AlbedoVar & get_mutable_te_surface_litter() { return te_surface_litter; }
        void set_te_surface_litter(const AlbedoVar & value) { this->te_surface_litter = value; }
    };

    class StatePlantWaterProcesses {
        public:
        StatePlantWaterProcesses() = default;
        virtual ~StatePlantWaterProcesses() = default;

        private:
        IndigoSaltTracer salt_tracer;

        public:
        const IndigoSaltTracer & get_salt_tracer() const { return salt_tracer; }
        IndigoSaltTracer & get_mutable_salt_tracer() { return salt_tracer; }
        void set_salt_tracer(const IndigoSaltTracer & value) { this->salt_tracer = value; }
    };

    class StickySoilheatflows {
        public:
        StickySoilheatflows() = default;
        virtual ~StickySoilheatflows() = default;

        private:
        CanopyFracRadDiffuse sewage_heat_store;
        CanopyFracRadDiffuse sewage_water_store;
        CanopyFracRadDiffuse travel_distance;

        public:
        const CanopyFracRadDiffuse & get_sewage_heat_store() const { return sewage_heat_store; }
        CanopyFracRadDiffuse & get_mutable_sewage_heat_store() { return sewage_heat_store; }
        void set_sewage_heat_store(const CanopyFracRadDiffuse & value) { this->sewage_heat_store = value; }

        const CanopyFracRadDiffuse & get_sewage_water_store() const { return sewage_water_store; }
        CanopyFracRadDiffuse & get_mutable_sewage_water_store() { return sewage_water_store; }
        void set_sewage_water_store(const CanopyFracRadDiffuse & value) { this->sewage_water_store = value; }

        const CanopyFracRadDiffuse & get_travel_distance() const { return travel_distance; }
        CanopyFracRadDiffuse & get_mutable_travel_distance() { return travel_distance; }
        void set_travel_distance(const CanopyFracRadDiffuse & value) { this->travel_distance = value; }
    };

    class StateSoilHeatProcesses {
        public:
        StateSoilHeatProcesses() = default;
        virtual ~StateSoilHeatProcesses() = default;

        private:
        StickySoilheatflows soilheatflows;

        public:
        const StickySoilheatflows & get_soilheatflows() const { return soilheatflows; }
        StickySoilheatflows & get_mutable_soilheatflows() { return soilheatflows; }
        void set_soilheatflows(const StickySoilheatflows & value) { this->soilheatflows = value; }
    };

    class StickySurfacewater {
        public:
        StickySurfacewater() = default;
        virtual ~StickySurfacewater() = default;

        private:
        AlbedoVar pump_pool;
        AlbedoVar surface_pool;

        public:
        const AlbedoVar & get_pump_pool() const { return pump_pool; }
        AlbedoVar & get_mutable_pump_pool() { return pump_pool; }
        void set_pump_pool(const AlbedoVar & value) { this->pump_pool = value; }

        const AlbedoVar & get_surface_pool() const { return surface_pool; }
        AlbedoVar & get_mutable_surface_pool() { return surface_pool; }
        void set_surface_pool(const AlbedoVar & value) { this->surface_pool = value; }
    };

    class StateSoilWaterProcesses {
        public:
        StateSoilWaterProcesses() = default;
        virtual ~StateSoilWaterProcesses() = default;

        private:
        StickySurfacewater surfacewater;

        public:
        const StickySurfacewater & get_surfacewater() const { return surfacewater; }
        StickySurfacewater & get_mutable_surfacewater() { return surfacewater; }
        void set_surfacewater(const StickySurfacewater & value) { this->surfacewater = value; }
    };

    class State {
        public:
        State() = default;
        virtual ~State() = default;

        private:
        StateAtmosphericRelatedProcesses atmospheric_related_processes;
        StateModelFacilities model_facilities;
        StateNitrogenandCarbon nitrogenand_carbon;
        StateNitrogenandCarbonBelowGround nitrogenand_carbon_below_ground;
        StatePlantWaterProcesses plant_water_processes;
        StateSoilHeatProcesses soil_heat_processes;
        StateSoilWaterProcesses soil_water_processes;

        public:
        const StateAtmosphericRelatedProcesses & get_atmospheric_related_processes() const { return atmospheric_related_processes; }
        StateAtmosphericRelatedProcesses & get_mutable_atmospheric_related_processes() { return atmospheric_related_processes; }
        void set_atmospheric_related_processes(const StateAtmosphericRelatedProcesses & value) { this->atmospheric_related_processes = value; }

        const StateModelFacilities & get_model_facilities() const { return model_facilities; }
        StateModelFacilities & get_mutable_model_facilities() { return model_facilities; }
        void set_model_facilities(const StateModelFacilities & value) { this->model_facilities = value; }

        const StateNitrogenandCarbon & get_nitrogenand_carbon() const { return nitrogenand_carbon; }
        StateNitrogenandCarbon & get_mutable_nitrogenand_carbon() { return nitrogenand_carbon; }
        void set_nitrogenand_carbon(const StateNitrogenandCarbon & value) { this->nitrogenand_carbon = value; }

        const StateNitrogenandCarbonBelowGround & get_nitrogenand_carbon_below_ground() const { return nitrogenand_carbon_below_ground; }
        StateNitrogenandCarbonBelowGround & get_mutable_nitrogenand_carbon_below_ground() { return nitrogenand_carbon_below_ground; }
        void set_nitrogenand_carbon_below_ground(const StateNitrogenandCarbonBelowGround & value) { this->nitrogenand_carbon_below_ground = value; }

        const StatePlantWaterProcesses & get_plant_water_processes() const { return plant_water_processes; }
        StatePlantWaterProcesses & get_mutable_plant_water_processes() { return plant_water_processes; }
        void set_plant_water_processes(const StatePlantWaterProcesses & value) { this->plant_water_processes = value; }

        const StateSoilHeatProcesses & get_soil_heat_processes() const { return soil_heat_processes; }
        StateSoilHeatProcesses & get_mutable_soil_heat_processes() { return soil_heat_processes; }
        void set_soil_heat_processes(const StateSoilHeatProcesses & value) { this->soil_heat_processes = value; }

        const StateSoilWaterProcesses & get_soil_water_processes() const { return soil_water_processes; }
        StateSoilWaterProcesses & get_mutable_soil_water_processes() { return soil_water_processes; }
        void set_soil_water_processes(const StateSoilWaterProcesses & value) { this->soil_water_processes = value; }
    };

    class StateArraysNitrogenandCarbon {
        public:
        StateArraysNitrogenandCarbon() = default;
        virtual ~StateArraysNitrogenandCarbon() = default;

        private:
        std::map<std::string, LaiAbovecanopy> plant_growth;

        public:
        const std::map<std::string, LaiAbovecanopy> & get_plant_growth() const { return plant_growth; }
        std::map<std::string, LaiAbovecanopy> & get_mutable_plant_growth() { return plant_growth; }
        void set_plant_growth(const std::map<std::string, LaiAbovecanopy> & value) { this->plant_growth = value; }
    };

    class StickyGasprocesses {
        public:
        StickyGasprocesses() = default;
        virtual ~StickyGasprocesses() = default;

        private:
        CCoarseRootsAtmLayer co2_soil;
        CCoarseRootsAtmLayer methanecontent;
        CCoarseRootsAtmLayer nitric_oxide;
        CCoarseRootsAtmLayer nitrogengas;
        CCoarseRootsAtmLayer nitrous_oxide;
        CCoarseRootsAtmLayer oxygen;

        public:
        const CCoarseRootsAtmLayer & get_co2_soil() const { return co2_soil; }
        CCoarseRootsAtmLayer & get_mutable_co2_soil() { return co2_soil; }
        void set_co2_soil(const CCoarseRootsAtmLayer & value) { this->co2_soil = value; }

        const CCoarseRootsAtmLayer & get_methanecontent() const { return methanecontent; }
        CCoarseRootsAtmLayer & get_mutable_methanecontent() { return methanecontent; }
        void set_methanecontent(const CCoarseRootsAtmLayer & value) { this->methanecontent = value; }

        const CCoarseRootsAtmLayer & get_nitric_oxide() const { return nitric_oxide; }
        CCoarseRootsAtmLayer & get_mutable_nitric_oxide() { return nitric_oxide; }
        void set_nitric_oxide(const CCoarseRootsAtmLayer & value) { this->nitric_oxide = value; }

        const CCoarseRootsAtmLayer & get_nitrogengas() const { return nitrogengas; }
        CCoarseRootsAtmLayer & get_mutable_nitrogengas() { return nitrogengas; }
        void set_nitrogengas(const CCoarseRootsAtmLayer & value) { this->nitrogengas = value; }

        const CCoarseRootsAtmLayer & get_nitrous_oxide() const { return nitrous_oxide; }
        CCoarseRootsAtmLayer & get_mutable_nitrous_oxide() { return nitrous_oxide; }
        void set_nitrous_oxide(const CCoarseRootsAtmLayer & value) { this->nitrous_oxide = value; }

        const CCoarseRootsAtmLayer & get_oxygen() const { return oxygen; }
        CCoarseRootsAtmLayer & get_mutable_oxygen() { return oxygen; }
        void set_oxygen(const CCoarseRootsAtmLayer & value) { this->oxygen = value; }
    };

    class IndecentSoilmineralPProcesses {
        public:
        IndecentSoilmineralPProcesses() = default;
        virtual ~IndecentSoilmineralPProcesses() = default;

        private:
        CCoarseRootsAtmLayer soilmineral_p;
        CCoarseRootsAtmLayer soil_phosphate;

        public:
        const CCoarseRootsAtmLayer & get_soilmineral_p() const { return soilmineral_p; }
        CCoarseRootsAtmLayer & get_mutable_soilmineral_p() { return soilmineral_p; }
        void set_soilmineral_p(const CCoarseRootsAtmLayer & value) { this->soilmineral_p = value; }

        const CCoarseRootsAtmLayer & get_soil_phosphate() const { return soil_phosphate; }
        CCoarseRootsAtmLayer & get_mutable_soil_phosphate() { return soil_phosphate; }
        void set_soil_phosphate(const CCoarseRootsAtmLayer & value) { this->soil_phosphate = value; }
    };

    class StateArraysNitrogenandCarbonBelowGround {
        public:
        StateArraysNitrogenandCarbonBelowGround() = default;
        virtual ~StateArraysNitrogenandCarbonBelowGround() = default;

        private:
        StickyGasprocesses gasprocesses;
        std::map<std::string, CCoarseRootsAtmLayer> soilmineral_nprocesses;
        IndecentSoilmineralPProcesses soilmineral_p_processes;
        std::map<std::string, CCoarseRootsAtmLayer> soilorganicprocesses;

        public:
        const StickyGasprocesses & get_gasprocesses() const { return gasprocesses; }
        StickyGasprocesses & get_mutable_gasprocesses() { return gasprocesses; }
        void set_gasprocesses(const StickyGasprocesses & value) { this->gasprocesses = value; }

        const std::map<std::string, CCoarseRootsAtmLayer> & get_soilmineral_nprocesses() const { return soilmineral_nprocesses; }
        std::map<std::string, CCoarseRootsAtmLayer> & get_mutable_soilmineral_nprocesses() { return soilmineral_nprocesses; }
        void set_soilmineral_nprocesses(const std::map<std::string, CCoarseRootsAtmLayer> & value) { this->soilmineral_nprocesses = value; }

        const IndecentSoilmineralPProcesses & get_soilmineral_p_processes() const { return soilmineral_p_processes; }
        IndecentSoilmineralPProcesses & get_mutable_soilmineral_p_processes() { return soilmineral_p_processes; }
        void set_soilmineral_p_processes(const IndecentSoilmineralPProcesses & value) { this->soilmineral_p_processes = value; }

        const std::map<std::string, CCoarseRootsAtmLayer> & get_soilorganicprocesses() const { return soilorganicprocesses; }
        std::map<std::string, CCoarseRootsAtmLayer> & get_mutable_soilorganicprocesses() { return soilorganicprocesses; }
        void set_soilorganicprocesses(const std::map<std::string, CCoarseRootsAtmLayer> & value) { this->soilorganicprocesses = value; }
    };

    class IndigoInterception {
        public:
        IndigoInterception() = default;
        virtual ~IndigoInterception() = default;

        private:
        SnowReduceLaiFactor canopy_interc_storage;

        public:
        const SnowReduceLaiFactor & get_canopy_interc_storage() const { return canopy_interc_storage; }
        SnowReduceLaiFactor & get_mutable_canopy_interc_storage() { return canopy_interc_storage; }
        void set_canopy_interc_storage(const SnowReduceLaiFactor & value) { this->canopy_interc_storage = value; }
    };

    class IndecentSaltTracer {
        public:
        IndecentSaltTracer() = default;
        virtual ~IndecentSaltTracer() = default;

        private:
        CCoarseRootsAtmLayer salt_storage;
        LaiAbovecanopy te_grain;
        CCoarseRootsAtmLayer te_humus;
        LaiAbovecanopy te_leaf;
        CCoarseRootsAtmLayer te_litter1;
        LaiAbovecanopy te_old_leaf;
        LaiAbovecanopy te_old_roots;
        LaiAbovecanopy te_old_stem;
        LaiAbovecanopy te_roots;
        LaiAbovecanopy te_stem;

        public:
        const CCoarseRootsAtmLayer & get_salt_storage() const { return salt_storage; }
        CCoarseRootsAtmLayer & get_mutable_salt_storage() { return salt_storage; }
        void set_salt_storage(const CCoarseRootsAtmLayer & value) { this->salt_storage = value; }

        const LaiAbovecanopy & get_te_grain() const { return te_grain; }
        LaiAbovecanopy & get_mutable_te_grain() { return te_grain; }
        void set_te_grain(const LaiAbovecanopy & value) { this->te_grain = value; }

        const CCoarseRootsAtmLayer & get_te_humus() const { return te_humus; }
        CCoarseRootsAtmLayer & get_mutable_te_humus() { return te_humus; }
        void set_te_humus(const CCoarseRootsAtmLayer & value) { this->te_humus = value; }

        const LaiAbovecanopy & get_te_leaf() const { return te_leaf; }
        LaiAbovecanopy & get_mutable_te_leaf() { return te_leaf; }
        void set_te_leaf(const LaiAbovecanopy & value) { this->te_leaf = value; }

        const CCoarseRootsAtmLayer & get_te_litter1() const { return te_litter1; }
        CCoarseRootsAtmLayer & get_mutable_te_litter1() { return te_litter1; }
        void set_te_litter1(const CCoarseRootsAtmLayer & value) { this->te_litter1 = value; }

        const LaiAbovecanopy & get_te_old_leaf() const { return te_old_leaf; }
        LaiAbovecanopy & get_mutable_te_old_leaf() { return te_old_leaf; }
        void set_te_old_leaf(const LaiAbovecanopy & value) { this->te_old_leaf = value; }

        const LaiAbovecanopy & get_te_old_roots() const { return te_old_roots; }
        LaiAbovecanopy & get_mutable_te_old_roots() { return te_old_roots; }
        void set_te_old_roots(const LaiAbovecanopy & value) { this->te_old_roots = value; }

        const LaiAbovecanopy & get_te_old_stem() const { return te_old_stem; }
        LaiAbovecanopy & get_mutable_te_old_stem() { return te_old_stem; }
        void set_te_old_stem(const LaiAbovecanopy & value) { this->te_old_stem = value; }

        const LaiAbovecanopy & get_te_roots() const { return te_roots; }
        LaiAbovecanopy & get_mutable_te_roots() { return te_roots; }
        void set_te_roots(const LaiAbovecanopy & value) { this->te_roots = value; }

        const LaiAbovecanopy & get_te_stem() const { return te_stem; }
        LaiAbovecanopy & get_mutable_te_stem() { return te_stem; }
        void set_te_stem(const LaiAbovecanopy & value) { this->te_stem = value; }
    };

    class IndigoWateruptake {
        public:
        IndigoWateruptake() = default;
        virtual ~IndigoWateruptake() = default;

        private:
        SnowReduceLaiFactor plant_water;

        public:
        const SnowReduceLaiFactor & get_plant_water() const { return plant_water; }
        SnowReduceLaiFactor & get_mutable_plant_water() { return plant_water; }
        void set_plant_water(const SnowReduceLaiFactor & value) { this->plant_water = value; }
    };

    class StateArraysPlantWaterProcesses {
        public:
        StateArraysPlantWaterProcesses() = default;
        virtual ~StateArraysPlantWaterProcesses() = default;

        private:
        IndigoInterception interception;
        IndecentSaltTracer salt_tracer;
        IndigoWateruptake wateruptake;

        public:
        const IndigoInterception & get_interception() const { return interception; }
        IndigoInterception & get_mutable_interception() { return interception; }
        void set_interception(const IndigoInterception & value) { this->interception = value; }

        const IndecentSaltTracer & get_salt_tracer() const { return salt_tracer; }
        IndecentSaltTracer & get_mutable_salt_tracer() { return salt_tracer; }
        void set_salt_tracer(const IndecentSaltTracer & value) { this->salt_tracer = value; }

        const IndigoWateruptake & get_wateruptake() const { return wateruptake; }
        IndigoWateruptake & get_mutable_wateruptake() { return wateruptake; }
        void set_wateruptake(const IndigoWateruptake & value) { this->wateruptake = value; }
    };

    class TentacledSoilfrost {
        public:
        TentacledSoilfrost() = default;
        virtual ~TentacledSoilfrost() = default;

        private:
        CCoarseRootsAtmLayer water_hfd;

        public:
        const CCoarseRootsAtmLayer & get_water_hfd() const { return water_hfd; }
        CCoarseRootsAtmLayer & get_mutable_water_hfd() { return water_hfd; }
        void set_water_hfd(const CCoarseRootsAtmLayer & value) { this->water_hfd = value; }
    };

    class IndigoSoilheatflows {
        public:
        IndigoSoilheatflows() = default;
        virtual ~IndigoSoilheatflows() = default;

        private:
        TempColdPipe cold_pipe_heat;
        HeatBox heat_box_storage;
        HeatBox heat_box_temp;
        TempColdPipe out_pipe_heat;
        CCoarseRootsAtmLayer soil_heat;

        public:
        const TempColdPipe & get_cold_pipe_heat() const { return cold_pipe_heat; }
        TempColdPipe & get_mutable_cold_pipe_heat() { return cold_pipe_heat; }
        void set_cold_pipe_heat(const TempColdPipe & value) { this->cold_pipe_heat = value; }

        const HeatBox & get_heat_box_storage() const { return heat_box_storage; }
        HeatBox & get_mutable_heat_box_storage() { return heat_box_storage; }
        void set_heat_box_storage(const HeatBox & value) { this->heat_box_storage = value; }

        const HeatBox & get_heat_box_temp() const { return heat_box_temp; }
        HeatBox & get_mutable_heat_box_temp() { return heat_box_temp; }
        void set_heat_box_temp(const HeatBox & value) { this->heat_box_temp = value; }

        const TempColdPipe & get_out_pipe_heat() const { return out_pipe_heat; }
        TempColdPipe & get_mutable_out_pipe_heat() { return out_pipe_heat; }
        void set_out_pipe_heat(const TempColdPipe & value) { this->out_pipe_heat = value; }

        const CCoarseRootsAtmLayer & get_soil_heat() const { return soil_heat; }
        CCoarseRootsAtmLayer & get_mutable_soil_heat() { return soil_heat; }
        void set_soil_heat(const CCoarseRootsAtmLayer & value) { this->soil_heat = value; }
    };

    class StateArraysSoilHeatProcesses {
        public:
        StateArraysSoilHeatProcesses() = default;
        virtual ~StateArraysSoilHeatProcesses() = default;

        private:
        TentacledSoilfrost soilfrost;
        IndigoSoilheatflows soilheatflows;

        public:
        const TentacledSoilfrost & get_soilfrost() const { return soilfrost; }
        TentacledSoilfrost & get_mutable_soilfrost() { return soilfrost; }
        void set_soilfrost(const TentacledSoilfrost & value) { this->soilfrost = value; }

        const IndigoSoilheatflows & get_soilheatflows() const { return soilheatflows; }
        IndigoSoilheatflows & get_mutable_soilheatflows() { return soilheatflows; }
        void set_soilheatflows(const IndigoSoilheatflows & value) { this->soilheatflows = value; }
    };

    class IndigoSoilwaterflows {
        public:
        IndigoSoilwaterflows() = default;
        virtual ~IndigoSoilwaterflows() = default;

        private:
        CCoarseRootsAtmLayer water_storage;

        public:
        const CCoarseRootsAtmLayer & get_water_storage() const { return water_storage; }
        CCoarseRootsAtmLayer & get_mutable_water_storage() { return water_storage; }
        void set_water_storage(const CCoarseRootsAtmLayer & value) { this->water_storage = value; }
    };

    class StateArraysSoilWaterProcesses {
        public:
        StateArraysSoilWaterProcesses() = default;
        virtual ~StateArraysSoilWaterProcesses() = default;

        private:
        IndigoSoilwaterflows soilwaterflows;

        public:
        const IndigoSoilwaterflows & get_soilwaterflows() const { return soilwaterflows; }
        IndigoSoilwaterflows & get_mutable_soilwaterflows() { return soilwaterflows; }
        void set_soilwaterflows(const IndigoSoilwaterflows & value) { this->soilwaterflows = value; }
    };

    class StateArrays {
        public:
        StateArrays() = default;
        virtual ~StateArrays() = default;

        private:
        StateArraysNitrogenandCarbon nitrogenand_carbon;
        StateArraysNitrogenandCarbonBelowGround nitrogenand_carbon_below_ground;
        StateArraysPlantWaterProcesses plant_water_processes;
        StateArraysSoilHeatProcesses soil_heat_processes;
        StateArraysSoilWaterProcesses soil_water_processes;

        public:
        const StateArraysNitrogenandCarbon & get_nitrogenand_carbon() const { return nitrogenand_carbon; }
        StateArraysNitrogenandCarbon & get_mutable_nitrogenand_carbon() { return nitrogenand_carbon; }
        void set_nitrogenand_carbon(const StateArraysNitrogenandCarbon & value) { this->nitrogenand_carbon = value; }

        const StateArraysNitrogenandCarbonBelowGround & get_nitrogenand_carbon_below_ground() const { return nitrogenand_carbon_below_ground; }
        StateArraysNitrogenandCarbonBelowGround & get_mutable_nitrogenand_carbon_below_ground() { return nitrogenand_carbon_below_ground; }
        void set_nitrogenand_carbon_below_ground(const StateArraysNitrogenandCarbonBelowGround & value) { this->nitrogenand_carbon_below_ground = value; }

        const StateArraysPlantWaterProcesses & get_plant_water_processes() const { return plant_water_processes; }
        StateArraysPlantWaterProcesses & get_mutable_plant_water_processes() { return plant_water_processes; }
        void set_plant_water_processes(const StateArraysPlantWaterProcesses & value) { this->plant_water_processes = value; }

        const StateArraysSoilHeatProcesses & get_soil_heat_processes() const { return soil_heat_processes; }
        StateArraysSoilHeatProcesses & get_mutable_soil_heat_processes() { return soil_heat_processes; }
        void set_soil_heat_processes(const StateArraysSoilHeatProcesses & value) { this->soil_heat_processes = value; }

        const StateArraysSoilWaterProcesses & get_soil_water_processes() const { return soil_water_processes; }
        StateArraysSoilWaterProcesses & get_mutable_soil_water_processes() { return soil_water_processes; }
        void set_soil_water_processes(const StateArraysSoilWaterProcesses & value) { this->soil_water_processes = value; }
    };

    class OutputVariables {
        public:
        OutputVariables() = default;
        virtual ~OutputVariables() = default;

        private:
        Auxiliary auxiliary;
        AuxiliaryArrays auxiliary_arrays;
        Driving driving;
        DrivingArrays driving_arrays;
        Flow flow;
        FlowArrays flow_arrays;
        State state;
        StateArrays state_arrays;

        public:
        const Auxiliary & get_auxiliary() const { return auxiliary; }
        Auxiliary & get_mutable_auxiliary() { return auxiliary; }
        void set_auxiliary(const Auxiliary & value) { this->auxiliary = value; }

        const AuxiliaryArrays & get_auxiliary_arrays() const { return auxiliary_arrays; }
        AuxiliaryArrays & get_mutable_auxiliary_arrays() { return auxiliary_arrays; }
        void set_auxiliary_arrays(const AuxiliaryArrays & value) { this->auxiliary_arrays = value; }

        const Driving & get_driving() const { return driving; }
        Driving & get_mutable_driving() { return driving; }
        void set_driving(const Driving & value) { this->driving = value; }

        const DrivingArrays & get_driving_arrays() const { return driving_arrays; }
        DrivingArrays & get_mutable_driving_arrays() { return driving_arrays; }
        void set_driving_arrays(const DrivingArrays & value) { this->driving_arrays = value; }

        const Flow & get_flow() const { return flow; }
        Flow & get_mutable_flow() { return flow; }
        void set_flow(const Flow & value) { this->flow = value; }

        const FlowArrays & get_flow_arrays() const { return flow_arrays; }
        FlowArrays & get_mutable_flow_arrays() { return flow_arrays; }
        void set_flow_arrays(const FlowArrays & value) { this->flow_arrays = value; }

        const State & get_state() const { return state; }
        State & get_mutable_state() { return state; }
        void set_state(const State & value) { this->state = value; }

        const StateArrays & get_state_arrays() const { return state_arrays; }
        StateArrays & get_mutable_state_arrays() { return state_arrays; }
        void set_state_arrays(const StateArrays & value) { this->state_arrays = value; }
    };

    class IndigoSnowPack {
        public:
        IndigoSnowPack() = default;
        virtual ~IndigoSnowPack() = default;

        private:
        PrecInput density_coef_mass;
        PrecInput density_coef_water;
        PrecInput melt_coef_air_temp;
        PrecInput melt_coef_glob_rad;
        PrecInput melt_coef_glob_rad_age1;

        public:
        const PrecInput & get_density_coef_mass() const { return density_coef_mass; }
        PrecInput & get_mutable_density_coef_mass() { return density_coef_mass; }
        void set_density_coef_mass(const PrecInput & value) { this->density_coef_mass = value; }

        const PrecInput & get_density_coef_water() const { return density_coef_water; }
        PrecInput & get_mutable_density_coef_water() { return density_coef_water; }
        void set_density_coef_water(const PrecInput & value) { this->density_coef_water = value; }

        const PrecInput & get_melt_coef_air_temp() const { return melt_coef_air_temp; }
        PrecInput & get_mutable_melt_coef_air_temp() { return melt_coef_air_temp; }
        void set_melt_coef_air_temp(const PrecInput & value) { this->melt_coef_air_temp = value; }

        const PrecInput & get_melt_coef_glob_rad() const { return melt_coef_glob_rad; }
        PrecInput & get_mutable_melt_coef_glob_rad() { return melt_coef_glob_rad; }
        void set_melt_coef_glob_rad(const PrecInput & value) { this->melt_coef_glob_rad = value; }

        const PrecInput & get_melt_coef_glob_rad_age1() const { return melt_coef_glob_rad_age1; }
        PrecInput & get_mutable_melt_coef_glob_rad_age1() { return melt_coef_glob_rad_age1; }
        void set_melt_coef_glob_rad_age1(const PrecInput & value) { this->melt_coef_glob_rad_age1 = value; }
    };

    class ParametersAtmosphericRelatedProcesses {
        public:
        ParametersAtmosphericRelatedProcesses() = default;
        virtual ~ParametersAtmosphericRelatedProcesses() = default;

        private:
        IndigoSnowPack snow_pack;

        public:
        const IndigoSnowPack & get_snow_pack() const { return snow_pack; }
        IndigoSnowPack & get_mutable_snow_pack() { return snow_pack; }
        void set_snow_pack(const IndigoSnowPack & value) { this->snow_pack = value; }
    };

    class TentacledModelStructure {
        public:
        TentacledModelStructure() = default;
        virtual ~TentacledModelStructure() = default;

        private:
        PrecInput xa_div;
        PrecInput xloop;
        PrecInput xn_lev;

        public:
        const PrecInput & get_xa_div() const { return xa_div; }
        PrecInput & get_mutable_xa_div() { return xa_div; }
        void set_xa_div(const PrecInput & value) { this->xa_div = value; }

        const PrecInput & get_xloop() const { return xloop; }
        PrecInput & get_mutable_xloop() { return xloop; }
        void set_xloop(const PrecInput & value) { this->xloop = value; }

        const PrecInput & get_xn_lev() const { return xn_lev; }
        PrecInput & get_mutable_xn_lev() { return xn_lev; }
        void set_xn_lev(const PrecInput & value) { this->xn_lev = value; }
    };

    class ParametersModelStructure {
        public:
        ParametersModelStructure() = default;
        virtual ~ParametersModelStructure() = default;

        private:
        TentacledModelStructure model_structure;

        public:
        const TentacledModelStructure & get_model_structure() const { return model_structure; }
        TentacledModelStructure & get_mutable_model_structure() { return model_structure; }
        void set_model_structure(const TentacledModelStructure & value) { this->model_structure = value; }
    };

    class IndecentWateruptake {
        public:
        IndecentWateruptake() = default;
        virtual ~IndecentWateruptake() = default;

        private:
        PrecInput crit_threshold_dry;

        public:
        const PrecInput & get_crit_threshold_dry() const { return crit_threshold_dry; }
        PrecInput & get_mutable_crit_threshold_dry() { return crit_threshold_dry; }
        void set_crit_threshold_dry(const PrecInput & value) { this->crit_threshold_dry = value; }
    };

    class ParametersPlantWaterProcesses {
        public:
        ParametersPlantWaterProcesses() = default;
        virtual ~ParametersPlantWaterProcesses() = default;

        private:
        IndecentWateruptake wateruptake;

        public:
        const IndecentWateruptake & get_wateruptake() const { return wateruptake; }
        IndecentWateruptake & get_mutable_wateruptake() { return wateruptake; }
        void set_wateruptake(const IndecentWateruptake & value) { this->wateruptake = value; }
    };

    class SoilThermal {
        public:
        SoilThermal() = default;
        virtual ~SoilThermal() = default;

        private:
        PrecInput clay_frozen_c1;
        PrecInput sand_frozen_c1;

        public:
        const PrecInput & get_clay_frozen_c1() const { return clay_frozen_c1; }
        PrecInput & get_mutable_clay_frozen_c1() { return clay_frozen_c1; }
        void set_clay_frozen_c1(const PrecInput & value) { this->clay_frozen_c1 = value; }

        const PrecInput & get_sand_frozen_c1() const { return sand_frozen_c1; }
        PrecInput & get_mutable_sand_frozen_c1() { return sand_frozen_c1; }
        void set_sand_frozen_c1(const PrecInput & value) { this->sand_frozen_c1 = value; }
    };

    class StickySoilfrost {
        public:
        StickySoilfrost() = default;
        virtual ~StickySoilfrost() = default;

        private:
        PrecInput alpha_heat_coef;
        PrecInput freezepoint_f0;
        PrecInput freezepoint_f_wi;
        PrecInput high_flow_damp_c;

        public:
        const PrecInput & get_alpha_heat_coef() const { return alpha_heat_coef; }
        PrecInput & get_mutable_alpha_heat_coef() { return alpha_heat_coef; }
        void set_alpha_heat_coef(const PrecInput & value) { this->alpha_heat_coef = value; }

        const PrecInput & get_freezepoint_f0() const { return freezepoint_f0; }
        PrecInput & get_mutable_freezepoint_f0() { return freezepoint_f0; }
        void set_freezepoint_f0(const PrecInput & value) { this->freezepoint_f0 = value; }

        const PrecInput & get_freezepoint_f_wi() const { return freezepoint_f_wi; }
        PrecInput & get_mutable_freezepoint_f_wi() { return freezepoint_f_wi; }
        void set_freezepoint_f_wi(const PrecInput & value) { this->freezepoint_f_wi = value; }

        const PrecInput & get_high_flow_damp_c() const { return high_flow_damp_c; }
        PrecInput & get_mutable_high_flow_damp_c() { return high_flow_damp_c; }
        void set_high_flow_damp_c(const PrecInput & value) { this->high_flow_damp_c = value; }
    };

    class IndecentSoilheatflows {
        public:
        IndecentSoilheatflows() = default;
        virtual ~IndecentSoilheatflows() = default;

        private:
        EvaporationMethod soil_init_temp_const;

        public:
        const EvaporationMethod & get_soil_init_temp_const() const { return soil_init_temp_const; }
        EvaporationMethod & get_mutable_soil_init_temp_const() { return soil_init_temp_const; }
        void set_soil_init_temp_const(const EvaporationMethod & value) { this->soil_init_temp_const = value; }
    };

    class ParametersSoilHeatProcesses {
        public:
        ParametersSoilHeatProcesses() = default;
        virtual ~ParametersSoilHeatProcesses() = default;

        private:
        StickySoilfrost soilfrost;
        IndecentSoilheatflows soilheatflows;
        SoilThermal soil_thermal;

        public:
        const StickySoilfrost & get_soilfrost() const { return soilfrost; }
        StickySoilfrost & get_mutable_soilfrost() { return soilfrost; }
        void set_soilfrost(const StickySoilfrost & value) { this->soilfrost = value; }

        const IndecentSoilheatflows & get_soilheatflows() const { return soilheatflows; }
        IndecentSoilheatflows & get_mutable_soilheatflows() { return soilheatflows; }
        void set_soilheatflows(const IndecentSoilheatflows & value) { this->soilheatflows = value; }

        const SoilThermal & get_soil_thermal() const { return soil_thermal; }
        SoilThermal & get_mutable_soil_thermal() { return soil_thermal; }
        void set_soil_thermal(const SoilThermal & value) { this->soil_thermal = value; }
    };

    class HilariousDrainageanddeeppercolation {
        public:
        HilariousDrainageanddeeppercolation() = default;
        virtual ~HilariousDrainageanddeeppercolation() = default;

        private:
        PrecInput emp_gf_lev_base;
        PrecInput emp_gf_lev_peak;
        PrecInput emp_gf_lowbase;
        PrecInput emp_g_flow_peak;
        PrecInput h_flow_input_index;
        PrecInput h_flow_output_index;

        public:
        const PrecInput & get_emp_gf_lev_base() const { return emp_gf_lev_base; }
        PrecInput & get_mutable_emp_gf_lev_base() { return emp_gf_lev_base; }
        void set_emp_gf_lev_base(const PrecInput & value) { this->emp_gf_lev_base = value; }

        const PrecInput & get_emp_gf_lev_peak() const { return emp_gf_lev_peak; }
        PrecInput & get_mutable_emp_gf_lev_peak() { return emp_gf_lev_peak; }
        void set_emp_gf_lev_peak(const PrecInput & value) { this->emp_gf_lev_peak = value; }

        const PrecInput & get_emp_gf_lowbase() const { return emp_gf_lowbase; }
        PrecInput & get_mutable_emp_gf_lowbase() { return emp_gf_lowbase; }
        void set_emp_gf_lowbase(const PrecInput & value) { this->emp_gf_lowbase = value; }

        const PrecInput & get_emp_g_flow_peak() const { return emp_g_flow_peak; }
        PrecInput & get_mutable_emp_g_flow_peak() { return emp_g_flow_peak; }
        void set_emp_g_flow_peak(const PrecInput & value) { this->emp_g_flow_peak = value; }

        const PrecInput & get_h_flow_input_index() const { return h_flow_input_index; }
        PrecInput & get_mutable_h_flow_input_index() { return h_flow_input_index; }
        void set_h_flow_input_index(const PrecInput & value) { this->h_flow_input_index = value; }

        const PrecInput & get_h_flow_output_index() const { return h_flow_output_index; }
        PrecInput & get_mutable_h_flow_output_index() { return h_flow_output_index; }
        void set_h_flow_output_index(const PrecInput & value) { this->h_flow_output_index = value; }
    };

    class IndecentSoilwaterflows {
        public:
        IndecentSoilwaterflows() = default;
        virtual ~IndecentSoilwaterflows() = default;

        private:
        EvaporationMethod initial_ground_water;

        public:
        const EvaporationMethod & get_initial_ground_water() const { return initial_ground_water; }
        EvaporationMethod & get_mutable_initial_ground_water() { return initial_ground_water; }
        void set_initial_ground_water(const EvaporationMethod & value) { this->initial_ground_water = value; }
    };

    class IndigoSurfacewater {
        public:
        IndigoSurfacewater() = default;
        virtual ~IndigoSurfacewater() = default;

        private:
        PrecInput surf_coef;

        public:
        const PrecInput & get_surf_coef() const { return surf_coef; }
        PrecInput & get_mutable_surf_coef() { return surf_coef; }
        void set_surf_coef(const PrecInput & value) { this->surf_coef = value; }
    };

    class ParametersSoilWaterProcesses {
        public:
        ParametersSoilWaterProcesses() = default;
        virtual ~ParametersSoilWaterProcesses() = default;

        private:
        HilariousDrainageanddeeppercolation drainageanddeeppercolation;
        IndecentSoilwaterflows soilwaterflows;
        IndigoSurfacewater surfacewater;

        public:
        const HilariousDrainageanddeeppercolation & get_drainageanddeeppercolation() const { return drainageanddeeppercolation; }
        HilariousDrainageanddeeppercolation & get_mutable_drainageanddeeppercolation() { return drainageanddeeppercolation; }
        void set_drainageanddeeppercolation(const HilariousDrainageanddeeppercolation & value) { this->drainageanddeeppercolation = value; }

        const IndecentSoilwaterflows & get_soilwaterflows() const { return soilwaterflows; }
        IndecentSoilwaterflows & get_mutable_soilwaterflows() { return soilwaterflows; }
        void set_soilwaterflows(const IndecentSoilwaterflows & value) { this->soilwaterflows = value; }

        const IndigoSurfacewater & get_surfacewater() const { return surfacewater; }
        IndigoSurfacewater & get_mutable_surfacewater() { return surfacewater; }
        void set_surfacewater(const IndigoSurfacewater & value) { this->surfacewater = value; }
    };

    class Parameters {
        public:
        Parameters() = default;
        virtual ~Parameters() = default;

        private:
        ParametersAtmosphericRelatedProcesses atmospheric_related_processes;
        ParametersModelStructure model_structure;
        ParametersPlantWaterProcesses plant_water_processes;
        ParametersSoilHeatProcesses soil_heat_processes;
        ParametersSoilWaterProcesses soil_water_processes;

        public:
        const ParametersAtmosphericRelatedProcesses & get_atmospheric_related_processes() const { return atmospheric_related_processes; }
        ParametersAtmosphericRelatedProcesses & get_mutable_atmospheric_related_processes() { return atmospheric_related_processes; }
        void set_atmospheric_related_processes(const ParametersAtmosphericRelatedProcesses & value) { this->atmospheric_related_processes = value; }

        const ParametersModelStructure & get_model_structure() const { return model_structure; }
        ParametersModelStructure & get_mutable_model_structure() { return model_structure; }
        void set_model_structure(const ParametersModelStructure & value) { this->model_structure = value; }

        const ParametersPlantWaterProcesses & get_plant_water_processes() const { return plant_water_processes; }
        ParametersPlantWaterProcesses & get_mutable_plant_water_processes() { return plant_water_processes; }
        void set_plant_water_processes(const ParametersPlantWaterProcesses & value) { this->plant_water_processes = value; }

        const ParametersSoilHeatProcesses & get_soil_heat_processes() const { return soil_heat_processes; }
        ParametersSoilHeatProcesses & get_mutable_soil_heat_processes() { return soil_heat_processes; }
        void set_soil_heat_processes(const ParametersSoilHeatProcesses & value) { this->soil_heat_processes = value; }

        const ParametersSoilWaterProcesses & get_soil_water_processes() const { return soil_water_processes; }
        ParametersSoilWaterProcesses & get_mutable_soil_water_processes() { return soil_water_processes; }
        void set_soil_water_processes(const ParametersSoilWaterProcesses & value) { this->soil_water_processes = value; }
    };

    class KonzelmannCoef {
        public:
        KonzelmannCoef() = default;
        virtual ~KonzelmannCoef() = default;

        private:
        std::string array_name;
        Condition3Enum condition_1;
        std::shared_ptr<std::string> condition_2;
        std::shared_ptr<std::string> condition_3;
        std::shared_ptr<std::string> condition_4;
        std::string default_index_1;
        std::string default_index_2;
        std::string default_index_3;
        std::shared_ptr<std::string> default_index_4;
        std::string index_1;
        std::string index_2;
        std::string index_3;
        std::shared_ptr<std::string> index_4;
        std::string max_value_index_1;
        std::string max_value_index_2;
        std::string max_value_index_3;
        std::shared_ptr<std::string> max_value_index_4;
        std::string min_value_index_1;
        std::string min_value_index_2;
        std::string min_value_index_3;
        std::shared_ptr<std::string> min_value_index_4;
        std::string sizeof_array;

        public:
        const std::string & get_array_name() const { return array_name; }
        std::string & get_mutable_array_name() { return array_name; }
        void set_array_name(const std::string & value) { this->array_name = value; }

        const Condition3Enum & get_condition_1() const { return condition_1; }
        Condition3Enum & get_mutable_condition_1() { return condition_1; }
        void set_condition_1(const Condition3Enum & value) { this->condition_1 = value; }

        std::shared_ptr<std::string> get_condition_2() const { return condition_2; }
        void set_condition_2(std::shared_ptr<std::string> value) { this->condition_2 = value; }

        std::shared_ptr<std::string> get_condition_3() const { return condition_3; }
        void set_condition_3(std::shared_ptr<std::string> value) { this->condition_3 = value; }

        std::shared_ptr<std::string> get_condition_4() const { return condition_4; }
        void set_condition_4(std::shared_ptr<std::string> value) { this->condition_4 = value; }

        const std::string & get_default_index_1() const { return default_index_1; }
        std::string & get_mutable_default_index_1() { return default_index_1; }
        void set_default_index_1(const std::string & value) { this->default_index_1 = value; }

        const std::string & get_default_index_2() const { return default_index_2; }
        std::string & get_mutable_default_index_2() { return default_index_2; }
        void set_default_index_2(const std::string & value) { this->default_index_2 = value; }

        const std::string & get_default_index_3() const { return default_index_3; }
        std::string & get_mutable_default_index_3() { return default_index_3; }
        void set_default_index_3(const std::string & value) { this->default_index_3 = value; }

        std::shared_ptr<std::string> get_default_index_4() const { return default_index_4; }
        void set_default_index_4(std::shared_ptr<std::string> value) { this->default_index_4 = value; }

        const std::string & get_index_1() const { return index_1; }
        std::string & get_mutable_index_1() { return index_1; }
        void set_index_1(const std::string & value) { this->index_1 = value; }

        const std::string & get_index_2() const { return index_2; }
        std::string & get_mutable_index_2() { return index_2; }
        void set_index_2(const std::string & value) { this->index_2 = value; }

        const std::string & get_index_3() const { return index_3; }
        std::string & get_mutable_index_3() { return index_3; }
        void set_index_3(const std::string & value) { this->index_3 = value; }

        std::shared_ptr<std::string> get_index_4() const { return index_4; }
        void set_index_4(std::shared_ptr<std::string> value) { this->index_4 = value; }

        const std::string & get_max_value_index_1() const { return max_value_index_1; }
        std::string & get_mutable_max_value_index_1() { return max_value_index_1; }
        void set_max_value_index_1(const std::string & value) { this->max_value_index_1 = value; }

        const std::string & get_max_value_index_2() const { return max_value_index_2; }
        std::string & get_mutable_max_value_index_2() { return max_value_index_2; }
        void set_max_value_index_2(const std::string & value) { this->max_value_index_2 = value; }

        const std::string & get_max_value_index_3() const { return max_value_index_3; }
        std::string & get_mutable_max_value_index_3() { return max_value_index_3; }
        void set_max_value_index_3(const std::string & value) { this->max_value_index_3 = value; }

        std::shared_ptr<std::string> get_max_value_index_4() const { return max_value_index_4; }
        void set_max_value_index_4(std::shared_ptr<std::string> value) { this->max_value_index_4 = value; }

        const std::string & get_min_value_index_1() const { return min_value_index_1; }
        std::string & get_mutable_min_value_index_1() { return min_value_index_1; }
        void set_min_value_index_1(const std::string & value) { this->min_value_index_1 = value; }

        const std::string & get_min_value_index_2() const { return min_value_index_2; }
        std::string & get_mutable_min_value_index_2() { return min_value_index_2; }
        void set_min_value_index_2(const std::string & value) { this->min_value_index_2 = value; }

        const std::string & get_min_value_index_3() const { return min_value_index_3; }
        std::string & get_mutable_min_value_index_3() { return min_value_index_3; }
        void set_min_value_index_3(const std::string & value) { this->min_value_index_3 = value; }

        std::shared_ptr<std::string> get_min_value_index_4() const { return min_value_index_4; }
        void set_min_value_index_4(std::shared_ptr<std::string> value) { this->min_value_index_4 = value; }

        const std::string & get_sizeof_array() const { return sizeof_array; }
        std::string & get_mutable_sizeof_array() { return sizeof_array; }
        void set_sizeof_array(const std::string & value) { this->sizeof_array = value; }
    };

    enum class RntLaIvCondition1 : int { NITROGEN_AND_CARBON_0_IS_FALSE, NITROGEN_AND_CARBON_1_IS_FALSE, PHOSPHORUS_1_IS_FALSE, PLANT_TYPE_0_IS_TRUE, PLANT_TYPE_3_IS_FALSE, RNT_LA_IV_CONDITION1_PLANT_TYPE_3_IS_FALSE };

    class RntLaIv {
        public:
        RntLaIv() = default;
        virtual ~RntLaIv() = default;

        private:
        LaiAbovecanopyArrayName array_name;
        RntLaIvCondition1 condition_1;
        std::shared_ptr<std::string> condition_2;
        std::shared_ptr<std::string> condition_3;
        std::shared_ptr<std::string> condition_4;
        std::shared_ptr<std::string> condition_5;
        std::string default_index_1;
        std::string index_1;
        std::string max_value_index_1;
        std::string min_value_index_1;
        std::string sizeof_array;

        public:
        const LaiAbovecanopyArrayName & get_array_name() const { return array_name; }
        LaiAbovecanopyArrayName & get_mutable_array_name() { return array_name; }
        void set_array_name(const LaiAbovecanopyArrayName & value) { this->array_name = value; }

        const RntLaIvCondition1 & get_condition_1() const { return condition_1; }
        RntLaIvCondition1 & get_mutable_condition_1() { return condition_1; }
        void set_condition_1(const RntLaIvCondition1 & value) { this->condition_1 = value; }

        std::shared_ptr<std::string> get_condition_2() const { return condition_2; }
        void set_condition_2(std::shared_ptr<std::string> value) { this->condition_2 = value; }

        std::shared_ptr<std::string> get_condition_3() const { return condition_3; }
        void set_condition_3(std::shared_ptr<std::string> value) { this->condition_3 = value; }

        std::shared_ptr<std::string> get_condition_4() const { return condition_4; }
        void set_condition_4(std::shared_ptr<std::string> value) { this->condition_4 = value; }

        std::shared_ptr<std::string> get_condition_5() const { return condition_5; }
        void set_condition_5(std::shared_ptr<std::string> value) { this->condition_5 = value; }

        const std::string & get_default_index_1() const { return default_index_1; }
        std::string & get_mutable_default_index_1() { return default_index_1; }
        void set_default_index_1(const std::string & value) { this->default_index_1 = value; }

        const std::string & get_index_1() const { return index_1; }
        std::string & get_mutable_index_1() { return index_1; }
        void set_index_1(const std::string & value) { this->index_1 = value; }

        const std::string & get_max_value_index_1() const { return max_value_index_1; }
        std::string & get_mutable_max_value_index_1() { return max_value_index_1; }
        void set_max_value_index_1(const std::string & value) { this->max_value_index_1 = value; }

        const std::string & get_min_value_index_1() const { return min_value_index_1; }
        std::string & get_mutable_min_value_index_1() { return min_value_index_1; }
        void set_min_value_index_1(const std::string & value) { this->min_value_index_1 = value; }

        const std::string & get_sizeof_array() const { return sizeof_array; }
        std::string & get_mutable_sizeof_array() { return sizeof_array; }
        void set_sizeof_array(const std::string & value) { this->sizeof_array = value; }
    };

    class StickyRadiationproperties {
        public:
        StickyRadiationproperties() = default;
        virtual ~StickyRadiationproperties() = default;

        private:
        KonzelmannCoef konzelmann_coef;
        RntLaIv rnt_la_iv;

        public:
        const KonzelmannCoef & get_konzelmann_coef() const { return konzelmann_coef; }
        KonzelmannCoef & get_mutable_konzelmann_coef() { return konzelmann_coef; }
        void set_konzelmann_coef(const KonzelmannCoef & value) { this->konzelmann_coef = value; }

        const RntLaIv & get_rnt_la_iv() const { return rnt_la_iv; }
        RntLaIv & get_mutable_rnt_la_iv() { return rnt_la_iv; }
        void set_rnt_la_iv(const RntLaIv & value) { this->rnt_la_iv = value; }
    };

    class ParametersArraysAtmosphericRelatedProcesses {
        public:
        ParametersArraysAtmosphericRelatedProcesses() = default;
        virtual ~ParametersArraysAtmosphericRelatedProcesses() = default;

        private:
        StickyRadiationproperties radiationproperties;

        public:
        const StickyRadiationproperties & get_radiationproperties() const { return radiationproperties; }
        StickyRadiationproperties & get_mutable_radiationproperties() { return radiationproperties; }
        void set_radiationproperties(const StickyRadiationproperties & value) { this->radiationproperties = value; }
    };

    class InfilDistF {
        public:
        InfilDistF() = default;
        virtual ~InfilDistF() = default;

        private:
        CCoarseRootsAtmLayerArrayName array_name;
        std::shared_ptr<std::string> condition_1;
        std::shared_ptr<std::string> condition_2;
        std::shared_ptr<std::string> condition_3;
        std::shared_ptr<Condition3Enum> condition_4;
        std::string default_index_1;
        std::string default_index_2;
        std::string default_index_3;
        std::string default_index_4;
        std::string default_index_5;
        std::string default_index_6;
        std::string default_index_7;
        std::string default_index_8;
        std::string index_1;
        std::string index_2;
        std::string index_3;
        std::string index_4;
        std::string index_5;
        std::string index_6;
        std::string index_7;
        std::string index_8;
        std::string max_value_index_1;
        std::string max_value_index_2;
        std::string max_value_index_3;
        std::string max_value_index_4;
        std::string max_value_index_5;
        std::string max_value_index_6;
        std::string max_value_index_7;
        std::string max_value_index_8;
        std::string min_value_index_1;
        std::string min_value_index_2;
        std::string min_value_index_3;
        std::string min_value_index_4;
        std::string min_value_index_5;
        std::string min_value_index_6;
        std::string min_value_index_7;
        std::string min_value_index_8;
        std::string sizeof_array;

        public:
        const CCoarseRootsAtmLayerArrayName & get_array_name() const { return array_name; }
        CCoarseRootsAtmLayerArrayName & get_mutable_array_name() { return array_name; }
        void set_array_name(const CCoarseRootsAtmLayerArrayName & value) { this->array_name = value; }

        std::shared_ptr<std::string> get_condition_1() const { return condition_1; }
        void set_condition_1(std::shared_ptr<std::string> value) { this->condition_1 = value; }

        std::shared_ptr<std::string> get_condition_2() const { return condition_2; }
        void set_condition_2(std::shared_ptr<std::string> value) { this->condition_2 = value; }

        std::shared_ptr<std::string> get_condition_3() const { return condition_3; }
        void set_condition_3(std::shared_ptr<std::string> value) { this->condition_3 = value; }

        std::shared_ptr<Condition3Enum> get_condition_4() const { return condition_4; }
        void set_condition_4(std::shared_ptr<Condition3Enum> value) { this->condition_4 = value; }

        const std::string & get_default_index_1() const { return default_index_1; }
        std::string & get_mutable_default_index_1() { return default_index_1; }
        void set_default_index_1(const std::string & value) { this->default_index_1 = value; }

        const std::string & get_default_index_2() const { return default_index_2; }
        std::string & get_mutable_default_index_2() { return default_index_2; }
        void set_default_index_2(const std::string & value) { this->default_index_2 = value; }

        const std::string & get_default_index_3() const { return default_index_3; }
        std::string & get_mutable_default_index_3() { return default_index_3; }
        void set_default_index_3(const std::string & value) { this->default_index_3 = value; }

        const std::string & get_default_index_4() const { return default_index_4; }
        std::string & get_mutable_default_index_4() { return default_index_4; }
        void set_default_index_4(const std::string & value) { this->default_index_4 = value; }

        const std::string & get_default_index_5() const { return default_index_5; }
        std::string & get_mutable_default_index_5() { return default_index_5; }
        void set_default_index_5(const std::string & value) { this->default_index_5 = value; }

        const std::string & get_default_index_6() const { return default_index_6; }
        std::string & get_mutable_default_index_6() { return default_index_6; }
        void set_default_index_6(const std::string & value) { this->default_index_6 = value; }

        const std::string & get_default_index_7() const { return default_index_7; }
        std::string & get_mutable_default_index_7() { return default_index_7; }
        void set_default_index_7(const std::string & value) { this->default_index_7 = value; }

        const std::string & get_default_index_8() const { return default_index_8; }
        std::string & get_mutable_default_index_8() { return default_index_8; }
        void set_default_index_8(const std::string & value) { this->default_index_8 = value; }

        const std::string & get_index_1() const { return index_1; }
        std::string & get_mutable_index_1() { return index_1; }
        void set_index_1(const std::string & value) { this->index_1 = value; }

        const std::string & get_index_2() const { return index_2; }
        std::string & get_mutable_index_2() { return index_2; }
        void set_index_2(const std::string & value) { this->index_2 = value; }

        const std::string & get_index_3() const { return index_3; }
        std::string & get_mutable_index_3() { return index_3; }
        void set_index_3(const std::string & value) { this->index_3 = value; }

        const std::string & get_index_4() const { return index_4; }
        std::string & get_mutable_index_4() { return index_4; }
        void set_index_4(const std::string & value) { this->index_4 = value; }

        const std::string & get_index_5() const { return index_5; }
        std::string & get_mutable_index_5() { return index_5; }
        void set_index_5(const std::string & value) { this->index_5 = value; }

        const std::string & get_index_6() const { return index_6; }
        std::string & get_mutable_index_6() { return index_6; }
        void set_index_6(const std::string & value) { this->index_6 = value; }

        const std::string & get_index_7() const { return index_7; }
        std::string & get_mutable_index_7() { return index_7; }
        void set_index_7(const std::string & value) { this->index_7 = value; }

        const std::string & get_index_8() const { return index_8; }
        std::string & get_mutable_index_8() { return index_8; }
        void set_index_8(const std::string & value) { this->index_8 = value; }

        const std::string & get_max_value_index_1() const { return max_value_index_1; }
        std::string & get_mutable_max_value_index_1() { return max_value_index_1; }
        void set_max_value_index_1(const std::string & value) { this->max_value_index_1 = value; }

        const std::string & get_max_value_index_2() const { return max_value_index_2; }
        std::string & get_mutable_max_value_index_2() { return max_value_index_2; }
        void set_max_value_index_2(const std::string & value) { this->max_value_index_2 = value; }

        const std::string & get_max_value_index_3() const { return max_value_index_3; }
        std::string & get_mutable_max_value_index_3() { return max_value_index_3; }
        void set_max_value_index_3(const std::string & value) { this->max_value_index_3 = value; }

        const std::string & get_max_value_index_4() const { return max_value_index_4; }
        std::string & get_mutable_max_value_index_4() { return max_value_index_4; }
        void set_max_value_index_4(const std::string & value) { this->max_value_index_4 = value; }

        const std::string & get_max_value_index_5() const { return max_value_index_5; }
        std::string & get_mutable_max_value_index_5() { return max_value_index_5; }
        void set_max_value_index_5(const std::string & value) { this->max_value_index_5 = value; }

        const std::string & get_max_value_index_6() const { return max_value_index_6; }
        std::string & get_mutable_max_value_index_6() { return max_value_index_6; }
        void set_max_value_index_6(const std::string & value) { this->max_value_index_6 = value; }

        const std::string & get_max_value_index_7() const { return max_value_index_7; }
        std::string & get_mutable_max_value_index_7() { return max_value_index_7; }
        void set_max_value_index_7(const std::string & value) { this->max_value_index_7 = value; }

        const std::string & get_max_value_index_8() const { return max_value_index_8; }
        std::string & get_mutable_max_value_index_8() { return max_value_index_8; }
        void set_max_value_index_8(const std::string & value) { this->max_value_index_8 = value; }

        const std::string & get_min_value_index_1() const { return min_value_index_1; }
        std::string & get_mutable_min_value_index_1() { return min_value_index_1; }
        void set_min_value_index_1(const std::string & value) { this->min_value_index_1 = value; }

        const std::string & get_min_value_index_2() const { return min_value_index_2; }
        std::string & get_mutable_min_value_index_2() { return min_value_index_2; }
        void set_min_value_index_2(const std::string & value) { this->min_value_index_2 = value; }

        const std::string & get_min_value_index_3() const { return min_value_index_3; }
        std::string & get_mutable_min_value_index_3() { return min_value_index_3; }
        void set_min_value_index_3(const std::string & value) { this->min_value_index_3 = value; }

        const std::string & get_min_value_index_4() const { return min_value_index_4; }
        std::string & get_mutable_min_value_index_4() { return min_value_index_4; }
        void set_min_value_index_4(const std::string & value) { this->min_value_index_4 = value; }

        const std::string & get_min_value_index_5() const { return min_value_index_5; }
        std::string & get_mutable_min_value_index_5() { return min_value_index_5; }
        void set_min_value_index_5(const std::string & value) { this->min_value_index_5 = value; }

        const std::string & get_min_value_index_6() const { return min_value_index_6; }
        std::string & get_mutable_min_value_index_6() { return min_value_index_6; }
        void set_min_value_index_6(const std::string & value) { this->min_value_index_6 = value; }

        const std::string & get_min_value_index_7() const { return min_value_index_7; }
        std::string & get_mutable_min_value_index_7() { return min_value_index_7; }
        void set_min_value_index_7(const std::string & value) { this->min_value_index_7 = value; }

        const std::string & get_min_value_index_8() const { return min_value_index_8; }
        std::string & get_mutable_min_value_index_8() { return min_value_index_8; }
        void set_min_value_index_8(const std::string & value) { this->min_value_index_8 = value; }

        const std::string & get_sizeof_array() const { return sizeof_array; }
        std::string & get_mutable_sizeof_array() { return sizeof_array; }
        void set_sizeof_array(const std::string & value) { this->sizeof_array = value; }
    };

    class TentacledIrrigation {
        public:
        TentacledIrrigation() = default;
        virtual ~TentacledIrrigation() = default;

        private:
        InfilDistF infil_dist_f;

        public:
        const InfilDistF & get_infil_dist_f() const { return infil_dist_f; }
        InfilDistF & get_mutable_infil_dist_f() { return infil_dist_f; }
        void set_infil_dist_f(const InfilDistF & value) { this->infil_dist_f = value; }
    };

    class AbsError {
        public:
        AbsError() = default;
        virtual ~AbsError() = default;

        private:
        std::string array_name;
        std::string condition_1;
        std::string sizeof_array;

        public:
        const std::string & get_array_name() const { return array_name; }
        std::string & get_mutable_array_name() { return array_name; }
        void set_array_name(const std::string & value) { this->array_name = value; }

        const std::string & get_condition_1() const { return condition_1; }
        std::string & get_mutable_condition_1() { return condition_1; }
        void set_condition_1(const std::string & value) { this->condition_1 = value; }

        const std::string & get_sizeof_array() const { return sizeof_array; }
        std::string & get_mutable_sizeof_array() { return sizeof_array; }
        void set_sizeof_array(const std::string & value) { this->sizeof_array = value; }
    };

    class BoxCox {
        public:
        BoxCox() = default;
        virtual ~BoxCox() = default;

        private:
        std::string array_name;
        std::string sizeof_array;

        public:
        const std::string & get_array_name() const { return array_name; }
        std::string & get_mutable_array_name() { return array_name; }
        void set_array_name(const std::string & value) { this->array_name = value; }

        const std::string & get_sizeof_array() const { return sizeof_array; }
        std::string & get_mutable_sizeof_array() { return sizeof_array; }
        void set_sizeof_array(const std::string & value) { this->sizeof_array = value; }
    };

    class TentacledTechnical {
        public:
        TentacledTechnical() = default;
        virtual ~TentacledTechnical() = default;

        private:
        AbsError abs_error;
        BoxCox box_coxoffset;
        BoxCox box_coxpower;
        AbsError key_index;
        AbsError rel_error;
        AbsError scaling_index;
        AbsError scaling_observed;

        public:
        const AbsError & get_abs_error() const { return abs_error; }
        AbsError & get_mutable_abs_error() { return abs_error; }
        void set_abs_error(const AbsError & value) { this->abs_error = value; }

        const BoxCox & get_box_coxoffset() const { return box_coxoffset; }
        BoxCox & get_mutable_box_coxoffset() { return box_coxoffset; }
        void set_box_coxoffset(const BoxCox & value) { this->box_coxoffset = value; }

        const BoxCox & get_box_coxpower() const { return box_coxpower; }
        BoxCox & get_mutable_box_coxpower() { return box_coxpower; }
        void set_box_coxpower(const BoxCox & value) { this->box_coxpower = value; }

        const AbsError & get_key_index() const { return key_index; }
        AbsError & get_mutable_key_index() { return key_index; }
        void set_key_index(const AbsError & value) { this->key_index = value; }

        const AbsError & get_rel_error() const { return rel_error; }
        AbsError & get_mutable_rel_error() { return rel_error; }
        void set_rel_error(const AbsError & value) { this->rel_error = value; }

        const AbsError & get_scaling_index() const { return scaling_index; }
        AbsError & get_mutable_scaling_index() { return scaling_index; }
        void set_scaling_index(const AbsError & value) { this->scaling_index = value; }

        const AbsError & get_scaling_observed() const { return scaling_observed; }
        AbsError & get_mutable_scaling_observed() { return scaling_observed; }
        void set_scaling_observed(const AbsError & value) { this->scaling_observed = value; }
    };

    class ParametersArraysModelFacilities {
        public:
        ParametersArraysModelFacilities() = default;
        virtual ~ParametersArraysModelFacilities() = default;

        private:
        TentacledIrrigation irrigation;
        TentacledTechnical technical;

        public:
        const TentacledIrrigation & get_irrigation() const { return irrigation; }
        TentacledIrrigation & get_mutable_irrigation() { return irrigation; }
        void set_irrigation(const TentacledIrrigation & value) { this->irrigation = value; }

        const TentacledTechnical & get_technical() const { return technical; }
        TentacledTechnical & get_mutable_technical() { return technical; }
        void set_technical(const TentacledTechnical & value) { this->technical = value; }
    };

    class TentacledExternalPInputs {
        public:
        TentacledExternalPInputs() = default;
        virtual ~TentacledExternalPInputs() = default;

        private:
        RntLaIv p_fert_rate;

        public:
        const RntLaIv & get_p_fert_rate() const { return p_fert_rate; }
        RntLaIv & get_mutable_p_fert_rate() { return p_fert_rate; }
        void set_p_fert_rate(const RntLaIv & value) { this->p_fert_rate = value; }
    };

    class StickyPlantGrowth {
        public:
        StickyPlantGrowth() = default;
        virtual ~StickyPlantGrowth() = default;

        private:
        RntLaIv allocation_grain_range;
        RntLaIv allo_fungic1;
        RntLaIv allo_max_fungic1;
        RntLaIv allo_rate_coef;
        RntLaIv c3_type;
        RntLaIv c_leafto_grain;
        RntLaIv c_leafto_stem;
        KonzelmannCoef cleaning_day_no;
        KonzelmannCoef cleaning_years;
        RntLaIv cnl_opt;
        RntLaIv cnl_th;
        RntLaIv cn_ratio_max_litter;
        RntLaIv cn_ratio_min_c_roots;
        RntLaIv cn_ratio_min_leaf;
        RntLaIv cn_ratio_min_roots;
        RntLaIv cn_ratio_min_stem;
        RntLaIv coarse_root_lf2;
        RntLaIv coarse_root_rate1;
        RntLaIv coarse_root_rate2;
        RntLaIv coarse_root_tsum1;
        RntLaIv coarse_root_tsum2;
        RntLaIv cpl_opt;
        RntLaIv cpl_th;
        RntLaIv cp_ratio_max_litter;
        RntLaIv cp_ratio_min_c_roots;
        RntLaIv cp_ratio_min_leaf;
        RntLaIv cp_ratio_min_roots;
        RntLaIv cp_ratio_min_stem;
        RntLaIv c_rootsto_grain;
        RntLaIv c_seed;
        RntLaIv c_stemto_grain;
        KonzelmannCoef degreeof_cleaning;
        RntLaIv dorm_final_day_no;
        RntLaIv dormancy_tth;
        RntLaIv drip;
        RntLaIv emergence_dayno;
        RntLaIv emergence_days;
        RntLaIv emerge_tsum;
        RntLaIv emerge_tth;
        RntLaIv f_harvest_c_roots;
        RntLaIv f_harvest_grain;
        RntLaIv f_harvest_leaf;
        RntLaIv f_harvest_roots;
        RntLaIv f_harvest_stem;
        RntLaIv fix_nsupply;
        RntLaIv f_litter_c_roots;
        RntLaIv f_litter_grain;
        RntLaIv f_litter_leaf;
        RntLaIv f_litter_roots;
        RntLaIv f_litter_stem;
        RntLaIv fraction_r;
        RntLaIv fungi_carbondemand_coef;
        RntLaIv fungi_mantle_rate;
        RntLaIv fungi_max_cn;
        RntLaIv fungi_max_cp;
        RntLaIv fungi_min_cn;
        RntLaIv fungi_min_cp;
        RntLaIv fungi_min_nmycon_supply;
        RntLaIv fungi_min_pmycon_supply;
        RntLaIv fungi_myc_rate;
        RntLaIv fungi_nh4_uptrate;
        RntLaIv fungi_no3_uptrate;
        RntLaIv fungi_norguptrate;
        RntLaIv fungi_po4_uptrate;
        RntLaIv fungi_porguptrate;
        RntLaIv fungi_rate1;
        RntLaIv fungi_rate2;
        RntLaIv grain_lf2;
        RntLaIv grain_rate1;
        RntLaIv grain_rate2;
        RntLaIv grain_step;
        RntLaIv grain_step_day;
        RntLaIv grain_step_temp;
        RntLaIv grain_th_day;
        RntLaIv grain_th_temp;
        RntLaIv grain_tsum1;
        RntLaIv grain_tsum2;
        RntLaIv growth_coef;
        RntLaIv gsi_post_harvest;
        KonzelmannCoef harvest_day_no;
        RntLaIv harvest_dayno;
        RntLaIv harvest_days;
        RntLaIv harvest_lai;
        KonzelmannCoef harvest_years;
        RntLaIv ic_coarse_root;
        RntLaIv ic_grain;
        RntLaIv ic_leaf;
        RntLaIv icn_coarse_root;
        RntLaIv icn_grain;
        RntLaIv icn_leaf;
        RntLaIv icn_old_coarse_root;
        RntLaIv icn_old_leaf;
        RntLaIv icn_old_root;
        RntLaIv icn_old_stem;
        RntLaIv icn_root;
        RntLaIv icn_stem;
        RntLaIv ic_old_coarse_root;
        RntLaIv ic_old_leaf;
        RntLaIv ic_old_root;
        RntLaIv ic_old_stem;
        RntLaIv icp_coarse_root;
        RntLaIv icp_grain;
        RntLaIv icp_leaf;
        RntLaIv icp_old_coarse_root;
        RntLaIv icp_old_leaf;
        RntLaIv icp_old_root;
        RntLaIv icp_old_stem;
        RntLaIv icp_root;
        RntLaIv icp_stem;
        RntLaIv ic_root;
        RntLaIv ic_stem;
        RntLaIv in_coarse_root;
        RntLaIv in_grain;
        RntLaIv initial_gsi;
        RntLaIv initial_tsum;
        RntLaIv in_leaf;
        RntLaIv in_old_coarse_root;
        RntLaIv in_old_leaf;
        RntLaIv in_old_root;
        RntLaIv in_old_stem;
        RntLaIv in_root;
        RntLaIv in_stem;
        RntLaIv ip_coarse_root;
        RntLaIv ip_grain;
        RntLaIv i_plant_age;
        RntLaIv ip_leaf;
        RntLaIv ip_old_coarse_root;
        RntLaIv ip_old_leaf;
        RntLaIv ip_old_root;
        RntLaIv ip_old_stem;
        RntLaIv ip_root;
        RntLaIv ip_stem;
        RntLaIv lai_enh_coef;
        RntLaIv leaf_lf2;
        RntLaIv leafc1;
        RntLaIv leafc2;
        RntLaIv leafc3;
        RntLaIv leaf_rate1;
        RntLaIv leaf_rate2;
        RntLaIv leaf_tsum1;
        RntLaIv leaf_tsum2;
        RntLaIv mature_tsum;
        RntLaIv mature_tth;
        RntLaIv max_gsi;
        RntLaIv max_leaf_lifetime;
        RntLaIv max_plant_lifetime;
        RntLaIv m_coef_coarse_root;
        RntLaIv m_coef_grain;
        RntLaIv m_coef_leaf;
        RntLaIv m_coef_root;
        RntLaIv m_coef_stem;
        RntLaIv min_frac_green_response;
        RntLaIv min_gsi;
        RntLaIv minimum_response;
        RntLaIv mobile_allo_coef;
        RntLaIv mulch;
        RntLaIv mycelia_frac;
        RntLaIv myco_degree_fungi_coef;
        RntLaIv navail_coef;
        RntLaIv new_coarse_roots;
        RntLaIv new_leaf;
        RntLaIv new_roots;
        RntLaIv new_stem;
        RntLaIv n_fix_coef;
        RntLaIv nh4_coef;
        RntLaIv n_leafto_grain;
        RntLaIv no3_coef;
        RntLaIv n_org_coef;
        RntLaIv nretention_fungi;
        RntLaIv n_rootsto_grain;
        RntLaIv n_stemto_grain;
        RntLaIv old_coarse_roots;
        RntLaIv old_leaf;
        RntLaIv old_roots;
        RntLaIv old_stem;
        RntLaIv opt_green_index;
        RntLaIv pavail_coef;
        RntLaIv p_f_harvest_c_roots;
        RntLaIv p_f_harvest_grain;
        RntLaIv p_f_harvest_leaf;
        RntLaIv p_f_harvest_roots;
        RntLaIv p_f_harvest_stem;
        RntLaIv p_f_litter_c_roots;
        RntLaIv p_f_litter_grain;
        RntLaIv p_f_litter_leaf;
        RntLaIv p_f_litter_roots;
        RntLaIv p_f_litter_stem;
        KonzelmannCoef plant_cleaning_index;
        KonzelmannCoef plant_day_index;
        KonzelmannCoef plant_year_index;
        RntLaIv p_leafto_grain;
        RntLaIv pmax;
        RntLaIv position4_target;
        RntLaIv pretention_fungi;
        RntLaIv p_rootsto_grain;
        RntLaIv p_stemto_grain;
        RntLaIv quan_eff;
        RntLaIv rad_efficiency;
        RntLaIv rad_eff_red;
        RntLaIv rate_coef_f_root;
        RntLaIv r_boundary;
        RntLaIv rel_w_water;
        RntLaIv resp_coef_fungi;
        RntLaIv ripening_tsum;
        RntLaIv ripening_tth;
        RntLaIv root_lf2;
        RntLaIv root_c_nc1;
        RntLaIv root_c_nc2;
        RntLaIv root_c_nc3;
        RntLaIv root_c_pc1;
        RntLaIv root_c_pc2;
        RntLaIv root_c_pc3;
        RntLaIv root_leaf_ratio;
        RntLaIv root_massc1;
        RntLaIv root_massc2;
        RntLaIv root_massc3;
        RntLaIv root_nodule_ratio;
        RntLaIv root_rate1;
        RntLaIv root_rate2;
        RntLaIv root_tsum1;
        RntLaIv root_tsum2;
        RntLaIv root_waterc1;
        RntLaIv root_waterc2;
        RntLaIv root_waterc3;
        RntLaIv shoot_coef;
        RntLaIv sowing_dayno;
        RntLaIv sowing_days;
        RntLaIv sow_tsum;
        RntLaIv sow_tth;
        RntLaIv specific_max_fixation;
        RntLaIv specific_min_fixation;
        RntLaIv specific_nsensivity;
        RntLaIv start_years;
        RntLaIv stem_lf2;
        RntLaIv stem_leaf_nodule_ratio;
        RntLaIv stem_rate1;
        RntLaIv stem_rate2;
        RntLaIv stem_tsum1;
        RntLaIv stem_tsum2;
        RntLaIv stubble_leaf;
        RntLaIv stubble_stem;
        RntLaIv tf_sum_start;
        RntLaIv tl_max;
        RntLaIv tl_min;
        RntLaIv tl_opt1;
        RntLaIv tl_opt2;
        RntLaIv tr_current;
        RntLaIv t_sum_opt;
        RntLaIv up_a_coef;
        RntLaIv up_b_coef;
        RntLaIv up_c_coef;
        RntLaIv up_cn_ratio;
        RntLaIv up_end;
        RntLaIv up_start;
        RntLaIv vcmax;
        RntLaIv water_efficiency;

        public:
        const RntLaIv & get_allocation_grain_range() const { return allocation_grain_range; }
        RntLaIv & get_mutable_allocation_grain_range() { return allocation_grain_range; }
        void set_allocation_grain_range(const RntLaIv & value) { this->allocation_grain_range = value; }

        const RntLaIv & get_allo_fungic1() const { return allo_fungic1; }
        RntLaIv & get_mutable_allo_fungic1() { return allo_fungic1; }
        void set_allo_fungic1(const RntLaIv & value) { this->allo_fungic1 = value; }

        const RntLaIv & get_allo_max_fungic1() const { return allo_max_fungic1; }
        RntLaIv & get_mutable_allo_max_fungic1() { return allo_max_fungic1; }
        void set_allo_max_fungic1(const RntLaIv & value) { this->allo_max_fungic1 = value; }

        const RntLaIv & get_allo_rate_coef() const { return allo_rate_coef; }
        RntLaIv & get_mutable_allo_rate_coef() { return allo_rate_coef; }
        void set_allo_rate_coef(const RntLaIv & value) { this->allo_rate_coef = value; }

        const RntLaIv & get_c3_type() const { return c3_type; }
        RntLaIv & get_mutable_c3_type() { return c3_type; }
        void set_c3_type(const RntLaIv & value) { this->c3_type = value; }

        const RntLaIv & get_c_leafto_grain() const { return c_leafto_grain; }
        RntLaIv & get_mutable_c_leafto_grain() { return c_leafto_grain; }
        void set_c_leafto_grain(const RntLaIv & value) { this->c_leafto_grain = value; }

        const RntLaIv & get_c_leafto_stem() const { return c_leafto_stem; }
        RntLaIv & get_mutable_c_leafto_stem() { return c_leafto_stem; }
        void set_c_leafto_stem(const RntLaIv & value) { this->c_leafto_stem = value; }

        const KonzelmannCoef & get_cleaning_day_no() const { return cleaning_day_no; }
        KonzelmannCoef & get_mutable_cleaning_day_no() { return cleaning_day_no; }
        void set_cleaning_day_no(const KonzelmannCoef & value) { this->cleaning_day_no = value; }

        const KonzelmannCoef & get_cleaning_years() const { return cleaning_years; }
        KonzelmannCoef & get_mutable_cleaning_years() { return cleaning_years; }
        void set_cleaning_years(const KonzelmannCoef & value) { this->cleaning_years = value; }

        const RntLaIv & get_cnl_opt() const { return cnl_opt; }
        RntLaIv & get_mutable_cnl_opt() { return cnl_opt; }
        void set_cnl_opt(const RntLaIv & value) { this->cnl_opt = value; }

        const RntLaIv & get_cnl_th() const { return cnl_th; }
        RntLaIv & get_mutable_cnl_th() { return cnl_th; }
        void set_cnl_th(const RntLaIv & value) { this->cnl_th = value; }

        const RntLaIv & get_cn_ratio_max_litter() const { return cn_ratio_max_litter; }
        RntLaIv & get_mutable_cn_ratio_max_litter() { return cn_ratio_max_litter; }
        void set_cn_ratio_max_litter(const RntLaIv & value) { this->cn_ratio_max_litter = value; }

        const RntLaIv & get_cn_ratio_min_c_roots() const { return cn_ratio_min_c_roots; }
        RntLaIv & get_mutable_cn_ratio_min_c_roots() { return cn_ratio_min_c_roots; }
        void set_cn_ratio_min_c_roots(const RntLaIv & value) { this->cn_ratio_min_c_roots = value; }

        const RntLaIv & get_cn_ratio_min_leaf() const { return cn_ratio_min_leaf; }
        RntLaIv & get_mutable_cn_ratio_min_leaf() { return cn_ratio_min_leaf; }
        void set_cn_ratio_min_leaf(const RntLaIv & value) { this->cn_ratio_min_leaf = value; }

        const RntLaIv & get_cn_ratio_min_roots() const { return cn_ratio_min_roots; }
        RntLaIv & get_mutable_cn_ratio_min_roots() { return cn_ratio_min_roots; }
        void set_cn_ratio_min_roots(const RntLaIv & value) { this->cn_ratio_min_roots = value; }

        const RntLaIv & get_cn_ratio_min_stem() const { return cn_ratio_min_stem; }
        RntLaIv & get_mutable_cn_ratio_min_stem() { return cn_ratio_min_stem; }
        void set_cn_ratio_min_stem(const RntLaIv & value) { this->cn_ratio_min_stem = value; }

        const RntLaIv & get_coarse_root_lf2() const { return coarse_root_lf2; }
        RntLaIv & get_mutable_coarse_root_lf2() { return coarse_root_lf2; }
        void set_coarse_root_lf2(const RntLaIv & value) { this->coarse_root_lf2 = value; }

        const RntLaIv & get_coarse_root_rate1() const { return coarse_root_rate1; }
        RntLaIv & get_mutable_coarse_root_rate1() { return coarse_root_rate1; }
        void set_coarse_root_rate1(const RntLaIv & value) { this->coarse_root_rate1 = value; }

        const RntLaIv & get_coarse_root_rate2() const { return coarse_root_rate2; }
        RntLaIv & get_mutable_coarse_root_rate2() { return coarse_root_rate2; }
        void set_coarse_root_rate2(const RntLaIv & value) { this->coarse_root_rate2 = value; }

        const RntLaIv & get_coarse_root_tsum1() const { return coarse_root_tsum1; }
        RntLaIv & get_mutable_coarse_root_tsum1() { return coarse_root_tsum1; }
        void set_coarse_root_tsum1(const RntLaIv & value) { this->coarse_root_tsum1 = value; }

        const RntLaIv & get_coarse_root_tsum2() const { return coarse_root_tsum2; }
        RntLaIv & get_mutable_coarse_root_tsum2() { return coarse_root_tsum2; }
        void set_coarse_root_tsum2(const RntLaIv & value) { this->coarse_root_tsum2 = value; }

        const RntLaIv & get_cpl_opt() const { return cpl_opt; }
        RntLaIv & get_mutable_cpl_opt() { return cpl_opt; }
        void set_cpl_opt(const RntLaIv & value) { this->cpl_opt = value; }

        const RntLaIv & get_cpl_th() const { return cpl_th; }
        RntLaIv & get_mutable_cpl_th() { return cpl_th; }
        void set_cpl_th(const RntLaIv & value) { this->cpl_th = value; }

        const RntLaIv & get_cp_ratio_max_litter() const { return cp_ratio_max_litter; }
        RntLaIv & get_mutable_cp_ratio_max_litter() { return cp_ratio_max_litter; }
        void set_cp_ratio_max_litter(const RntLaIv & value) { this->cp_ratio_max_litter = value; }

        const RntLaIv & get_cp_ratio_min_c_roots() const { return cp_ratio_min_c_roots; }
        RntLaIv & get_mutable_cp_ratio_min_c_roots() { return cp_ratio_min_c_roots; }
        void set_cp_ratio_min_c_roots(const RntLaIv & value) { this->cp_ratio_min_c_roots = value; }

        const RntLaIv & get_cp_ratio_min_leaf() const { return cp_ratio_min_leaf; }
        RntLaIv & get_mutable_cp_ratio_min_leaf() { return cp_ratio_min_leaf; }
        void set_cp_ratio_min_leaf(const RntLaIv & value) { this->cp_ratio_min_leaf = value; }

        const RntLaIv & get_cp_ratio_min_roots() const { return cp_ratio_min_roots; }
        RntLaIv & get_mutable_cp_ratio_min_roots() { return cp_ratio_min_roots; }
        void set_cp_ratio_min_roots(const RntLaIv & value) { this->cp_ratio_min_roots = value; }

        const RntLaIv & get_cp_ratio_min_stem() const { return cp_ratio_min_stem; }
        RntLaIv & get_mutable_cp_ratio_min_stem() { return cp_ratio_min_stem; }
        void set_cp_ratio_min_stem(const RntLaIv & value) { this->cp_ratio_min_stem = value; }

        const RntLaIv & get_c_rootsto_grain() const { return c_rootsto_grain; }
        RntLaIv & get_mutable_c_rootsto_grain() { return c_rootsto_grain; }
        void set_c_rootsto_grain(const RntLaIv & value) { this->c_rootsto_grain = value; }

        const RntLaIv & get_c_seed() const { return c_seed; }
        RntLaIv & get_mutable_c_seed() { return c_seed; }
        void set_c_seed(const RntLaIv & value) { this->c_seed = value; }

        const RntLaIv & get_c_stemto_grain() const { return c_stemto_grain; }
        RntLaIv & get_mutable_c_stemto_grain() { return c_stemto_grain; }
        void set_c_stemto_grain(const RntLaIv & value) { this->c_stemto_grain = value; }

        const KonzelmannCoef & get_degreeof_cleaning() const { return degreeof_cleaning; }
        KonzelmannCoef & get_mutable_degreeof_cleaning() { return degreeof_cleaning; }
        void set_degreeof_cleaning(const KonzelmannCoef & value) { this->degreeof_cleaning = value; }

        const RntLaIv & get_dorm_final_day_no() const { return dorm_final_day_no; }
        RntLaIv & get_mutable_dorm_final_day_no() { return dorm_final_day_no; }
        void set_dorm_final_day_no(const RntLaIv & value) { this->dorm_final_day_no = value; }

        const RntLaIv & get_dormancy_tth() const { return dormancy_tth; }
        RntLaIv & get_mutable_dormancy_tth() { return dormancy_tth; }
        void set_dormancy_tth(const RntLaIv & value) { this->dormancy_tth = value; }

        const RntLaIv & get_drip() const { return drip; }
        RntLaIv & get_mutable_drip() { return drip; }
        void set_drip(const RntLaIv & value) { this->drip = value; }

        const RntLaIv & get_emergence_dayno() const { return emergence_dayno; }
        RntLaIv & get_mutable_emergence_dayno() { return emergence_dayno; }
        void set_emergence_dayno(const RntLaIv & value) { this->emergence_dayno = value; }

        const RntLaIv & get_emergence_days() const { return emergence_days; }
        RntLaIv & get_mutable_emergence_days() { return emergence_days; }
        void set_emergence_days(const RntLaIv & value) { this->emergence_days = value; }

        const RntLaIv & get_emerge_tsum() const { return emerge_tsum; }
        RntLaIv & get_mutable_emerge_tsum() { return emerge_tsum; }
        void set_emerge_tsum(const RntLaIv & value) { this->emerge_tsum = value; }

        const RntLaIv & get_emerge_tth() const { return emerge_tth; }
        RntLaIv & get_mutable_emerge_tth() { return emerge_tth; }
        void set_emerge_tth(const RntLaIv & value) { this->emerge_tth = value; }

        const RntLaIv & get_f_harvest_c_roots() const { return f_harvest_c_roots; }
        RntLaIv & get_mutable_f_harvest_c_roots() { return f_harvest_c_roots; }
        void set_f_harvest_c_roots(const RntLaIv & value) { this->f_harvest_c_roots = value; }

        const RntLaIv & get_f_harvest_grain() const { return f_harvest_grain; }
        RntLaIv & get_mutable_f_harvest_grain() { return f_harvest_grain; }
        void set_f_harvest_grain(const RntLaIv & value) { this->f_harvest_grain = value; }

        const RntLaIv & get_f_harvest_leaf() const { return f_harvest_leaf; }
        RntLaIv & get_mutable_f_harvest_leaf() { return f_harvest_leaf; }
        void set_f_harvest_leaf(const RntLaIv & value) { this->f_harvest_leaf = value; }

        const RntLaIv & get_f_harvest_roots() const { return f_harvest_roots; }
        RntLaIv & get_mutable_f_harvest_roots() { return f_harvest_roots; }
        void set_f_harvest_roots(const RntLaIv & value) { this->f_harvest_roots = value; }

        const RntLaIv & get_f_harvest_stem() const { return f_harvest_stem; }
        RntLaIv & get_mutable_f_harvest_stem() { return f_harvest_stem; }
        void set_f_harvest_stem(const RntLaIv & value) { this->f_harvest_stem = value; }

        const RntLaIv & get_fix_nsupply() const { return fix_nsupply; }
        RntLaIv & get_mutable_fix_nsupply() { return fix_nsupply; }
        void set_fix_nsupply(const RntLaIv & value) { this->fix_nsupply = value; }

        const RntLaIv & get_f_litter_c_roots() const { return f_litter_c_roots; }
        RntLaIv & get_mutable_f_litter_c_roots() { return f_litter_c_roots; }
        void set_f_litter_c_roots(const RntLaIv & value) { this->f_litter_c_roots = value; }

        const RntLaIv & get_f_litter_grain() const { return f_litter_grain; }
        RntLaIv & get_mutable_f_litter_grain() { return f_litter_grain; }
        void set_f_litter_grain(const RntLaIv & value) { this->f_litter_grain = value; }

        const RntLaIv & get_f_litter_leaf() const { return f_litter_leaf; }
        RntLaIv & get_mutable_f_litter_leaf() { return f_litter_leaf; }
        void set_f_litter_leaf(const RntLaIv & value) { this->f_litter_leaf = value; }

        const RntLaIv & get_f_litter_roots() const { return f_litter_roots; }
        RntLaIv & get_mutable_f_litter_roots() { return f_litter_roots; }
        void set_f_litter_roots(const RntLaIv & value) { this->f_litter_roots = value; }

        const RntLaIv & get_f_litter_stem() const { return f_litter_stem; }
        RntLaIv & get_mutable_f_litter_stem() { return f_litter_stem; }
        void set_f_litter_stem(const RntLaIv & value) { this->f_litter_stem = value; }

        const RntLaIv & get_fraction_r() const { return fraction_r; }
        RntLaIv & get_mutable_fraction_r() { return fraction_r; }
        void set_fraction_r(const RntLaIv & value) { this->fraction_r = value; }

        const RntLaIv & get_fungi_carbondemand_coef() const { return fungi_carbondemand_coef; }
        RntLaIv & get_mutable_fungi_carbondemand_coef() { return fungi_carbondemand_coef; }
        void set_fungi_carbondemand_coef(const RntLaIv & value) { this->fungi_carbondemand_coef = value; }

        const RntLaIv & get_fungi_mantle_rate() const { return fungi_mantle_rate; }
        RntLaIv & get_mutable_fungi_mantle_rate() { return fungi_mantle_rate; }
        void set_fungi_mantle_rate(const RntLaIv & value) { this->fungi_mantle_rate = value; }

        const RntLaIv & get_fungi_max_cn() const { return fungi_max_cn; }
        RntLaIv & get_mutable_fungi_max_cn() { return fungi_max_cn; }
        void set_fungi_max_cn(const RntLaIv & value) { this->fungi_max_cn = value; }

        const RntLaIv & get_fungi_max_cp() const { return fungi_max_cp; }
        RntLaIv & get_mutable_fungi_max_cp() { return fungi_max_cp; }
        void set_fungi_max_cp(const RntLaIv & value) { this->fungi_max_cp = value; }

        const RntLaIv & get_fungi_min_cn() const { return fungi_min_cn; }
        RntLaIv & get_mutable_fungi_min_cn() { return fungi_min_cn; }
        void set_fungi_min_cn(const RntLaIv & value) { this->fungi_min_cn = value; }

        const RntLaIv & get_fungi_min_cp() const { return fungi_min_cp; }
        RntLaIv & get_mutable_fungi_min_cp() { return fungi_min_cp; }
        void set_fungi_min_cp(const RntLaIv & value) { this->fungi_min_cp = value; }

        const RntLaIv & get_fungi_min_nmycon_supply() const { return fungi_min_nmycon_supply; }
        RntLaIv & get_mutable_fungi_min_nmycon_supply() { return fungi_min_nmycon_supply; }
        void set_fungi_min_nmycon_supply(const RntLaIv & value) { this->fungi_min_nmycon_supply = value; }

        const RntLaIv & get_fungi_min_pmycon_supply() const { return fungi_min_pmycon_supply; }
        RntLaIv & get_mutable_fungi_min_pmycon_supply() { return fungi_min_pmycon_supply; }
        void set_fungi_min_pmycon_supply(const RntLaIv & value) { this->fungi_min_pmycon_supply = value; }

        const RntLaIv & get_fungi_myc_rate() const { return fungi_myc_rate; }
        RntLaIv & get_mutable_fungi_myc_rate() { return fungi_myc_rate; }
        void set_fungi_myc_rate(const RntLaIv & value) { this->fungi_myc_rate = value; }

        const RntLaIv & get_fungi_nh4_uptrate() const { return fungi_nh4_uptrate; }
        RntLaIv & get_mutable_fungi_nh4_uptrate() { return fungi_nh4_uptrate; }
        void set_fungi_nh4_uptrate(const RntLaIv & value) { this->fungi_nh4_uptrate = value; }

        const RntLaIv & get_fungi_no3_uptrate() const { return fungi_no3_uptrate; }
        RntLaIv & get_mutable_fungi_no3_uptrate() { return fungi_no3_uptrate; }
        void set_fungi_no3_uptrate(const RntLaIv & value) { this->fungi_no3_uptrate = value; }

        const RntLaIv & get_fungi_norguptrate() const { return fungi_norguptrate; }
        RntLaIv & get_mutable_fungi_norguptrate() { return fungi_norguptrate; }
        void set_fungi_norguptrate(const RntLaIv & value) { this->fungi_norguptrate = value; }

        const RntLaIv & get_fungi_po4_uptrate() const { return fungi_po4_uptrate; }
        RntLaIv & get_mutable_fungi_po4_uptrate() { return fungi_po4_uptrate; }
        void set_fungi_po4_uptrate(const RntLaIv & value) { this->fungi_po4_uptrate = value; }

        const RntLaIv & get_fungi_porguptrate() const { return fungi_porguptrate; }
        RntLaIv & get_mutable_fungi_porguptrate() { return fungi_porguptrate; }
        void set_fungi_porguptrate(const RntLaIv & value) { this->fungi_porguptrate = value; }

        const RntLaIv & get_fungi_rate1() const { return fungi_rate1; }
        RntLaIv & get_mutable_fungi_rate1() { return fungi_rate1; }
        void set_fungi_rate1(const RntLaIv & value) { this->fungi_rate1 = value; }

        const RntLaIv & get_fungi_rate2() const { return fungi_rate2; }
        RntLaIv & get_mutable_fungi_rate2() { return fungi_rate2; }
        void set_fungi_rate2(const RntLaIv & value) { this->fungi_rate2 = value; }

        const RntLaIv & get_grain_lf2() const { return grain_lf2; }
        RntLaIv & get_mutable_grain_lf2() { return grain_lf2; }
        void set_grain_lf2(const RntLaIv & value) { this->grain_lf2 = value; }

        const RntLaIv & get_grain_rate1() const { return grain_rate1; }
        RntLaIv & get_mutable_grain_rate1() { return grain_rate1; }
        void set_grain_rate1(const RntLaIv & value) { this->grain_rate1 = value; }

        const RntLaIv & get_grain_rate2() const { return grain_rate2; }
        RntLaIv & get_mutable_grain_rate2() { return grain_rate2; }
        void set_grain_rate2(const RntLaIv & value) { this->grain_rate2 = value; }

        const RntLaIv & get_grain_step() const { return grain_step; }
        RntLaIv & get_mutable_grain_step() { return grain_step; }
        void set_grain_step(const RntLaIv & value) { this->grain_step = value; }

        const RntLaIv & get_grain_step_day() const { return grain_step_day; }
        RntLaIv & get_mutable_grain_step_day() { return grain_step_day; }
        void set_grain_step_day(const RntLaIv & value) { this->grain_step_day = value; }

        const RntLaIv & get_grain_step_temp() const { return grain_step_temp; }
        RntLaIv & get_mutable_grain_step_temp() { return grain_step_temp; }
        void set_grain_step_temp(const RntLaIv & value) { this->grain_step_temp = value; }

        const RntLaIv & get_grain_th_day() const { return grain_th_day; }
        RntLaIv & get_mutable_grain_th_day() { return grain_th_day; }
        void set_grain_th_day(const RntLaIv & value) { this->grain_th_day = value; }

        const RntLaIv & get_grain_th_temp() const { return grain_th_temp; }
        RntLaIv & get_mutable_grain_th_temp() { return grain_th_temp; }
        void set_grain_th_temp(const RntLaIv & value) { this->grain_th_temp = value; }

        const RntLaIv & get_grain_tsum1() const { return grain_tsum1; }
        RntLaIv & get_mutable_grain_tsum1() { return grain_tsum1; }
        void set_grain_tsum1(const RntLaIv & value) { this->grain_tsum1 = value; }

        const RntLaIv & get_grain_tsum2() const { return grain_tsum2; }
        RntLaIv & get_mutable_grain_tsum2() { return grain_tsum2; }
        void set_grain_tsum2(const RntLaIv & value) { this->grain_tsum2 = value; }

        const RntLaIv & get_growth_coef() const { return growth_coef; }
        RntLaIv & get_mutable_growth_coef() { return growth_coef; }
        void set_growth_coef(const RntLaIv & value) { this->growth_coef = value; }

        const RntLaIv & get_gsi_post_harvest() const { return gsi_post_harvest; }
        RntLaIv & get_mutable_gsi_post_harvest() { return gsi_post_harvest; }
        void set_gsi_post_harvest(const RntLaIv & value) { this->gsi_post_harvest = value; }

        const KonzelmannCoef & get_harvest_day_no() const { return harvest_day_no; }
        KonzelmannCoef & get_mutable_harvest_day_no() { return harvest_day_no; }
        void set_harvest_day_no(const KonzelmannCoef & value) { this->harvest_day_no = value; }

        const RntLaIv & get_harvest_dayno() const { return harvest_dayno; }
        RntLaIv & get_mutable_harvest_dayno() { return harvest_dayno; }
        void set_harvest_dayno(const RntLaIv & value) { this->harvest_dayno = value; }

        const RntLaIv & get_harvest_days() const { return harvest_days; }
        RntLaIv & get_mutable_harvest_days() { return harvest_days; }
        void set_harvest_days(const RntLaIv & value) { this->harvest_days = value; }

        const RntLaIv & get_harvest_lai() const { return harvest_lai; }
        RntLaIv & get_mutable_harvest_lai() { return harvest_lai; }
        void set_harvest_lai(const RntLaIv & value) { this->harvest_lai = value; }

        const KonzelmannCoef & get_harvest_years() const { return harvest_years; }
        KonzelmannCoef & get_mutable_harvest_years() { return harvest_years; }
        void set_harvest_years(const KonzelmannCoef & value) { this->harvest_years = value; }

        const RntLaIv & get_ic_coarse_root() const { return ic_coarse_root; }
        RntLaIv & get_mutable_ic_coarse_root() { return ic_coarse_root; }
        void set_ic_coarse_root(const RntLaIv & value) { this->ic_coarse_root = value; }

        const RntLaIv & get_ic_grain() const { return ic_grain; }
        RntLaIv & get_mutable_ic_grain() { return ic_grain; }
        void set_ic_grain(const RntLaIv & value) { this->ic_grain = value; }

        const RntLaIv & get_ic_leaf() const { return ic_leaf; }
        RntLaIv & get_mutable_ic_leaf() { return ic_leaf; }
        void set_ic_leaf(const RntLaIv & value) { this->ic_leaf = value; }

        const RntLaIv & get_icn_coarse_root() const { return icn_coarse_root; }
        RntLaIv & get_mutable_icn_coarse_root() { return icn_coarse_root; }
        void set_icn_coarse_root(const RntLaIv & value) { this->icn_coarse_root = value; }

        const RntLaIv & get_icn_grain() const { return icn_grain; }
        RntLaIv & get_mutable_icn_grain() { return icn_grain; }
        void set_icn_grain(const RntLaIv & value) { this->icn_grain = value; }

        const RntLaIv & get_icn_leaf() const { return icn_leaf; }
        RntLaIv & get_mutable_icn_leaf() { return icn_leaf; }
        void set_icn_leaf(const RntLaIv & value) { this->icn_leaf = value; }

        const RntLaIv & get_icn_old_coarse_root() const { return icn_old_coarse_root; }
        RntLaIv & get_mutable_icn_old_coarse_root() { return icn_old_coarse_root; }
        void set_icn_old_coarse_root(const RntLaIv & value) { this->icn_old_coarse_root = value; }

        const RntLaIv & get_icn_old_leaf() const { return icn_old_leaf; }
        RntLaIv & get_mutable_icn_old_leaf() { return icn_old_leaf; }
        void set_icn_old_leaf(const RntLaIv & value) { this->icn_old_leaf = value; }

        const RntLaIv & get_icn_old_root() const { return icn_old_root; }
        RntLaIv & get_mutable_icn_old_root() { return icn_old_root; }
        void set_icn_old_root(const RntLaIv & value) { this->icn_old_root = value; }

        const RntLaIv & get_icn_old_stem() const { return icn_old_stem; }
        RntLaIv & get_mutable_icn_old_stem() { return icn_old_stem; }
        void set_icn_old_stem(const RntLaIv & value) { this->icn_old_stem = value; }

        const RntLaIv & get_icn_root() const { return icn_root; }
        RntLaIv & get_mutable_icn_root() { return icn_root; }
        void set_icn_root(const RntLaIv & value) { this->icn_root = value; }

        const RntLaIv & get_icn_stem() const { return icn_stem; }
        RntLaIv & get_mutable_icn_stem() { return icn_stem; }
        void set_icn_stem(const RntLaIv & value) { this->icn_stem = value; }

        const RntLaIv & get_ic_old_coarse_root() const { return ic_old_coarse_root; }
        RntLaIv & get_mutable_ic_old_coarse_root() { return ic_old_coarse_root; }
        void set_ic_old_coarse_root(const RntLaIv & value) { this->ic_old_coarse_root = value; }

        const RntLaIv & get_ic_old_leaf() const { return ic_old_leaf; }
        RntLaIv & get_mutable_ic_old_leaf() { return ic_old_leaf; }
        void set_ic_old_leaf(const RntLaIv & value) { this->ic_old_leaf = value; }

        const RntLaIv & get_ic_old_root() const { return ic_old_root; }
        RntLaIv & get_mutable_ic_old_root() { return ic_old_root; }
        void set_ic_old_root(const RntLaIv & value) { this->ic_old_root = value; }

        const RntLaIv & get_ic_old_stem() const { return ic_old_stem; }
        RntLaIv & get_mutable_ic_old_stem() { return ic_old_stem; }
        void set_ic_old_stem(const RntLaIv & value) { this->ic_old_stem = value; }

        const RntLaIv & get_icp_coarse_root() const { return icp_coarse_root; }
        RntLaIv & get_mutable_icp_coarse_root() { return icp_coarse_root; }
        void set_icp_coarse_root(const RntLaIv & value) { this->icp_coarse_root = value; }

        const RntLaIv & get_icp_grain() const { return icp_grain; }
        RntLaIv & get_mutable_icp_grain() { return icp_grain; }
        void set_icp_grain(const RntLaIv & value) { this->icp_grain = value; }

        const RntLaIv & get_icp_leaf() const { return icp_leaf; }
        RntLaIv & get_mutable_icp_leaf() { return icp_leaf; }
        void set_icp_leaf(const RntLaIv & value) { this->icp_leaf = value; }

        const RntLaIv & get_icp_old_coarse_root() const { return icp_old_coarse_root; }
        RntLaIv & get_mutable_icp_old_coarse_root() { return icp_old_coarse_root; }
        void set_icp_old_coarse_root(const RntLaIv & value) { this->icp_old_coarse_root = value; }

        const RntLaIv & get_icp_old_leaf() const { return icp_old_leaf; }
        RntLaIv & get_mutable_icp_old_leaf() { return icp_old_leaf; }
        void set_icp_old_leaf(const RntLaIv & value) { this->icp_old_leaf = value; }

        const RntLaIv & get_icp_old_root() const { return icp_old_root; }
        RntLaIv & get_mutable_icp_old_root() { return icp_old_root; }
        void set_icp_old_root(const RntLaIv & value) { this->icp_old_root = value; }

        const RntLaIv & get_icp_old_stem() const { return icp_old_stem; }
        RntLaIv & get_mutable_icp_old_stem() { return icp_old_stem; }
        void set_icp_old_stem(const RntLaIv & value) { this->icp_old_stem = value; }

        const RntLaIv & get_icp_root() const { return icp_root; }
        RntLaIv & get_mutable_icp_root() { return icp_root; }
        void set_icp_root(const RntLaIv & value) { this->icp_root = value; }

        const RntLaIv & get_icp_stem() const { return icp_stem; }
        RntLaIv & get_mutable_icp_stem() { return icp_stem; }
        void set_icp_stem(const RntLaIv & value) { this->icp_stem = value; }

        const RntLaIv & get_ic_root() const { return ic_root; }
        RntLaIv & get_mutable_ic_root() { return ic_root; }
        void set_ic_root(const RntLaIv & value) { this->ic_root = value; }

        const RntLaIv & get_ic_stem() const { return ic_stem; }
        RntLaIv & get_mutable_ic_stem() { return ic_stem; }
        void set_ic_stem(const RntLaIv & value) { this->ic_stem = value; }

        const RntLaIv & get_in_coarse_root() const { return in_coarse_root; }
        RntLaIv & get_mutable_in_coarse_root() { return in_coarse_root; }
        void set_in_coarse_root(const RntLaIv & value) { this->in_coarse_root = value; }

        const RntLaIv & get_in_grain() const { return in_grain; }
        RntLaIv & get_mutable_in_grain() { return in_grain; }
        void set_in_grain(const RntLaIv & value) { this->in_grain = value; }

        const RntLaIv & get_initial_gsi() const { return initial_gsi; }
        RntLaIv & get_mutable_initial_gsi() { return initial_gsi; }
        void set_initial_gsi(const RntLaIv & value) { this->initial_gsi = value; }

        const RntLaIv & get_initial_tsum() const { return initial_tsum; }
        RntLaIv & get_mutable_initial_tsum() { return initial_tsum; }
        void set_initial_tsum(const RntLaIv & value) { this->initial_tsum = value; }

        const RntLaIv & get_in_leaf() const { return in_leaf; }
        RntLaIv & get_mutable_in_leaf() { return in_leaf; }
        void set_in_leaf(const RntLaIv & value) { this->in_leaf = value; }

        const RntLaIv & get_in_old_coarse_root() const { return in_old_coarse_root; }
        RntLaIv & get_mutable_in_old_coarse_root() { return in_old_coarse_root; }
        void set_in_old_coarse_root(const RntLaIv & value) { this->in_old_coarse_root = value; }

        const RntLaIv & get_in_old_leaf() const { return in_old_leaf; }
        RntLaIv & get_mutable_in_old_leaf() { return in_old_leaf; }
        void set_in_old_leaf(const RntLaIv & value) { this->in_old_leaf = value; }

        const RntLaIv & get_in_old_root() const { return in_old_root; }
        RntLaIv & get_mutable_in_old_root() { return in_old_root; }
        void set_in_old_root(const RntLaIv & value) { this->in_old_root = value; }

        const RntLaIv & get_in_old_stem() const { return in_old_stem; }
        RntLaIv & get_mutable_in_old_stem() { return in_old_stem; }
        void set_in_old_stem(const RntLaIv & value) { this->in_old_stem = value; }

        const RntLaIv & get_in_root() const { return in_root; }
        RntLaIv & get_mutable_in_root() { return in_root; }
        void set_in_root(const RntLaIv & value) { this->in_root = value; }

        const RntLaIv & get_in_stem() const { return in_stem; }
        RntLaIv & get_mutable_in_stem() { return in_stem; }
        void set_in_stem(const RntLaIv & value) { this->in_stem = value; }

        const RntLaIv & get_ip_coarse_root() const { return ip_coarse_root; }
        RntLaIv & get_mutable_ip_coarse_root() { return ip_coarse_root; }
        void set_ip_coarse_root(const RntLaIv & value) { this->ip_coarse_root = value; }

        const RntLaIv & get_ip_grain() const { return ip_grain; }
        RntLaIv & get_mutable_ip_grain() { return ip_grain; }
        void set_ip_grain(const RntLaIv & value) { this->ip_grain = value; }

        const RntLaIv & get_i_plant_age() const { return i_plant_age; }
        RntLaIv & get_mutable_i_plant_age() { return i_plant_age; }
        void set_i_plant_age(const RntLaIv & value) { this->i_plant_age = value; }

        const RntLaIv & get_ip_leaf() const { return ip_leaf; }
        RntLaIv & get_mutable_ip_leaf() { return ip_leaf; }
        void set_ip_leaf(const RntLaIv & value) { this->ip_leaf = value; }

        const RntLaIv & get_ip_old_coarse_root() const { return ip_old_coarse_root; }
        RntLaIv & get_mutable_ip_old_coarse_root() { return ip_old_coarse_root; }
        void set_ip_old_coarse_root(const RntLaIv & value) { this->ip_old_coarse_root = value; }

        const RntLaIv & get_ip_old_leaf() const { return ip_old_leaf; }
        RntLaIv & get_mutable_ip_old_leaf() { return ip_old_leaf; }
        void set_ip_old_leaf(const RntLaIv & value) { this->ip_old_leaf = value; }

        const RntLaIv & get_ip_old_root() const { return ip_old_root; }
        RntLaIv & get_mutable_ip_old_root() { return ip_old_root; }
        void set_ip_old_root(const RntLaIv & value) { this->ip_old_root = value; }

        const RntLaIv & get_ip_old_stem() const { return ip_old_stem; }
        RntLaIv & get_mutable_ip_old_stem() { return ip_old_stem; }
        void set_ip_old_stem(const RntLaIv & value) { this->ip_old_stem = value; }

        const RntLaIv & get_ip_root() const { return ip_root; }
        RntLaIv & get_mutable_ip_root() { return ip_root; }
        void set_ip_root(const RntLaIv & value) { this->ip_root = value; }

        const RntLaIv & get_ip_stem() const { return ip_stem; }
        RntLaIv & get_mutable_ip_stem() { return ip_stem; }
        void set_ip_stem(const RntLaIv & value) { this->ip_stem = value; }

        const RntLaIv & get_lai_enh_coef() const { return lai_enh_coef; }
        RntLaIv & get_mutable_lai_enh_coef() { return lai_enh_coef; }
        void set_lai_enh_coef(const RntLaIv & value) { this->lai_enh_coef = value; }

        const RntLaIv & get_leaf_lf2() const { return leaf_lf2; }
        RntLaIv & get_mutable_leaf_lf2() { return leaf_lf2; }
        void set_leaf_lf2(const RntLaIv & value) { this->leaf_lf2 = value; }

        const RntLaIv & get_leafc1() const { return leafc1; }
        RntLaIv & get_mutable_leafc1() { return leafc1; }
        void set_leafc1(const RntLaIv & value) { this->leafc1 = value; }

        const RntLaIv & get_leafc2() const { return leafc2; }
        RntLaIv & get_mutable_leafc2() { return leafc2; }
        void set_leafc2(const RntLaIv & value) { this->leafc2 = value; }

        const RntLaIv & get_leafc3() const { return leafc3; }
        RntLaIv & get_mutable_leafc3() { return leafc3; }
        void set_leafc3(const RntLaIv & value) { this->leafc3 = value; }

        const RntLaIv & get_leaf_rate1() const { return leaf_rate1; }
        RntLaIv & get_mutable_leaf_rate1() { return leaf_rate1; }
        void set_leaf_rate1(const RntLaIv & value) { this->leaf_rate1 = value; }

        const RntLaIv & get_leaf_rate2() const { return leaf_rate2; }
        RntLaIv & get_mutable_leaf_rate2() { return leaf_rate2; }
        void set_leaf_rate2(const RntLaIv & value) { this->leaf_rate2 = value; }

        const RntLaIv & get_leaf_tsum1() const { return leaf_tsum1; }
        RntLaIv & get_mutable_leaf_tsum1() { return leaf_tsum1; }
        void set_leaf_tsum1(const RntLaIv & value) { this->leaf_tsum1 = value; }

        const RntLaIv & get_leaf_tsum2() const { return leaf_tsum2; }
        RntLaIv & get_mutable_leaf_tsum2() { return leaf_tsum2; }
        void set_leaf_tsum2(const RntLaIv & value) { this->leaf_tsum2 = value; }

        const RntLaIv & get_mature_tsum() const { return mature_tsum; }
        RntLaIv & get_mutable_mature_tsum() { return mature_tsum; }
        void set_mature_tsum(const RntLaIv & value) { this->mature_tsum = value; }

        const RntLaIv & get_mature_tth() const { return mature_tth; }
        RntLaIv & get_mutable_mature_tth() { return mature_tth; }
        void set_mature_tth(const RntLaIv & value) { this->mature_tth = value; }

        const RntLaIv & get_max_gsi() const { return max_gsi; }
        RntLaIv & get_mutable_max_gsi() { return max_gsi; }
        void set_max_gsi(const RntLaIv & value) { this->max_gsi = value; }

        const RntLaIv & get_max_leaf_lifetime() const { return max_leaf_lifetime; }
        RntLaIv & get_mutable_max_leaf_lifetime() { return max_leaf_lifetime; }
        void set_max_leaf_lifetime(const RntLaIv & value) { this->max_leaf_lifetime = value; }

        const RntLaIv & get_max_plant_lifetime() const { return max_plant_lifetime; }
        RntLaIv & get_mutable_max_plant_lifetime() { return max_plant_lifetime; }
        void set_max_plant_lifetime(const RntLaIv & value) { this->max_plant_lifetime = value; }

        const RntLaIv & get_m_coef_coarse_root() const { return m_coef_coarse_root; }
        RntLaIv & get_mutable_m_coef_coarse_root() { return m_coef_coarse_root; }
        void set_m_coef_coarse_root(const RntLaIv & value) { this->m_coef_coarse_root = value; }

        const RntLaIv & get_m_coef_grain() const { return m_coef_grain; }
        RntLaIv & get_mutable_m_coef_grain() { return m_coef_grain; }
        void set_m_coef_grain(const RntLaIv & value) { this->m_coef_grain = value; }

        const RntLaIv & get_m_coef_leaf() const { return m_coef_leaf; }
        RntLaIv & get_mutable_m_coef_leaf() { return m_coef_leaf; }
        void set_m_coef_leaf(const RntLaIv & value) { this->m_coef_leaf = value; }

        const RntLaIv & get_m_coef_root() const { return m_coef_root; }
        RntLaIv & get_mutable_m_coef_root() { return m_coef_root; }
        void set_m_coef_root(const RntLaIv & value) { this->m_coef_root = value; }

        const RntLaIv & get_m_coef_stem() const { return m_coef_stem; }
        RntLaIv & get_mutable_m_coef_stem() { return m_coef_stem; }
        void set_m_coef_stem(const RntLaIv & value) { this->m_coef_stem = value; }

        const RntLaIv & get_min_frac_green_response() const { return min_frac_green_response; }
        RntLaIv & get_mutable_min_frac_green_response() { return min_frac_green_response; }
        void set_min_frac_green_response(const RntLaIv & value) { this->min_frac_green_response = value; }

        const RntLaIv & get_min_gsi() const { return min_gsi; }
        RntLaIv & get_mutable_min_gsi() { return min_gsi; }
        void set_min_gsi(const RntLaIv & value) { this->min_gsi = value; }

        const RntLaIv & get_minimum_response() const { return minimum_response; }
        RntLaIv & get_mutable_minimum_response() { return minimum_response; }
        void set_minimum_response(const RntLaIv & value) { this->minimum_response = value; }

        const RntLaIv & get_mobile_allo_coef() const { return mobile_allo_coef; }
        RntLaIv & get_mutable_mobile_allo_coef() { return mobile_allo_coef; }
        void set_mobile_allo_coef(const RntLaIv & value) { this->mobile_allo_coef = value; }

        const RntLaIv & get_mulch() const { return mulch; }
        RntLaIv & get_mutable_mulch() { return mulch; }
        void set_mulch(const RntLaIv & value) { this->mulch = value; }

        const RntLaIv & get_mycelia_frac() const { return mycelia_frac; }
        RntLaIv & get_mutable_mycelia_frac() { return mycelia_frac; }
        void set_mycelia_frac(const RntLaIv & value) { this->mycelia_frac = value; }

        const RntLaIv & get_myco_degree_fungi_coef() const { return myco_degree_fungi_coef; }
        RntLaIv & get_mutable_myco_degree_fungi_coef() { return myco_degree_fungi_coef; }
        void set_myco_degree_fungi_coef(const RntLaIv & value) { this->myco_degree_fungi_coef = value; }

        const RntLaIv & get_navail_coef() const { return navail_coef; }
        RntLaIv & get_mutable_navail_coef() { return navail_coef; }
        void set_navail_coef(const RntLaIv & value) { this->navail_coef = value; }

        const RntLaIv & get_new_coarse_roots() const { return new_coarse_roots; }
        RntLaIv & get_mutable_new_coarse_roots() { return new_coarse_roots; }
        void set_new_coarse_roots(const RntLaIv & value) { this->new_coarse_roots = value; }

        const RntLaIv & get_new_leaf() const { return new_leaf; }
        RntLaIv & get_mutable_new_leaf() { return new_leaf; }
        void set_new_leaf(const RntLaIv & value) { this->new_leaf = value; }

        const RntLaIv & get_new_roots() const { return new_roots; }
        RntLaIv & get_mutable_new_roots() { return new_roots; }
        void set_new_roots(const RntLaIv & value) { this->new_roots = value; }

        const RntLaIv & get_new_stem() const { return new_stem; }
        RntLaIv & get_mutable_new_stem() { return new_stem; }
        void set_new_stem(const RntLaIv & value) { this->new_stem = value; }

        const RntLaIv & get_n_fix_coef() const { return n_fix_coef; }
        RntLaIv & get_mutable_n_fix_coef() { return n_fix_coef; }
        void set_n_fix_coef(const RntLaIv & value) { this->n_fix_coef = value; }

        const RntLaIv & get_nh4_coef() const { return nh4_coef; }
        RntLaIv & get_mutable_nh4_coef() { return nh4_coef; }
        void set_nh4_coef(const RntLaIv & value) { this->nh4_coef = value; }

        const RntLaIv & get_n_leafto_grain() const { return n_leafto_grain; }
        RntLaIv & get_mutable_n_leafto_grain() { return n_leafto_grain; }
        void set_n_leafto_grain(const RntLaIv & value) { this->n_leafto_grain = value; }

        const RntLaIv & get_no3_coef() const { return no3_coef; }
        RntLaIv & get_mutable_no3_coef() { return no3_coef; }
        void set_no3_coef(const RntLaIv & value) { this->no3_coef = value; }

        const RntLaIv & get_n_org_coef() const { return n_org_coef; }
        RntLaIv & get_mutable_n_org_coef() { return n_org_coef; }
        void set_n_org_coef(const RntLaIv & value) { this->n_org_coef = value; }

        const RntLaIv & get_nretention_fungi() const { return nretention_fungi; }
        RntLaIv & get_mutable_nretention_fungi() { return nretention_fungi; }
        void set_nretention_fungi(const RntLaIv & value) { this->nretention_fungi = value; }

        const RntLaIv & get_n_rootsto_grain() const { return n_rootsto_grain; }
        RntLaIv & get_mutable_n_rootsto_grain() { return n_rootsto_grain; }
        void set_n_rootsto_grain(const RntLaIv & value) { this->n_rootsto_grain = value; }

        const RntLaIv & get_n_stemto_grain() const { return n_stemto_grain; }
        RntLaIv & get_mutable_n_stemto_grain() { return n_stemto_grain; }
        void set_n_stemto_grain(const RntLaIv & value) { this->n_stemto_grain = value; }

        const RntLaIv & get_old_coarse_roots() const { return old_coarse_roots; }
        RntLaIv & get_mutable_old_coarse_roots() { return old_coarse_roots; }
        void set_old_coarse_roots(const RntLaIv & value) { this->old_coarse_roots = value; }

        const RntLaIv & get_old_leaf() const { return old_leaf; }
        RntLaIv & get_mutable_old_leaf() { return old_leaf; }
        void set_old_leaf(const RntLaIv & value) { this->old_leaf = value; }

        const RntLaIv & get_old_roots() const { return old_roots; }
        RntLaIv & get_mutable_old_roots() { return old_roots; }
        void set_old_roots(const RntLaIv & value) { this->old_roots = value; }

        const RntLaIv & get_old_stem() const { return old_stem; }
        RntLaIv & get_mutable_old_stem() { return old_stem; }
        void set_old_stem(const RntLaIv & value) { this->old_stem = value; }

        const RntLaIv & get_opt_green_index() const { return opt_green_index; }
        RntLaIv & get_mutable_opt_green_index() { return opt_green_index; }
        void set_opt_green_index(const RntLaIv & value) { this->opt_green_index = value; }

        const RntLaIv & get_pavail_coef() const { return pavail_coef; }
        RntLaIv & get_mutable_pavail_coef() { return pavail_coef; }
        void set_pavail_coef(const RntLaIv & value) { this->pavail_coef = value; }

        const RntLaIv & get_p_f_harvest_c_roots() const { return p_f_harvest_c_roots; }
        RntLaIv & get_mutable_p_f_harvest_c_roots() { return p_f_harvest_c_roots; }
        void set_p_f_harvest_c_roots(const RntLaIv & value) { this->p_f_harvest_c_roots = value; }

        const RntLaIv & get_p_f_harvest_grain() const { return p_f_harvest_grain; }
        RntLaIv & get_mutable_p_f_harvest_grain() { return p_f_harvest_grain; }
        void set_p_f_harvest_grain(const RntLaIv & value) { this->p_f_harvest_grain = value; }

        const RntLaIv & get_p_f_harvest_leaf() const { return p_f_harvest_leaf; }
        RntLaIv & get_mutable_p_f_harvest_leaf() { return p_f_harvest_leaf; }
        void set_p_f_harvest_leaf(const RntLaIv & value) { this->p_f_harvest_leaf = value; }

        const RntLaIv & get_p_f_harvest_roots() const { return p_f_harvest_roots; }
        RntLaIv & get_mutable_p_f_harvest_roots() { return p_f_harvest_roots; }
        void set_p_f_harvest_roots(const RntLaIv & value) { this->p_f_harvest_roots = value; }

        const RntLaIv & get_p_f_harvest_stem() const { return p_f_harvest_stem; }
        RntLaIv & get_mutable_p_f_harvest_stem() { return p_f_harvest_stem; }
        void set_p_f_harvest_stem(const RntLaIv & value) { this->p_f_harvest_stem = value; }

        const RntLaIv & get_p_f_litter_c_roots() const { return p_f_litter_c_roots; }
        RntLaIv & get_mutable_p_f_litter_c_roots() { return p_f_litter_c_roots; }
        void set_p_f_litter_c_roots(const RntLaIv & value) { this->p_f_litter_c_roots = value; }

        const RntLaIv & get_p_f_litter_grain() const { return p_f_litter_grain; }
        RntLaIv & get_mutable_p_f_litter_grain() { return p_f_litter_grain; }
        void set_p_f_litter_grain(const RntLaIv & value) { this->p_f_litter_grain = value; }

        const RntLaIv & get_p_f_litter_leaf() const { return p_f_litter_leaf; }
        RntLaIv & get_mutable_p_f_litter_leaf() { return p_f_litter_leaf; }
        void set_p_f_litter_leaf(const RntLaIv & value) { this->p_f_litter_leaf = value; }

        const RntLaIv & get_p_f_litter_roots() const { return p_f_litter_roots; }
        RntLaIv & get_mutable_p_f_litter_roots() { return p_f_litter_roots; }
        void set_p_f_litter_roots(const RntLaIv & value) { this->p_f_litter_roots = value; }

        const RntLaIv & get_p_f_litter_stem() const { return p_f_litter_stem; }
        RntLaIv & get_mutable_p_f_litter_stem() { return p_f_litter_stem; }
        void set_p_f_litter_stem(const RntLaIv & value) { this->p_f_litter_stem = value; }

        const KonzelmannCoef & get_plant_cleaning_index() const { return plant_cleaning_index; }
        KonzelmannCoef & get_mutable_plant_cleaning_index() { return plant_cleaning_index; }
        void set_plant_cleaning_index(const KonzelmannCoef & value) { this->plant_cleaning_index = value; }

        const KonzelmannCoef & get_plant_day_index() const { return plant_day_index; }
        KonzelmannCoef & get_mutable_plant_day_index() { return plant_day_index; }
        void set_plant_day_index(const KonzelmannCoef & value) { this->plant_day_index = value; }

        const KonzelmannCoef & get_plant_year_index() const { return plant_year_index; }
        KonzelmannCoef & get_mutable_plant_year_index() { return plant_year_index; }
        void set_plant_year_index(const KonzelmannCoef & value) { this->plant_year_index = value; }

        const RntLaIv & get_p_leafto_grain() const { return p_leafto_grain; }
        RntLaIv & get_mutable_p_leafto_grain() { return p_leafto_grain; }
        void set_p_leafto_grain(const RntLaIv & value) { this->p_leafto_grain = value; }

        const RntLaIv & get_pmax() const { return pmax; }
        RntLaIv & get_mutable_pmax() { return pmax; }
        void set_pmax(const RntLaIv & value) { this->pmax = value; }

        const RntLaIv & get_position4_target() const { return position4_target; }
        RntLaIv & get_mutable_position4_target() { return position4_target; }
        void set_position4_target(const RntLaIv & value) { this->position4_target = value; }

        const RntLaIv & get_pretention_fungi() const { return pretention_fungi; }
        RntLaIv & get_mutable_pretention_fungi() { return pretention_fungi; }
        void set_pretention_fungi(const RntLaIv & value) { this->pretention_fungi = value; }

        const RntLaIv & get_p_rootsto_grain() const { return p_rootsto_grain; }
        RntLaIv & get_mutable_p_rootsto_grain() { return p_rootsto_grain; }
        void set_p_rootsto_grain(const RntLaIv & value) { this->p_rootsto_grain = value; }

        const RntLaIv & get_p_stemto_grain() const { return p_stemto_grain; }
        RntLaIv & get_mutable_p_stemto_grain() { return p_stemto_grain; }
        void set_p_stemto_grain(const RntLaIv & value) { this->p_stemto_grain = value; }

        const RntLaIv & get_quan_eff() const { return quan_eff; }
        RntLaIv & get_mutable_quan_eff() { return quan_eff; }
        void set_quan_eff(const RntLaIv & value) { this->quan_eff = value; }

        const RntLaIv & get_rad_efficiency() const { return rad_efficiency; }
        RntLaIv & get_mutable_rad_efficiency() { return rad_efficiency; }
        void set_rad_efficiency(const RntLaIv & value) { this->rad_efficiency = value; }

        const RntLaIv & get_rad_eff_red() const { return rad_eff_red; }
        RntLaIv & get_mutable_rad_eff_red() { return rad_eff_red; }
        void set_rad_eff_red(const RntLaIv & value) { this->rad_eff_red = value; }

        const RntLaIv & get_rate_coef_f_root() const { return rate_coef_f_root; }
        RntLaIv & get_mutable_rate_coef_f_root() { return rate_coef_f_root; }
        void set_rate_coef_f_root(const RntLaIv & value) { this->rate_coef_f_root = value; }

        const RntLaIv & get_r_boundary() const { return r_boundary; }
        RntLaIv & get_mutable_r_boundary() { return r_boundary; }
        void set_r_boundary(const RntLaIv & value) { this->r_boundary = value; }

        const RntLaIv & get_rel_w_water() const { return rel_w_water; }
        RntLaIv & get_mutable_rel_w_water() { return rel_w_water; }
        void set_rel_w_water(const RntLaIv & value) { this->rel_w_water = value; }

        const RntLaIv & get_resp_coef_fungi() const { return resp_coef_fungi; }
        RntLaIv & get_mutable_resp_coef_fungi() { return resp_coef_fungi; }
        void set_resp_coef_fungi(const RntLaIv & value) { this->resp_coef_fungi = value; }

        const RntLaIv & get_ripening_tsum() const { return ripening_tsum; }
        RntLaIv & get_mutable_ripening_tsum() { return ripening_tsum; }
        void set_ripening_tsum(const RntLaIv & value) { this->ripening_tsum = value; }

        const RntLaIv & get_ripening_tth() const { return ripening_tth; }
        RntLaIv & get_mutable_ripening_tth() { return ripening_tth; }
        void set_ripening_tth(const RntLaIv & value) { this->ripening_tth = value; }

        const RntLaIv & get_root_lf2() const { return root_lf2; }
        RntLaIv & get_mutable_root_lf2() { return root_lf2; }
        void set_root_lf2(const RntLaIv & value) { this->root_lf2 = value; }

        const RntLaIv & get_root_c_nc1() const { return root_c_nc1; }
        RntLaIv & get_mutable_root_c_nc1() { return root_c_nc1; }
        void set_root_c_nc1(const RntLaIv & value) { this->root_c_nc1 = value; }

        const RntLaIv & get_root_c_nc2() const { return root_c_nc2; }
        RntLaIv & get_mutable_root_c_nc2() { return root_c_nc2; }
        void set_root_c_nc2(const RntLaIv & value) { this->root_c_nc2 = value; }

        const RntLaIv & get_root_c_nc3() const { return root_c_nc3; }
        RntLaIv & get_mutable_root_c_nc3() { return root_c_nc3; }
        void set_root_c_nc3(const RntLaIv & value) { this->root_c_nc3 = value; }

        const RntLaIv & get_root_c_pc1() const { return root_c_pc1; }
        RntLaIv & get_mutable_root_c_pc1() { return root_c_pc1; }
        void set_root_c_pc1(const RntLaIv & value) { this->root_c_pc1 = value; }

        const RntLaIv & get_root_c_pc2() const { return root_c_pc2; }
        RntLaIv & get_mutable_root_c_pc2() { return root_c_pc2; }
        void set_root_c_pc2(const RntLaIv & value) { this->root_c_pc2 = value; }

        const RntLaIv & get_root_c_pc3() const { return root_c_pc3; }
        RntLaIv & get_mutable_root_c_pc3() { return root_c_pc3; }
        void set_root_c_pc3(const RntLaIv & value) { this->root_c_pc3 = value; }

        const RntLaIv & get_root_leaf_ratio() const { return root_leaf_ratio; }
        RntLaIv & get_mutable_root_leaf_ratio() { return root_leaf_ratio; }
        void set_root_leaf_ratio(const RntLaIv & value) { this->root_leaf_ratio = value; }

        const RntLaIv & get_root_massc1() const { return root_massc1; }
        RntLaIv & get_mutable_root_massc1() { return root_massc1; }
        void set_root_massc1(const RntLaIv & value) { this->root_massc1 = value; }

        const RntLaIv & get_root_massc2() const { return root_massc2; }
        RntLaIv & get_mutable_root_massc2() { return root_massc2; }
        void set_root_massc2(const RntLaIv & value) { this->root_massc2 = value; }

        const RntLaIv & get_root_massc3() const { return root_massc3; }
        RntLaIv & get_mutable_root_massc3() { return root_massc3; }
        void set_root_massc3(const RntLaIv & value) { this->root_massc3 = value; }

        const RntLaIv & get_root_nodule_ratio() const { return root_nodule_ratio; }
        RntLaIv & get_mutable_root_nodule_ratio() { return root_nodule_ratio; }
        void set_root_nodule_ratio(const RntLaIv & value) { this->root_nodule_ratio = value; }

        const RntLaIv & get_root_rate1() const { return root_rate1; }
        RntLaIv & get_mutable_root_rate1() { return root_rate1; }
        void set_root_rate1(const RntLaIv & value) { this->root_rate1 = value; }

        const RntLaIv & get_root_rate2() const { return root_rate2; }
        RntLaIv & get_mutable_root_rate2() { return root_rate2; }
        void set_root_rate2(const RntLaIv & value) { this->root_rate2 = value; }

        const RntLaIv & get_root_tsum1() const { return root_tsum1; }
        RntLaIv & get_mutable_root_tsum1() { return root_tsum1; }
        void set_root_tsum1(const RntLaIv & value) { this->root_tsum1 = value; }

        const RntLaIv & get_root_tsum2() const { return root_tsum2; }
        RntLaIv & get_mutable_root_tsum2() { return root_tsum2; }
        void set_root_tsum2(const RntLaIv & value) { this->root_tsum2 = value; }

        const RntLaIv & get_root_waterc1() const { return root_waterc1; }
        RntLaIv & get_mutable_root_waterc1() { return root_waterc1; }
        void set_root_waterc1(const RntLaIv & value) { this->root_waterc1 = value; }

        const RntLaIv & get_root_waterc2() const { return root_waterc2; }
        RntLaIv & get_mutable_root_waterc2() { return root_waterc2; }
        void set_root_waterc2(const RntLaIv & value) { this->root_waterc2 = value; }

        const RntLaIv & get_root_waterc3() const { return root_waterc3; }
        RntLaIv & get_mutable_root_waterc3() { return root_waterc3; }
        void set_root_waterc3(const RntLaIv & value) { this->root_waterc3 = value; }

        const RntLaIv & get_shoot_coef() const { return shoot_coef; }
        RntLaIv & get_mutable_shoot_coef() { return shoot_coef; }
        void set_shoot_coef(const RntLaIv & value) { this->shoot_coef = value; }

        const RntLaIv & get_sowing_dayno() const { return sowing_dayno; }
        RntLaIv & get_mutable_sowing_dayno() { return sowing_dayno; }
        void set_sowing_dayno(const RntLaIv & value) { this->sowing_dayno = value; }

        const RntLaIv & get_sowing_days() const { return sowing_days; }
        RntLaIv & get_mutable_sowing_days() { return sowing_days; }
        void set_sowing_days(const RntLaIv & value) { this->sowing_days = value; }

        const RntLaIv & get_sow_tsum() const { return sow_tsum; }
        RntLaIv & get_mutable_sow_tsum() { return sow_tsum; }
        void set_sow_tsum(const RntLaIv & value) { this->sow_tsum = value; }

        const RntLaIv & get_sow_tth() const { return sow_tth; }
        RntLaIv & get_mutable_sow_tth() { return sow_tth; }
        void set_sow_tth(const RntLaIv & value) { this->sow_tth = value; }

        const RntLaIv & get_specific_max_fixation() const { return specific_max_fixation; }
        RntLaIv & get_mutable_specific_max_fixation() { return specific_max_fixation; }
        void set_specific_max_fixation(const RntLaIv & value) { this->specific_max_fixation = value; }

        const RntLaIv & get_specific_min_fixation() const { return specific_min_fixation; }
        RntLaIv & get_mutable_specific_min_fixation() { return specific_min_fixation; }
        void set_specific_min_fixation(const RntLaIv & value) { this->specific_min_fixation = value; }

        const RntLaIv & get_specific_nsensivity() const { return specific_nsensivity; }
        RntLaIv & get_mutable_specific_nsensivity() { return specific_nsensivity; }
        void set_specific_nsensivity(const RntLaIv & value) { this->specific_nsensivity = value; }

        const RntLaIv & get_start_years() const { return start_years; }
        RntLaIv & get_mutable_start_years() { return start_years; }
        void set_start_years(const RntLaIv & value) { this->start_years = value; }

        const RntLaIv & get_stem_lf2() const { return stem_lf2; }
        RntLaIv & get_mutable_stem_lf2() { return stem_lf2; }
        void set_stem_lf2(const RntLaIv & value) { this->stem_lf2 = value; }

        const RntLaIv & get_stem_leaf_nodule_ratio() const { return stem_leaf_nodule_ratio; }
        RntLaIv & get_mutable_stem_leaf_nodule_ratio() { return stem_leaf_nodule_ratio; }
        void set_stem_leaf_nodule_ratio(const RntLaIv & value) { this->stem_leaf_nodule_ratio = value; }

        const RntLaIv & get_stem_rate1() const { return stem_rate1; }
        RntLaIv & get_mutable_stem_rate1() { return stem_rate1; }
        void set_stem_rate1(const RntLaIv & value) { this->stem_rate1 = value; }

        const RntLaIv & get_stem_rate2() const { return stem_rate2; }
        RntLaIv & get_mutable_stem_rate2() { return stem_rate2; }
        void set_stem_rate2(const RntLaIv & value) { this->stem_rate2 = value; }

        const RntLaIv & get_stem_tsum1() const { return stem_tsum1; }
        RntLaIv & get_mutable_stem_tsum1() { return stem_tsum1; }
        void set_stem_tsum1(const RntLaIv & value) { this->stem_tsum1 = value; }

        const RntLaIv & get_stem_tsum2() const { return stem_tsum2; }
        RntLaIv & get_mutable_stem_tsum2() { return stem_tsum2; }
        void set_stem_tsum2(const RntLaIv & value) { this->stem_tsum2 = value; }

        const RntLaIv & get_stubble_leaf() const { return stubble_leaf; }
        RntLaIv & get_mutable_stubble_leaf() { return stubble_leaf; }
        void set_stubble_leaf(const RntLaIv & value) { this->stubble_leaf = value; }

        const RntLaIv & get_stubble_stem() const { return stubble_stem; }
        RntLaIv & get_mutable_stubble_stem() { return stubble_stem; }
        void set_stubble_stem(const RntLaIv & value) { this->stubble_stem = value; }

        const RntLaIv & get_tf_sum_start() const { return tf_sum_start; }
        RntLaIv & get_mutable_tf_sum_start() { return tf_sum_start; }
        void set_tf_sum_start(const RntLaIv & value) { this->tf_sum_start = value; }

        const RntLaIv & get_tl_max() const { return tl_max; }
        RntLaIv & get_mutable_tl_max() { return tl_max; }
        void set_tl_max(const RntLaIv & value) { this->tl_max = value; }

        const RntLaIv & get_tl_min() const { return tl_min; }
        RntLaIv & get_mutable_tl_min() { return tl_min; }
        void set_tl_min(const RntLaIv & value) { this->tl_min = value; }

        const RntLaIv & get_tl_opt1() const { return tl_opt1; }
        RntLaIv & get_mutable_tl_opt1() { return tl_opt1; }
        void set_tl_opt1(const RntLaIv & value) { this->tl_opt1 = value; }

        const RntLaIv & get_tl_opt2() const { return tl_opt2; }
        RntLaIv & get_mutable_tl_opt2() { return tl_opt2; }
        void set_tl_opt2(const RntLaIv & value) { this->tl_opt2 = value; }

        const RntLaIv & get_tr_current() const { return tr_current; }
        RntLaIv & get_mutable_tr_current() { return tr_current; }
        void set_tr_current(const RntLaIv & value) { this->tr_current = value; }

        const RntLaIv & get_t_sum_opt() const { return t_sum_opt; }
        RntLaIv & get_mutable_t_sum_opt() { return t_sum_opt; }
        void set_t_sum_opt(const RntLaIv & value) { this->t_sum_opt = value; }

        const RntLaIv & get_up_a_coef() const { return up_a_coef; }
        RntLaIv & get_mutable_up_a_coef() { return up_a_coef; }
        void set_up_a_coef(const RntLaIv & value) { this->up_a_coef = value; }

        const RntLaIv & get_up_b_coef() const { return up_b_coef; }
        RntLaIv & get_mutable_up_b_coef() { return up_b_coef; }
        void set_up_b_coef(const RntLaIv & value) { this->up_b_coef = value; }

        const RntLaIv & get_up_c_coef() const { return up_c_coef; }
        RntLaIv & get_mutable_up_c_coef() { return up_c_coef; }
        void set_up_c_coef(const RntLaIv & value) { this->up_c_coef = value; }

        const RntLaIv & get_up_cn_ratio() const { return up_cn_ratio; }
        RntLaIv & get_mutable_up_cn_ratio() { return up_cn_ratio; }
        void set_up_cn_ratio(const RntLaIv & value) { this->up_cn_ratio = value; }

        const RntLaIv & get_up_end() const { return up_end; }
        RntLaIv & get_mutable_up_end() { return up_end; }
        void set_up_end(const RntLaIv & value) { this->up_end = value; }

        const RntLaIv & get_up_start() const { return up_start; }
        RntLaIv & get_mutable_up_start() { return up_start; }
        void set_up_start(const RntLaIv & value) { this->up_start = value; }

        const RntLaIv & get_vcmax() const { return vcmax; }
        RntLaIv & get_mutable_vcmax() { return vcmax; }
        void set_vcmax(const RntLaIv & value) { this->vcmax = value; }

        const RntLaIv & get_water_efficiency() const { return water_efficiency; }
        RntLaIv & get_mutable_water_efficiency() { return water_efficiency; }
        void set_water_efficiency(const RntLaIv & value) { this->water_efficiency = value; }
    };

    class ParametersArraysNitrogenandCarbon {
        public:
        ParametersArraysNitrogenandCarbon() = default;
        virtual ~ParametersArraysNitrogenandCarbon() = default;

        private:
        std::map<std::string, RntLaIv> external_ninputs;
        TentacledExternalPInputs external_p_inputs;
        StickyPlantGrowth plant_growth;

        public:
        const std::map<std::string, RntLaIv> & get_external_ninputs() const { return external_ninputs; }
        std::map<std::string, RntLaIv> & get_mutable_external_ninputs() { return external_ninputs; }
        void set_external_ninputs(const std::map<std::string, RntLaIv> & value) { this->external_ninputs = value; }

        const TentacledExternalPInputs & get_external_p_inputs() const { return external_p_inputs; }
        TentacledExternalPInputs & get_mutable_external_p_inputs() { return external_p_inputs; }
        void set_external_p_inputs(const TentacledExternalPInputs & value) { this->external_p_inputs = value; }

        const StickyPlantGrowth & get_plant_growth() const { return plant_growth; }
        StickyPlantGrowth & get_mutable_plant_growth() { return plant_growth; }
        void set_plant_growth(const StickyPlantGrowth & value) { this->plant_growth = value; }
    };

    class IndigoGasprocesses {
        public:
        IndigoGasprocesses() = default;
        virtual ~IndigoGasprocesses() = default;

        private:
        InfilDistF init_co2_conc;
        InfilDistF init_oxygen_conc;
        InfilDistF p_hvalue;

        public:
        const InfilDistF & get_init_co2_conc() const { return init_co2_conc; }
        InfilDistF & get_mutable_init_co2_conc() { return init_co2_conc; }
        void set_init_co2_conc(const InfilDistF & value) { this->init_co2_conc = value; }

        const InfilDistF & get_init_oxygen_conc() const { return init_oxygen_conc; }
        InfilDistF & get_mutable_init_oxygen_conc() { return init_oxygen_conc; }
        void set_init_oxygen_conc(const InfilDistF & value) { this->init_oxygen_conc = value; }

        const InfilDistF & get_p_hvalue() const { return p_hvalue; }
        InfilDistF & get_mutable_p_hvalue() { return p_hvalue; }
        void set_p_hvalue(const InfilDistF & value) { this->p_hvalue = value; }
    };

    class SoilmineralNprocesses {
        public:
        SoilmineralNprocesses() = default;
        virtual ~SoilmineralNprocesses() = default;

        private:
        InfilDistF denit_dist_z;
        RntLaIv flex_degree;
        InfilDistF i_ammonium_conc;
        InfilDistF i_nitrate_conc;
        InfilDistF nh4_ads_frac;
        InfilDistF rel_scale_response;

        public:
        const InfilDistF & get_denit_dist_z() const { return denit_dist_z; }
        InfilDistF & get_mutable_denit_dist_z() { return denit_dist_z; }
        void set_denit_dist_z(const InfilDistF & value) { this->denit_dist_z = value; }

        const RntLaIv & get_flex_degree() const { return flex_degree; }
        RntLaIv & get_mutable_flex_degree() { return flex_degree; }
        void set_flex_degree(const RntLaIv & value) { this->flex_degree = value; }

        const InfilDistF & get_i_ammonium_conc() const { return i_ammonium_conc; }
        InfilDistF & get_mutable_i_ammonium_conc() { return i_ammonium_conc; }
        void set_i_ammonium_conc(const InfilDistF & value) { this->i_ammonium_conc = value; }

        const InfilDistF & get_i_nitrate_conc() const { return i_nitrate_conc; }
        InfilDistF & get_mutable_i_nitrate_conc() { return i_nitrate_conc; }
        void set_i_nitrate_conc(const InfilDistF & value) { this->i_nitrate_conc = value; }

        const InfilDistF & get_nh4_ads_frac() const { return nh4_ads_frac; }
        InfilDistF & get_mutable_nh4_ads_frac() { return nh4_ads_frac; }
        void set_nh4_ads_frac(const InfilDistF & value) { this->nh4_ads_frac = value; }

        const InfilDistF & get_rel_scale_response() const { return rel_scale_response; }
        InfilDistF & get_mutable_rel_scale_response() { return rel_scale_response; }
        void set_rel_scale_response(const InfilDistF & value) { this->rel_scale_response = value; }
    };

    class HilariousSoilmineralPProcesses {
        public:
        HilariousSoilmineralPProcesses() = default;
        virtual ~HilariousSoilmineralPProcesses() = default;

        private:
        InfilDistF i_labile_phosphate_conc;
        InfilDistF inital_pcontent;

        public:
        const InfilDistF & get_i_labile_phosphate_conc() const { return i_labile_phosphate_conc; }
        InfilDistF & get_mutable_i_labile_phosphate_conc() { return i_labile_phosphate_conc; }
        void set_i_labile_phosphate_conc(const InfilDistF & value) { this->i_labile_phosphate_conc = value; }

        const InfilDistF & get_inital_pcontent() const { return inital_pcontent; }
        InfilDistF & get_mutable_inital_pcontent() { return inital_pcontent; }
        void set_inital_pcontent(const InfilDistF & value) { this->inital_pcontent = value; }
    };

    class TentacledSoilorganicprocesses {
        public:
        TentacledSoilorganicprocesses() = default;
        virtual ~TentacledSoilorganicprocesses() = default;

        private:
        std::map<std::string, std::string> init_bulk_density;
        std::map<std::string, std::string> init_c_cont;
        std::map<std::string, std::string> init_cn_humus;
        std::map<std::string, std::string> init_cn_litter;
        InfilDistF init_fc;
        InfilDistF init_fcn;
        InfilDistF init_fcp;
        InfilDistF init_fn;
        InfilDistF init_fp;
        std::map<std::string, std::string> init_frac_litter2;
        InfilDistF init_hc;
        InfilDistF init_hcn;
        InfilDistF init_hcp;
        InfilDistF init_hn;
        InfilDistF init_hp;
        InfilDistF init_l1_c;
        InfilDistF init_l1_cn;
        InfilDistF init_l1_cp;
        InfilDistF init_l1_n;
        InfilDistF init_l1_p;
        InfilDistF init_l2_c;
        InfilDistF init_l2_cn;
        InfilDistF init_l2_cp;
        InfilDistF init_l2_n;
        InfilDistF init_l2_p;
        InfilDistF init_mc;
        InfilDistF init_mcn;
        InfilDistF init_mcp;
        InfilDistF init_mn;
        InfilDistF init_mp;
        std::map<std::string, std::string> init_n_cont;
        InfilDistF rate_coef_dissolved;

        public:
        const std::map<std::string, std::string> & get_init_bulk_density() const { return init_bulk_density; }
        std::map<std::string, std::string> & get_mutable_init_bulk_density() { return init_bulk_density; }
        void set_init_bulk_density(const std::map<std::string, std::string> & value) { this->init_bulk_density = value; }

        const std::map<std::string, std::string> & get_init_c_cont() const { return init_c_cont; }
        std::map<std::string, std::string> & get_mutable_init_c_cont() { return init_c_cont; }
        void set_init_c_cont(const std::map<std::string, std::string> & value) { this->init_c_cont = value; }

        const std::map<std::string, std::string> & get_init_cn_humus() const { return init_cn_humus; }
        std::map<std::string, std::string> & get_mutable_init_cn_humus() { return init_cn_humus; }
        void set_init_cn_humus(const std::map<std::string, std::string> & value) { this->init_cn_humus = value; }

        const std::map<std::string, std::string> & get_init_cn_litter() const { return init_cn_litter; }
        std::map<std::string, std::string> & get_mutable_init_cn_litter() { return init_cn_litter; }
        void set_init_cn_litter(const std::map<std::string, std::string> & value) { this->init_cn_litter = value; }

        const InfilDistF & get_init_fc() const { return init_fc; }
        InfilDistF & get_mutable_init_fc() { return init_fc; }
        void set_init_fc(const InfilDistF & value) { this->init_fc = value; }

        const InfilDistF & get_init_fcn() const { return init_fcn; }
        InfilDistF & get_mutable_init_fcn() { return init_fcn; }
        void set_init_fcn(const InfilDistF & value) { this->init_fcn = value; }

        const InfilDistF & get_init_fcp() const { return init_fcp; }
        InfilDistF & get_mutable_init_fcp() { return init_fcp; }
        void set_init_fcp(const InfilDistF & value) { this->init_fcp = value; }

        const InfilDistF & get_init_fn() const { return init_fn; }
        InfilDistF & get_mutable_init_fn() { return init_fn; }
        void set_init_fn(const InfilDistF & value) { this->init_fn = value; }

        const InfilDistF & get_init_fp() const { return init_fp; }
        InfilDistF & get_mutable_init_fp() { return init_fp; }
        void set_init_fp(const InfilDistF & value) { this->init_fp = value; }

        const std::map<std::string, std::string> & get_init_frac_litter2() const { return init_frac_litter2; }
        std::map<std::string, std::string> & get_mutable_init_frac_litter2() { return init_frac_litter2; }
        void set_init_frac_litter2(const std::map<std::string, std::string> & value) { this->init_frac_litter2 = value; }

        const InfilDistF & get_init_hc() const { return init_hc; }
        InfilDistF & get_mutable_init_hc() { return init_hc; }
        void set_init_hc(const InfilDistF & value) { this->init_hc = value; }

        const InfilDistF & get_init_hcn() const { return init_hcn; }
        InfilDistF & get_mutable_init_hcn() { return init_hcn; }
        void set_init_hcn(const InfilDistF & value) { this->init_hcn = value; }

        const InfilDistF & get_init_hcp() const { return init_hcp; }
        InfilDistF & get_mutable_init_hcp() { return init_hcp; }
        void set_init_hcp(const InfilDistF & value) { this->init_hcp = value; }

        const InfilDistF & get_init_hn() const { return init_hn; }
        InfilDistF & get_mutable_init_hn() { return init_hn; }
        void set_init_hn(const InfilDistF & value) { this->init_hn = value; }

        const InfilDistF & get_init_hp() const { return init_hp; }
        InfilDistF & get_mutable_init_hp() { return init_hp; }
        void set_init_hp(const InfilDistF & value) { this->init_hp = value; }

        const InfilDistF & get_init_l1_c() const { return init_l1_c; }
        InfilDistF & get_mutable_init_l1_c() { return init_l1_c; }
        void set_init_l1_c(const InfilDistF & value) { this->init_l1_c = value; }

        const InfilDistF & get_init_l1_cn() const { return init_l1_cn; }
        InfilDistF & get_mutable_init_l1_cn() { return init_l1_cn; }
        void set_init_l1_cn(const InfilDistF & value) { this->init_l1_cn = value; }

        const InfilDistF & get_init_l1_cp() const { return init_l1_cp; }
        InfilDistF & get_mutable_init_l1_cp() { return init_l1_cp; }
        void set_init_l1_cp(const InfilDistF & value) { this->init_l1_cp = value; }

        const InfilDistF & get_init_l1_n() const { return init_l1_n; }
        InfilDistF & get_mutable_init_l1_n() { return init_l1_n; }
        void set_init_l1_n(const InfilDistF & value) { this->init_l1_n = value; }

        const InfilDistF & get_init_l1_p() const { return init_l1_p; }
        InfilDistF & get_mutable_init_l1_p() { return init_l1_p; }
        void set_init_l1_p(const InfilDistF & value) { this->init_l1_p = value; }

        const InfilDistF & get_init_l2_c() const { return init_l2_c; }
        InfilDistF & get_mutable_init_l2_c() { return init_l2_c; }
        void set_init_l2_c(const InfilDistF & value) { this->init_l2_c = value; }

        const InfilDistF & get_init_l2_cn() const { return init_l2_cn; }
        InfilDistF & get_mutable_init_l2_cn() { return init_l2_cn; }
        void set_init_l2_cn(const InfilDistF & value) { this->init_l2_cn = value; }

        const InfilDistF & get_init_l2_cp() const { return init_l2_cp; }
        InfilDistF & get_mutable_init_l2_cp() { return init_l2_cp; }
        void set_init_l2_cp(const InfilDistF & value) { this->init_l2_cp = value; }

        const InfilDistF & get_init_l2_n() const { return init_l2_n; }
        InfilDistF & get_mutable_init_l2_n() { return init_l2_n; }
        void set_init_l2_n(const InfilDistF & value) { this->init_l2_n = value; }

        const InfilDistF & get_init_l2_p() const { return init_l2_p; }
        InfilDistF & get_mutable_init_l2_p() { return init_l2_p; }
        void set_init_l2_p(const InfilDistF & value) { this->init_l2_p = value; }

        const InfilDistF & get_init_mc() const { return init_mc; }
        InfilDistF & get_mutable_init_mc() { return init_mc; }
        void set_init_mc(const InfilDistF & value) { this->init_mc = value; }

        const InfilDistF & get_init_mcn() const { return init_mcn; }
        InfilDistF & get_mutable_init_mcn() { return init_mcn; }
        void set_init_mcn(const InfilDistF & value) { this->init_mcn = value; }

        const InfilDistF & get_init_mcp() const { return init_mcp; }
        InfilDistF & get_mutable_init_mcp() { return init_mcp; }
        void set_init_mcp(const InfilDistF & value) { this->init_mcp = value; }

        const InfilDistF & get_init_mn() const { return init_mn; }
        InfilDistF & get_mutable_init_mn() { return init_mn; }
        void set_init_mn(const InfilDistF & value) { this->init_mn = value; }

        const InfilDistF & get_init_mp() const { return init_mp; }
        InfilDistF & get_mutable_init_mp() { return init_mp; }
        void set_init_mp(const InfilDistF & value) { this->init_mp = value; }

        const std::map<std::string, std::string> & get_init_n_cont() const { return init_n_cont; }
        std::map<std::string, std::string> & get_mutable_init_n_cont() { return init_n_cont; }
        void set_init_n_cont(const std::map<std::string, std::string> & value) { this->init_n_cont = value; }

        const InfilDistF & get_rate_coef_dissolved() const { return rate_coef_dissolved; }
        InfilDistF & get_mutable_rate_coef_dissolved() { return rate_coef_dissolved; }
        void set_rate_coef_dissolved(const InfilDistF & value) { this->rate_coef_dissolved = value; }
    };

    class ParametersArraysNitrogenandCarbonBelowGround {
        public:
        ParametersArraysNitrogenandCarbonBelowGround() = default;
        virtual ~ParametersArraysNitrogenandCarbonBelowGround() = default;

        private:
        IndigoGasprocesses gasprocesses;
        SoilmineralNprocesses soilmineral_nprocesses;
        HilariousSoilmineralPProcesses soilmineral_p_processes;
        TentacledSoilorganicprocesses soilorganicprocesses;

        public:
        const IndigoGasprocesses & get_gasprocesses() const { return gasprocesses; }
        IndigoGasprocesses & get_mutable_gasprocesses() { return gasprocesses; }
        void set_gasprocesses(const IndigoGasprocesses & value) { this->gasprocesses = value; }

        const SoilmineralNprocesses & get_soilmineral_nprocesses() const { return soilmineral_nprocesses; }
        SoilmineralNprocesses & get_mutable_soilmineral_nprocesses() { return soilmineral_nprocesses; }
        void set_soilmineral_nprocesses(const SoilmineralNprocesses & value) { this->soilmineral_nprocesses = value; }

        const HilariousSoilmineralPProcesses & get_soilmineral_p_processes() const { return soilmineral_p_processes; }
        HilariousSoilmineralPProcesses & get_mutable_soilmineral_p_processes() { return soilmineral_p_processes; }
        void set_soilmineral_p_processes(const HilariousSoilmineralPProcesses & value) { this->soilmineral_p_processes = value; }

        const TentacledSoilorganicprocesses & get_soilorganicprocesses() const { return soilorganicprocesses; }
        TentacledSoilorganicprocesses & get_mutable_soilorganicprocesses() { return soilorganicprocesses; }
        void set_soilorganicprocesses(const TentacledSoilorganicprocesses & value) { this->soilorganicprocesses = value; }
    };

    class IndecentInterception {
        public:
        IndecentInterception() = default;
        virtual ~IndecentInterception() = default;

        private:
        RntLaIv lai_cover_sensitivity;
        RntLaIv maximal_cover;

        public:
        const RntLaIv & get_lai_cover_sensitivity() const { return lai_cover_sensitivity; }
        RntLaIv & get_mutable_lai_cover_sensitivity() { return lai_cover_sensitivity; }
        void set_lai_cover_sensitivity(const RntLaIv & value) { this->lai_cover_sensitivity = value; }

        const RntLaIv & get_maximal_cover() const { return maximal_cover; }
        RntLaIv & get_mutable_maximal_cover() { return maximal_cover; }
        void set_maximal_cover(const RntLaIv & value) { this->maximal_cover = value; }
    };

    enum class AlbedoVArrayName : int { NUMBEROF_DAY_NUMBERFOR_SINGLE_PLANT_SEASONALITY, NUMBER_ROOT_DAY_LAYERS };

    class AlbedoV {
        public:
        AlbedoV() = default;
        virtual ~AlbedoV() = default;

        private:
        AlbedoVArrayName array_name;
        std::string condition_1;
        std::string condition_2;
        std::string condition_3;
        std::shared_ptr<std::string> condition_4;
        std::string default_index_1;
        std::string default_index_2;
        std::string default_index_3;
        std::string default_index_4;
        std::string default_index_5;
        std::string index_1;
        std::string index_2;
        std::string index_3;
        std::string index_4;
        std::string index_5;
        std::string max_value_index_1;
        std::string max_value_index_2;
        std::string max_value_index_3;
        std::string max_value_index_4;
        std::string max_value_index_5;
        std::string min_value_index_1;
        std::string min_value_index_2;
        std::string min_value_index_3;
        std::string min_value_index_4;
        std::string min_value_index_5;
        std::string sizeof_array;

        public:
        const AlbedoVArrayName & get_array_name() const { return array_name; }
        AlbedoVArrayName & get_mutable_array_name() { return array_name; }
        void set_array_name(const AlbedoVArrayName & value) { this->array_name = value; }

        const std::string & get_condition_1() const { return condition_1; }
        std::string & get_mutable_condition_1() { return condition_1; }
        void set_condition_1(const std::string & value) { this->condition_1 = value; }

        const std::string & get_condition_2() const { return condition_2; }
        std::string & get_mutable_condition_2() { return condition_2; }
        void set_condition_2(const std::string & value) { this->condition_2 = value; }

        const std::string & get_condition_3() const { return condition_3; }
        std::string & get_mutable_condition_3() { return condition_3; }
        void set_condition_3(const std::string & value) { this->condition_3 = value; }

        std::shared_ptr<std::string> get_condition_4() const { return condition_4; }
        void set_condition_4(std::shared_ptr<std::string> value) { this->condition_4 = value; }

        const std::string & get_default_index_1() const { return default_index_1; }
        std::string & get_mutable_default_index_1() { return default_index_1; }
        void set_default_index_1(const std::string & value) { this->default_index_1 = value; }

        const std::string & get_default_index_2() const { return default_index_2; }
        std::string & get_mutable_default_index_2() { return default_index_2; }
        void set_default_index_2(const std::string & value) { this->default_index_2 = value; }

        const std::string & get_default_index_3() const { return default_index_3; }
        std::string & get_mutable_default_index_3() { return default_index_3; }
        void set_default_index_3(const std::string & value) { this->default_index_3 = value; }

        const std::string & get_default_index_4() const { return default_index_4; }
        std::string & get_mutable_default_index_4() { return default_index_4; }
        void set_default_index_4(const std::string & value) { this->default_index_4 = value; }

        const std::string & get_default_index_5() const { return default_index_5; }
        std::string & get_mutable_default_index_5() { return default_index_5; }
        void set_default_index_5(const std::string & value) { this->default_index_5 = value; }

        const std::string & get_index_1() const { return index_1; }
        std::string & get_mutable_index_1() { return index_1; }
        void set_index_1(const std::string & value) { this->index_1 = value; }

        const std::string & get_index_2() const { return index_2; }
        std::string & get_mutable_index_2() { return index_2; }
        void set_index_2(const std::string & value) { this->index_2 = value; }

        const std::string & get_index_3() const { return index_3; }
        std::string & get_mutable_index_3() { return index_3; }
        void set_index_3(const std::string & value) { this->index_3 = value; }

        const std::string & get_index_4() const { return index_4; }
        std::string & get_mutable_index_4() { return index_4; }
        void set_index_4(const std::string & value) { this->index_4 = value; }

        const std::string & get_index_5() const { return index_5; }
        std::string & get_mutable_index_5() { return index_5; }
        void set_index_5(const std::string & value) { this->index_5 = value; }

        const std::string & get_max_value_index_1() const { return max_value_index_1; }
        std::string & get_mutable_max_value_index_1() { return max_value_index_1; }
        void set_max_value_index_1(const std::string & value) { this->max_value_index_1 = value; }

        const std::string & get_max_value_index_2() const { return max_value_index_2; }
        std::string & get_mutable_max_value_index_2() { return max_value_index_2; }
        void set_max_value_index_2(const std::string & value) { this->max_value_index_2 = value; }

        const std::string & get_max_value_index_3() const { return max_value_index_3; }
        std::string & get_mutable_max_value_index_3() { return max_value_index_3; }
        void set_max_value_index_3(const std::string & value) { this->max_value_index_3 = value; }

        const std::string & get_max_value_index_4() const { return max_value_index_4; }
        std::string & get_mutable_max_value_index_4() { return max_value_index_4; }
        void set_max_value_index_4(const std::string & value) { this->max_value_index_4 = value; }

        const std::string & get_max_value_index_5() const { return max_value_index_5; }
        std::string & get_mutable_max_value_index_5() { return max_value_index_5; }
        void set_max_value_index_5(const std::string & value) { this->max_value_index_5 = value; }

        const std::string & get_min_value_index_1() const { return min_value_index_1; }
        std::string & get_mutable_min_value_index_1() { return min_value_index_1; }
        void set_min_value_index_1(const std::string & value) { this->min_value_index_1 = value; }

        const std::string & get_min_value_index_2() const { return min_value_index_2; }
        std::string & get_mutable_min_value_index_2() { return min_value_index_2; }
        void set_min_value_index_2(const std::string & value) { this->min_value_index_2 = value; }

        const std::string & get_min_value_index_3() const { return min_value_index_3; }
        std::string & get_mutable_min_value_index_3() { return min_value_index_3; }
        void set_min_value_index_3(const std::string & value) { this->min_value_index_3 = value; }

        const std::string & get_min_value_index_4() const { return min_value_index_4; }
        std::string & get_mutable_min_value_index_4() { return min_value_index_4; }
        void set_min_value_index_4(const std::string & value) { this->min_value_index_4 = value; }

        const std::string & get_min_value_index_5() const { return min_value_index_5; }
        std::string & get_mutable_min_value_index_5() { return min_value_index_5; }
        void set_min_value_index_5(const std::string & value) { this->min_value_index_5 = value; }

        const std::string & get_sizeof_array() const { return sizeof_array; }
        std::string & get_mutable_sizeof_array() { return sizeof_array; }
        void set_sizeof_array(const std::string & value) { this->sizeof_array = value; }
    };

    class StickyPlant {
        public:
        StickyPlant() = default;
        virtual ~StickyPlant() = default;

        private:
        RntLaIv a_end_value;
        RntLaIv albedo_grain_stage;
        AlbedoV albedo_v;
        RntLaIv albedo_veg_stage;
        RntLaIv a_optimum_value;
        RntLaIv areak_exp;
        RntLaIv a_start_value;
        AlbedoV canopy_height;
        AlbedoV c_form;
        AlbedoV day_number;
        RntLaIv diameter_height_ratio;
        RntLaIv end_day_no;
        RntLaIv height_age_coef;
        RntLaIv height_grain_coef;
        RntLaIv height_mass_coef;
        RntLaIv height_max_grain;
        RntLaIv h_end_value;
        RntLaIv h_optimum_value;
        RntLaIv h_start_value;
        AlbedoV leaf_area_index;
        RntLaIv l_end_value;
        RntLaIv l_optimum_value;
        RntLaIv l_start_value;
        RntLaIv max_cover;
        RntLaIv max_height;
        RntLaIv optimum_day_no;
        AlbedoV p_day_number;
        AlbedoV p_root_depth;
        AlbedoV p_root_length;
        RntLaIv r_end_value;
        RntLaIv rl_end_value;
        RntLaIv rl_optimum_value;
        RntLaIv rl_start_value;
        InfilDistF root_fraction;
        RntLaIv root_inc_depth;
        RntLaIv root_lowest_depth;
        RntLaIv r_optimum_value;
        RntLaIv r_start_value;
        RntLaIv shape_end;
        RntLaIv shape_start;
        RntLaIv specific_leaf_area;
        RntLaIv specific_root_length;
        RntLaIv spec_leaf_area_begin;
        RntLaIv start_day_no;
        RntLaIv xcenter_pos;

        public:
        const RntLaIv & get_a_end_value() const { return a_end_value; }
        RntLaIv & get_mutable_a_end_value() { return a_end_value; }
        void set_a_end_value(const RntLaIv & value) { this->a_end_value = value; }

        const RntLaIv & get_albedo_grain_stage() const { return albedo_grain_stage; }
        RntLaIv & get_mutable_albedo_grain_stage() { return albedo_grain_stage; }
        void set_albedo_grain_stage(const RntLaIv & value) { this->albedo_grain_stage = value; }

        const AlbedoV & get_albedo_v() const { return albedo_v; }
        AlbedoV & get_mutable_albedo_v() { return albedo_v; }
        void set_albedo_v(const AlbedoV & value) { this->albedo_v = value; }

        const RntLaIv & get_albedo_veg_stage() const { return albedo_veg_stage; }
        RntLaIv & get_mutable_albedo_veg_stage() { return albedo_veg_stage; }
        void set_albedo_veg_stage(const RntLaIv & value) { this->albedo_veg_stage = value; }

        const RntLaIv & get_a_optimum_value() const { return a_optimum_value; }
        RntLaIv & get_mutable_a_optimum_value() { return a_optimum_value; }
        void set_a_optimum_value(const RntLaIv & value) { this->a_optimum_value = value; }

        const RntLaIv & get_areak_exp() const { return areak_exp; }
        RntLaIv & get_mutable_areak_exp() { return areak_exp; }
        void set_areak_exp(const RntLaIv & value) { this->areak_exp = value; }

        const RntLaIv & get_a_start_value() const { return a_start_value; }
        RntLaIv & get_mutable_a_start_value() { return a_start_value; }
        void set_a_start_value(const RntLaIv & value) { this->a_start_value = value; }

        const AlbedoV & get_canopy_height() const { return canopy_height; }
        AlbedoV & get_mutable_canopy_height() { return canopy_height; }
        void set_canopy_height(const AlbedoV & value) { this->canopy_height = value; }

        const AlbedoV & get_c_form() const { return c_form; }
        AlbedoV & get_mutable_c_form() { return c_form; }
        void set_c_form(const AlbedoV & value) { this->c_form = value; }

        const AlbedoV & get_day_number() const { return day_number; }
        AlbedoV & get_mutable_day_number() { return day_number; }
        void set_day_number(const AlbedoV & value) { this->day_number = value; }

        const RntLaIv & get_diameter_height_ratio() const { return diameter_height_ratio; }
        RntLaIv & get_mutable_diameter_height_ratio() { return diameter_height_ratio; }
        void set_diameter_height_ratio(const RntLaIv & value) { this->diameter_height_ratio = value; }

        const RntLaIv & get_end_day_no() const { return end_day_no; }
        RntLaIv & get_mutable_end_day_no() { return end_day_no; }
        void set_end_day_no(const RntLaIv & value) { this->end_day_no = value; }

        const RntLaIv & get_height_age_coef() const { return height_age_coef; }
        RntLaIv & get_mutable_height_age_coef() { return height_age_coef; }
        void set_height_age_coef(const RntLaIv & value) { this->height_age_coef = value; }

        const RntLaIv & get_height_grain_coef() const { return height_grain_coef; }
        RntLaIv & get_mutable_height_grain_coef() { return height_grain_coef; }
        void set_height_grain_coef(const RntLaIv & value) { this->height_grain_coef = value; }

        const RntLaIv & get_height_mass_coef() const { return height_mass_coef; }
        RntLaIv & get_mutable_height_mass_coef() { return height_mass_coef; }
        void set_height_mass_coef(const RntLaIv & value) { this->height_mass_coef = value; }

        const RntLaIv & get_height_max_grain() const { return height_max_grain; }
        RntLaIv & get_mutable_height_max_grain() { return height_max_grain; }
        void set_height_max_grain(const RntLaIv & value) { this->height_max_grain = value; }

        const RntLaIv & get_h_end_value() const { return h_end_value; }
        RntLaIv & get_mutable_h_end_value() { return h_end_value; }
        void set_h_end_value(const RntLaIv & value) { this->h_end_value = value; }

        const RntLaIv & get_h_optimum_value() const { return h_optimum_value; }
        RntLaIv & get_mutable_h_optimum_value() { return h_optimum_value; }
        void set_h_optimum_value(const RntLaIv & value) { this->h_optimum_value = value; }

        const RntLaIv & get_h_start_value() const { return h_start_value; }
        RntLaIv & get_mutable_h_start_value() { return h_start_value; }
        void set_h_start_value(const RntLaIv & value) { this->h_start_value = value; }

        const AlbedoV & get_leaf_area_index() const { return leaf_area_index; }
        AlbedoV & get_mutable_leaf_area_index() { return leaf_area_index; }
        void set_leaf_area_index(const AlbedoV & value) { this->leaf_area_index = value; }

        const RntLaIv & get_l_end_value() const { return l_end_value; }
        RntLaIv & get_mutable_l_end_value() { return l_end_value; }
        void set_l_end_value(const RntLaIv & value) { this->l_end_value = value; }

        const RntLaIv & get_l_optimum_value() const { return l_optimum_value; }
        RntLaIv & get_mutable_l_optimum_value() { return l_optimum_value; }
        void set_l_optimum_value(const RntLaIv & value) { this->l_optimum_value = value; }

        const RntLaIv & get_l_start_value() const { return l_start_value; }
        RntLaIv & get_mutable_l_start_value() { return l_start_value; }
        void set_l_start_value(const RntLaIv & value) { this->l_start_value = value; }

        const RntLaIv & get_max_cover() const { return max_cover; }
        RntLaIv & get_mutable_max_cover() { return max_cover; }
        void set_max_cover(const RntLaIv & value) { this->max_cover = value; }

        const RntLaIv & get_max_height() const { return max_height; }
        RntLaIv & get_mutable_max_height() { return max_height; }
        void set_max_height(const RntLaIv & value) { this->max_height = value; }

        const RntLaIv & get_optimum_day_no() const { return optimum_day_no; }
        RntLaIv & get_mutable_optimum_day_no() { return optimum_day_no; }
        void set_optimum_day_no(const RntLaIv & value) { this->optimum_day_no = value; }

        const AlbedoV & get_p_day_number() const { return p_day_number; }
        AlbedoV & get_mutable_p_day_number() { return p_day_number; }
        void set_p_day_number(const AlbedoV & value) { this->p_day_number = value; }

        const AlbedoV & get_p_root_depth() const { return p_root_depth; }
        AlbedoV & get_mutable_p_root_depth() { return p_root_depth; }
        void set_p_root_depth(const AlbedoV & value) { this->p_root_depth = value; }

        const AlbedoV & get_p_root_length() const { return p_root_length; }
        AlbedoV & get_mutable_p_root_length() { return p_root_length; }
        void set_p_root_length(const AlbedoV & value) { this->p_root_length = value; }

        const RntLaIv & get_r_end_value() const { return r_end_value; }
        RntLaIv & get_mutable_r_end_value() { return r_end_value; }
        void set_r_end_value(const RntLaIv & value) { this->r_end_value = value; }

        const RntLaIv & get_rl_end_value() const { return rl_end_value; }
        RntLaIv & get_mutable_rl_end_value() { return rl_end_value; }
        void set_rl_end_value(const RntLaIv & value) { this->rl_end_value = value; }

        const RntLaIv & get_rl_optimum_value() const { return rl_optimum_value; }
        RntLaIv & get_mutable_rl_optimum_value() { return rl_optimum_value; }
        void set_rl_optimum_value(const RntLaIv & value) { this->rl_optimum_value = value; }

        const RntLaIv & get_rl_start_value() const { return rl_start_value; }
        RntLaIv & get_mutable_rl_start_value() { return rl_start_value; }
        void set_rl_start_value(const RntLaIv & value) { this->rl_start_value = value; }

        const InfilDistF & get_root_fraction() const { return root_fraction; }
        InfilDistF & get_mutable_root_fraction() { return root_fraction; }
        void set_root_fraction(const InfilDistF & value) { this->root_fraction = value; }

        const RntLaIv & get_root_inc_depth() const { return root_inc_depth; }
        RntLaIv & get_mutable_root_inc_depth() { return root_inc_depth; }
        void set_root_inc_depth(const RntLaIv & value) { this->root_inc_depth = value; }

        const RntLaIv & get_root_lowest_depth() const { return root_lowest_depth; }
        RntLaIv & get_mutable_root_lowest_depth() { return root_lowest_depth; }
        void set_root_lowest_depth(const RntLaIv & value) { this->root_lowest_depth = value; }

        const RntLaIv & get_r_optimum_value() const { return r_optimum_value; }
        RntLaIv & get_mutable_r_optimum_value() { return r_optimum_value; }
        void set_r_optimum_value(const RntLaIv & value) { this->r_optimum_value = value; }

        const RntLaIv & get_r_start_value() const { return r_start_value; }
        RntLaIv & get_mutable_r_start_value() { return r_start_value; }
        void set_r_start_value(const RntLaIv & value) { this->r_start_value = value; }

        const RntLaIv & get_shape_end() const { return shape_end; }
        RntLaIv & get_mutable_shape_end() { return shape_end; }
        void set_shape_end(const RntLaIv & value) { this->shape_end = value; }

        const RntLaIv & get_shape_start() const { return shape_start; }
        RntLaIv & get_mutable_shape_start() { return shape_start; }
        void set_shape_start(const RntLaIv & value) { this->shape_start = value; }

        const RntLaIv & get_specific_leaf_area() const { return specific_leaf_area; }
        RntLaIv & get_mutable_specific_leaf_area() { return specific_leaf_area; }
        void set_specific_leaf_area(const RntLaIv & value) { this->specific_leaf_area = value; }

        const RntLaIv & get_specific_root_length() const { return specific_root_length; }
        RntLaIv & get_mutable_specific_root_length() { return specific_root_length; }
        void set_specific_root_length(const RntLaIv & value) { this->specific_root_length = value; }

        const RntLaIv & get_spec_leaf_area_begin() const { return spec_leaf_area_begin; }
        RntLaIv & get_mutable_spec_leaf_area_begin() { return spec_leaf_area_begin; }
        void set_spec_leaf_area_begin(const RntLaIv & value) { this->spec_leaf_area_begin = value; }

        const RntLaIv & get_start_day_no() const { return start_day_no; }
        RntLaIv & get_mutable_start_day_no() { return start_day_no; }
        void set_start_day_no(const RntLaIv & value) { this->start_day_no = value; }

        const RntLaIv & get_xcenter_pos() const { return xcenter_pos; }
        RntLaIv & get_mutable_xcenter_pos() { return xcenter_pos; }
        void set_xcenter_pos(const RntLaIv & value) { this->xcenter_pos = value; }
    };

    class TentacledPotentialTranspiration {
        public:
        TentacledPotentialTranspiration() = default;
        virtual ~TentacledPotentialTranspiration() = default;

        private:
        RntLaIv air_resist_lai_effect;
        RntLaIv canopy_dens_max;
        RntLaIv conduct_max;
        RntLaIv conduct_ris;
        RntLaIv conduct_vpd;
        RntLaIv d_end_value;
        AlbedoV displace;
        RntLaIv d_optimum_value;
        RntLaIv d_start_value;
        RntLaIv plant_add_index;
        AlbedoV resistance_surface;
        AlbedoV roughness_length;
        RntLaIv roughness_max;
        RntLaIv roughness_min;
        RntLaIv z_end_value;
        RntLaIv z_optimum_value;
        RntLaIv z_start_value;

        public:
        const RntLaIv & get_air_resist_lai_effect() const { return air_resist_lai_effect; }
        RntLaIv & get_mutable_air_resist_lai_effect() { return air_resist_lai_effect; }
        void set_air_resist_lai_effect(const RntLaIv & value) { this->air_resist_lai_effect = value; }

        const RntLaIv & get_canopy_dens_max() const { return canopy_dens_max; }
        RntLaIv & get_mutable_canopy_dens_max() { return canopy_dens_max; }
        void set_canopy_dens_max(const RntLaIv & value) { this->canopy_dens_max = value; }

        const RntLaIv & get_conduct_max() const { return conduct_max; }
        RntLaIv & get_mutable_conduct_max() { return conduct_max; }
        void set_conduct_max(const RntLaIv & value) { this->conduct_max = value; }

        const RntLaIv & get_conduct_ris() const { return conduct_ris; }
        RntLaIv & get_mutable_conduct_ris() { return conduct_ris; }
        void set_conduct_ris(const RntLaIv & value) { this->conduct_ris = value; }

        const RntLaIv & get_conduct_vpd() const { return conduct_vpd; }
        RntLaIv & get_mutable_conduct_vpd() { return conduct_vpd; }
        void set_conduct_vpd(const RntLaIv & value) { this->conduct_vpd = value; }

        const RntLaIv & get_d_end_value() const { return d_end_value; }
        RntLaIv & get_mutable_d_end_value() { return d_end_value; }
        void set_d_end_value(const RntLaIv & value) { this->d_end_value = value; }

        const AlbedoV & get_displace() const { return displace; }
        AlbedoV & get_mutable_displace() { return displace; }
        void set_displace(const AlbedoV & value) { this->displace = value; }

        const RntLaIv & get_d_optimum_value() const { return d_optimum_value; }
        RntLaIv & get_mutable_d_optimum_value() { return d_optimum_value; }
        void set_d_optimum_value(const RntLaIv & value) { this->d_optimum_value = value; }

        const RntLaIv & get_d_start_value() const { return d_start_value; }
        RntLaIv & get_mutable_d_start_value() { return d_start_value; }
        void set_d_start_value(const RntLaIv & value) { this->d_start_value = value; }

        const RntLaIv & get_plant_add_index() const { return plant_add_index; }
        RntLaIv & get_mutable_plant_add_index() { return plant_add_index; }
        void set_plant_add_index(const RntLaIv & value) { this->plant_add_index = value; }

        const AlbedoV & get_resistance_surface() const { return resistance_surface; }
        AlbedoV & get_mutable_resistance_surface() { return resistance_surface; }
        void set_resistance_surface(const AlbedoV & value) { this->resistance_surface = value; }

        const AlbedoV & get_roughness_length() const { return roughness_length; }
        AlbedoV & get_mutable_roughness_length() { return roughness_length; }
        void set_roughness_length(const AlbedoV & value) { this->roughness_length = value; }

        const RntLaIv & get_roughness_max() const { return roughness_max; }
        RntLaIv & get_mutable_roughness_max() { return roughness_max; }
        void set_roughness_max(const RntLaIv & value) { this->roughness_max = value; }

        const RntLaIv & get_roughness_min() const { return roughness_min; }
        RntLaIv & get_mutable_roughness_min() { return roughness_min; }
        void set_roughness_min(const RntLaIv & value) { this->roughness_min = value; }

        const RntLaIv & get_z_end_value() const { return z_end_value; }
        RntLaIv & get_mutable_z_end_value() { return z_end_value; }
        void set_z_end_value(const RntLaIv & value) { this->z_end_value = value; }

        const RntLaIv & get_z_optimum_value() const { return z_optimum_value; }
        RntLaIv & get_mutable_z_optimum_value() { return z_optimum_value; }
        void set_z_optimum_value(const RntLaIv & value) { this->z_optimum_value = value; }

        const RntLaIv & get_z_start_value() const { return z_start_value; }
        RntLaIv & get_mutable_z_start_value() { return z_start_value; }
        void set_z_start_value(const RntLaIv & value) { this->z_start_value = value; }
    };

    class HilariousSaltTracer {
        public:
        HilariousSaltTracer() = default;
        virtual ~HilariousSaltTracer() = default;

        private:
        InfilDistF ad_c;
        InfilDistF init_salt_conc;

        public:
        const InfilDistF & get_ad_c() const { return ad_c; }
        InfilDistF & get_mutable_ad_c() { return ad_c; }
        void set_ad_c(const InfilDistF & value) { this->ad_c = value; }

        const InfilDistF & get_init_salt_conc() const { return init_salt_conc; }
        InfilDistF & get_mutable_init_salt_conc() { return init_salt_conc; }
        void set_init_salt_conc(const InfilDistF & value) { this->init_salt_conc = value; }
    };

    class ParametersArraysPlantWaterProcesses {
        public:
        ParametersArraysPlantWaterProcesses() = default;
        virtual ~ParametersArraysPlantWaterProcesses() = default;

        private:
        IndecentInterception interception;
        StickyPlant plant;
        TentacledPotentialTranspiration potential_transpiration;
        HilariousSaltTracer salt_tracer;
        std::map<std::string, RntLaIv> wateruptake;

        public:
        const IndecentInterception & get_interception() const { return interception; }
        IndecentInterception & get_mutable_interception() { return interception; }
        void set_interception(const IndecentInterception & value) { this->interception = value; }

        const StickyPlant & get_plant() const { return plant; }
        StickyPlant & get_mutable_plant() { return plant; }
        void set_plant(const StickyPlant & value) { this->plant = value; }

        const TentacledPotentialTranspiration & get_potential_transpiration() const { return potential_transpiration; }
        TentacledPotentialTranspiration & get_mutable_potential_transpiration() { return potential_transpiration; }
        void set_potential_transpiration(const TentacledPotentialTranspiration & value) { this->potential_transpiration = value; }

        const HilariousSaltTracer & get_salt_tracer() const { return salt_tracer; }
        HilariousSaltTracer & get_mutable_salt_tracer() { return salt_tracer; }
        void set_salt_tracer(const HilariousSaltTracer & value) { this->salt_tracer = value; }

        const std::map<std::string, RntLaIv> & get_wateruptake() const { return wateruptake; }
        std::map<std::string, RntLaIv> & get_mutable_wateruptake() { return wateruptake; }
        void set_wateruptake(const std::map<std::string, RntLaIv> & value) { this->wateruptake = value; }
    };

    class HilariousSoilheatflows {
        public:
        HilariousSoilheatflows() = default;
        virtual ~HilariousSoilheatflows() = default;

        private:
        InfilDistF heatstorage;
        std::map<std::string, std::string> pipe_segment_length;
        InfilDistF prod_coef_a;
        InfilDistF prod_coef_a2;
        InfilDistF temperature;
        KonzelmannCoef water_pipe_box_layer;

        public:
        const InfilDistF & get_heatstorage() const { return heatstorage; }
        InfilDistF & get_mutable_heatstorage() { return heatstorage; }
        void set_heatstorage(const InfilDistF & value) { this->heatstorage = value; }

        const std::map<std::string, std::string> & get_pipe_segment_length() const { return pipe_segment_length; }
        std::map<std::string, std::string> & get_mutable_pipe_segment_length() { return pipe_segment_length; }
        void set_pipe_segment_length(const std::map<std::string, std::string> & value) { this->pipe_segment_length = value; }

        const InfilDistF & get_prod_coef_a() const { return prod_coef_a; }
        InfilDistF & get_mutable_prod_coef_a() { return prod_coef_a; }
        void set_prod_coef_a(const InfilDistF & value) { this->prod_coef_a = value; }

        const InfilDistF & get_prod_coef_a2() const { return prod_coef_a2; }
        InfilDistF & get_mutable_prod_coef_a2() { return prod_coef_a2; }
        void set_prod_coef_a2(const InfilDistF & value) { this->prod_coef_a2 = value; }

        const InfilDistF & get_temperature() const { return temperature; }
        InfilDistF & get_mutable_temperature() { return temperature; }
        void set_temperature(const InfilDistF & value) { this->temperature = value; }

        const KonzelmannCoef & get_water_pipe_box_layer() const { return water_pipe_box_layer; }
        KonzelmannCoef & get_mutable_water_pipe_box_layer() { return water_pipe_box_layer; }
        void set_water_pipe_box_layer(const KonzelmannCoef & value) { this->water_pipe_box_layer = value; }
    };

    class ParametersArraysSoilHeatProcesses {
        public:
        ParametersArraysSoilHeatProcesses() = default;
        virtual ~ParametersArraysSoilHeatProcesses() = default;

        private:
        HilariousSoilheatflows soilheatflows;
        std::map<std::string, InfilDistF> soil_thermal;

        public:
        const HilariousSoilheatflows & get_soilheatflows() const { return soilheatflows; }
        HilariousSoilheatflows & get_mutable_soilheatflows() { return soilheatflows; }
        void set_soilheatflows(const HilariousSoilheatflows & value) { this->soilheatflows = value; }

        const std::map<std::string, InfilDistF> & get_soil_thermal() const { return soil_thermal; }
        std::map<std::string, InfilDistF> & get_mutable_soil_thermal() { return soil_thermal; }
        void set_soil_thermal(const std::map<std::string, InfilDistF> & value) { this->soil_thermal = value; }
    };

    class SoilHydraulic {
        public:
        SoilHydraulic() = default;
        virtual ~SoilHydraulic() = default;

        private:
        std::map<std::string, std::string> air_entry;
        std::map<std::string, std::string> alpha;
        InfilDistF b_m_value;
        InfilDistF b_n_value;
        InfilDistF b_n_power_sat_effective;
        InfilDistF b_n_power_sat_rel;
        InfilDistF b_n_tortuosity;
        InfilDistF b_air_entry;
        InfilDistF b_alpha;
        InfilDistF b_lambda;
        InfilDistF b_macro_pore;
        InfilDistF b_matrix_conductivity;
        InfilDistF b_residual_water;
        InfilDistF b_saturation;
        InfilDistF b_scalingp_f;
        InfilDistF b_total_conductivity;
        InfilDistF b_upper_boundary;
        InfilDistF b_wilting_point;
        std::map<std::string, std::string> clay_content;
        std::map<std::string, std::string> lambda;
        std::map<std::string, std::string> lower_valid;
        std::map<std::string, std::string> m_value;
        InfilDistF m_m_value;
        InfilDistF m_n_value;
        InfilDistF m_n_power_sat_effective;
        InfilDistF m_n_power_sat_rel;
        InfilDistF m_n_tortuosity;
        InfilDistF m_scalingp_f;
        std::map<std::string, std::string> macro_pore;
        InfilDistF m_air_entry;
        InfilDistF m_alpha;
        std::map<std::string, std::string> matrix_conductivity;
        InfilDistF m_lambda;
        InfilDistF m_macro_pore;
        InfilDistF m_matrix_conductivity;
        InfilDistF m_residual_water;
        InfilDistF m_saturation;
        InfilDistF m_total_conductivity;
        InfilDistF m_upper_boundary;
        InfilDistF m_upper_boundary_theta;
        InfilDistF m_wilting_point;
        std::map<std::string, std::string> n_value;
        std::map<std::string, std::string> n_power_sat_effective;
        std::map<std::string, std::string> n_power_sat_rel;
        std::map<std::string, std::string> n_tortuosity;
        std::map<std::string, std::string> profile_layer;
        std::map<std::string, std::string> profile_no;
        std::map<std::string, std::string> profile_rep_no;
        std::map<std::string, std::string> regline_n;
        std::map<std::string, std::string> regline_r2;
        std::map<std::string, std::string> residual_water;
        std::map<std::string, std::string> sand_content;
        std::map<std::string, std::string> saturation;
        std::map<std::string, std::string> scalingp_f;
        std::map<std::string, std::string> total_conductivity;
        std::map<std::string, std::string> upper_boundary;
        InfilDistF upper_boundary_theta;
        std::map<std::string, std::string> upper_theta_boundary;
        std::map<std::string, std::string> upper_valid;
        std::map<std::string, std::string> wilting_point;

        public:
        const std::map<std::string, std::string> & get_air_entry() const { return air_entry; }
        std::map<std::string, std::string> & get_mutable_air_entry() { return air_entry; }
        void set_air_entry(const std::map<std::string, std::string> & value) { this->air_entry = value; }

        const std::map<std::string, std::string> & get_alpha() const { return alpha; }
        std::map<std::string, std::string> & get_mutable_alpha() { return alpha; }
        void set_alpha(const std::map<std::string, std::string> & value) { this->alpha = value; }

        const InfilDistF & get_b_m_value() const { return b_m_value; }
        InfilDistF & get_mutable_b_m_value() { return b_m_value; }
        void set_b_m_value(const InfilDistF & value) { this->b_m_value = value; }

        const InfilDistF & get_b_n_value() const { return b_n_value; }
        InfilDistF & get_mutable_b_n_value() { return b_n_value; }
        void set_b_n_value(const InfilDistF & value) { this->b_n_value = value; }

        const InfilDistF & get_b_n_power_sat_effective() const { return b_n_power_sat_effective; }
        InfilDistF & get_mutable_b_n_power_sat_effective() { return b_n_power_sat_effective; }
        void set_b_n_power_sat_effective(const InfilDistF & value) { this->b_n_power_sat_effective = value; }

        const InfilDistF & get_b_n_power_sat_rel() const { return b_n_power_sat_rel; }
        InfilDistF & get_mutable_b_n_power_sat_rel() { return b_n_power_sat_rel; }
        void set_b_n_power_sat_rel(const InfilDistF & value) { this->b_n_power_sat_rel = value; }

        const InfilDistF & get_b_n_tortuosity() const { return b_n_tortuosity; }
        InfilDistF & get_mutable_b_n_tortuosity() { return b_n_tortuosity; }
        void set_b_n_tortuosity(const InfilDistF & value) { this->b_n_tortuosity = value; }

        const InfilDistF & get_b_air_entry() const { return b_air_entry; }
        InfilDistF & get_mutable_b_air_entry() { return b_air_entry; }
        void set_b_air_entry(const InfilDistF & value) { this->b_air_entry = value; }

        const InfilDistF & get_b_alpha() const { return b_alpha; }
        InfilDistF & get_mutable_b_alpha() { return b_alpha; }
        void set_b_alpha(const InfilDistF & value) { this->b_alpha = value; }

        const InfilDistF & get_b_lambda() const { return b_lambda; }
        InfilDistF & get_mutable_b_lambda() { return b_lambda; }
        void set_b_lambda(const InfilDistF & value) { this->b_lambda = value; }

        const InfilDistF & get_b_macro_pore() const { return b_macro_pore; }
        InfilDistF & get_mutable_b_macro_pore() { return b_macro_pore; }
        void set_b_macro_pore(const InfilDistF & value) { this->b_macro_pore = value; }

        const InfilDistF & get_b_matrix_conductivity() const { return b_matrix_conductivity; }
        InfilDistF & get_mutable_b_matrix_conductivity() { return b_matrix_conductivity; }
        void set_b_matrix_conductivity(const InfilDistF & value) { this->b_matrix_conductivity = value; }

        const InfilDistF & get_b_residual_water() const { return b_residual_water; }
        InfilDistF & get_mutable_b_residual_water() { return b_residual_water; }
        void set_b_residual_water(const InfilDistF & value) { this->b_residual_water = value; }

        const InfilDistF & get_b_saturation() const { return b_saturation; }
        InfilDistF & get_mutable_b_saturation() { return b_saturation; }
        void set_b_saturation(const InfilDistF & value) { this->b_saturation = value; }

        const InfilDistF & get_b_scalingp_f() const { return b_scalingp_f; }
        InfilDistF & get_mutable_b_scalingp_f() { return b_scalingp_f; }
        void set_b_scalingp_f(const InfilDistF & value) { this->b_scalingp_f = value; }

        const InfilDistF & get_b_total_conductivity() const { return b_total_conductivity; }
        InfilDistF & get_mutable_b_total_conductivity() { return b_total_conductivity; }
        void set_b_total_conductivity(const InfilDistF & value) { this->b_total_conductivity = value; }

        const InfilDistF & get_b_upper_boundary() const { return b_upper_boundary; }
        InfilDistF & get_mutable_b_upper_boundary() { return b_upper_boundary; }
        void set_b_upper_boundary(const InfilDistF & value) { this->b_upper_boundary = value; }

        const InfilDistF & get_b_wilting_point() const { return b_wilting_point; }
        InfilDistF & get_mutable_b_wilting_point() { return b_wilting_point; }
        void set_b_wilting_point(const InfilDistF & value) { this->b_wilting_point = value; }

        const std::map<std::string, std::string> & get_clay_content() const { return clay_content; }
        std::map<std::string, std::string> & get_mutable_clay_content() { return clay_content; }
        void set_clay_content(const std::map<std::string, std::string> & value) { this->clay_content = value; }

        const std::map<std::string, std::string> & get_lambda() const { return lambda; }
        std::map<std::string, std::string> & get_mutable_lambda() { return lambda; }
        void set_lambda(const std::map<std::string, std::string> & value) { this->lambda = value; }

        const std::map<std::string, std::string> & get_lower_valid() const { return lower_valid; }
        std::map<std::string, std::string> & get_mutable_lower_valid() { return lower_valid; }
        void set_lower_valid(const std::map<std::string, std::string> & value) { this->lower_valid = value; }

        const std::map<std::string, std::string> & get_m_value() const { return m_value; }
        std::map<std::string, std::string> & get_mutable_m_value() { return m_value; }
        void set_m_value(const std::map<std::string, std::string> & value) { this->m_value = value; }

        const InfilDistF & get_m_m_value() const { return m_m_value; }
        InfilDistF & get_mutable_m_m_value() { return m_m_value; }
        void set_m_m_value(const InfilDistF & value) { this->m_m_value = value; }

        const InfilDistF & get_m_n_value() const { return m_n_value; }
        InfilDistF & get_mutable_m_n_value() { return m_n_value; }
        void set_m_n_value(const InfilDistF & value) { this->m_n_value = value; }

        const InfilDistF & get_m_n_power_sat_effective() const { return m_n_power_sat_effective; }
        InfilDistF & get_mutable_m_n_power_sat_effective() { return m_n_power_sat_effective; }
        void set_m_n_power_sat_effective(const InfilDistF & value) { this->m_n_power_sat_effective = value; }

        const InfilDistF & get_m_n_power_sat_rel() const { return m_n_power_sat_rel; }
        InfilDistF & get_mutable_m_n_power_sat_rel() { return m_n_power_sat_rel; }
        void set_m_n_power_sat_rel(const InfilDistF & value) { this->m_n_power_sat_rel = value; }

        const InfilDistF & get_m_n_tortuosity() const { return m_n_tortuosity; }
        InfilDistF & get_mutable_m_n_tortuosity() { return m_n_tortuosity; }
        void set_m_n_tortuosity(const InfilDistF & value) { this->m_n_tortuosity = value; }

        const InfilDistF & get_m_scalingp_f() const { return m_scalingp_f; }
        InfilDistF & get_mutable_m_scalingp_f() { return m_scalingp_f; }
        void set_m_scalingp_f(const InfilDistF & value) { this->m_scalingp_f = value; }

        const std::map<std::string, std::string> & get_macro_pore() const { return macro_pore; }
        std::map<std::string, std::string> & get_mutable_macro_pore() { return macro_pore; }
        void set_macro_pore(const std::map<std::string, std::string> & value) { this->macro_pore = value; }

        const InfilDistF & get_m_air_entry() const { return m_air_entry; }
        InfilDistF & get_mutable_m_air_entry() { return m_air_entry; }
        void set_m_air_entry(const InfilDistF & value) { this->m_air_entry = value; }

        const InfilDistF & get_m_alpha() const { return m_alpha; }
        InfilDistF & get_mutable_m_alpha() { return m_alpha; }
        void set_m_alpha(const InfilDistF & value) { this->m_alpha = value; }

        const std::map<std::string, std::string> & get_matrix_conductivity() const { return matrix_conductivity; }
        std::map<std::string, std::string> & get_mutable_matrix_conductivity() { return matrix_conductivity; }
        void set_matrix_conductivity(const std::map<std::string, std::string> & value) { this->matrix_conductivity = value; }

        const InfilDistF & get_m_lambda() const { return m_lambda; }
        InfilDistF & get_mutable_m_lambda() { return m_lambda; }
        void set_m_lambda(const InfilDistF & value) { this->m_lambda = value; }

        const InfilDistF & get_m_macro_pore() const { return m_macro_pore; }
        InfilDistF & get_mutable_m_macro_pore() { return m_macro_pore; }
        void set_m_macro_pore(const InfilDistF & value) { this->m_macro_pore = value; }

        const InfilDistF & get_m_matrix_conductivity() const { return m_matrix_conductivity; }
        InfilDistF & get_mutable_m_matrix_conductivity() { return m_matrix_conductivity; }
        void set_m_matrix_conductivity(const InfilDistF & value) { this->m_matrix_conductivity = value; }

        const InfilDistF & get_m_residual_water() const { return m_residual_water; }
        InfilDistF & get_mutable_m_residual_water() { return m_residual_water; }
        void set_m_residual_water(const InfilDistF & value) { this->m_residual_water = value; }

        const InfilDistF & get_m_saturation() const { return m_saturation; }
        InfilDistF & get_mutable_m_saturation() { return m_saturation; }
        void set_m_saturation(const InfilDistF & value) { this->m_saturation = value; }

        const InfilDistF & get_m_total_conductivity() const { return m_total_conductivity; }
        InfilDistF & get_mutable_m_total_conductivity() { return m_total_conductivity; }
        void set_m_total_conductivity(const InfilDistF & value) { this->m_total_conductivity = value; }

        const InfilDistF & get_m_upper_boundary() const { return m_upper_boundary; }
        InfilDistF & get_mutable_m_upper_boundary() { return m_upper_boundary; }
        void set_m_upper_boundary(const InfilDistF & value) { this->m_upper_boundary = value; }

        const InfilDistF & get_m_upper_boundary_theta() const { return m_upper_boundary_theta; }
        InfilDistF & get_mutable_m_upper_boundary_theta() { return m_upper_boundary_theta; }
        void set_m_upper_boundary_theta(const InfilDistF & value) { this->m_upper_boundary_theta = value; }

        const InfilDistF & get_m_wilting_point() const { return m_wilting_point; }
        InfilDistF & get_mutable_m_wilting_point() { return m_wilting_point; }
        void set_m_wilting_point(const InfilDistF & value) { this->m_wilting_point = value; }

        const std::map<std::string, std::string> & get_n_value() const { return n_value; }
        std::map<std::string, std::string> & get_mutable_n_value() { return n_value; }
        void set_n_value(const std::map<std::string, std::string> & value) { this->n_value = value; }

        const std::map<std::string, std::string> & get_n_power_sat_effective() const { return n_power_sat_effective; }
        std::map<std::string, std::string> & get_mutable_n_power_sat_effective() { return n_power_sat_effective; }
        void set_n_power_sat_effective(const std::map<std::string, std::string> & value) { this->n_power_sat_effective = value; }

        const std::map<std::string, std::string> & get_n_power_sat_rel() const { return n_power_sat_rel; }
        std::map<std::string, std::string> & get_mutable_n_power_sat_rel() { return n_power_sat_rel; }
        void set_n_power_sat_rel(const std::map<std::string, std::string> & value) { this->n_power_sat_rel = value; }

        const std::map<std::string, std::string> & get_n_tortuosity() const { return n_tortuosity; }
        std::map<std::string, std::string> & get_mutable_n_tortuosity() { return n_tortuosity; }
        void set_n_tortuosity(const std::map<std::string, std::string> & value) { this->n_tortuosity = value; }

        const std::map<std::string, std::string> & get_profile_layer() const { return profile_layer; }
        std::map<std::string, std::string> & get_mutable_profile_layer() { return profile_layer; }
        void set_profile_layer(const std::map<std::string, std::string> & value) { this->profile_layer = value; }

        const std::map<std::string, std::string> & get_profile_no() const { return profile_no; }
        std::map<std::string, std::string> & get_mutable_profile_no() { return profile_no; }
        void set_profile_no(const std::map<std::string, std::string> & value) { this->profile_no = value; }

        const std::map<std::string, std::string> & get_profile_rep_no() const { return profile_rep_no; }
        std::map<std::string, std::string> & get_mutable_profile_rep_no() { return profile_rep_no; }
        void set_profile_rep_no(const std::map<std::string, std::string> & value) { this->profile_rep_no = value; }

        const std::map<std::string, std::string> & get_regline_n() const { return regline_n; }
        std::map<std::string, std::string> & get_mutable_regline_n() { return regline_n; }
        void set_regline_n(const std::map<std::string, std::string> & value) { this->regline_n = value; }

        const std::map<std::string, std::string> & get_regline_r2() const { return regline_r2; }
        std::map<std::string, std::string> & get_mutable_regline_r2() { return regline_r2; }
        void set_regline_r2(const std::map<std::string, std::string> & value) { this->regline_r2 = value; }

        const std::map<std::string, std::string> & get_residual_water() const { return residual_water; }
        std::map<std::string, std::string> & get_mutable_residual_water() { return residual_water; }
        void set_residual_water(const std::map<std::string, std::string> & value) { this->residual_water = value; }

        const std::map<std::string, std::string> & get_sand_content() const { return sand_content; }
        std::map<std::string, std::string> & get_mutable_sand_content() { return sand_content; }
        void set_sand_content(const std::map<std::string, std::string> & value) { this->sand_content = value; }

        const std::map<std::string, std::string> & get_saturation() const { return saturation; }
        std::map<std::string, std::string> & get_mutable_saturation() { return saturation; }
        void set_saturation(const std::map<std::string, std::string> & value) { this->saturation = value; }

        const std::map<std::string, std::string> & get_scalingp_f() const { return scalingp_f; }
        std::map<std::string, std::string> & get_mutable_scalingp_f() { return scalingp_f; }
        void set_scalingp_f(const std::map<std::string, std::string> & value) { this->scalingp_f = value; }

        const std::map<std::string, std::string> & get_total_conductivity() const { return total_conductivity; }
        std::map<std::string, std::string> & get_mutable_total_conductivity() { return total_conductivity; }
        void set_total_conductivity(const std::map<std::string, std::string> & value) { this->total_conductivity = value; }

        const std::map<std::string, std::string> & get_upper_boundary() const { return upper_boundary; }
        std::map<std::string, std::string> & get_mutable_upper_boundary() { return upper_boundary; }
        void set_upper_boundary(const std::map<std::string, std::string> & value) { this->upper_boundary = value; }

        const InfilDistF & get_upper_boundary_theta() const { return upper_boundary_theta; }
        InfilDistF & get_mutable_upper_boundary_theta() { return upper_boundary_theta; }
        void set_upper_boundary_theta(const InfilDistF & value) { this->upper_boundary_theta = value; }

        const std::map<std::string, std::string> & get_upper_theta_boundary() const { return upper_theta_boundary; }
        std::map<std::string, std::string> & get_mutable_upper_theta_boundary() { return upper_theta_boundary; }
        void set_upper_theta_boundary(const std::map<std::string, std::string> & value) { this->upper_theta_boundary = value; }

        const std::map<std::string, std::string> & get_upper_valid() const { return upper_valid; }
        std::map<std::string, std::string> & get_mutable_upper_valid() { return upper_valid; }
        void set_upper_valid(const std::map<std::string, std::string> & value) { this->upper_valid = value; }

        const std::map<std::string, std::string> & get_wilting_point() const { return wilting_point; }
        std::map<std::string, std::string> & get_mutable_wilting_point() { return wilting_point; }
        void set_wilting_point(const std::map<std::string, std::string> & value) { this->wilting_point = value; }
    };

    class HilariousSoilwaterflows {
        public:
        HilariousSoilwaterflows() = default;
        virtual ~HilariousSoilwaterflows() = default;

        private:
        InfilDistF hys_max_eff_cond;
        InfilDistF hys_max_eff_ret;
        InfilDistF ini_pressure_heads;
        InfilDistF ini_water_contents;

        public:
        const InfilDistF & get_hys_max_eff_cond() const { return hys_max_eff_cond; }
        InfilDistF & get_mutable_hys_max_eff_cond() { return hys_max_eff_cond; }
        void set_hys_max_eff_cond(const InfilDistF & value) { this->hys_max_eff_cond = value; }

        const InfilDistF & get_hys_max_eff_ret() const { return hys_max_eff_ret; }
        InfilDistF & get_mutable_hys_max_eff_ret() { return hys_max_eff_ret; }
        void set_hys_max_eff_ret(const InfilDistF & value) { this->hys_max_eff_ret = value; }

        const InfilDistF & get_ini_pressure_heads() const { return ini_pressure_heads; }
        InfilDistF & get_mutable_ini_pressure_heads() { return ini_pressure_heads; }
        void set_ini_pressure_heads(const InfilDistF & value) { this->ini_pressure_heads = value; }

        const InfilDistF & get_ini_water_contents() const { return ini_water_contents; }
        InfilDistF & get_mutable_ini_water_contents() { return ini_water_contents; }
        void set_ini_water_contents(const InfilDistF & value) { this->ini_water_contents = value; }
    };

    class ParametersArraysSoilWaterProcesses {
        public:
        ParametersArraysSoilWaterProcesses() = default;
        virtual ~ParametersArraysSoilWaterProcesses() = default;

        private:
        SoilHydraulic soil_hydraulic;
        HilariousSoilwaterflows soilwaterflows;

        public:
        const SoilHydraulic & get_soil_hydraulic() const { return soil_hydraulic; }
        SoilHydraulic & get_mutable_soil_hydraulic() { return soil_hydraulic; }
        void set_soil_hydraulic(const SoilHydraulic & value) { this->soil_hydraulic = value; }

        const HilariousSoilwaterflows & get_soilwaterflows() const { return soilwaterflows; }
        HilariousSoilwaterflows & get_mutable_soilwaterflows() { return soilwaterflows; }
        void set_soilwaterflows(const HilariousSoilwaterflows & value) { this->soilwaterflows = value; }
    };

    class ParametersArrays {
        public:
        ParametersArrays() = default;
        virtual ~ParametersArrays() = default;

        private:
        ParametersArraysAtmosphericRelatedProcesses atmospheric_related_processes;
        ParametersArraysModelFacilities model_facilities;
        ParametersArraysNitrogenandCarbon nitrogenand_carbon;
        ParametersArraysNitrogenandCarbonBelowGround nitrogenand_carbon_below_ground;
        ParametersArraysPlantWaterProcesses plant_water_processes;
        ParametersArraysSoilHeatProcesses soil_heat_processes;
        ParametersArraysSoilWaterProcesses soil_water_processes;

        public:
        const ParametersArraysAtmosphericRelatedProcesses & get_atmospheric_related_processes() const { return atmospheric_related_processes; }
        ParametersArraysAtmosphericRelatedProcesses & get_mutable_atmospheric_related_processes() { return atmospheric_related_processes; }
        void set_atmospheric_related_processes(const ParametersArraysAtmosphericRelatedProcesses & value) { this->atmospheric_related_processes = value; }

        const ParametersArraysModelFacilities & get_model_facilities() const { return model_facilities; }
        ParametersArraysModelFacilities & get_mutable_model_facilities() { return model_facilities; }
        void set_model_facilities(const ParametersArraysModelFacilities & value) { this->model_facilities = value; }

        const ParametersArraysNitrogenandCarbon & get_nitrogenand_carbon() const { return nitrogenand_carbon; }
        ParametersArraysNitrogenandCarbon & get_mutable_nitrogenand_carbon() { return nitrogenand_carbon; }
        void set_nitrogenand_carbon(const ParametersArraysNitrogenandCarbon & value) { this->nitrogenand_carbon = value; }

        const ParametersArraysNitrogenandCarbonBelowGround & get_nitrogenand_carbon_below_ground() const { return nitrogenand_carbon_below_ground; }
        ParametersArraysNitrogenandCarbonBelowGround & get_mutable_nitrogenand_carbon_below_ground() { return nitrogenand_carbon_below_ground; }
        void set_nitrogenand_carbon_below_ground(const ParametersArraysNitrogenandCarbonBelowGround & value) { this->nitrogenand_carbon_below_ground = value; }

        const ParametersArraysPlantWaterProcesses & get_plant_water_processes() const { return plant_water_processes; }
        ParametersArraysPlantWaterProcesses & get_mutable_plant_water_processes() { return plant_water_processes; }
        void set_plant_water_processes(const ParametersArraysPlantWaterProcesses & value) { this->plant_water_processes = value; }

        const ParametersArraysSoilHeatProcesses & get_soil_heat_processes() const { return soil_heat_processes; }
        ParametersArraysSoilHeatProcesses & get_mutable_soil_heat_processes() { return soil_heat_processes; }
        void set_soil_heat_processes(const ParametersArraysSoilHeatProcesses & value) { this->soil_heat_processes = value; }

        const ParametersArraysSoilWaterProcesses & get_soil_water_processes() const { return soil_water_processes; }
        ParametersArraysSoilWaterProcesses & get_mutable_soil_water_processes() { return soil_water_processes; }
        void set_soil_water_processes(const ParametersArraysSoilWaterProcesses & value) { this->soil_water_processes = value; }
    };

    class AdditionalDetails {
        public:
        AdditionalDetails() = default;
        virtual ~AdditionalDetails() = default;

        private:
        std::string locked_multi_store;

        public:
        const std::string & get_locked_multi_store() const { return locked_multi_store; }
        std::string & get_mutable_locked_multi_store() { return locked_multi_store; }
        void set_locked_multi_store(const std::string & value) { this->locked_multi_store = value; }
    };

    class GeneralInformation {
        public:
        GeneralInformation() = default;
        virtual ~GeneralInformation() = default;

        private:
        std::string comments;
        std::string date_created;
        std::string date_modification;
        std::string exe_file_date;
        std::string file_version_number;
        std::string finished;
        std::string m_bin_file;
        std::string multi_simulaton;
        std::string original_file_name;
        std::string rund_id;
        std::string sim_number;

        public:
        const std::string & get_comments() const { return comments; }
        std::string & get_mutable_comments() { return comments; }
        void set_comments(const std::string & value) { this->comments = value; }

        const std::string & get_date_created() const { return date_created; }
        std::string & get_mutable_date_created() { return date_created; }
        void set_date_created(const std::string & value) { this->date_created = value; }

        const std::string & get_date_modification() const { return date_modification; }
        std::string & get_mutable_date_modification() { return date_modification; }
        void set_date_modification(const std::string & value) { this->date_modification = value; }

        const std::string & get_exe_file_date() const { return exe_file_date; }
        std::string & get_mutable_exe_file_date() { return exe_file_date; }
        void set_exe_file_date(const std::string & value) { this->exe_file_date = value; }

        const std::string & get_file_version_number() const { return file_version_number; }
        std::string & get_mutable_file_version_number() { return file_version_number; }
        void set_file_version_number(const std::string & value) { this->file_version_number = value; }

        const std::string & get_finished() const { return finished; }
        std::string & get_mutable_finished() { return finished; }
        void set_finished(const std::string & value) { this->finished = value; }

        const std::string & get_m_bin_file() const { return m_bin_file; }
        std::string & get_mutable_m_bin_file() { return m_bin_file; }
        void set_m_bin_file(const std::string & value) { this->m_bin_file = value; }

        const std::string & get_multi_simulaton() const { return multi_simulaton; }
        std::string & get_mutable_multi_simulaton() { return multi_simulaton; }
        void set_multi_simulaton(const std::string & value) { this->multi_simulaton = value; }

        const std::string & get_original_file_name() const { return original_file_name; }
        std::string & get_mutable_original_file_name() { return original_file_name; }
        void set_original_file_name(const std::string & value) { this->original_file_name = value; }

        const std::string & get_rund_id() const { return rund_id; }
        std::string & get_mutable_rund_id() { return rund_id; }
        void set_rund_id(const std::string & value) { this->rund_id = value; }

        const std::string & get_sim_number() const { return sim_number; }
        std::string & get_mutable_sim_number() { return sim_number; }
        void set_sim_number(const std::string & value) { this->sim_number = value; }
    };

    class NumericalOptions {
        public:
        NumericalOptions() = default;
        virtual ~NumericalOptions() = default;

        private:
        std::string number_iterations;

        public:
        const std::string & get_number_iterations() const { return number_iterations; }
        std::string & get_mutable_number_iterations() { return number_iterations; }
        void set_number_iterations(const std::string & value) { this->number_iterations = value; }
    };

    class SimulationPeriod {
        public:
        SimulationPeriod() = default;
        virtual ~SimulationPeriod() = default;

        private:
        std::string length_post_period;
        std::string prior_sim_time;
        std::string sim_end_date;
        std::string sim_end_min;
        std::string sim_start_date;
        std::string sim_start_min;
        std::string sim_start_scaling;

        public:
        const std::string & get_length_post_period() const { return length_post_period; }
        std::string & get_mutable_length_post_period() { return length_post_period; }
        void set_length_post_period(const std::string & value) { this->length_post_period = value; }

        const std::string & get_prior_sim_time() const { return prior_sim_time; }
        std::string & get_mutable_prior_sim_time() { return prior_sim_time; }
        void set_prior_sim_time(const std::string & value) { this->prior_sim_time = value; }

        const std::string & get_sim_end_date() const { return sim_end_date; }
        std::string & get_mutable_sim_end_date() { return sim_end_date; }
        void set_sim_end_date(const std::string & value) { this->sim_end_date = value; }

        const std::string & get_sim_end_min() const { return sim_end_min; }
        std::string & get_mutable_sim_end_min() { return sim_end_min; }
        void set_sim_end_min(const std::string & value) { this->sim_end_min = value; }

        const std::string & get_sim_start_date() const { return sim_start_date; }
        std::string & get_mutable_sim_start_date() { return sim_start_date; }
        void set_sim_start_date(const std::string & value) { this->sim_start_date = value; }

        const std::string & get_sim_start_min() const { return sim_start_min; }
        std::string & get_mutable_sim_start_min() { return sim_start_min; }
        void set_sim_start_min(const std::string & value) { this->sim_start_min = value; }

        const std::string & get_sim_start_scaling() const { return sim_start_scaling; }
        std::string & get_mutable_sim_start_scaling() { return sim_start_scaling; }
        void set_sim_start_scaling(const std::string & value) { this->sim_start_scaling = value; }
    };

    class TimeResolution {
        public:
        TimeResolution() = default;
        virtual ~TimeResolution() = default;

        private:
        std::string output_interval_days;
        std::string output_interval_minutes;
        std::string time_resoluton;

        public:
        const std::string & get_output_interval_days() const { return output_interval_days; }
        std::string & get_mutable_output_interval_days() { return output_interval_days; }
        void set_output_interval_days(const std::string & value) { this->output_interval_days = value; }

        const std::string & get_output_interval_minutes() const { return output_interval_minutes; }
        std::string & get_mutable_output_interval_minutes() { return output_interval_minutes; }
        void set_output_interval_minutes(const std::string & value) { this->output_interval_minutes = value; }

        const std::string & get_time_resoluton() const { return time_resoluton; }
        std::string & get_mutable_time_resoluton() { return time_resoluton; }
        void set_time_resoluton(const std::string & value) { this->time_resoluton = value; }
    };

    class RunInfo {
        public:
        RunInfo() = default;
        virtual ~RunInfo() = default;

        private:
        AdditionalDetails additional_details;
        GeneralInformation general_information;
        NumericalOptions numerical_options;
        SimulationPeriod simulation_period;
        TimeResolution time_resolution;

        public:
        const AdditionalDetails & get_additional_details() const { return additional_details; }
        AdditionalDetails & get_mutable_additional_details() { return additional_details; }
        void set_additional_details(const AdditionalDetails & value) { this->additional_details = value; }

        const GeneralInformation & get_general_information() const { return general_information; }
        GeneralInformation & get_mutable_general_information() { return general_information; }
        void set_general_information(const GeneralInformation & value) { this->general_information = value; }

        const NumericalOptions & get_numerical_options() const { return numerical_options; }
        NumericalOptions & get_mutable_numerical_options() { return numerical_options; }
        void set_numerical_options(const NumericalOptions & value) { this->numerical_options = value; }

        const SimulationPeriod & get_simulation_period() const { return simulation_period; }
        SimulationPeriod & get_mutable_simulation_period() { return simulation_period; }
        void set_simulation_period(const SimulationPeriod & value) { this->simulation_period = value; }

        const TimeResolution & get_time_resolution() const { return time_resolution; }
        TimeResolution & get_mutable_time_resolution() { return time_resolution; }
        void set_time_resolution(const TimeResolution & value) { this->time_resolution = value; }
    };

    class Node {
        public:
        Node() = default;
        virtual ~Node() = default;

        private:
        ModelFiles model_files;
        ModelOptions model_options;
        OutputVariables output_variables;
        Parameters parameters;
        ParametersArrays parameters_arrays;
        RunInfo run_info;

        public:
        const ModelFiles & get_model_files() const { return model_files; }
        ModelFiles & get_mutable_model_files() { return model_files; }
        void set_model_files(const ModelFiles & value) { this->model_files = value; }

        const ModelOptions & get_model_options() const { return model_options; }
        ModelOptions & get_mutable_model_options() { return model_options; }
        void set_model_options(const ModelOptions & value) { this->model_options = value; }

        const OutputVariables & get_output_variables() const { return output_variables; }
        OutputVariables & get_mutable_output_variables() { return output_variables; }
        void set_output_variables(const OutputVariables & value) { this->output_variables = value; }

        const Parameters & get_parameters() const { return parameters; }
        Parameters & get_mutable_parameters() { return parameters; }
        void set_parameters(const Parameters & value) { this->parameters = value; }

        const ParametersArrays & get_parameters_arrays() const { return parameters_arrays; }
        ParametersArrays & get_mutable_parameters_arrays() { return parameters_arrays; }
        void set_parameters_arrays(const ParametersArrays & value) { this->parameters_arrays = value; }

        const RunInfo & get_run_info() const { return run_info; }
        RunInfo & get_mutable_run_info() { return run_info; }
        void set_run_info(const RunInfo & value) { this->run_info = value; }
    };

    class Coup {
        public:
        Coup() = default;
        virtual ~Coup() = default;

        private:
        Node node;

        public:
        const Node & get_node() const { return node; }
        Node & get_mutable_node() { return node; }
        void set_node(const Node & value) { this->node = value; }
    };
}

namespace nlohmann {
    void from_json(const json & j, coup::HeatPumpdata & x);
    void to_json(json & j, const coup::HeatPumpdata & x);

    void from_json(const json & j, coup::Meteorologicaldata & x);
    void to_json(json & j, const coup::Meteorologicaldata & x);

    void from_json(const json & j, coup::PurpleMeteorologicalData & x);
    void to_json(json & j, const coup::PurpleMeteorologicalData & x);

    void from_json(const json & j, coup::ModelFilesAtmosphericRelatedProcesses & x);
    void to_json(json & j, const coup::ModelFilesAtmosphericRelatedProcesses & x);

    void from_json(const json & j, coup::OutputFile & x);
    void to_json(json & j, const coup::OutputFile & x);

    void from_json(const json & j, coup::PurpleTechnical & x);
    void to_json(json & j, const coup::PurpleTechnical & x);

    void from_json(const json & j, coup::ModelFilesModelFacilities & x);
    void to_json(json & j, const coup::ModelFilesModelFacilities & x);

    void from_json(const json & j, coup::PurpleExternalNinputs & x);
    void to_json(json & j, const coup::PurpleExternalNinputs & x);

    void from_json(const json & j, coup::PurplePlantGrowth & x);
    void to_json(json & j, const coup::PurplePlantGrowth & x);

    void from_json(const json & j, coup::ModelFilesNitrogenandCarbon & x);
    void to_json(json & j, const coup::ModelFilesNitrogenandCarbon & x);

    void from_json(const json & j, coup::PurpleAbioticdrivingvariables & x);
    void to_json(json & j, const coup::PurpleAbioticdrivingvariables & x);

    void from_json(const json & j, coup::ModelFilesNitrogenandCarbonBelowGround & x);
    void to_json(json & j, const coup::ModelFilesNitrogenandCarbonBelowGround & x);

    void from_json(const json & j, coup::PurplePlant & x);
    void to_json(json & j, const coup::PurplePlant & x);

    void from_json(const json & j, coup::SaltRoadDeposition & x);
    void to_json(json & j, const coup::SaltRoadDeposition & x);

    void from_json(const json & j, coup::PurpleSaltTracer & x);
    void to_json(json & j, const coup::PurpleSaltTracer & x);

    void from_json(const json & j, coup::ModelFilesPlantWaterProcesses & x);
    void to_json(json & j, const coup::ModelFilesPlantWaterProcesses & x);

    void from_json(const json & j, coup::PurpleDrainageanddeeppercolation & x);
    void to_json(json & j, const coup::PurpleDrainageanddeeppercolation & x);

    void from_json(const json & j, coup::ModelFilesSoilWaterProcesses & x);
    void to_json(json & j, const coup::ModelFilesSoilWaterProcesses & x);

    void from_json(const json & j, coup::ModelFiles & x);
    void to_json(json & j, const coup::ModelFiles & x);

    void from_json(const json & j, coup::PrecInput & x);
    void to_json(json & j, const coup::PrecInput & x);

    void from_json(const json & j, coup::FluffyMeteorologicalData & x);
    void to_json(json & j, const coup::FluffyMeteorologicalData & x);

    void from_json(const json & j, coup::PurpleRadiationproperties & x);
    void to_json(json & j, const coup::PurpleRadiationproperties & x);

    void from_json(const json & j, coup::EvaporationMethod & x);
    void to_json(json & j, const coup::EvaporationMethod & x);

    void from_json(const json & j, coup::PurpleSoilevaporation & x);
    void to_json(json & j, const coup::PurpleSoilevaporation & x);

    void from_json(const json & j, coup::ModelOptionsAtmosphericRelatedProcesses & x);
    void to_json(json & j, const coup::ModelOptionsAtmosphericRelatedProcesses & x);

    void from_json(const json & j, coup::FluffyTechnical & x);
    void to_json(json & j, const coup::FluffyTechnical & x);

    void from_json(const json & j, coup::ModelOptionsModelFacilities & x);
    void to_json(json & j, const coup::ModelOptionsModelFacilities & x);

    void from_json(const json & j, coup::PurpleModelStructure & x);
    void to_json(json & j, const coup::PurpleModelStructure & x);

    void from_json(const json & j, coup::ModelOptionsModelStructure & x);
    void to_json(json & j, const coup::ModelOptionsModelStructure & x);

    void from_json(const json & j, coup::PurpleInterception & x);
    void to_json(json & j, const coup::PurpleInterception & x);

    void from_json(const json & j, coup::PurpleWateruptake & x);
    void to_json(json & j, const coup::PurpleWateruptake & x);

    void from_json(const json & j, coup::ModelOptionsPlantWaterProcesses & x);
    void to_json(json & j, const coup::ModelOptionsPlantWaterProcesses & x);

    void from_json(const json & j, coup::FluffyDrainageanddeeppercolation & x);
    void to_json(json & j, const coup::FluffyDrainageanddeeppercolation & x);

    void from_json(const json & j, coup::PurpleSurfacewater & x);
    void to_json(json & j, const coup::PurpleSurfacewater & x);

    void from_json(const json & j, coup::ModelOptionsSoilWaterProcesses & x);
    void to_json(json & j, const coup::ModelOptionsSoilWaterProcesses & x);

    void from_json(const json & j, coup::ModelOptions & x);
    void to_json(json & j, const coup::ModelOptions & x);

    void from_json(const json & j, coup::AlbedoVar & x);
    void to_json(json & j, const coup::AlbedoVar & x);

    void from_json(const json & j, coup::CanopyFracRadDiffuse & x);
    void to_json(json & j, const coup::CanopyFracRadDiffuse & x);

    void from_json(const json & j, coup::FluffyRadiationproperties & x);
    void to_json(json & j, const coup::FluffyRadiationproperties & x);

    void from_json(const json & j, coup::AuxiliaryAtmosphericRelatedProcesses & x);
    void to_json(json & j, const coup::AuxiliaryAtmosphericRelatedProcesses & x);

    void from_json(const json & j, coup::FluffyModelStructure & x);
    void to_json(json & j, const coup::FluffyModelStructure & x);

    void from_json(const json & j, coup::AuxiliaryModelStructure & x);
    void to_json(json & j, const coup::AuxiliaryModelStructure & x);

    void from_json(const json & j, coup::FluffyExternalNinputs & x);
    void to_json(json & j, const coup::FluffyExternalNinputs & x);

    void from_json(const json & j, coup::AuxiliaryNitrogenandCarbon & x);
    void to_json(json & j, const coup::AuxiliaryNitrogenandCarbon & x);

    void from_json(const json & j, coup::PurpleSoilmineralPProcesses & x);
    void to_json(json & j, const coup::PurpleSoilmineralPProcesses & x);

    void from_json(const json & j, coup::AuxiliaryNitrogenandCarbonBelowGround & x);
    void to_json(json & j, const coup::AuxiliaryNitrogenandCarbonBelowGround & x);

    void from_json(const json & j, coup::FluffyInterception & x);
    void to_json(json & j, const coup::FluffyInterception & x);

    void from_json(const json & j, coup::FluffyPlant & x);
    void to_json(json & j, const coup::FluffyPlant & x);

    void from_json(const json & j, coup::PurplePotentialTranspiration & x);
    void to_json(json & j, const coup::PurplePotentialTranspiration & x);

    void from_json(const json & j, coup::FluffyWateruptake & x);
    void to_json(json & j, const coup::FluffyWateruptake & x);

    void from_json(const json & j, coup::AuxiliaryPlantWaterProcesses & x);
    void to_json(json & j, const coup::AuxiliaryPlantWaterProcesses & x);

    void from_json(const json & j, coup::PurpleSoilfrost & x);
    void to_json(json & j, const coup::PurpleSoilfrost & x);

    void from_json(const json & j, coup::PurpleSoilheatflows & x);
    void to_json(json & j, const coup::PurpleSoilheatflows & x);

    void from_json(const json & j, coup::AuxiliarySoilHeatProcesses & x);
    void to_json(json & j, const coup::AuxiliarySoilHeatProcesses & x);

    void from_json(const json & j, coup::TentacledDrainageanddeeppercolation & x);
    void to_json(json & j, const coup::TentacledDrainageanddeeppercolation & x);

    void from_json(const json & j, coup::PurpleSoilwaterflows & x);
    void to_json(json & j, const coup::PurpleSoilwaterflows & x);

    void from_json(const json & j, coup::FluffySurfacewater & x);
    void to_json(json & j, const coup::FluffySurfacewater & x);

    void from_json(const json & j, coup::AuxiliarySoilWaterProcesses & x);
    void to_json(json & j, const coup::AuxiliarySoilWaterProcesses & x);

    void from_json(const json & j, coup::Auxiliary & x);
    void to_json(json & j, const coup::Auxiliary & x);

    void from_json(const json & j, coup::LaiAbovecanopy & x);
    void to_json(json & j, const coup::LaiAbovecanopy & x);

    void from_json(const json & j, coup::TentacledRadiationproperties & x);
    void to_json(json & j, const coup::TentacledRadiationproperties & x);

    void from_json(const json & j, coup::SnowReduceLaiFactor & x);
    void to_json(json & j, const coup::SnowReduceLaiFactor & x);

    void from_json(const json & j, coup::PurpleSnowPack & x);
    void to_json(json & j, const coup::PurpleSnowPack & x);

    void from_json(const json & j, coup::AuxiliaryArraysAtmosphericRelatedProcesses & x);
    void to_json(json & j, const coup::AuxiliaryArraysAtmosphericRelatedProcesses & x);

    void from_json(const json & j, coup::CCoarseRootsAtmLayer & x);
    void to_json(json & j, const coup::CCoarseRootsAtmLayer & x);

    void from_json(const json & j, coup::FluffyPlantGrowth & x);
    void to_json(json & j, const coup::FluffyPlantGrowth & x);

    void from_json(const json & j, coup::AuxiliaryArraysNitrogenandCarbon & x);
    void to_json(json & j, const coup::AuxiliaryArraysNitrogenandCarbon & x);

    void from_json(const json & j, coup::PurpleGasprocesses & x);
    void to_json(json & j, const coup::PurpleGasprocesses & x);

    void from_json(const json & j, coup::FluffySoilmineralPProcesses & x);
    void to_json(json & j, const coup::FluffySoilmineralPProcesses & x);

    void from_json(const json & j, coup::AuxiliaryArraysNitrogenandCarbonBelowGround & x);
    void to_json(json & j, const coup::AuxiliaryArraysNitrogenandCarbonBelowGround & x);

    void from_json(const json & j, coup::TentacledInterception & x);
    void to_json(json & j, const coup::TentacledInterception & x);

    void from_json(const json & j, coup::TentacledPlant & x);
    void to_json(json & j, const coup::TentacledPlant & x);

    void from_json(const json & j, coup::FluffyPotentialTranspiration & x);
    void to_json(json & j, const coup::FluffyPotentialTranspiration & x);

    void from_json(const json & j, coup::FluffySaltTracer & x);
    void to_json(json & j, const coup::FluffySaltTracer & x);

    void from_json(const json & j, coup::TentacledWateruptake & x);
    void to_json(json & j, const coup::TentacledWateruptake & x);

    void from_json(const json & j, coup::AuxiliaryArraysPlantWaterProcesses & x);
    void to_json(json & j, const coup::AuxiliaryArraysPlantWaterProcesses & x);

    void from_json(const json & j, coup::TempColdPipe & x);
    void to_json(json & j, const coup::TempColdPipe & x);

    void from_json(const json & j, coup::FluffySoilheatflows & x);
    void to_json(json & j, const coup::FluffySoilheatflows & x);

    void from_json(const json & j, coup::AuxiliaryArraysSoilHeatProcesses & x);
    void to_json(json & j, const coup::AuxiliaryArraysSoilHeatProcesses & x);

    void from_json(const json & j, coup::StickyDrainageanddeeppercolation & x);
    void to_json(json & j, const coup::StickyDrainageanddeeppercolation & x);

    void from_json(const json & j, coup::FluffySoilwaterflows & x);
    void to_json(json & j, const coup::FluffySoilwaterflows & x);

    void from_json(const json & j, coup::AuxiliaryArraysSoilWaterProcesses & x);
    void to_json(json & j, const coup::AuxiliaryArraysSoilWaterProcesses & x);

    void from_json(const json & j, coup::AuxiliaryArrays & x);
    void to_json(json & j, const coup::AuxiliaryArrays & x);

    void from_json(const json & j, coup::FluffySnowPack & x);
    void to_json(json & j, const coup::FluffySnowPack & x);

    void from_json(const json & j, coup::DrivingAtmosphericRelatedProcesses & x);
    void to_json(json & j, const coup::DrivingAtmosphericRelatedProcesses & x);

    void from_json(const json & j, coup::FluffyAbioticdrivingvariables & x);
    void to_json(json & j, const coup::FluffyAbioticdrivingvariables & x);

    void from_json(const json & j, coup::DrivingNitrogenandCarbonBelowGround & x);
    void to_json(json & j, const coup::DrivingNitrogenandCarbonBelowGround & x);

    void from_json(const json & j, coup::TentacledSaltTracer & x);
    void to_json(json & j, const coup::TentacledSaltTracer & x);

    void from_json(const json & j, coup::DrivingPlantWaterProcesses & x);
    void to_json(json & j, const coup::DrivingPlantWaterProcesses & x);

    void from_json(const json & j, coup::Driving & x);
    void to_json(json & j, const coup::Driving & x);

    void from_json(const json & j, coup::TentacledMeteorologicalData & x);
    void to_json(json & j, const coup::TentacledMeteorologicalData & x);

    void from_json(const json & j, coup::DrivingArraysAtmosphericRelatedProcesses & x);
    void to_json(json & j, const coup::DrivingArraysAtmosphericRelatedProcesses & x);

    void from_json(const json & j, coup::TentacledAbioticdrivingvariables & x);
    void to_json(json & j, const coup::TentacledAbioticdrivingvariables & x);

    void from_json(const json & j, coup::DrivingArraysNitrogenandCarbonBelowGround & x);
    void to_json(json & j, const coup::DrivingArraysNitrogenandCarbonBelowGround & x);

    void from_json(const json & j, coup::DrivingArrays & x);
    void to_json(json & j, const coup::DrivingArrays & x);

    void from_json(const json & j, coup::TentacledSnowPack & x);
    void to_json(json & j, const coup::TentacledSnowPack & x);

    void from_json(const json & j, coup::FluffySoilevaporation & x);
    void to_json(json & j, const coup::FluffySoilevaporation & x);

    void from_json(const json & j, coup::FlowAtmosphericRelatedProcesses & x);
    void to_json(json & j, const coup::FlowAtmosphericRelatedProcesses & x);

    void from_json(const json & j, coup::PurpleIrrigation & x);
    void to_json(json & j, const coup::PurpleIrrigation & x);

    void from_json(const json & j, coup::FlowModelFacilities & x);
    void to_json(json & j, const coup::FlowModelFacilities & x);

    void from_json(const json & j, coup::PurpleExternalPInputs & x);
    void to_json(json & j, const coup::PurpleExternalPInputs & x);

    void from_json(const json & j, coup::FlowNitrogenandCarbon & x);
    void to_json(json & j, const coup::FlowNitrogenandCarbon & x);

    void from_json(const json & j, coup::FluffyGasprocesses & x);
    void to_json(json & j, const coup::FluffyGasprocesses & x);

    void from_json(const json & j, coup::TentacledSoilmineralPProcesses & x);
    void to_json(json & j, const coup::TentacledSoilmineralPProcesses & x);

    void from_json(const json & j, coup::PurpleSoilorganicprocesses & x);
    void to_json(json & j, const coup::PurpleSoilorganicprocesses & x);

    void from_json(const json & j, coup::FlowNitrogenandCarbonBelowGround & x);
    void to_json(json & j, const coup::FlowNitrogenandCarbonBelowGround & x);

    void from_json(const json & j, coup::FlowPlantWaterProcesses & x);
    void to_json(json & j, const coup::FlowPlantWaterProcesses & x);

    void from_json(const json & j, coup::Soilheatpump & x);
    void to_json(json & j, const coup::Soilheatpump & x);

    void from_json(const json & j, coup::FlowSoilHeatProcesses & x);
    void to_json(json & j, const coup::FlowSoilHeatProcesses & x);

    void from_json(const json & j, coup::IndigoDrainageanddeeppercolation & x);
    void to_json(json & j, const coup::IndigoDrainageanddeeppercolation & x);

    void from_json(const json & j, coup::TentacledSoilwaterflows & x);
    void to_json(json & j, const coup::TentacledSoilwaterflows & x);

    void from_json(const json & j, coup::TentacledSurfacewater & x);
    void to_json(json & j, const coup::TentacledSurfacewater & x);

    void from_json(const json & j, coup::FlowSoilWaterProcesses & x);
    void to_json(json & j, const coup::FlowSoilWaterProcesses & x);

    void from_json(const json & j, coup::Flow & x);
    void to_json(json & j, const coup::Flow & x);

    void from_json(const json & j, coup::TentacledExternalNinputs & x);
    void to_json(json & j, const coup::TentacledExternalNinputs & x);

    void from_json(const json & j, coup::FlowArraysNitrogenandCarbon & x);
    void to_json(json & j, const coup::FlowArraysNitrogenandCarbon & x);

    void from_json(const json & j, coup::StickySoilmineralPProcesses & x);
    void to_json(json & j, const coup::StickySoilmineralPProcesses & x);

    void from_json(const json & j, coup::FlowArraysNitrogenandCarbonBelowGround & x);
    void to_json(json & j, const coup::FlowArraysNitrogenandCarbonBelowGround & x);

    void from_json(const json & j, coup::StickyInterception & x);
    void to_json(json & j, const coup::StickyInterception & x);

    void from_json(const json & j, coup::StickySaltTracer & x);
    void to_json(json & j, const coup::StickySaltTracer & x);

    void from_json(const json & j, coup::StickyWateruptake & x);
    void to_json(json & j, const coup::StickyWateruptake & x);

    void from_json(const json & j, coup::FlowArraysPlantWaterProcesses & x);
    void to_json(json & j, const coup::FlowArraysPlantWaterProcesses & x);

    void from_json(const json & j, coup::FluffySoilfrost & x);
    void to_json(json & j, const coup::FluffySoilfrost & x);

    void from_json(const json & j, coup::HeatBox & x);
    void to_json(json & j, const coup::HeatBox & x);

    void from_json(const json & j, coup::TentacledSoilheatflows & x);
    void to_json(json & j, const coup::TentacledSoilheatflows & x);

    void from_json(const json & j, coup::FlowArraysSoilHeatProcesses & x);
    void to_json(json & j, const coup::FlowArraysSoilHeatProcesses & x);

    void from_json(const json & j, coup::IndecentDrainageanddeeppercolation & x);
    void to_json(json & j, const coup::IndecentDrainageanddeeppercolation & x);

    void from_json(const json & j, coup::StickySoilwaterflows & x);
    void to_json(json & j, const coup::StickySoilwaterflows & x);

    void from_json(const json & j, coup::FlowArraysSoilWaterProcesses & x);
    void to_json(json & j, const coup::FlowArraysSoilWaterProcesses & x);

    void from_json(const json & j, coup::FlowArrays & x);
    void to_json(json & j, const coup::FlowArrays & x);

    void from_json(const json & j, coup::StickySnowPack & x);
    void to_json(json & j, const coup::StickySnowPack & x);

    void from_json(const json & j, coup::StateAtmosphericRelatedProcesses & x);
    void to_json(json & j, const coup::StateAtmosphericRelatedProcesses & x);

    void from_json(const json & j, coup::FluffyIrrigation & x);
    void to_json(json & j, const coup::FluffyIrrigation & x);

    void from_json(const json & j, coup::StateModelFacilities & x);
    void to_json(json & j, const coup::StateModelFacilities & x);

    void from_json(const json & j, coup::StickyExternalNinputs & x);
    void to_json(json & j, const coup::StickyExternalNinputs & x);

    void from_json(const json & j, coup::FluffyExternalPInputs & x);
    void to_json(json & j, const coup::FluffyExternalPInputs & x);

    void from_json(const json & j, coup::TentacledPlantGrowth & x);
    void to_json(json & j, const coup::TentacledPlantGrowth & x);

    void from_json(const json & j, coup::StateNitrogenandCarbon & x);
    void to_json(json & j, const coup::StateNitrogenandCarbon & x);

    void from_json(const json & j, coup::TentacledGasprocesses & x);
    void to_json(json & j, const coup::TentacledGasprocesses & x);

    void from_json(const json & j, coup::IndigoSoilmineralPProcesses & x);
    void to_json(json & j, const coup::IndigoSoilmineralPProcesses & x);

    void from_json(const json & j, coup::FluffySoilorganicprocesses & x);
    void to_json(json & j, const coup::FluffySoilorganicprocesses & x);

    void from_json(const json & j, coup::StateNitrogenandCarbonBelowGround & x);
    void to_json(json & j, const coup::StateNitrogenandCarbonBelowGround & x);

    void from_json(const json & j, coup::IndigoSaltTracer & x);
    void to_json(json & j, const coup::IndigoSaltTracer & x);

    void from_json(const json & j, coup::StatePlantWaterProcesses & x);
    void to_json(json & j, const coup::StatePlantWaterProcesses & x);

    void from_json(const json & j, coup::StickySoilheatflows & x);
    void to_json(json & j, const coup::StickySoilheatflows & x);

    void from_json(const json & j, coup::StateSoilHeatProcesses & x);
    void to_json(json & j, const coup::StateSoilHeatProcesses & x);

    void from_json(const json & j, coup::StickySurfacewater & x);
    void to_json(json & j, const coup::StickySurfacewater & x);

    void from_json(const json & j, coup::StateSoilWaterProcesses & x);
    void to_json(json & j, const coup::StateSoilWaterProcesses & x);

    void from_json(const json & j, coup::State & x);
    void to_json(json & j, const coup::State & x);

    void from_json(const json & j, coup::StateArraysNitrogenandCarbon & x);
    void to_json(json & j, const coup::StateArraysNitrogenandCarbon & x);

    void from_json(const json & j, coup::StickyGasprocesses & x);
    void to_json(json & j, const coup::StickyGasprocesses & x);

    void from_json(const json & j, coup::IndecentSoilmineralPProcesses & x);
    void to_json(json & j, const coup::IndecentSoilmineralPProcesses & x);

    void from_json(const json & j, coup::StateArraysNitrogenandCarbonBelowGround & x);
    void to_json(json & j, const coup::StateArraysNitrogenandCarbonBelowGround & x);

    void from_json(const json & j, coup::IndigoInterception & x);
    void to_json(json & j, const coup::IndigoInterception & x);

    void from_json(const json & j, coup::IndecentSaltTracer & x);
    void to_json(json & j, const coup::IndecentSaltTracer & x);

    void from_json(const json & j, coup::IndigoWateruptake & x);
    void to_json(json & j, const coup::IndigoWateruptake & x);

    void from_json(const json & j, coup::StateArraysPlantWaterProcesses & x);
    void to_json(json & j, const coup::StateArraysPlantWaterProcesses & x);

    void from_json(const json & j, coup::TentacledSoilfrost & x);
    void to_json(json & j, const coup::TentacledSoilfrost & x);

    void from_json(const json & j, coup::IndigoSoilheatflows & x);
    void to_json(json & j, const coup::IndigoSoilheatflows & x);

    void from_json(const json & j, coup::StateArraysSoilHeatProcesses & x);
    void to_json(json & j, const coup::StateArraysSoilHeatProcesses & x);

    void from_json(const json & j, coup::IndigoSoilwaterflows & x);
    void to_json(json & j, const coup::IndigoSoilwaterflows & x);

    void from_json(const json & j, coup::StateArraysSoilWaterProcesses & x);
    void to_json(json & j, const coup::StateArraysSoilWaterProcesses & x);

    void from_json(const json & j, coup::StateArrays & x);
    void to_json(json & j, const coup::StateArrays & x);

    void from_json(const json & j, coup::OutputVariables & x);
    void to_json(json & j, const coup::OutputVariables & x);

    void from_json(const json & j, coup::IndigoSnowPack & x);
    void to_json(json & j, const coup::IndigoSnowPack & x);

    void from_json(const json & j, coup::ParametersAtmosphericRelatedProcesses & x);
    void to_json(json & j, const coup::ParametersAtmosphericRelatedProcesses & x);

    void from_json(const json & j, coup::TentacledModelStructure & x);
    void to_json(json & j, const coup::TentacledModelStructure & x);

    void from_json(const json & j, coup::ParametersModelStructure & x);
    void to_json(json & j, const coup::ParametersModelStructure & x);

    void from_json(const json & j, coup::IndecentWateruptake & x);
    void to_json(json & j, const coup::IndecentWateruptake & x);

    void from_json(const json & j, coup::ParametersPlantWaterProcesses & x);
    void to_json(json & j, const coup::ParametersPlantWaterProcesses & x);

    void from_json(const json & j, coup::SoilThermal & x);
    void to_json(json & j, const coup::SoilThermal & x);

    void from_json(const json & j, coup::StickySoilfrost & x);
    void to_json(json & j, const coup::StickySoilfrost & x);

    void from_json(const json & j, coup::IndecentSoilheatflows & x);
    void to_json(json & j, const coup::IndecentSoilheatflows & x);

    void from_json(const json & j, coup::ParametersSoilHeatProcesses & x);
    void to_json(json & j, const coup::ParametersSoilHeatProcesses & x);

    void from_json(const json & j, coup::HilariousDrainageanddeeppercolation & x);
    void to_json(json & j, const coup::HilariousDrainageanddeeppercolation & x);

    void from_json(const json & j, coup::IndecentSoilwaterflows & x);
    void to_json(json & j, const coup::IndecentSoilwaterflows & x);

    void from_json(const json & j, coup::IndigoSurfacewater & x);
    void to_json(json & j, const coup::IndigoSurfacewater & x);

    void from_json(const json & j, coup::ParametersSoilWaterProcesses & x);
    void to_json(json & j, const coup::ParametersSoilWaterProcesses & x);

    void from_json(const json & j, coup::Parameters & x);
    void to_json(json & j, const coup::Parameters & x);

    void from_json(const json & j, coup::KonzelmannCoef & x);
    void to_json(json & j, const coup::KonzelmannCoef & x);

    void from_json(const json & j, coup::RntLaIv & x);
    void to_json(json & j, const coup::RntLaIv & x);

    void from_json(const json & j, coup::StickyRadiationproperties & x);
    void to_json(json & j, const coup::StickyRadiationproperties & x);

    void from_json(const json & j, coup::ParametersArraysAtmosphericRelatedProcesses & x);
    void to_json(json & j, const coup::ParametersArraysAtmosphericRelatedProcesses & x);

    void from_json(const json & j, coup::InfilDistF & x);
    void to_json(json & j, const coup::InfilDistF & x);

    void from_json(const json & j, coup::TentacledIrrigation & x);
    void to_json(json & j, const coup::TentacledIrrigation & x);

    void from_json(const json & j, coup::AbsError & x);
    void to_json(json & j, const coup::AbsError & x);

    void from_json(const json & j, coup::BoxCox & x);
    void to_json(json & j, const coup::BoxCox & x);

    void from_json(const json & j, coup::TentacledTechnical & x);
    void to_json(json & j, const coup::TentacledTechnical & x);

    void from_json(const json & j, coup::ParametersArraysModelFacilities & x);
    void to_json(json & j, const coup::ParametersArraysModelFacilities & x);

    void from_json(const json & j, coup::TentacledExternalPInputs & x);
    void to_json(json & j, const coup::TentacledExternalPInputs & x);

    void from_json(const json & j, coup::StickyPlantGrowth & x);
    void to_json(json & j, const coup::StickyPlantGrowth & x);

    void from_json(const json & j, coup::ParametersArraysNitrogenandCarbon & x);
    void to_json(json & j, const coup::ParametersArraysNitrogenandCarbon & x);

    void from_json(const json & j, coup::IndigoGasprocesses & x);
    void to_json(json & j, const coup::IndigoGasprocesses & x);

    void from_json(const json & j, coup::SoilmineralNprocesses & x);
    void to_json(json & j, const coup::SoilmineralNprocesses & x);

    void from_json(const json & j, coup::HilariousSoilmineralPProcesses & x);
    void to_json(json & j, const coup::HilariousSoilmineralPProcesses & x);

    void from_json(const json & j, coup::TentacledSoilorganicprocesses & x);
    void to_json(json & j, const coup::TentacledSoilorganicprocesses & x);

    void from_json(const json & j, coup::ParametersArraysNitrogenandCarbonBelowGround & x);
    void to_json(json & j, const coup::ParametersArraysNitrogenandCarbonBelowGround & x);

    void from_json(const json & j, coup::IndecentInterception & x);
    void to_json(json & j, const coup::IndecentInterception & x);

    void from_json(const json & j, coup::AlbedoV & x);
    void to_json(json & j, const coup::AlbedoV & x);

    void from_json(const json & j, coup::StickyPlant & x);
    void to_json(json & j, const coup::StickyPlant & x);

    void from_json(const json & j, coup::TentacledPotentialTranspiration & x);
    void to_json(json & j, const coup::TentacledPotentialTranspiration & x);

    void from_json(const json & j, coup::HilariousSaltTracer & x);
    void to_json(json & j, const coup::HilariousSaltTracer & x);

    void from_json(const json & j, coup::ParametersArraysPlantWaterProcesses & x);
    void to_json(json & j, const coup::ParametersArraysPlantWaterProcesses & x);

    void from_json(const json & j, coup::HilariousSoilheatflows & x);
    void to_json(json & j, const coup::HilariousSoilheatflows & x);

    void from_json(const json & j, coup::ParametersArraysSoilHeatProcesses & x);
    void to_json(json & j, const coup::ParametersArraysSoilHeatProcesses & x);

    void from_json(const json & j, coup::SoilHydraulic & x);
    void to_json(json & j, const coup::SoilHydraulic & x);

    void from_json(const json & j, coup::HilariousSoilwaterflows & x);
    void to_json(json & j, const coup::HilariousSoilwaterflows & x);

    void from_json(const json & j, coup::ParametersArraysSoilWaterProcesses & x);
    void to_json(json & j, const coup::ParametersArraysSoilWaterProcesses & x);

    void from_json(const json & j, coup::ParametersArrays & x);
    void to_json(json & j, const coup::ParametersArrays & x);

    void from_json(const json & j, coup::AdditionalDetails & x);
    void to_json(json & j, const coup::AdditionalDetails & x);

    void from_json(const json & j, coup::GeneralInformation & x);
    void to_json(json & j, const coup::GeneralInformation & x);

    void from_json(const json & j, coup::NumericalOptions & x);
    void to_json(json & j, const coup::NumericalOptions & x);

    void from_json(const json & j, coup::SimulationPeriod & x);
    void to_json(json & j, const coup::SimulationPeriod & x);

    void from_json(const json & j, coup::TimeResolution & x);
    void to_json(json & j, const coup::TimeResolution & x);

    void from_json(const json & j, coup::RunInfo & x);
    void to_json(json & j, const coup::RunInfo & x);

    void from_json(const json & j, coup::Node & x);
    void to_json(json & j, const coup::Node & x);

    void from_json(const json & j, coup::Coup & x);
    void to_json(json & j, const coup::Coup & x);

    void from_json(const json & j, coup::Condition3Enum & x);
    void to_json(json & j, const coup::Condition3Enum & x);

    void from_json(const json & j, coup::Condition2Enum & x);
    void to_json(json & j, const coup::Condition2Enum & x);

    void from_json(const json & j, coup::LaiAbovecanopyArrayName & x);
    void to_json(json & j, const coup::LaiAbovecanopyArrayName & x);

    void from_json(const json & j, coup::LaiAbovecanopyCondition1 & x);
    void to_json(json & j, const coup::LaiAbovecanopyCondition1 & x);

    void from_json(const json & j, coup::CCoarseRootsAtmLayerArrayName & x);
    void to_json(json & j, const coup::CCoarseRootsAtmLayerArrayName & x);

    void from_json(const json & j, coup::ArrayName & x);
    void to_json(json & j, const coup::ArrayName & x);

    void from_json(const json & j, coup::RntLaIvCondition1 & x);
    void to_json(json & j, const coup::RntLaIvCondition1 & x);

    void from_json(const json & j, coup::AlbedoVArrayName & x);
    void to_json(json & j, const coup::AlbedoVArrayName & x);

    inline void from_json(const json & j, coup::HeatPumpdata& x) {
        x.set_condition_1(j.at("Condition_1").get<std::string>());
        x.set_condition_2(j.at("Condition_2").get<std::string>());
        x.set_condition_3(coup::get_optional<coup::Condition3Enum>(j, "Condition_3"));
        x.set_pf_file(j.at("PF_File").get<std::string>());
    }

    inline void to_json(json & j, const coup::HeatPumpdata & x) {
        j = json::object();
        j["Condition_1"] = x.get_condition_1();
        j["Condition_2"] = x.get_condition_2();
        j["Condition_3"] = x.get_condition_3();
        j["PF_File"] = x.get_pf_file();
    }

    inline void from_json(const json & j, coup::Meteorologicaldata& x) {
        x.set_condition_1(j.at("Condition_1").get<std::string>());
        x.set_pf_file(j.at("PF_File").get<std::string>());
    }

    inline void to_json(json & j, const coup::Meteorologicaldata & x) {
        j = json::object();
        j["Condition_1"] = x.get_condition_1();
        j["PF_File"] = x.get_pf_file();
    }

    inline void from_json(const json & j, coup::PurpleMeteorologicalData& x) {
        x.set_heat_pumpdata(j.at("HeatPumpdata").get<coup::HeatPumpdata>());
        x.set_lateral_water_inflow(j.at("LateralWaterInflow").get<coup::HeatPumpdata>());
        x.set_meteorologicaldata(j.at("Meteorologicaldata").get<coup::Meteorologicaldata>());
        x.set_saltconcentration(j.at("Saltconcentration").get<coup::HeatPumpdata>());
        x.set_snowdepths(j.at("Snowdepths").get<coup::HeatPumpdata>());
    }

    inline void to_json(json & j, const coup::PurpleMeteorologicalData & x) {
        j = json::object();
        j["HeatPumpdata"] = x.get_heat_pumpdata();
        j["LateralWaterInflow"] = x.get_lateral_water_inflow();
        j["Meteorologicaldata"] = x.get_meteorologicaldata();
        j["Saltconcentration"] = x.get_saltconcentration();
        j["Snowdepths"] = x.get_snowdepths();
    }

    inline void from_json(const json & j, coup::ModelFilesAtmosphericRelatedProcesses& x) {
        x.set_meteorological_data(j.at("MeteorologicalData").get<coup::PurpleMeteorologicalData>());
    }

    inline void to_json(json & j, const coup::ModelFilesAtmosphericRelatedProcesses & x) {
        j = json::object();
        j["MeteorologicalData"] = x.get_meteorological_data();
    }

    inline void from_json(const json & j, coup::OutputFile& x) {
        x.set_pf_file(j.at("PF_File").get<std::string>());
    }

    inline void to_json(json & j, const coup::OutputFile & x) {
        j = json::object();
        j["PF_File"] = x.get_pf_file();
    }

    inline void from_json(const json & j, coup::PurpleTechnical& x) {
        x.set_output_file(j.at("OutputFile").get<coup::OutputFile>());
        x.set_validation_file1(j.at("ValidationFile1").get<coup::Meteorologicaldata>());
        x.set_validation_file10(j.at("ValidationFile10").get<coup::Meteorologicaldata>());
        x.set_validation_file11(j.at("ValidationFile11").get<coup::Meteorologicaldata>());
        x.set_validation_file12(j.at("ValidationFile12").get<coup::Meteorologicaldata>());
        x.set_validation_file13(j.at("ValidationFile13").get<coup::Meteorologicaldata>());
        x.set_validation_file14(j.at("ValidationFile14").get<coup::Meteorologicaldata>());
        x.set_validation_file15(j.at("ValidationFile15").get<coup::Meteorologicaldata>());
        x.set_validation_file16(j.at("ValidationFile16").get<coup::Meteorologicaldata>());
        x.set_validation_file2(j.at("ValidationFile2").get<coup::Meteorologicaldata>());
        x.set_validation_file3(j.at("ValidationFile3").get<coup::Meteorologicaldata>());
        x.set_validation_file4(j.at("ValidationFile4").get<coup::Meteorologicaldata>());
        x.set_validation_file5(j.at("ValidationFile5").get<coup::Meteorologicaldata>());
        x.set_validation_file6(j.at("ValidationFile6").get<coup::Meteorologicaldata>());
        x.set_validation_file7(j.at("ValidationFile7").get<coup::Meteorologicaldata>());
        x.set_validation_file8(j.at("ValidationFile8").get<coup::Meteorologicaldata>());
        x.set_validation_file9(j.at("ValidationFile9").get<coup::Meteorologicaldata>());
    }

    inline void to_json(json & j, const coup::PurpleTechnical & x) {
        j = json::object();
        j["OutputFile"] = x.get_output_file();
        j["ValidationFile1"] = x.get_validation_file1();
        j["ValidationFile10"] = x.get_validation_file10();
        j["ValidationFile11"] = x.get_validation_file11();
        j["ValidationFile12"] = x.get_validation_file12();
        j["ValidationFile13"] = x.get_validation_file13();
        j["ValidationFile14"] = x.get_validation_file14();
        j["ValidationFile15"] = x.get_validation_file15();
        j["ValidationFile16"] = x.get_validation_file16();
        j["ValidationFile2"] = x.get_validation_file2();
        j["ValidationFile3"] = x.get_validation_file3();
        j["ValidationFile4"] = x.get_validation_file4();
        j["ValidationFile5"] = x.get_validation_file5();
        j["ValidationFile6"] = x.get_validation_file6();
        j["ValidationFile7"] = x.get_validation_file7();
        j["ValidationFile8"] = x.get_validation_file8();
        j["ValidationFile9"] = x.get_validation_file9();
    }

    inline void from_json(const json & j, coup::ModelFilesModelFacilities& x) {
        x.set_technical(j.at("Technical").get<coup::PurpleTechnical>());
    }

    inline void to_json(json & j, const coup::ModelFilesModelFacilities & x) {
        j = json::object();
        j["Technical"] = x.get_technical();
    }

    inline void from_json(const json & j, coup::PurpleExternalNinputs& x) {
        x.set_manure(j.at("Manure").get<coup::Meteorologicaldata>());
        x.set_n_deposition_file(j.at("NDepositionFile").get<coup::Meteorologicaldata>());
    }

    inline void to_json(json & j, const coup::PurpleExternalNinputs & x) {
        j = json::object();
        j["Manure"] = x.get_manure();
        j["NDepositionFile"] = x.get_n_deposition_file();
    }

    inline void from_json(const json & j, coup::PurplePlantGrowth& x) {
        x.set_grazing_periods(j.at("GrazingPeriods").get<coup::Meteorologicaldata>());
        x.set_harvestdatedata(j.at("Harvestdatedata").get<coup::Meteorologicaldata>());
        x.set_plant_biomassdata(j.at("PlantBiomassdata").get<coup::Meteorologicaldata>());
    }

    inline void to_json(json & j, const coup::PurplePlantGrowth & x) {
        j = json::object();
        j["GrazingPeriods"] = x.get_grazing_periods();
        j["Harvestdatedata"] = x.get_harvestdatedata();
        j["PlantBiomassdata"] = x.get_plant_biomassdata();
    }

    inline void from_json(const json & j, coup::ModelFilesNitrogenandCarbon& x) {
        x.set_external_ninputs(j.at("ExternalNinputs").get<coup::PurpleExternalNinputs>());
        x.set_plant_growth(j.at("PlantGrowth").get<coup::PurplePlantGrowth>());
    }

    inline void to_json(json & j, const coup::ModelFilesNitrogenandCarbon & x) {
        j = json::object();
        j["ExternalNinputs"] = x.get_external_ninputs();
        j["PlantGrowth"] = x.get_plant_growth();
    }

    inline void from_json(const json & j, coup::PurpleAbioticdrivingvariables& x) {
        x.set_abioticsoildata(j.at("Abioticsoildata").get<coup::Meteorologicaldata>());
        x.set_green_index(j.at("GreenIndex").get<coup::HeatPumpdata>());
    }

    inline void to_json(json & j, const coup::PurpleAbioticdrivingvariables & x) {
        j = json::object();
        j["Abioticsoildata"] = x.get_abioticsoildata();
        j["GreenIndex"] = x.get_green_index();
    }

    inline void from_json(const json & j, coup::ModelFilesNitrogenandCarbonBelowGround& x) {
        x.set_abioticdrivingvariables(j.at("Abioticdrivingvariables").get<coup::PurpleAbioticdrivingvariables>());
    }

    inline void to_json(json & j, const coup::ModelFilesNitrogenandCarbonBelowGround & x) {
        j = json::object();
        j["Abioticdrivingvariables"] = x.get_abioticdrivingvariables();
    }

    inline void from_json(const json & j, coup::PurplePlant& x) {
        x.set_cropdata(j.at("Cropdata").get<coup::HeatPumpdata>());
    }

    inline void to_json(json & j, const coup::PurplePlant & x) {
        j = json::object();
        j["Cropdata"] = x.get_cropdata();
    }

    inline void from_json(const json & j, coup::SaltRoadDeposition& x) {
        x.set_condition_1(j.at("Condition_1").get<coup::Condition3Enum>());
        x.set_condition_2(j.at("Condition_2").get<coup::Condition2Enum>());
        x.set_condition_3(j.at("Condition_3").get<coup::Condition3Enum>());
        x.set_condition_4(j.at("Condition_4").get<std::string>());
        x.set_pf_file(j.at("PF_File").get<std::string>());
    }

    inline void to_json(json & j, const coup::SaltRoadDeposition & x) {
        j = json::object();
        j["Condition_1"] = x.get_condition_1();
        j["Condition_2"] = x.get_condition_2();
        j["Condition_3"] = x.get_condition_3();
        j["Condition_4"] = x.get_condition_4();
        j["PF_File"] = x.get_pf_file();
    }

    inline void from_json(const json & j, coup::PurpleSaltTracer& x) {
        x.set_salt_road_deposition(j.at("SaltRoadDeposition").get<coup::SaltRoadDeposition>());
    }

    inline void to_json(json & j, const coup::PurpleSaltTracer & x) {
        j = json::object();
        j["SaltRoadDeposition"] = x.get_salt_road_deposition();
    }

    inline void from_json(const json & j, coup::ModelFilesPlantWaterProcesses& x) {
        x.set_plant(j.at("Plant").get<coup::PurplePlant>());
        x.set_salt_tracer(j.at("SaltTracer").get<coup::PurpleSaltTracer>());
    }

    inline void to_json(json & j, const coup::ModelFilesPlantWaterProcesses & x) {
        j = json::object();
        j["Plant"] = x.get_plant();
        j["SaltTracer"] = x.get_salt_tracer();
    }

    inline void from_json(const json & j, coup::PurpleDrainageanddeeppercolation& x) {
        x.set_groundwaterlevel(j.at("Groundwaterlevel").get<coup::HeatPumpdata>());
        x.set_pressuredheadat_lowerboundary(j.at("PressuredheadatLowerboundary").get<coup::HeatPumpdata>());
    }

    inline void to_json(json & j, const coup::PurpleDrainageanddeeppercolation & x) {
        j = json::object();
        j["Groundwaterlevel"] = x.get_groundwaterlevel();
        j["PressuredheadatLowerboundary"] = x.get_pressuredheadat_lowerboundary();
    }

    inline void from_json(const json & j, coup::ModelFilesSoilWaterProcesses& x) {
        x.set_drainageanddeeppercolation(j.at("Drainageanddeeppercolation").get<coup::PurpleDrainageanddeeppercolation>());
    }

    inline void to_json(json & j, const coup::ModelFilesSoilWaterProcesses & x) {
        j = json::object();
        j["Drainageanddeeppercolation"] = x.get_drainageanddeeppercolation();
    }

    inline void from_json(const json & j, coup::ModelFiles& x) {
        x.set_atmospheric_related_processes(j.at("AtmosphericRelatedProcesses").get<coup::ModelFilesAtmosphericRelatedProcesses>());
        x.set_model_facilities(j.at("ModelFacilities").get<coup::ModelFilesModelFacilities>());
        x.set_nitrogenand_carbon(j.at("NitrogenandCarbon").get<coup::ModelFilesNitrogenandCarbon>());
        x.set_nitrogenand_carbon_below_ground(j.at("NitrogenandCarbon-BelowGround").get<coup::ModelFilesNitrogenandCarbonBelowGround>());
        x.set_plant_water_processes(j.at("PlantWaterProcesses").get<coup::ModelFilesPlantWaterProcesses>());
        x.set_soil_water_processes(j.at("SoilWaterProcesses").get<coup::ModelFilesSoilWaterProcesses>());
    }

    inline void to_json(json & j, const coup::ModelFiles & x) {
        j = json::object();
        j["AtmosphericRelatedProcesses"] = x.get_atmospheric_related_processes();
        j["ModelFacilities"] = x.get_model_facilities();
        j["NitrogenandCarbon"] = x.get_nitrogenand_carbon();
        j["NitrogenandCarbon-BelowGround"] = x.get_nitrogenand_carbon_below_ground();
        j["PlantWaterProcesses"] = x.get_plant_water_processes();
        j["SoilWaterProcesses"] = x.get_soil_water_processes();
    }

    inline void from_json(const json & j, coup::PrecInput& x) {
        x.set_condition_1(coup::get_optional<std::string>(j, "Condition_1"));
        x.set_condition_2(coup::get_optional<std::string>(j, "Condition_2"));
        x.set_condition_3(coup::get_optional<std::string>(j, "Condition_3"));
        x.set_condition_4(coup::get_optional<std::string>(j, "Condition_4"));
        x.set_condition_5(coup::get_optional<std::string>(j, "Condition_5"));
        x.set_current(j.at("Current").get<std::string>());
        x.set_prec_input_default(j.at("Default").get<std::string>());
        x.set_max(coup::get_optional<std::string>(j, "Max"));
        x.set_min(coup::get_optional<std::string>(j, "Min"));
        x.set_opt_0(coup::get_optional<std::string>(j, "Opt_0"));
        x.set_opt_1(coup::get_optional<std::string>(j, "Opt_1"));
        x.set_opt_2(coup::get_optional<std::string>(j, "Opt_2"));
        x.set_opt_3(coup::get_optional<std::string>(j, "Opt_3"));
    }

    inline void to_json(json & j, const coup::PrecInput & x) {
        j = json::object();
        j["Condition_1"] = x.get_condition_1();
        j["Condition_2"] = x.get_condition_2();
        j["Condition_3"] = x.get_condition_3();
        j["Condition_4"] = x.get_condition_4();
        j["Condition_5"] = x.get_condition_5();
        j["Current"] = x.get_current();
        j["Default"] = x.get_prec_input_default();
        j["Max"] = x.get_max();
        j["Min"] = x.get_min();
        j["Opt_0"] = x.get_opt_0();
        j["Opt_1"] = x.get_opt_1();
        j["Opt_2"] = x.get_opt_2();
        j["Opt_3"] = x.get_opt_3();
    }

    inline void from_json(const json & j, coup::FluffyMeteorologicalData& x) {
        x.set_prec_input(j.at("PrecInput").get<coup::PrecInput>());
        x.set_rad_glob_input(j.at("RadGlobInput").get<coup::PrecInput>());
        x.set_temp_air_input(j.at("TempAirInput").get<coup::PrecInput>());
    }

    inline void to_json(json & j, const coup::FluffyMeteorologicalData & x) {
        j = json::object();
        j["PrecInput"] = x.get_prec_input();
        j["RadGlobInput"] = x.get_rad_glob_input();
        j["TempAirInput"] = x.get_temp_air_input();
    }

    inline void from_json(const json & j, coup::PurpleRadiationproperties& x) {
        x.set_radiation_input(j.at("RadiationInput").get<coup::PrecInput>());
    }

    inline void to_json(json & j, const coup::PurpleRadiationproperties & x) {
        j = json::object();
        j["RadiationInput"] = x.get_radiation_input();
    }

    inline void from_json(const json & j, coup::EvaporationMethod& x) {
        x.set_condition_1(coup::get_optional<coup::Condition3Enum>(j, "Condition_1"));
        x.set_condition_2(coup::get_optional<std::string>(j, "Condition_2"));
        x.set_condition_3(coup::get_optional<std::string>(j, "Condition_3"));
        x.set_condition_4(coup::get_optional<std::string>(j, "Condition_4"));
        x.set_current(j.at("Current").get<std::string>());
        x.set_evaporation_method_default(j.at("Default").get<std::string>());
        x.set_max(coup::get_optional<std::string>(j, "Max"));
        x.set_min(coup::get_optional<std::string>(j, "Min"));
        x.set_opt_0(coup::get_optional<std::string>(j, "Opt_0"));
        x.set_opt_1(coup::get_optional<std::string>(j, "Opt_1"));
        x.set_opt_2(coup::get_optional<std::string>(j, "Opt_2"));
        x.set_opt_3(coup::get_optional<std::string>(j, "Opt_3"));
        x.set_opt_4(coup::get_optional<std::string>(j, "Opt_4"));
    }

    inline void to_json(json & j, const coup::EvaporationMethod & x) {
        j = json::object();
        j["Condition_1"] = x.get_condition_1();
        j["Condition_2"] = x.get_condition_2();
        j["Condition_3"] = x.get_condition_3();
        j["Condition_4"] = x.get_condition_4();
        j["Current"] = x.get_current();
        j["Default"] = x.get_evaporation_method_default();
        j["Max"] = x.get_max();
        j["Min"] = x.get_min();
        j["Opt_0"] = x.get_opt_0();
        j["Opt_1"] = x.get_opt_1();
        j["Opt_2"] = x.get_opt_2();
        j["Opt_3"] = x.get_opt_3();
        j["Opt_4"] = x.get_opt_4();
    }

    inline void from_json(const json & j, coup::PurpleSoilevaporation& x) {
        x.set_evaporation_method(j.at("EvaporationMethod").get<coup::EvaporationMethod>());
        x.set_surface_temperature(j.at("SurfaceTemperature").get<coup::EvaporationMethod>());
    }

    inline void to_json(json & j, const coup::PurpleSoilevaporation & x) {
        j = json::object();
        j["EvaporationMethod"] = x.get_evaporation_method();
        j["SurfaceTemperature"] = x.get_surface_temperature();
    }

    inline void from_json(const json & j, coup::ModelOptionsAtmosphericRelatedProcesses& x) {
        x.set_meteorological_data(j.at("MeteorologicalData").get<coup::FluffyMeteorologicalData>());
        x.set_radiationproperties(j.at("Radiationproperties").get<coup::PurpleRadiationproperties>());
        x.set_soilevaporation(j.at("Soilevaporation").get<coup::PurpleSoilevaporation>());
    }

    inline void to_json(json & j, const coup::ModelOptionsAtmosphericRelatedProcesses & x) {
        j = json::object();
        j["MeteorologicalData"] = x.get_meteorological_data();
        j["Radiationproperties"] = x.get_radiationproperties();
        j["Soilevaporation"] = x.get_soilevaporation();
    }

    inline void from_json(const json & j, coup::FluffyTechnical& x) {
        x.set_time_resolution(j.at("TimeResolution").get<coup::PrecInput>());
        x.set_type_of_driving_file(j.at("TypeOfDrivingFile").get<coup::PrecInput>());
    }

    inline void to_json(json & j, const coup::FluffyTechnical & x) {
        j = json::object();
        j["TimeResolution"] = x.get_time_resolution();
        j["TypeOfDrivingFile"] = x.get_type_of_driving_file();
    }

    inline void from_json(const json & j, coup::ModelOptionsModelFacilities& x) {
        x.set_technical(j.at("Technical").get<coup::FluffyTechnical>());
    }

    inline void to_json(json & j, const coup::ModelOptionsModelFacilities & x) {
        j = json::object();
        j["Technical"] = x.get_technical();
    }

    inline void from_json(const json & j, coup::PurpleModelStructure& x) {
        x.set_evaporation(j.at("Evaporation").get<coup::EvaporationMethod>());
        x.set_ground_water_flow(j.at("GroundWaterFlow").get<coup::EvaporationMethod>());
        x.set_lateral_input(j.at("LateralInput").get<coup::EvaporationMethod>());
        x.set_plant_type(j.at("PlantType").get<coup::EvaporationMethod>());
        x.set_snow_pack(j.at("SnowPack").get<coup::EvaporationMethod>());
        x.set_water_eq(j.at("WaterEq").get<coup::EvaporationMethod>());
    }

    inline void to_json(json & j, const coup::PurpleModelStructure & x) {
        j = json::object();
        j["Evaporation"] = x.get_evaporation();
        j["GroundWaterFlow"] = x.get_ground_water_flow();
        j["LateralInput"] = x.get_lateral_input();
        j["PlantType"] = x.get_plant_type();
        j["SnowPack"] = x.get_snow_pack();
        j["WaterEq"] = x.get_water_eq();
    }

    inline void from_json(const json & j, coup::ModelOptionsModelStructure& x) {
        x.set_model_structure(j.at("ModelStructure").get<coup::PurpleModelStructure>());
    }

    inline void to_json(json & j, const coup::ModelOptionsModelStructure & x) {
        j = json::object();
        j["ModelStructure"] = x.get_model_structure();
    }

    inline void from_json(const json & j, coup::PurpleInterception& x) {
        x.set_prec_interception(j.at("PrecInterception").get<coup::PrecInput>());
    }

    inline void to_json(json & j, const coup::PurpleInterception & x) {
        j = json::object();
        j["PrecInterception"] = x.get_prec_interception();
    }

    inline void from_json(const json & j, coup::PurpleWateruptake& x) {
        x.set_demand_redistribution(j.at("DemandRedistribution").get<coup::EvaporationMethod>());
    }

    inline void to_json(json & j, const coup::PurpleWateruptake & x) {
        j = json::object();
        j["DemandRedistribution"] = x.get_demand_redistribution();
    }

    inline void from_json(const json & j, coup::ModelOptionsPlantWaterProcesses& x) {
        x.set_interception(j.at("Interception").get<coup::PurpleInterception>());
        x.set_wateruptake(j.at("Wateruptake").get<coup::PurpleWateruptake>());
    }

    inline void to_json(json & j, const coup::ModelOptionsPlantWaterProcesses & x) {
        j = json::object();
        j["Interception"] = x.get_interception();
        j["Wateruptake"] = x.get_wateruptake();
    }

    inline void from_json(const json & j, coup::FluffyDrainageanddeeppercolation& x) {
        x.set_empirical_drain_eq(j.at("EmpiricalDrainEq").get<coup::PrecInput>());
        x.set_lateral_gw_source(j.at("LateralGWSource").get<coup::PrecInput>());
        x.set_physical_drain_eq(j.at("PhysicalDrainEq").get<coup::PrecInput>());
    }

    inline void to_json(json & j, const coup::FluffyDrainageanddeeppercolation & x) {
        j = json::object();
        j["EmpiricalDrainEq"] = x.get_empirical_drain_eq();
        j["LateralGWSource"] = x.get_lateral_gw_source();
        j["PhysicalDrainEq"] = x.get_physical_drain_eq();
    }

    inline void from_json(const json & j, coup::PurpleSurfacewater& x) {
        x.set_run_on_input(j.at("RunOnInput").get<coup::EvaporationMethod>());
    }

    inline void to_json(json & j, const coup::PurpleSurfacewater & x) {
        j = json::object();
        j["RunOnInput"] = x.get_run_on_input();
    }

    inline void from_json(const json & j, coup::ModelOptionsSoilWaterProcesses& x) {
        x.set_drainageanddeeppercolation(j.at("Drainageanddeeppercolation").get<coup::FluffyDrainageanddeeppercolation>());
        x.set_surfacewater(j.at("Surfacewater").get<coup::PurpleSurfacewater>());
    }

    inline void to_json(json & j, const coup::ModelOptionsSoilWaterProcesses & x) {
        j = json::object();
        j["Drainageanddeeppercolation"] = x.get_drainageanddeeppercolation();
        j["Surfacewater"] = x.get_surfacewater();
    }

    inline void from_json(const json & j, coup::ModelOptions& x) {
        x.set_atmospheric_related_processes(j.at("AtmosphericRelatedProcesses").get<coup::ModelOptionsAtmosphericRelatedProcesses>());
        x.set_model_facilities(j.at("ModelFacilities").get<coup::ModelOptionsModelFacilities>());
        x.set_model_structure(j.at("ModelStructure").get<coup::ModelOptionsModelStructure>());
        x.set_plant_water_processes(j.at("PlantWaterProcesses").get<coup::ModelOptionsPlantWaterProcesses>());
        x.set_soil_water_processes(j.at("SoilWaterProcesses").get<coup::ModelOptionsSoilWaterProcesses>());
    }

    inline void to_json(json & j, const coup::ModelOptions & x) {
        j = json::object();
        j["AtmosphericRelatedProcesses"] = x.get_atmospheric_related_processes();
        j["ModelFacilities"] = x.get_model_facilities();
        j["ModelStructure"] = x.get_model_structure();
        j["PlantWaterProcesses"] = x.get_plant_water_processes();
        j["SoilWaterProcesses"] = x.get_soil_water_processes();
    }

    inline void from_json(const json & j, coup::AlbedoVar& x) {
        x.set_condition_1(j.at("Condition_1").get<coup::Condition3Enum>());
        x.set_condition_2(coup::get_optional<std::string>(j, "Condition_2"));
        x.set_condition_3(coup::get_optional<std::string>(j, "Condition_3"));
        x.set_condition_4(coup::get_optional<std::string>(j, "Condition_4"));
        x.set_condition_5(coup::get_optional<std::string>(j, "Condition_5"));
        x.set_condition_6(coup::get_optional<std::string>(j, "Condition_6"));
        x.set_out_multi(j.at("OutMulti").get<std::string>());
        x.set_out_single(j.at("OutSingle").get<std::string>());
    }

    inline void to_json(json & j, const coup::AlbedoVar & x) {
        j = json::object();
        j["Condition_1"] = x.get_condition_1();
        j["Condition_2"] = x.get_condition_2();
        j["Condition_3"] = x.get_condition_3();
        j["Condition_4"] = x.get_condition_4();
        j["Condition_5"] = x.get_condition_5();
        j["Condition_6"] = x.get_condition_6();
        j["OutMulti"] = x.get_out_multi();
        j["OutSingle"] = x.get_out_single();
    }

    inline void from_json(const json & j, coup::CanopyFracRadDiffuse& x) {
        x.set_condition_1(j.at("Condition_1").get<std::string>());
        x.set_condition_2(coup::get_optional<std::string>(j, "Condition_2"));
        x.set_condition_3(coup::get_optional<std::string>(j, "Condition_3"));
        x.set_condition_4(coup::get_optional<std::string>(j, "Condition_4"));
        x.set_condition_5(coup::get_optional<coup::Condition2Enum>(j, "Condition_5"));
        x.set_out_multi(j.at("OutMulti").get<std::string>());
        x.set_out_single(j.at("OutSingle").get<std::string>());
    }

    inline void to_json(json & j, const coup::CanopyFracRadDiffuse & x) {
        j = json::object();
        j["Condition_1"] = x.get_condition_1();
        j["Condition_2"] = x.get_condition_2();
        j["Condition_3"] = x.get_condition_3();
        j["Condition_4"] = x.get_condition_4();
        j["Condition_5"] = x.get_condition_5();
        j["OutMulti"] = x.get_out_multi();
        j["OutSingle"] = x.get_out_single();
    }

    inline void from_json(const json & j, coup::FluffyRadiationproperties& x) {
        x.set_albedo_var(j.at("AlbedoVar").get<coup::AlbedoVar>());
        x.set_canopy_frac_rad(j.at("CanopyFracRad").get<coup::AlbedoVar>());
        x.set_canopy_frac_rad1(j.at("CanopyFracRad1").get<coup::AlbedoVar>());
        x.set_canopy_frac_rad2(j.at("CanopyFracRad2").get<coup::AlbedoVar>());
        x.set_canopy_frac_rad_diffuse(j.at("CanopyFracRadDiffuse").get<coup::CanopyFracRadDiffuse>());
        x.set_canopy_frac_rad_direct(j.at("CanopyFracRadDirect").get<coup::CanopyFracRadDiffuse>());
        x.set_canopy_frac_rad_long(j.at("CanopyFracRadLong").get<coup::CanopyFracRadDiffuse>());
        x.set_ground_albedo(j.at("GroundAlbedo").get<coup::AlbedoVar>());
        x.set_rad_in_diffuse(j.at("RadInDiffuse").get<coup::AlbedoVar>());
        x.set_rad_in_direct(j.at("RadInDirect").get<coup::AlbedoVar>());
        x.set_rad_in_long_ground(j.at("RadInLongGround").get<coup::AlbedoVar>());
        x.set_rad_in_long_ground1(j.at("RadInLongGround1").get<coup::AlbedoVar>());
        x.set_rad_in_long_ground2(j.at("RadInLongGround2").get<coup::AlbedoVar>());
        x.set_rad_in_short_ground(j.at("RadInShortGround").get<coup::AlbedoVar>());
        x.set_rad_long_out(j.at("RadLongOut").get<coup::AlbedoVar>());
        x.set_rad_net_canopy(j.at("RadNetCanopy").get<coup::AlbedoVar>());
        x.set_rad_net_ground(j.at("RadNetGround").get<coup::AlbedoVar>());
        x.set_rad_net_ground1(j.at("RadNetGround1").get<coup::AlbedoVar>());
        x.set_rad_net_ground2(j.at("RadNetGround2").get<coup::AlbedoVar>());
        x.set_rad_net_long_canopy(j.at("RadNetLongCanopy").get<coup::AlbedoVar>());
        x.set_rad_net_long_ground(j.at("RadNetLongGround").get<coup::AlbedoVar>());
        x.set_rad_net_short(j.at("RadNetShort").get<coup::AlbedoVar>());
        x.set_rad_net_short_canopy(j.at("RadNetShortCanopy").get<coup::AlbedoVar>());
        x.set_rad_net_short_ground(j.at("RadNetShortGround").get<coup::AlbedoVar>());
        x.set_rad_short_out(j.at("RadShortOut").get<coup::AlbedoVar>());
        x.set_snow_albedo(j.at("SnowAlbedo").get<coup::AlbedoVar>());
        x.set_soil_albedo(j.at("SoilAlbedo").get<coup::AlbedoVar>());
    }

    inline void to_json(json & j, const coup::FluffyRadiationproperties & x) {
        j = json::object();
        j["AlbedoVar"] = x.get_albedo_var();
        j["CanopyFracRad"] = x.get_canopy_frac_rad();
        j["CanopyFracRad1"] = x.get_canopy_frac_rad1();
        j["CanopyFracRad2"] = x.get_canopy_frac_rad2();
        j["CanopyFracRadDiffuse"] = x.get_canopy_frac_rad_diffuse();
        j["CanopyFracRadDirect"] = x.get_canopy_frac_rad_direct();
        j["CanopyFracRadLong"] = x.get_canopy_frac_rad_long();
        j["GroundAlbedo"] = x.get_ground_albedo();
        j["RadInDiffuse"] = x.get_rad_in_diffuse();
        j["RadInDirect"] = x.get_rad_in_direct();
        j["RadInLongGround"] = x.get_rad_in_long_ground();
        j["RadInLongGround1"] = x.get_rad_in_long_ground1();
        j["RadInLongGround2"] = x.get_rad_in_long_ground2();
        j["RadInShortGround"] = x.get_rad_in_short_ground();
        j["RadLongOut"] = x.get_rad_long_out();
        j["RadNetCanopy"] = x.get_rad_net_canopy();
        j["RadNetGround"] = x.get_rad_net_ground();
        j["RadNetGround1"] = x.get_rad_net_ground1();
        j["RadNetGround2"] = x.get_rad_net_ground2();
        j["RadNetLongCanopy"] = x.get_rad_net_long_canopy();
        j["RadNetLongGround"] = x.get_rad_net_long_ground();
        j["RadNetShort"] = x.get_rad_net_short();
        j["RadNetShortCanopy"] = x.get_rad_net_short_canopy();
        j["RadNetShortGround"] = x.get_rad_net_short_ground();
        j["RadShortOut"] = x.get_rad_short_out();
        j["SnowAlbedo"] = x.get_snow_albedo();
        j["SoilAlbedo"] = x.get_soil_albedo();
    }

    inline void from_json(const json & j, coup::AuxiliaryAtmosphericRelatedProcesses& x) {
        x.set_radiationproperties(j.at("Radiationproperties").get<coup::FluffyRadiationproperties>());
        x.set_snow_pack(j.at("SnowPack").get<std::map<std::string, coup::AlbedoVar>>());
        x.set_soilevaporation(j.at("Soilevaporation").get<std::map<std::string, coup::CanopyFracRadDiffuse>>());
    }

    inline void to_json(json & j, const coup::AuxiliaryAtmosphericRelatedProcesses & x) {
        j = json::object();
        j["Radiationproperties"] = x.get_radiationproperties();
        j["SnowPack"] = x.get_snow_pack();
        j["Soilevaporation"] = x.get_soilevaporation();
    }

    inline void from_json(const json & j, coup::FluffyModelStructure& x) {
        x.set_timestep(j.at("Timestep").get<coup::AlbedoVar>());
    }

    inline void to_json(json & j, const coup::FluffyModelStructure & x) {
        j = json::object();
        j["Timestep"] = x.get_timestep();
    }

    inline void from_json(const json & j, coup::AuxiliaryModelStructure& x) {
        x.set_model_structure(j.at("ModelStructure").get<coup::FluffyModelStructure>());
    }

    inline void to_json(json & j, const coup::AuxiliaryModelStructure & x) {
        j = json::object();
        j["ModelStructure"] = x.get_model_structure();
    }

    inline void from_json(const json & j, coup::FluffyExternalNinputs& x) {
        x.set_n_irrig_appl_rate(j.at("NIrrigApplRate").get<coup::CanopyFracRadDiffuse>());
        x.set_total_deposition_n_leaf(j.at("TotalDepositionNLeaf").get<coup::CanopyFracRadDiffuse>());
    }

    inline void to_json(json & j, const coup::FluffyExternalNinputs & x) {
        j = json::object();
        j["NIrrigApplRate"] = x.get_n_irrig_appl_rate();
        j["TotalDepositionNLeaf"] = x.get_total_deposition_n_leaf();
    }

    inline void from_json(const json & j, coup::AuxiliaryNitrogenandCarbon& x) {
        x.set_external_ninputs(j.at("ExternalNinputs").get<coup::FluffyExternalNinputs>());
        x.set_plant_growth(j.at("PlantGrowth").get<std::map<std::string, coup::AlbedoVar>>());
    }

    inline void to_json(json & j, const coup::AuxiliaryNitrogenandCarbon & x) {
        j = json::object();
        j["ExternalNinputs"] = x.get_external_ninputs();
        j["PlantGrowth"] = x.get_plant_growth();
    }

    inline void from_json(const json & j, coup::PurpleSoilmineralPProcesses& x) {
        x.set_p_conc_po4_drainage(j.at("PConcPO4Drainage").get<coup::CanopyFracRadDiffuse>());
        x.set_p_tot_phosphate_soil(j.at("PTotPhosphateSoil").get<coup::CanopyFracRadDiffuse>());
        x.set_p_tot_po4_drainage(j.at("PTotPO4Drainage").get<coup::CanopyFracRadDiffuse>());
        x.set_p_tot_po4_plant_uptake(j.at("PTotPO4PlantUptake").get<coup::CanopyFracRadDiffuse>());
        x.set_p_tot_solid_pminerals(j.at("PTotSolidPminerals").get<coup::CanopyFracRadDiffuse>());
        x.set_p_tot_weathering_soil(j.at("PTotWeatheringSoil").get<coup::CanopyFracRadDiffuse>());
        x.set_tot_min_p_drainage_conc(j.at("TotMinPDrainageConc").get<coup::CanopyFracRadDiffuse>());
    }

    inline void to_json(json & j, const coup::PurpleSoilmineralPProcesses & x) {
        j = json::object();
        j["PConcPO4Drainage"] = x.get_p_conc_po4_drainage();
        j["PTotPhosphateSoil"] = x.get_p_tot_phosphate_soil();
        j["PTotPO4Drainage"] = x.get_p_tot_po4_drainage();
        j["PTotPO4PlantUptake"] = x.get_p_tot_po4_plant_uptake();
        j["PTotSolidPminerals"] = x.get_p_tot_solid_pminerals();
        j["PTotWeatheringSoil"] = x.get_p_tot_weathering_soil();
        j["TotMinPDrainageConc"] = x.get_tot_min_p_drainage_conc();
    }

    inline void from_json(const json & j, coup::AuxiliaryNitrogenandCarbonBelowGround& x) {
        x.set_gasprocesses(j.at("Gasprocesses").get<std::map<std::string, coup::CanopyFracRadDiffuse>>());
        x.set_soilmineral_nprocesses(j.at("SoilmineralNprocesses").get<std::map<std::string, coup::AlbedoVar>>());
        x.set_soilmineral_p_processes(j.at("SoilmineralPProcesses").get<coup::PurpleSoilmineralPProcesses>());
        x.set_soilorganicprocesses(j.at("Soilorganicprocesses").get<std::map<std::string, coup::AlbedoVar>>());
    }

    inline void to_json(json & j, const coup::AuxiliaryNitrogenandCarbonBelowGround & x) {
        j = json::object();
        j["Gasprocesses"] = x.get_gasprocesses();
        j["SoilmineralNprocesses"] = x.get_soilmineral_nprocesses();
        j["SoilmineralPProcesses"] = x.get_soilmineral_p_processes();
        j["Soilorganicprocesses"] = x.get_soilorganicprocesses();
    }

    inline void from_json(const json & j, coup::FluffyInterception& x) {
        x.set_intercepted_water_th_q(j.at("InterceptedWaterThQ").get<coup::CanopyFracRadDiffuse>());
        x.set_interception_act_eva(j.at("InterceptionActEva").get<coup::CanopyFracRadDiffuse>());
        x.set_interception_capacity(j.at("InterceptionCapacity").get<coup::CanopyFracRadDiffuse>());
        x.set_interception_pot_eva(j.at("InterceptionPotEva").get<coup::CanopyFracRadDiffuse>());
        x.set_interception_rate(j.at("InterceptionRate").get<coup::CanopyFracRadDiffuse>());
        x.set_interception_storage(j.at("InterceptionStorage").get<coup::CanopyFracRadDiffuse>());
        x.set_throughfall(j.at("Throughfall").get<coup::CanopyFracRadDiffuse>());
    }

    inline void to_json(json & j, const coup::FluffyInterception & x) {
        j = json::object();
        j["InterceptedWaterThQ"] = x.get_intercepted_water_th_q();
        j["InterceptionActEva"] = x.get_interception_act_eva();
        j["InterceptionCapacity"] = x.get_interception_capacity();
        j["InterceptionPotEva"] = x.get_interception_pot_eva();
        j["InterceptionRate"] = x.get_interception_rate();
        j["InterceptionStorage"] = x.get_interception_storage();
        j["Throughfall"] = x.get_throughfall();
    }

    inline void from_json(const json & j, coup::FluffyPlant& x) {
        x.set_leaf_area_index_sum(j.at("LeafAreaIndexSum").get<coup::AlbedoVar>());
        x.set_root_length_total(j.at("RootLength_Total").get<coup::AlbedoVar>());
        x.set_tot_soil_cover_fraction(j.at("TotSoilCoverFraction").get<coup::AlbedoVar>());
        x.set_tsum_plant(j.at("TsumPlant").get<coup::AlbedoVar>());
    }

    inline void to_json(json & j, const coup::FluffyPlant & x) {
        j = json::object();
        j["LeafAreaIndexSum"] = x.get_leaf_area_index_sum();
        j["RootLength_Total"] = x.get_root_length_total();
        j["TotSoilCoverFraction"] = x.get_tot_soil_cover_fraction();
        j["TsumPlant"] = x.get_tsum_plant();
    }

    inline void from_json(const json & j, coup::PurplePotentialTranspiration& x) {
        x.set_canopy_height(j.at("CanopyHeight").get<coup::CanopyFracRadDiffuse>());
        x.set_displacement_height(j.at("DisplacementHeight").get<coup::CanopyFracRadDiffuse>());
        x.set_resist_air_mean(j.at("ResistAirMean").get<coup::CanopyFracRadDiffuse>());
        x.set_res_surf_vegetation(j.at("ResSurfVegetation").get<coup::CanopyFracRadDiffuse>());
        x.set_rough_length(j.at("RoughLength").get<coup::CanopyFracRadDiffuse>());
    }

    inline void to_json(json & j, const coup::PurplePotentialTranspiration & x) {
        j = json::object();
        j["CanopyHeight"] = x.get_canopy_height();
        j["DisplacementHeight"] = x.get_displacement_height();
        j["ResistAirMean"] = x.get_resist_air_mean();
        j["ResSurfVegetation"] = x.get_res_surf_vegetation();
        j["RoughLength"] = x.get_rough_length();
    }

    inline void from_json(const json & j, coup::FluffyWateruptake& x) {
        x.set_pot_water_uptake(j.at("PotWaterUptake").get<coup::CanopyFracRadDiffuse>());
        x.set_red_c_totalallplant(j.at("RedCTotalallplant").get<coup::CanopyFracRadDiffuse>());
        x.set_transpirationallpl(j.at("Transpirationallpl").get<coup::CanopyFracRadDiffuse>());
        x.set_water_uptake_trig_temp(j.at("WaterUptakeTrigTemp").get<coup::CanopyFracRadDiffuse>());
    }

    inline void to_json(json & j, const coup::FluffyWateruptake & x) {
        j = json::object();
        j["PotWaterUptake"] = x.get_pot_water_uptake();
        j["RedCTotalallplant"] = x.get_red_c_totalallplant();
        j["Transpirationallpl"] = x.get_transpirationallpl();
        j["WaterUptakeTrigTemp"] = x.get_water_uptake_trig_temp();
    }

    inline void from_json(const json & j, coup::AuxiliaryPlantWaterProcesses& x) {
        x.set_interception(j.at("Interception").get<coup::FluffyInterception>());
        x.set_plant(j.at("Plant").get<coup::FluffyPlant>());
        x.set_potential_transpiration(j.at("PotentialTranspiration").get<coup::PurplePotentialTranspiration>());
        x.set_salt_tracer(j.at("SaltTracer").get<std::map<std::string, coup::AlbedoVar>>());
        x.set_wateruptake(j.at("Wateruptake").get<coup::FluffyWateruptake>());
    }

    inline void to_json(json & j, const coup::AuxiliaryPlantWaterProcesses & x) {
        j = json::object();
        j["Interception"] = x.get_interception();
        j["Plant"] = x.get_plant();
        j["PotentialTranspiration"] = x.get_potential_transpiration();
        j["SaltTracer"] = x.get_salt_tracer();
        j["Wateruptake"] = x.get_wateruptake();
    }

    inline void from_json(const json & j, coup::PurpleSoilfrost& x) {
        x.set_frost_lower_boundary1(j.at("FrostLowerBoundary1").get<coup::AlbedoVar>());
        x.set_frost_lower_boundary2(j.at("FrostLowerBoundary2").get<coup::AlbedoVar>());
        x.set_frost_upper_boundary1(j.at("FrostUpperBoundary1").get<coup::AlbedoVar>());
        x.set_frost_upper_boundary2(j.at("FrostUpperBoundary2").get<coup::AlbedoVar>());
        x.set_swelling(j.at("Swelling").get<coup::AlbedoVar>());
    }

    inline void to_json(json & j, const coup::PurpleSoilfrost & x) {
        j = json::object();
        j["FrostLowerBoundary1"] = x.get_frost_lower_boundary1();
        j["FrostLowerBoundary2"] = x.get_frost_lower_boundary2();
        j["FrostUpperBoundary1"] = x.get_frost_upper_boundary1();
        j["FrostUpperBoundary2"] = x.get_frost_upper_boundary2();
        j["Swelling"] = x.get_swelling();
    }

    inline void from_json(const json & j, coup::PurpleSoilheatflows& x) {
        x.set_heat_box_enhancer(j.at("HeatBoxEnhancer").get<coup::CanopyFracRadDiffuse>());
        x.set_temp_sewage(j.at("TempSewage").get<coup::CanopyFracRadDiffuse>());
        x.set_temp_soil_surf(j.at("TempSoilSurf").get<coup::CanopyFracRadDiffuse>());
    }

    inline void to_json(json & j, const coup::PurpleSoilheatflows & x) {
        j = json::object();
        j["HeatBoxEnhancer"] = x.get_heat_box_enhancer();
        j["TempSewage"] = x.get_temp_sewage();
        j["TempSoilSurf"] = x.get_temp_soil_surf();
    }

    inline void from_json(const json & j, coup::AuxiliarySoilHeatProcesses& x) {
        x.set_soilfrost(j.at("Soilfrost").get<coup::PurpleSoilfrost>());
        x.set_soilheatflows(j.at("Soilheatflows").get<coup::PurpleSoilheatflows>());
    }

    inline void to_json(json & j, const coup::AuxiliarySoilHeatProcesses & x) {
        j = json::object();
        j["Soilfrost"] = x.get_soilfrost();
        j["Soilheatflows"] = x.get_soilheatflows();
    }

    inline void from_json(const json & j, coup::TentacledDrainageanddeeppercolation& x) {
        x.set_saturation_level(j.at("SaturationLevel").get<coup::AlbedoVar>());
    }

    inline void to_json(json & j, const coup::TentacledDrainageanddeeppercolation & x) {
        j = json::object();
        j["SaturationLevel"] = x.get_saturation_level();
    }

    inline void from_json(const json & j, coup::PurpleSoilwaterflows& x) {
        x.set_tot_mean_transit_time(j.at("TotMeanTransitTime").get<coup::CanopyFracRadDiffuse>());
    }

    inline void to_json(json & j, const coup::PurpleSoilwaterflows & x) {
        j = json::object();
        j["TotMeanTransitTime"] = x.get_tot_mean_transit_time();
    }

    inline void from_json(const json & j, coup::FluffySurfacewater& x) {
        x.set_spool_cover(j.at("SpoolCover").get<coup::AlbedoVar>());
    }

    inline void to_json(json & j, const coup::FluffySurfacewater & x) {
        j = json::object();
        j["SpoolCover"] = x.get_spool_cover();
    }

    inline void from_json(const json & j, coup::AuxiliarySoilWaterProcesses& x) {
        x.set_drainageanddeeppercolation(j.at("Drainageanddeeppercolation").get<coup::TentacledDrainageanddeeppercolation>());
        x.set_soilwaterflows(j.at("Soilwaterflows").get<coup::PurpleSoilwaterflows>());
        x.set_surfacewater(j.at("Surfacewater").get<coup::FluffySurfacewater>());
    }

    inline void to_json(json & j, const coup::AuxiliarySoilWaterProcesses & x) {
        j = json::object();
        j["Drainageanddeeppercolation"] = x.get_drainageanddeeppercolation();
        j["Soilwaterflows"] = x.get_soilwaterflows();
        j["Surfacewater"] = x.get_surfacewater();
    }

    inline void from_json(const json & j, coup::Auxiliary& x) {
        x.set_atmospheric_related_processes(j.at("AtmosphericRelatedProcesses").get<coup::AuxiliaryAtmosphericRelatedProcesses>());
        x.set_model_structure(j.at("ModelStructure").get<coup::AuxiliaryModelStructure>());
        x.set_nitrogenand_carbon(j.at("NitrogenandCarbon").get<coup::AuxiliaryNitrogenandCarbon>());
        x.set_nitrogenand_carbon_below_ground(j.at("NitrogenandCarbon-BelowGround").get<coup::AuxiliaryNitrogenandCarbonBelowGround>());
        x.set_plant_water_processes(j.at("PlantWaterProcesses").get<coup::AuxiliaryPlantWaterProcesses>());
        x.set_soil_heat_processes(j.at("SoilHeatProcesses").get<coup::AuxiliarySoilHeatProcesses>());
        x.set_soil_water_processes(j.at("SoilWaterProcesses").get<coup::AuxiliarySoilWaterProcesses>());
    }

    inline void to_json(json & j, const coup::Auxiliary & x) {
        j = json::object();
        j["AtmosphericRelatedProcesses"] = x.get_atmospheric_related_processes();
        j["ModelStructure"] = x.get_model_structure();
        j["NitrogenandCarbon"] = x.get_nitrogenand_carbon();
        j["NitrogenandCarbon-BelowGround"] = x.get_nitrogenand_carbon_below_ground();
        j["PlantWaterProcesses"] = x.get_plant_water_processes();
        j["SoilHeatProcesses"] = x.get_soil_heat_processes();
        j["SoilWaterProcesses"] = x.get_soil_water_processes();
    }

    inline void from_json(const json & j, coup::LaiAbovecanopy& x) {
        x.set_array_name(j.at("ArrayName").get<coup::LaiAbovecanopyArrayName>());
        x.set_condition_1(j.at("Condition_1").get<coup::LaiAbovecanopyCondition1>());
        x.set_condition_2(coup::get_optional<std::string>(j, "Condition_2"));
        x.set_condition_3(coup::get_optional<std::string>(j, "Condition_3"));
        x.set_condition_4(coup::get_optional<std::string>(j, "Condition_4"));
        x.set_out_multi_index_1(j.at("OutMulti_Index_1").get<std::string>());
        x.set_out_single_index_1(j.at("OutSingle_Index_1").get<std::string>());
        x.set_sizeof_array(j.at("SizeofArray").get<std::string>());
    }

    inline void to_json(json & j, const coup::LaiAbovecanopy & x) {
        j = json::object();
        j["ArrayName"] = x.get_array_name();
        j["Condition_1"] = x.get_condition_1();
        j["Condition_2"] = x.get_condition_2();
        j["Condition_3"] = x.get_condition_3();
        j["Condition_4"] = x.get_condition_4();
        j["OutMulti_Index_1"] = x.get_out_multi_index_1();
        j["OutSingle_Index_1"] = x.get_out_single_index_1();
        j["SizeofArray"] = x.get_sizeof_array();
    }

    inline void from_json(const json & j, coup::TentacledRadiationproperties& x) {
        x.set_lai_abovecanopy(j.at("LAIAbovecanopy").get<coup::LaiAbovecanopy>());
        x.set_mc_temp_canopy(j.at("MCTempCanopy").get<coup::LaiAbovecanopy>());
        x.set_netradiation_canopy(j.at("NetradiationCanopy").get<coup::LaiAbovecanopy>());
    }

    inline void to_json(json & j, const coup::TentacledRadiationproperties & x) {
        j = json::object();
        j["LAIAbovecanopy"] = x.get_lai_abovecanopy();
        j["MCTempCanopy"] = x.get_mc_temp_canopy();
        j["NetradiationCanopy"] = x.get_netradiation_canopy();
    }

    inline void from_json(const json & j, coup::SnowReduceLaiFactor& x) {
        x.set_array_name(j.at("ArrayName").get<coup::LaiAbovecanopyArrayName>());
        x.set_condition_1(j.at("Condition_1").get<coup::Condition3Enum>());
        x.set_condition_2(coup::get_optional<coup::Condition2Enum>(j, "Condition_2"));
        x.set_condition_3(coup::get_optional<std::string>(j, "Condition_3"));
        x.set_condition_4(coup::get_optional<std::string>(j, "Condition_4"));
        x.set_condition_5(coup::get_optional<coup::Condition3Enum>(j, "Condition_5"));
        x.set_out_multi_index_1(j.at("OutMulti_Index_1").get<std::string>());
        x.set_out_single_index_1(j.at("OutSingle_Index_1").get<std::string>());
        x.set_sizeof_array(j.at("SizeofArray").get<std::string>());
    }

    inline void to_json(json & j, const coup::SnowReduceLaiFactor & x) {
        j = json::object();
        j["ArrayName"] = x.get_array_name();
        j["Condition_1"] = x.get_condition_1();
        j["Condition_2"] = x.get_condition_2();
        j["Condition_3"] = x.get_condition_3();
        j["Condition_4"] = x.get_condition_4();
        j["Condition_5"] = x.get_condition_5();
        j["OutMulti_Index_1"] = x.get_out_multi_index_1();
        j["OutSingle_Index_1"] = x.get_out_single_index_1();
        j["SizeofArray"] = x.get_sizeof_array();
    }

    inline void from_json(const json & j, coup::PurpleSnowPack& x) {
        x.set_snow_reduce_lai_factor(j.at("SnowReduceLAIFactor").get<coup::SnowReduceLaiFactor>());
    }

    inline void to_json(json & j, const coup::PurpleSnowPack & x) {
        j = json::object();
        j["SnowReduceLAIFactor"] = x.get_snow_reduce_lai_factor();
    }

    inline void from_json(const json & j, coup::AuxiliaryArraysAtmosphericRelatedProcesses& x) {
        x.set_radiationproperties(j.at("Radiationproperties").get<coup::TentacledRadiationproperties>());
        x.set_snow_pack(j.at("SnowPack").get<coup::PurpleSnowPack>());
    }

    inline void to_json(json & j, const coup::AuxiliaryArraysAtmosphericRelatedProcesses & x) {
        j = json::object();
        j["Radiationproperties"] = x.get_radiationproperties();
        j["SnowPack"] = x.get_snow_pack();
    }

    inline void from_json(const json & j, coup::CCoarseRootsAtmLayer& x) {
        x.set_array_name(j.at("ArrayName").get<coup::CCoarseRootsAtmLayerArrayName>());
        x.set_condition_1(j.at("Condition_1").get<coup::Condition3Enum>());
        x.set_condition_2(coup::get_optional<std::string>(j, "Condition_2"));
        x.set_condition_3(coup::get_optional<std::string>(j, "Condition_3"));
        x.set_condition_4(coup::get_optional<std::string>(j, "Condition_4"));
        x.set_out_multi_index_1(j.at("OutMulti_Index_1").get<std::string>());
        x.set_out_multi_index_2(j.at("OutMulti_Index_2").get<std::string>());
        x.set_out_multi_index_3(j.at("OutMulti_Index_3").get<std::string>());
        x.set_out_multi_index_4(j.at("OutMulti_Index_4").get<std::string>());
        x.set_out_multi_index_5(j.at("OutMulti_Index_5").get<std::string>());
        x.set_out_multi_index_6(j.at("OutMulti_Index_6").get<std::string>());
        x.set_out_multi_index_7(j.at("OutMulti_Index_7").get<std::string>());
        x.set_out_multi_index_8(j.at("OutMulti_Index_8").get<std::string>());
        x.set_out_single_index_1(j.at("OutSingle_Index_1").get<std::string>());
        x.set_out_single_index_2(j.at("OutSingle_Index_2").get<std::string>());
        x.set_out_single_index_3(j.at("OutSingle_Index_3").get<std::string>());
        x.set_out_single_index_4(j.at("OutSingle_Index_4").get<std::string>());
        x.set_out_single_index_5(j.at("OutSingle_Index_5").get<std::string>());
        x.set_out_single_index_6(j.at("OutSingle_Index_6").get<std::string>());
        x.set_out_single_index_7(j.at("OutSingle_Index_7").get<std::string>());
        x.set_out_single_index_8(j.at("OutSingle_Index_8").get<std::string>());
        x.set_sizeof_array(j.at("SizeofArray").get<std::string>());
    }

    inline void to_json(json & j, const coup::CCoarseRootsAtmLayer & x) {
        j = json::object();
        j["ArrayName"] = x.get_array_name();
        j["Condition_1"] = x.get_condition_1();
        j["Condition_2"] = x.get_condition_2();
        j["Condition_3"] = x.get_condition_3();
        j["Condition_4"] = x.get_condition_4();
        j["OutMulti_Index_1"] = x.get_out_multi_index_1();
        j["OutMulti_Index_2"] = x.get_out_multi_index_2();
        j["OutMulti_Index_3"] = x.get_out_multi_index_3();
        j["OutMulti_Index_4"] = x.get_out_multi_index_4();
        j["OutMulti_Index_5"] = x.get_out_multi_index_5();
        j["OutMulti_Index_6"] = x.get_out_multi_index_6();
        j["OutMulti_Index_7"] = x.get_out_multi_index_7();
        j["OutMulti_Index_8"] = x.get_out_multi_index_8();
        j["OutSingle_Index_1"] = x.get_out_single_index_1();
        j["OutSingle_Index_2"] = x.get_out_single_index_2();
        j["OutSingle_Index_3"] = x.get_out_single_index_3();
        j["OutSingle_Index_4"] = x.get_out_single_index_4();
        j["OutSingle_Index_5"] = x.get_out_single_index_5();
        j["OutSingle_Index_6"] = x.get_out_single_index_6();
        j["OutSingle_Index_7"] = x.get_out_single_index_7();
        j["OutSingle_Index_8"] = x.get_out_single_index_8();
        j["SizeofArray"] = x.get_sizeof_array();
    }

    inline void from_json(const json & j, coup::FluffyPlantGrowth& x) {
        x.set_annual_change_c_plant(j.at("AnnualChangeCPlant").get<coup::LaiAbovecanopy>());
        x.set_c_acc_npp_coarse_root(j.at("CAccNPPCoarseRoot").get<coup::LaiAbovecanopy>());
        x.set_c_acc_npp_leaf(j.at("CAccNPPLeaf").get<coup::LaiAbovecanopy>());
        x.set_c_acc_npp_plant(j.at("CAccNPPPlant").get<coup::LaiAbovecanopy>());
        x.set_c_acc_npp_root(j.at("CAccNPPRoot").get<coup::LaiAbovecanopy>());
        x.set_c_acc_npp_stem(j.at("CAccNPPStem").get<coup::LaiAbovecanopy>());
        x.set_c_coarse_roots_atm_layer(j.at("CCoarseRootsAtmLayer").get<coup::CCoarseRootsAtmLayer>());
        x.set_c_fungi_atmlayer(j.at("CFungiAtmlayer").get<coup::CCoarseRootsAtmLayer>());
        x.set_c_mobile_plant_flux(j.at("CMobilePlantFlux").get<coup::SnowReduceLaiFactor>());
        x.set_cnpp_coarse_root(j.at("CNPPCoarseRoot").get<coup::SnowReduceLaiFactor>());
        x.set_cnpp_leaf(j.at("CNPPLeaf").get<coup::SnowReduceLaiFactor>());
        x.set_cnpp_plant(j.at("CNPPPlant").get<coup::SnowReduceLaiFactor>());
        x.set_cnpp_root(j.at("CNPPRoot").get<coup::SnowReduceLaiFactor>());
        x.set_cnpp_stem(j.at("CNPPStem").get<coup::SnowReduceLaiFactor>());
        x.set_cn_ratio_coarse_roots(j.at("CNRatioCoarseRoots").get<coup::SnowReduceLaiFactor>());
        x.set_cn_ratio_fungi(j.at("CNRatioFungi").get<coup::SnowReduceLaiFactor>());
        x.set_cn_ratio_grain(j.at("CNRatioGrain").get<coup::SnowReduceLaiFactor>());
        x.set_cn_ratio_leaf(j.at("CNRatioLeaf").get<coup::SnowReduceLaiFactor>());
        x.set_cn_ratio_roots(j.at("CNRatioRoots").get<coup::SnowReduceLaiFactor>());
        x.set_cn_ratio_stem(j.at("CNRatioStem").get<coup::SnowReduceLaiFactor>());
        x.set_c_plant(j.at("CPlant").get<coup::SnowReduceLaiFactor>());
        x.set_c_plant_above_g(j.at("CPlantAboveG").get<coup::SnowReduceLaiFactor>());
        x.set_c_plant_litter_fall(j.at("CPlantLitterFall").get<coup::SnowReduceLaiFactor>());
        x.set_c_plant_resp(j.at("CPlantResp").get<coup::SnowReduceLaiFactor>());
        x.set_c_plant_resp_above_g(j.at("CPlantRespAboveG").get<coup::SnowReduceLaiFactor>());
        x.set_cp_ratio_coarse_roots(j.at("CPRatioCoarseRoots").get<coup::SnowReduceLaiFactor>());
        x.set_cp_ratio_fungi(j.at("CPRatioFungi").get<coup::SnowReduceLaiFactor>());
        x.set_cp_ratio_grain(j.at("CPRatioGrain").get<coup::SnowReduceLaiFactor>());
        x.set_cp_ratio_leaf(j.at("CPRatioLeaf").get<coup::SnowReduceLaiFactor>());
        x.set_cp_ratio_roots(j.at("CPRatioRoots").get<coup::SnowReduceLaiFactor>());
        x.set_cp_ratio_stem(j.at("CPRatioStem").get<coup::SnowReduceLaiFactor>());
        x.set_c_roots(j.at("CRoots").get<coup::SnowReduceLaiFactor>());
        x.set_c_roots_atm_layer(j.at("CRootsAtmLayer").get<coup::CCoarseRootsAtmLayer>());
        x.set_c_total_leaf(j.at("CTotalLeaf").get<coup::SnowReduceLaiFactor>());
        x.set_dorming_temp_sum(j.at("DormingTempSum").get<coup::SnowReduceLaiFactor>());
        x.set_fact_cn_fungi(j.at("factCNFungi").get<coup::SnowReduceLaiFactor>());
        x.set_fact_cp_fungi(j.at("factCPFungi").get<coup::SnowReduceLaiFactor>());
        x.set_fact_navail_fungi(j.at("factNavailFungi").get<coup::SnowReduceLaiFactor>());
        x.set_fact_ndemand_fungi(j.at("factNdemandFungi").get<coup::SnowReduceLaiFactor>());
        x.set_fact_nsupply_fungi(j.at("factNsupplyFungi").get<coup::SnowReduceLaiFactor>());
        x.set_fact_pavail_fungi(j.at("factPavailFungi").get<coup::SnowReduceLaiFactor>());
        x.set_fact_pdemand_fungi(j.at("factPdemandFungi").get<coup::SnowReduceLaiFactor>());
        x.set_fact_psupply_fungi(j.at("factPsupplyFungi").get<coup::SnowReduceLaiFactor>());
        x.set_fungi_ammoniauptpot(j.at("FungiAmmoniauptpot").get<coup::SnowReduceLaiFactor>());
        x.set_fungi_nitrateuptpot(j.at("FungiNitrateuptpot").get<coup::SnowReduceLaiFactor>());
        x.set_fungi_organic_nuptpot(j.at("FungiOrganicNuptpot").get<coup::SnowReduceLaiFactor>());
        x.set_fungi_organic_puptpot(j.at("FungiOrganicPuptpot").get<coup::SnowReduceLaiFactor>());
        x.set_fungi_phosphateuptpot(j.at("FungiPhosphateuptpot").get<coup::SnowReduceLaiFactor>());
        x.set_fungi_root_cover(j.at("FungiRootCover").get<coup::SnowReduceLaiFactor>());
        x.set_growth_temp_sum(j.at("GrowthTempSum").get<coup::SnowReduceLaiFactor>());
        x.set_n_fungi_available(j.at("NFungiAvailable").get<coup::SnowReduceLaiFactor>());
        x.set_n_fungi_demand(j.at("NFungiDemand").get<coup::SnowReduceLaiFactor>());
        x.set_n_mobile_plant_flux(j.at("NMobilePlantFlux").get<coup::SnowReduceLaiFactor>());
        x.set_n_plant(j.at("NPlant").get<coup::SnowReduceLaiFactor>());
        x.set_n_plant_above_g(j.at("NPlantAboveG").get<coup::SnowReduceLaiFactor>());
        x.set_n_plant_demand(j.at("NPlantDemand").get<coup::SnowReduceLaiFactor>());
        x.set_n_plant_litter_fall(j.at("NPlantLitterFall").get<coup::SnowReduceLaiFactor>());
        x.set_n_plant_org_uptake(j.at("NPlantOrgUptake").get<coup::SnowReduceLaiFactor>());
        x.set_n_plant_soil_demand(j.at("NPlantSoilDemand").get<coup::SnowReduceLaiFactor>());
        x.set_n_roots(j.at("NRoots").get<coup::SnowReduceLaiFactor>());
        x.set_n_total_leaf(j.at("NTotalLeaf").get<coup::SnowReduceLaiFactor>());
        x.set_n_uptake_deficit1(j.at("NUptakeDeficit1").get<coup::SnowReduceLaiFactor>());
        x.set_n_uptake_deficit2(j.at("NUptakeDeficit2").get<coup::SnowReduceLaiFactor>());
        x.set_n_upt_fungi_deficit1(j.at("NUptFungiDeficit1").get<coup::SnowReduceLaiFactor>());
        x.set_n_upt_fungi_deficit2(j.at("NUptFungiDeficit2").get<coup::SnowReduceLaiFactor>());
        x.set_pco2_stomata(j.at("PCO2Stomata").get<coup::SnowReduceLaiFactor>());
        x.set_pco2_surface(j.at("PCO2Surface").get<coup::SnowReduceLaiFactor>());
        x.set_p_fungi_available(j.at("PFungiAvailable").get<coup::SnowReduceLaiFactor>());
        x.set_p_fungi_demand(j.at("PFungiDemand").get<coup::SnowReduceLaiFactor>());
        x.set_p_light(j.at("PLight").get<coup::SnowReduceLaiFactor>());
        x.set_p_mobile_plant_flux(j.at("PMobilePlantFlux").get<coup::SnowReduceLaiFactor>());
        x.set_p_plant(j.at("PPlant").get<coup::SnowReduceLaiFactor>());
        x.set_p_plant_above_g(j.at("PPlantAboveG").get<coup::SnowReduceLaiFactor>());
        x.set_p_plant_demand(j.at("PPlantDemand").get<coup::SnowReduceLaiFactor>());
        x.set_p_plant_litter_fall(j.at("PPlantLitterFall").get<coup::SnowReduceLaiFactor>());
        x.set_p_plant_org_uptake(j.at("PPlantOrgUptake").get<coup::SnowReduceLaiFactor>());
        x.set_p_plant_soil_demand(j.at("PPlantSoilDemand").get<coup::SnowReduceLaiFactor>());
        x.set_p_roots(j.at("PRoots").get<coup::SnowReduceLaiFactor>());
        x.set_p_rubisco(j.at("PRubisco").get<coup::SnowReduceLaiFactor>());
        x.set_p_sink(j.at("PSink").get<coup::SnowReduceLaiFactor>());
        x.set_p_total_leaf(j.at("PTotalLeaf").get<coup::SnowReduceLaiFactor>());
        x.set_p_uptake_deficit1(j.at("PUptakeDeficit1").get<coup::SnowReduceLaiFactor>());
        x.set_p_uptake_deficit2(j.at("PUptakeDeficit2").get<coup::SnowReduceLaiFactor>());
        x.set_p_upt_fungi_deficit1(j.at("PUptFungiDeficit1").get<coup::SnowReduceLaiFactor>());
        x.set_p_upt_fungi_deficit2(j.at("PUptFungiDeficit2").get<coup::SnowReduceLaiFactor>());
        x.set_radiationadsorbed(j.at("Radiationadsorbed").get<coup::SnowReduceLaiFactor>());
        x.set_response_light(j.at("ResponseLight").get<coup::SnowReduceLaiFactor>());
        x.set_response_n(j.at("ResponseN").get<coup::SnowReduceLaiFactor>());
        x.set_response_n_water(j.at("ResponseN-Water").get<coup::SnowReduceLaiFactor>());
        x.set_response_phosphorus(j.at("ResponsePhosphorus").get<coup::SnowReduceLaiFactor>());
        x.set_response_salt(j.at("ResponseSalt").get<coup::SnowReduceLaiFactor>());
        x.set_response_temp(j.at("ResponseTemp").get<coup::SnowReduceLaiFactor>());
        x.set_response_water(j.at("ResponseWater").get<coup::SnowReduceLaiFactor>());
        x.set_sim_plant_year_age(j.at("SimPlantYearAge").get<coup::SnowReduceLaiFactor>());
        x.set_zadok_day_num_shift(j.at("ZadokDayNumShift").get<coup::SnowReduceLaiFactor>());
        x.set_zadok_index(j.at("ZadokIndex").get<coup::SnowReduceLaiFactor>());
    }

    inline void to_json(json & j, const coup::FluffyPlantGrowth & x) {
        j = json::object();
        j["AnnualChangeCPlant"] = x.get_annual_change_c_plant();
        j["CAccNPPCoarseRoot"] = x.get_c_acc_npp_coarse_root();
        j["CAccNPPLeaf"] = x.get_c_acc_npp_leaf();
        j["CAccNPPPlant"] = x.get_c_acc_npp_plant();
        j["CAccNPPRoot"] = x.get_c_acc_npp_root();
        j["CAccNPPStem"] = x.get_c_acc_npp_stem();
        j["CCoarseRootsAtmLayer"] = x.get_c_coarse_roots_atm_layer();
        j["CFungiAtmlayer"] = x.get_c_fungi_atmlayer();
        j["CMobilePlantFlux"] = x.get_c_mobile_plant_flux();
        j["CNPPCoarseRoot"] = x.get_cnpp_coarse_root();
        j["CNPPLeaf"] = x.get_cnpp_leaf();
        j["CNPPPlant"] = x.get_cnpp_plant();
        j["CNPPRoot"] = x.get_cnpp_root();
        j["CNPPStem"] = x.get_cnpp_stem();
        j["CNRatioCoarseRoots"] = x.get_cn_ratio_coarse_roots();
        j["CNRatioFungi"] = x.get_cn_ratio_fungi();
        j["CNRatioGrain"] = x.get_cn_ratio_grain();
        j["CNRatioLeaf"] = x.get_cn_ratio_leaf();
        j["CNRatioRoots"] = x.get_cn_ratio_roots();
        j["CNRatioStem"] = x.get_cn_ratio_stem();
        j["CPlant"] = x.get_c_plant();
        j["CPlantAboveG"] = x.get_c_plant_above_g();
        j["CPlantLitterFall"] = x.get_c_plant_litter_fall();
        j["CPlantResp"] = x.get_c_plant_resp();
        j["CPlantRespAboveG"] = x.get_c_plant_resp_above_g();
        j["CPRatioCoarseRoots"] = x.get_cp_ratio_coarse_roots();
        j["CPRatioFungi"] = x.get_cp_ratio_fungi();
        j["CPRatioGrain"] = x.get_cp_ratio_grain();
        j["CPRatioLeaf"] = x.get_cp_ratio_leaf();
        j["CPRatioRoots"] = x.get_cp_ratio_roots();
        j["CPRatioStem"] = x.get_cp_ratio_stem();
        j["CRoots"] = x.get_c_roots();
        j["CRootsAtmLayer"] = x.get_c_roots_atm_layer();
        j["CTotalLeaf"] = x.get_c_total_leaf();
        j["DormingTempSum"] = x.get_dorming_temp_sum();
        j["factCNFungi"] = x.get_fact_cn_fungi();
        j["factCPFungi"] = x.get_fact_cp_fungi();
        j["factNavailFungi"] = x.get_fact_navail_fungi();
        j["factNdemandFungi"] = x.get_fact_ndemand_fungi();
        j["factNsupplyFungi"] = x.get_fact_nsupply_fungi();
        j["factPavailFungi"] = x.get_fact_pavail_fungi();
        j["factPdemandFungi"] = x.get_fact_pdemand_fungi();
        j["factPsupplyFungi"] = x.get_fact_psupply_fungi();
        j["FungiAmmoniauptpot"] = x.get_fungi_ammoniauptpot();
        j["FungiNitrateuptpot"] = x.get_fungi_nitrateuptpot();
        j["FungiOrganicNuptpot"] = x.get_fungi_organic_nuptpot();
        j["FungiOrganicPuptpot"] = x.get_fungi_organic_puptpot();
        j["FungiPhosphateuptpot"] = x.get_fungi_phosphateuptpot();
        j["FungiRootCover"] = x.get_fungi_root_cover();
        j["GrowthTempSum"] = x.get_growth_temp_sum();
        j["NFungiAvailable"] = x.get_n_fungi_available();
        j["NFungiDemand"] = x.get_n_fungi_demand();
        j["NMobilePlantFlux"] = x.get_n_mobile_plant_flux();
        j["NPlant"] = x.get_n_plant();
        j["NPlantAboveG"] = x.get_n_plant_above_g();
        j["NPlantDemand"] = x.get_n_plant_demand();
        j["NPlantLitterFall"] = x.get_n_plant_litter_fall();
        j["NPlantOrgUptake"] = x.get_n_plant_org_uptake();
        j["NPlantSoilDemand"] = x.get_n_plant_soil_demand();
        j["NRoots"] = x.get_n_roots();
        j["NTotalLeaf"] = x.get_n_total_leaf();
        j["NUptakeDeficit1"] = x.get_n_uptake_deficit1();
        j["NUptakeDeficit2"] = x.get_n_uptake_deficit2();
        j["NUptFungiDeficit1"] = x.get_n_upt_fungi_deficit1();
        j["NUptFungiDeficit2"] = x.get_n_upt_fungi_deficit2();
        j["PCO2Stomata"] = x.get_pco2_stomata();
        j["PCO2Surface"] = x.get_pco2_surface();
        j["PFungiAvailable"] = x.get_p_fungi_available();
        j["PFungiDemand"] = x.get_p_fungi_demand();
        j["PLight"] = x.get_p_light();
        j["PMobilePlantFlux"] = x.get_p_mobile_plant_flux();
        j["PPlant"] = x.get_p_plant();
        j["PPlantAboveG"] = x.get_p_plant_above_g();
        j["PPlantDemand"] = x.get_p_plant_demand();
        j["PPlantLitterFall"] = x.get_p_plant_litter_fall();
        j["PPlantOrgUptake"] = x.get_p_plant_org_uptake();
        j["PPlantSoilDemand"] = x.get_p_plant_soil_demand();
        j["PRoots"] = x.get_p_roots();
        j["PRubisco"] = x.get_p_rubisco();
        j["PSink"] = x.get_p_sink();
        j["PTotalLeaf"] = x.get_p_total_leaf();
        j["PUptakeDeficit1"] = x.get_p_uptake_deficit1();
        j["PUptakeDeficit2"] = x.get_p_uptake_deficit2();
        j["PUptFungiDeficit1"] = x.get_p_upt_fungi_deficit1();
        j["PUptFungiDeficit2"] = x.get_p_upt_fungi_deficit2();
        j["Radiationadsorbed"] = x.get_radiationadsorbed();
        j["ResponseLight"] = x.get_response_light();
        j["ResponseN"] = x.get_response_n();
        j["ResponseN-Water"] = x.get_response_n_water();
        j["ResponsePhosphorus"] = x.get_response_phosphorus();
        j["ResponseSalt"] = x.get_response_salt();
        j["ResponseTemp"] = x.get_response_temp();
        j["ResponseWater"] = x.get_response_water();
        j["SimPlantYearAge"] = x.get_sim_plant_year_age();
        j["ZadokDayNumShift"] = x.get_zadok_day_num_shift();
        j["ZadokIndex"] = x.get_zadok_index();
    }

    inline void from_json(const json & j, coup::AuxiliaryArraysNitrogenandCarbon& x) {
        x.set_plant_growth(j.at("PlantGrowth").get<coup::FluffyPlantGrowth>());
    }

    inline void to_json(json & j, const coup::AuxiliaryArraysNitrogenandCarbon & x) {
        j = json::object();
        j["PlantGrowth"] = x.get_plant_growth();
    }

    inline void from_json(const json & j, coup::PurpleGasprocesses& x) {
        x.set_air_porosity(j.at("AirPorosity").get<coup::CCoarseRootsAtmLayer>());
        x.set_an_vol_fraction(j.at("An_VolFraction").get<coup::CCoarseRootsAtmLayer>());
        x.set_ch4_airconcentration(j.at("CH4airconcentration").get<coup::CCoarseRootsAtmLayer>());
        x.set_ch4_waterconc(j.at("CH4waterconc").get<coup::CCoarseRootsAtmLayer>());
        x.set_co2_concentration(j.at("CO2Concentration").get<coup::CCoarseRootsAtmLayer>());
        x.set_co2_diffusioncoefficient(j.at("CO2diffusioncoefficient").get<coup::CCoarseRootsAtmLayer>());
        x.set_oxygen_concentration(j.at("OxygenConcentration").get<coup::CCoarseRootsAtmLayer>());
    }

    inline void to_json(json & j, const coup::PurpleGasprocesses & x) {
        j = json::object();
        j["AirPorosity"] = x.get_air_porosity();
        j["An_VolFraction"] = x.get_an_vol_fraction();
        j["CH4airconcentration"] = x.get_ch4_airconcentration();
        j["CH4waterconc"] = x.get_ch4_waterconc();
        j["CO2Concentration"] = x.get_co2_concentration();
        j["CO2diffusioncoefficient"] = x.get_co2_diffusioncoefficient();
        j["OxygenConcentration"] = x.get_oxygen_concentration();
    }

    inline void from_json(const json & j, coup::FluffySoilmineralPProcesses& x) {
        x.set_soil_pconc(j.at("SoilPconc").get<coup::CCoarseRootsAtmLayer>());
        x.set_soil_p_solution(j.at("SoilPSolution").get<coup::CCoarseRootsAtmLayer>());
    }

    inline void to_json(json & j, const coup::FluffySoilmineralPProcesses & x) {
        j = json::object();
        j["SoilPconc"] = x.get_soil_pconc();
        j["SoilPSolution"] = x.get_soil_p_solution();
    }

    inline void from_json(const json & j, coup::AuxiliaryArraysNitrogenandCarbonBelowGround& x) {
        x.set_gasprocesses(j.at("Gasprocesses").get<coup::PurpleGasprocesses>());
        x.set_soilmineral_nprocesses(j.at("SoilmineralNprocesses").get<std::map<std::string, coup::CCoarseRootsAtmLayer>>());
        x.set_soilmineral_p_processes(j.at("SoilmineralPProcesses").get<coup::FluffySoilmineralPProcesses>());
        x.set_soilorganicprocesses(j.at("Soilorganicprocesses").get<std::map<std::string, coup::CCoarseRootsAtmLayer>>());
    }

    inline void to_json(json & j, const coup::AuxiliaryArraysNitrogenandCarbonBelowGround & x) {
        j = json::object();
        j["Gasprocesses"] = x.get_gasprocesses();
        j["SoilmineralNprocesses"] = x.get_soilmineral_nprocesses();
        j["SoilmineralPProcesses"] = x.get_soilmineral_p_processes();
        j["Soilorganicprocesses"] = x.get_soilorganicprocesses();
    }

    inline void from_json(const json & j, coup::TentacledInterception& x) {
        x.set_canopy_interc_capac(j.at("CanopyIntercCapac").get<coup::LaiAbovecanopy>());
        x.set_canopy_interc_pot_eva(j.at("CanopyIntercPotEva").get<coup::LaiAbovecanopy>());
    }

    inline void to_json(json & j, const coup::TentacledInterception & x) {
        j = json::object();
        j["CanopyIntercCapac"] = x.get_canopy_interc_capac();
        j["CanopyIntercPotEva"] = x.get_canopy_interc_pot_eva();
    }

    inline void from_json(const json & j, coup::TentacledPlant& x) {
        x.set_canopy_height(j.at("CanopyHeight").get<coup::SnowReduceLaiFactor>());
        x.set_leaf_area_index(j.at("LeafAreaIndex").get<coup::SnowReduceLaiFactor>());
        x.set_plant_albedo(j.at("PlantAlbedo").get<coup::SnowReduceLaiFactor>());
        x.set_root_depth(j.at("RootDepth").get<coup::SnowReduceLaiFactor>());
        x.set_root_depth_distribution(j.at("RootDepthDistribution").get<coup::CCoarseRootsAtmLayer>());
        x.set_root_length(j.at("RootLength").get<coup::SnowReduceLaiFactor>());
        x.set_sim_leaf_area_index(j.at("SimLeafAreaIndex").get<coup::SnowReduceLaiFactor>());
        x.set_sim_plant_albedo(j.at("SimPlantAlbedo").get<coup::SnowReduceLaiFactor>());
        x.set_sim_plant_height(j.at("SimPlantHeight").get<coup::SnowReduceLaiFactor>());
        x.set_sim_root_depth(j.at("SimRootDepth").get<coup::SnowReduceLaiFactor>());
        x.set_sim_root_length(j.at("SimRootLength").get<coup::SnowReduceLaiFactor>());
        x.set_soil_cover_fraction(j.at("SoilCoverFraction").get<coup::SnowReduceLaiFactor>());
    }

    inline void to_json(json & j, const coup::TentacledPlant & x) {
        j = json::object();
        j["CanopyHeight"] = x.get_canopy_height();
        j["LeafAreaIndex"] = x.get_leaf_area_index();
        j["PlantAlbedo"] = x.get_plant_albedo();
        j["RootDepth"] = x.get_root_depth();
        j["RootDepthDistribution"] = x.get_root_depth_distribution();
        j["RootLength"] = x.get_root_length();
        j["SimLeafAreaIndex"] = x.get_sim_leaf_area_index();
        j["SimPlantAlbedo"] = x.get_sim_plant_albedo();
        j["SimPlantHeight"] = x.get_sim_plant_height();
        j["SimRootDepth"] = x.get_sim_root_depth();
        j["SimRootLength"] = x.get_sim_root_length();
        j["SoilCoverFraction"] = x.get_soil_cover_fraction();
    }

    inline void from_json(const json & j, coup::FluffyPotentialTranspiration& x) {
        x.set_displacement_height(j.at("DisplacementHeight").get<coup::LaiAbovecanopy>());
        x.set_pot_max_transpiration(j.at("PotMaxTranspiration").get<coup::LaiAbovecanopy>());
        x.set_pot_transpiration(j.at("PotTranspiration").get<coup::LaiAbovecanopy>());
        x.set_resist_air_canopy(j.at("ResistAirCanopy").get<coup::LaiAbovecanopy>());
        x.set_resistance_canopy(j.at("ResistanceCanopy").get<coup::LaiAbovecanopy>());
        x.set_resistance_min_canopy(j.at("ResistanceMinCanopy").get<coup::LaiAbovecanopy>());
        x.set_response_transp_atm(j.at("ResponseTranspAtm").get<coup::LaiAbovecanopy>());
        x.set_roughness_length(j.at("RoughnessLength").get<coup::LaiAbovecanopy>());
    }

    inline void to_json(json & j, const coup::FluffyPotentialTranspiration & x) {
        j = json::object();
        j["DisplacementHeight"] = x.get_displacement_height();
        j["PotMaxTranspiration"] = x.get_pot_max_transpiration();
        j["PotTranspiration"] = x.get_pot_transpiration();
        j["ResistAirCanopy"] = x.get_resist_air_canopy();
        j["ResistanceCanopy"] = x.get_resistance_canopy();
        j["ResistanceMinCanopy"] = x.get_resistance_min_canopy();
        j["ResponseTranspAtm"] = x.get_response_transp_atm();
        j["RoughnessLength"] = x.get_roughness_length();
    }

    inline void from_json(const json & j, coup::FluffySaltTracer& x) {
        x.set_osmotic_pressure(j.at("OsmoticPressure").get<coup::CCoarseRootsAtmLayer>());
        x.set_salt_conc(j.at("SaltConc").get<coup::CCoarseRootsAtmLayer>());
        x.set_tec_ratio_grain(j.at("TECRatioGrain").get<coup::SnowReduceLaiFactor>());
        x.set_tec_ratio_leaf(j.at("TECRatioLeaf").get<coup::SnowReduceLaiFactor>());
        x.set_tec_ratio_old_leaf(j.at("TECRatioOldLeaf").get<coup::SnowReduceLaiFactor>());
        x.set_tec_ratio_old_roots(j.at("TECRatioOldRoots").get<coup::SnowReduceLaiFactor>());
        x.set_tec_ratio_old_stem(j.at("TECRatioOldStem").get<coup::SnowReduceLaiFactor>());
        x.set_tec_ratio_roots(j.at("TECRatioRoots").get<coup::SnowReduceLaiFactor>());
        x.set_tec_ratio_stem(j.at("TECRatioStem").get<coup::SnowReduceLaiFactor>());
    }

    inline void to_json(json & j, const coup::FluffySaltTracer & x) {
        j = json::object();
        j["OsmoticPressure"] = x.get_osmotic_pressure();
        j["SaltConc"] = x.get_salt_conc();
        j["TECRatioGrain"] = x.get_tec_ratio_grain();
        j["TECRatioLeaf"] = x.get_tec_ratio_leaf();
        j["TECRatioOldLeaf"] = x.get_tec_ratio_old_leaf();
        j["TECRatioOldRoots"] = x.get_tec_ratio_old_roots();
        j["TECRatioOldStem"] = x.get_tec_ratio_old_stem();
        j["TECRatioRoots"] = x.get_tec_ratio_roots();
        j["TECRatioStem"] = x.get_tec_ratio_stem();
    }

    inline void from_json(const json & j, coup::TentacledWateruptake& x) {
        x.set_plant_pot_water_uptake(j.at("PlantPotWaterUptake").get<coup::LaiAbovecanopy>());
        x.set_plant_water_potential(j.at("PlantWaterPotential").get<coup::LaiAbovecanopy>());
        x.set_red_c_moisture(j.at("RedCMoisture").get<coup::LaiAbovecanopy>());
        x.set_red_c_temperature(j.at("RedCTemperature").get<coup::LaiAbovecanopy>());
        x.set_red_c_total(j.at("RedCTotal").get<coup::LaiAbovecanopy>());
        x.set_resist_plant(j.at("ResistPlant").get<coup::LaiAbovecanopy>());
        x.set_resist_soil_plant(j.at("ResistSoil_Plant").get<coup::LaiAbovecanopy>());
    }

    inline void to_json(json & j, const coup::TentacledWateruptake & x) {
        j = json::object();
        j["PlantPotWaterUptake"] = x.get_plant_pot_water_uptake();
        j["PlantWaterPotential"] = x.get_plant_water_potential();
        j["RedCMoisture"] = x.get_red_c_moisture();
        j["RedCTemperature"] = x.get_red_c_temperature();
        j["RedCTotal"] = x.get_red_c_total();
        j["ResistPlant"] = x.get_resist_plant();
        j["ResistSoil_Plant"] = x.get_resist_soil_plant();
    }

    inline void from_json(const json & j, coup::AuxiliaryArraysPlantWaterProcesses& x) {
        x.set_interception(j.at("Interception").get<coup::TentacledInterception>());
        x.set_plant(j.at("Plant").get<coup::TentacledPlant>());
        x.set_potential_transpiration(j.at("PotentialTranspiration").get<coup::FluffyPotentialTranspiration>());
        x.set_salt_tracer(j.at("SaltTracer").get<coup::FluffySaltTracer>());
        x.set_wateruptake(j.at("Wateruptake").get<coup::TentacledWateruptake>());
    }

    inline void to_json(json & j, const coup::AuxiliaryArraysPlantWaterProcesses & x) {
        j = json::object();
        j["Interception"] = x.get_interception();
        j["Plant"] = x.get_plant();
        j["PotentialTranspiration"] = x.get_potential_transpiration();
        j["SaltTracer"] = x.get_salt_tracer();
        j["Wateruptake"] = x.get_wateruptake();
    }

    inline void from_json(const json & j, coup::TempColdPipe& x) {
        x.set_array_name(j.at("ArrayName").get<coup::ArrayName>());
        x.set_condition_1(j.at("Condition_1").get<coup::Condition3Enum>());
        x.set_condition_2(j.at("Condition_2").get<coup::ArrayName>());
        x.set_out_multi_index_1(j.at("OutMulti_Index_1").get<std::string>());
        x.set_out_multi_index_10(j.at("OutMulti_Index_10").get<std::string>());
        x.set_out_multi_index_11(j.at("OutMulti_Index_11").get<std::string>());
        x.set_out_multi_index_12(j.at("OutMulti_Index_12").get<std::string>());
        x.set_out_multi_index_13(j.at("OutMulti_Index_13").get<std::string>());
        x.set_out_multi_index_14(j.at("OutMulti_Index_14").get<std::string>());
        x.set_out_multi_index_15(j.at("OutMulti_Index_15").get<std::string>());
        x.set_out_multi_index_16(j.at("OutMulti_Index_16").get<std::string>());
        x.set_out_multi_index_17(j.at("OutMulti_Index_17").get<std::string>());
        x.set_out_multi_index_18(j.at("OutMulti_Index_18").get<std::string>());
        x.set_out_multi_index_19(j.at("OutMulti_Index_19").get<std::string>());
        x.set_out_multi_index_2(j.at("OutMulti_Index_2").get<std::string>());
        x.set_out_multi_index_20(j.at("OutMulti_Index_20").get<std::string>());
        x.set_out_multi_index_3(j.at("OutMulti_Index_3").get<std::string>());
        x.set_out_multi_index_4(j.at("OutMulti_Index_4").get<std::string>());
        x.set_out_multi_index_5(j.at("OutMulti_Index_5").get<std::string>());
        x.set_out_multi_index_6(j.at("OutMulti_Index_6").get<std::string>());
        x.set_out_multi_index_7(j.at("OutMulti_Index_7").get<std::string>());
        x.set_out_multi_index_8(j.at("OutMulti_Index_8").get<std::string>());
        x.set_out_multi_index_9(j.at("OutMulti_Index_9").get<std::string>());
        x.set_out_single_index_1(j.at("OutSingle_Index_1").get<std::string>());
        x.set_out_single_index_10(j.at("OutSingle_Index_10").get<std::string>());
        x.set_out_single_index_11(j.at("OutSingle_Index_11").get<std::string>());
        x.set_out_single_index_12(j.at("OutSingle_Index_12").get<std::string>());
        x.set_out_single_index_13(j.at("OutSingle_Index_13").get<std::string>());
        x.set_out_single_index_14(j.at("OutSingle_Index_14").get<std::string>());
        x.set_out_single_index_15(j.at("OutSingle_Index_15").get<std::string>());
        x.set_out_single_index_16(j.at("OutSingle_Index_16").get<std::string>());
        x.set_out_single_index_17(j.at("OutSingle_Index_17").get<std::string>());
        x.set_out_single_index_18(j.at("OutSingle_Index_18").get<std::string>());
        x.set_out_single_index_19(j.at("OutSingle_Index_19").get<std::string>());
        x.set_out_single_index_2(j.at("OutSingle_Index_2").get<std::string>());
        x.set_out_single_index_20(j.at("OutSingle_Index_20").get<std::string>());
        x.set_out_single_index_3(j.at("OutSingle_Index_3").get<std::string>());
        x.set_out_single_index_4(j.at("OutSingle_Index_4").get<std::string>());
        x.set_out_single_index_5(j.at("OutSingle_Index_5").get<std::string>());
        x.set_out_single_index_6(j.at("OutSingle_Index_6").get<std::string>());
        x.set_out_single_index_7(j.at("OutSingle_Index_7").get<std::string>());
        x.set_out_single_index_8(j.at("OutSingle_Index_8").get<std::string>());
        x.set_out_single_index_9(j.at("OutSingle_Index_9").get<std::string>());
        x.set_sizeof_array(j.at("SizeofArray").get<std::string>());
    }

    inline void to_json(json & j, const coup::TempColdPipe & x) {
        j = json::object();
        j["ArrayName"] = x.get_array_name();
        j["Condition_1"] = x.get_condition_1();
        j["Condition_2"] = x.get_condition_2();
        j["OutMulti_Index_1"] = x.get_out_multi_index_1();
        j["OutMulti_Index_10"] = x.get_out_multi_index_10();
        j["OutMulti_Index_11"] = x.get_out_multi_index_11();
        j["OutMulti_Index_12"] = x.get_out_multi_index_12();
        j["OutMulti_Index_13"] = x.get_out_multi_index_13();
        j["OutMulti_Index_14"] = x.get_out_multi_index_14();
        j["OutMulti_Index_15"] = x.get_out_multi_index_15();
        j["OutMulti_Index_16"] = x.get_out_multi_index_16();
        j["OutMulti_Index_17"] = x.get_out_multi_index_17();
        j["OutMulti_Index_18"] = x.get_out_multi_index_18();
        j["OutMulti_Index_19"] = x.get_out_multi_index_19();
        j["OutMulti_Index_2"] = x.get_out_multi_index_2();
        j["OutMulti_Index_20"] = x.get_out_multi_index_20();
        j["OutMulti_Index_3"] = x.get_out_multi_index_3();
        j["OutMulti_Index_4"] = x.get_out_multi_index_4();
        j["OutMulti_Index_5"] = x.get_out_multi_index_5();
        j["OutMulti_Index_6"] = x.get_out_multi_index_6();
        j["OutMulti_Index_7"] = x.get_out_multi_index_7();
        j["OutMulti_Index_8"] = x.get_out_multi_index_8();
        j["OutMulti_Index_9"] = x.get_out_multi_index_9();
        j["OutSingle_Index_1"] = x.get_out_single_index_1();
        j["OutSingle_Index_10"] = x.get_out_single_index_10();
        j["OutSingle_Index_11"] = x.get_out_single_index_11();
        j["OutSingle_Index_12"] = x.get_out_single_index_12();
        j["OutSingle_Index_13"] = x.get_out_single_index_13();
        j["OutSingle_Index_14"] = x.get_out_single_index_14();
        j["OutSingle_Index_15"] = x.get_out_single_index_15();
        j["OutSingle_Index_16"] = x.get_out_single_index_16();
        j["OutSingle_Index_17"] = x.get_out_single_index_17();
        j["OutSingle_Index_18"] = x.get_out_single_index_18();
        j["OutSingle_Index_19"] = x.get_out_single_index_19();
        j["OutSingle_Index_2"] = x.get_out_single_index_2();
        j["OutSingle_Index_20"] = x.get_out_single_index_20();
        j["OutSingle_Index_3"] = x.get_out_single_index_3();
        j["OutSingle_Index_4"] = x.get_out_single_index_4();
        j["OutSingle_Index_5"] = x.get_out_single_index_5();
        j["OutSingle_Index_6"] = x.get_out_single_index_6();
        j["OutSingle_Index_7"] = x.get_out_single_index_7();
        j["OutSingle_Index_8"] = x.get_out_single_index_8();
        j["OutSingle_Index_9"] = x.get_out_single_index_9();
        j["SizeofArray"] = x.get_sizeof_array();
    }

    inline void from_json(const json & j, coup::FluffySoilheatflows& x) {
        x.set_exact_temperature(j.at("ExactTemperature").get<coup::CCoarseRootsAtmLayer>());
        x.set_temp_cold_pipe(j.at("TempColdPipe").get<coup::TempColdPipe>());
        x.set_temperature(j.at("Temperature").get<coup::CCoarseRootsAtmLayer>());
        x.set_temp_out_pipe(j.at("TempOutPipe").get<coup::TempColdPipe>());
        x.set_thermal_conductivity(j.at("ThermalConductivity").get<coup::CCoarseRootsAtmLayer>());
        x.set_thermal_qualilty(j.at("ThermalQualilty").get<coup::CCoarseRootsAtmLayer>());
    }

    inline void to_json(json & j, const coup::FluffySoilheatflows & x) {
        j = json::object();
        j["ExactTemperature"] = x.get_exact_temperature();
        j["TempColdPipe"] = x.get_temp_cold_pipe();
        j["Temperature"] = x.get_temperature();
        j["TempOutPipe"] = x.get_temp_out_pipe();
        j["ThermalConductivity"] = x.get_thermal_conductivity();
        j["ThermalQualilty"] = x.get_thermal_qualilty();
    }

    inline void from_json(const json & j, coup::AuxiliaryArraysSoilHeatProcesses& x) {
        x.set_soilheatflows(j.at("Soilheatflows").get<coup::FluffySoilheatflows>());
    }

    inline void to_json(json & j, const coup::AuxiliaryArraysSoilHeatProcesses & x) {
        j = json::object();
        j["Soilheatflows"] = x.get_soilheatflows();
    }

    inline void from_json(const json & j, coup::StickyDrainageanddeeppercolation& x) {
        x.set_corr_height_factor(j.at("CorrHeightFactor").get<coup::CCoarseRootsAtmLayer>());
    }

    inline void to_json(json & j, const coup::StickyDrainageanddeeppercolation & x) {
        j = json::object();
        j["CorrHeightFactor"] = x.get_corr_height_factor();
    }

    inline void from_json(const json & j, coup::FluffySoilwaterflows& x) {
        x.set_hys_effect(j.at("HysEffect").get<coup::CCoarseRootsAtmLayer>());
        x.set_mean_transit_time(j.at("MeanTransitTime").get<coup::CCoarseRootsAtmLayer>());
        x.set_pressure_head(j.at("PressureHead").get<coup::CCoarseRootsAtmLayer>());
        x.set_theta_b(j.at("ThetaB").get<coup::CCoarseRootsAtmLayer>());
        x.set_total_water_content(j.at("TotalWaterContent").get<coup::CCoarseRootsAtmLayer>());
        x.set_water_content(j.at("WaterContent").get<coup::CCoarseRootsAtmLayer>());
        x.set_w_bypassflow(j.at("WBypassflow").get<coup::CCoarseRootsAtmLayer>());
    }

    inline void to_json(json & j, const coup::FluffySoilwaterflows & x) {
        j = json::object();
        j["HysEffect"] = x.get_hys_effect();
        j["MeanTransitTime"] = x.get_mean_transit_time();
        j["PressureHead"] = x.get_pressure_head();
        j["ThetaB"] = x.get_theta_b();
        j["TotalWaterContent"] = x.get_total_water_content();
        j["WaterContent"] = x.get_water_content();
        j["WBypassflow"] = x.get_w_bypassflow();
    }

    inline void from_json(const json & j, coup::AuxiliaryArraysSoilWaterProcesses& x) {
        x.set_drainageanddeeppercolation(j.at("Drainageanddeeppercolation").get<coup::StickyDrainageanddeeppercolation>());
        x.set_soilwaterflows(j.at("Soilwaterflows").get<coup::FluffySoilwaterflows>());
    }

    inline void to_json(json & j, const coup::AuxiliaryArraysSoilWaterProcesses & x) {
        j = json::object();
        j["Drainageanddeeppercolation"] = x.get_drainageanddeeppercolation();
        j["Soilwaterflows"] = x.get_soilwaterflows();
    }

    inline void from_json(const json & j, coup::AuxiliaryArrays& x) {
        x.set_atmospheric_related_processes(j.at("AtmosphericRelatedProcesses").get<coup::AuxiliaryArraysAtmosphericRelatedProcesses>());
        x.set_nitrogenand_carbon(j.at("NitrogenandCarbon").get<coup::AuxiliaryArraysNitrogenandCarbon>());
        x.set_nitrogenand_carbon_below_ground(j.at("NitrogenandCarbon-BelowGround").get<coup::AuxiliaryArraysNitrogenandCarbonBelowGround>());
        x.set_plant_water_processes(j.at("PlantWaterProcesses").get<coup::AuxiliaryArraysPlantWaterProcesses>());
        x.set_soil_heat_processes(j.at("SoilHeatProcesses").get<coup::AuxiliaryArraysSoilHeatProcesses>());
        x.set_soil_water_processes(j.at("SoilWaterProcesses").get<coup::AuxiliaryArraysSoilWaterProcesses>());
    }

    inline void to_json(json & j, const coup::AuxiliaryArrays & x) {
        j = json::object();
        j["AtmosphericRelatedProcesses"] = x.get_atmospheric_related_processes();
        j["NitrogenandCarbon"] = x.get_nitrogenand_carbon();
        j["NitrogenandCarbon-BelowGround"] = x.get_nitrogenand_carbon_below_ground();
        j["PlantWaterProcesses"] = x.get_plant_water_processes();
        j["SoilHeatProcesses"] = x.get_soil_heat_processes();
        j["SoilWaterProcesses"] = x.get_soil_water_processes();
    }

    inline void from_json(const json & j, coup::FluffySnowPack& x) {
        x.set_snow_measured(j.at("SnowMeasured").get<coup::AlbedoVar>());
    }

    inline void to_json(json & j, const coup::FluffySnowPack & x) {
        j = json::object();
        j["SnowMeasured"] = x.get_snow_measured();
    }

    inline void from_json(const json & j, coup::DrivingAtmosphericRelatedProcesses& x) {
        x.set_meteorological_data(j.at("MeteorologicalData").get<std::map<std::string, coup::CanopyFracRadDiffuse>>());
        x.set_snow_pack(j.at("SnowPack").get<coup::FluffySnowPack>());
    }

    inline void to_json(json & j, const coup::DrivingAtmosphericRelatedProcesses & x) {
        j = json::object();
        j["MeteorologicalData"] = x.get_meteorological_data();
        j["SnowPack"] = x.get_snow_pack();
    }

    inline void from_json(const json & j, coup::FluffyAbioticdrivingvariables& x) {
        x.set_green_index_change(j.at("GreenIndexChange").get<coup::CanopyFracRadDiffuse>());
        x.set_n_driv_deep_percolation(j.at("NDrivDeepPercolation").get<coup::CanopyFracRadDiffuse>());
        x.set_n_driv_infiltration(j.at("NDrivInfiltration").get<coup::CanopyFracRadDiffuse>());
    }

    inline void to_json(json & j, const coup::FluffyAbioticdrivingvariables & x) {
        j = json::object();
        j["GreenIndexChange"] = x.get_green_index_change();
        j["NDrivDeepPercolation"] = x.get_n_driv_deep_percolation();
        j["NDrivInfiltration"] = x.get_n_driv_infiltration();
    }

    inline void from_json(const json & j, coup::DrivingNitrogenandCarbonBelowGround& x) {
        x.set_abioticdrivingvariables(j.at("Abioticdrivingvariables").get<coup::FluffyAbioticdrivingvariables>());
    }

    inline void to_json(json & j, const coup::DrivingNitrogenandCarbonBelowGround & x) {
        j = json::object();
        j["Abioticdrivingvariables"] = x.get_abioticdrivingvariables();
    }

    inline void from_json(const json & j, coup::TentacledSaltTracer& x) {
        x.set_salt_air_deposition(j.at("SaltAirDeposition").get<coup::AlbedoVar>());
        x.set_salt_infil_conc(j.at("SaltInfilConc").get<coup::AlbedoVar>());
        x.set_salt_irrigation_conc(j.at("SaltIrrigationConc").get<coup::AlbedoVar>());
        x.set_salt_plough_deposition(j.at("SaltPloughDeposition").get<coup::AlbedoVar>());
        x.set_salt_run_off_deposition(j.at("SaltRunOffDeposition").get<coup::AlbedoVar>());
    }

    inline void to_json(json & j, const coup::TentacledSaltTracer & x) {
        j = json::object();
        j["SaltAirDeposition"] = x.get_salt_air_deposition();
        j["SaltInfilConc"] = x.get_salt_infil_conc();
        j["SaltIrrigationConc"] = x.get_salt_irrigation_conc();
        j["SaltPloughDeposition"] = x.get_salt_plough_deposition();
        j["SaltRunOffDeposition"] = x.get_salt_run_off_deposition();
    }

    inline void from_json(const json & j, coup::DrivingPlantWaterProcesses& x) {
        x.set_salt_tracer(j.at("SaltTracer").get<coup::TentacledSaltTracer>());
    }

    inline void to_json(json & j, const coup::DrivingPlantWaterProcesses & x) {
        j = json::object();
        j["SaltTracer"] = x.get_salt_tracer();
    }

    inline void from_json(const json & j, coup::Driving& x) {
        x.set_atmospheric_related_processes(j.at("AtmosphericRelatedProcesses").get<coup::DrivingAtmosphericRelatedProcesses>());
        x.set_nitrogenand_carbon_below_ground(j.at("NitrogenandCarbon-BelowGround").get<coup::DrivingNitrogenandCarbonBelowGround>());
        x.set_plant_water_processes(j.at("PlantWaterProcesses").get<coup::DrivingPlantWaterProcesses>());
    }

    inline void to_json(json & j, const coup::Driving & x) {
        j = json::object();
        j["AtmosphericRelatedProcesses"] = x.get_atmospheric_related_processes();
        j["NitrogenandCarbon-BelowGround"] = x.get_nitrogenand_carbon_below_ground();
        j["PlantWaterProcesses"] = x.get_plant_water_processes();
    }

    inline void from_json(const json & j, coup::TentacledMeteorologicalData& x) {
        x.set_wsource(j.at("Wsource").get<coup::CCoarseRootsAtmLayer>());
    }

    inline void to_json(json & j, const coup::TentacledMeteorologicalData & x) {
        j = json::object();
        j["Wsource"] = x.get_wsource();
    }

    inline void from_json(const json & j, coup::DrivingArraysAtmosphericRelatedProcesses& x) {
        x.set_meteorological_data(j.at("MeteorologicalData").get<coup::TentacledMeteorologicalData>());
    }

    inline void to_json(json & j, const coup::DrivingArraysAtmosphericRelatedProcesses & x) {
        j = json::object();
        j["MeteorologicalData"] = x.get_meteorological_data();
    }

    inline void from_json(const json & j, coup::TentacledAbioticdrivingvariables& x) {
        x.set_n_driv_drainage(j.at("NDrivDrainage").get<coup::CCoarseRootsAtmLayer>());
        x.set_n_driv_salt_stress(j.at("NDrivSaltStress").get<coup::SnowReduceLaiFactor>());
        x.set_n_driv_temperature(j.at("NDrivTemperature").get<coup::CCoarseRootsAtmLayer>());
        x.set_n_driv_theta(j.at("NDrivTheta").get<coup::CCoarseRootsAtmLayer>());
        x.set_n_driv_water_flow(j.at("NDrivWaterFlow").get<coup::CCoarseRootsAtmLayer>());
        x.set_n_driv_water_stress(j.at("NDrivWaterStress").get<coup::SnowReduceLaiFactor>());
    }

    inline void to_json(json & j, const coup::TentacledAbioticdrivingvariables & x) {
        j = json::object();
        j["NDrivDrainage"] = x.get_n_driv_drainage();
        j["NDrivSaltStress"] = x.get_n_driv_salt_stress();
        j["NDrivTemperature"] = x.get_n_driv_temperature();
        j["NDrivTheta"] = x.get_n_driv_theta();
        j["NDrivWaterFlow"] = x.get_n_driv_water_flow();
        j["NDrivWaterStress"] = x.get_n_driv_water_stress();
    }

    inline void from_json(const json & j, coup::DrivingArraysNitrogenandCarbonBelowGround& x) {
        x.set_abioticdrivingvariables(j.at("Abioticdrivingvariables").get<coup::TentacledAbioticdrivingvariables>());
    }

    inline void to_json(json & j, const coup::DrivingArraysNitrogenandCarbonBelowGround & x) {
        j = json::object();
        j["Abioticdrivingvariables"] = x.get_abioticdrivingvariables();
    }

    inline void from_json(const json & j, coup::DrivingArrays& x) {
        x.set_atmospheric_related_processes(j.at("AtmosphericRelatedProcesses").get<coup::DrivingArraysAtmosphericRelatedProcesses>());
        x.set_nitrogenand_carbon_below_ground(j.at("NitrogenandCarbon-BelowGround").get<coup::DrivingArraysNitrogenandCarbonBelowGround>());
    }

    inline void to_json(json & j, const coup::DrivingArrays & x) {
        j = json::object();
        j["AtmosphericRelatedProcesses"] = x.get_atmospheric_related_processes();
        j["NitrogenandCarbon-BelowGround"] = x.get_nitrogenand_carbon_below_ground();
    }

    inline void from_json(const json & j, coup::TentacledSnowPack& x) {
        x.set_snow_evaporation(j.at("SnowEvaporation").get<coup::CanopyFracRadDiffuse>());
        x.set_snow_inflow(j.at("SnowInflow").get<coup::CanopyFracRadDiffuse>());
        x.set_snowmassexport(j.at("Snowmassexport").get<coup::CanopyFracRadDiffuse>());
        x.set_snowmassimport(j.at("Snowmassimport").get<coup::CanopyFracRadDiffuse>());
        x.set_snow_water_outflow(j.at("SnowWaterOutflow").get<coup::CanopyFracRadDiffuse>());
    }

    inline void to_json(json & j, const coup::TentacledSnowPack & x) {
        j = json::object();
        j["SnowEvaporation"] = x.get_snow_evaporation();
        j["SnowInflow"] = x.get_snow_inflow();
        j["Snowmassexport"] = x.get_snowmassexport();
        j["Snowmassimport"] = x.get_snowmassimport();
        j["SnowWaterOutflow"] = x.get_snow_water_outflow();
    }

    inline void from_json(const json & j, coup::FluffySoilevaporation& x) {
        x.set_soil_evaporation(j.at("SoilEvaporation").get<coup::AlbedoVar>());
        x.set_soil_evaporation1(j.at("SoilEvaporation1").get<coup::AlbedoVar>());
        x.set_soil_evaporation2(j.at("SoilEvaporation2").get<coup::AlbedoVar>());
        x.set_surf_heat_flow1(j.at("SurfHeatFlow1").get<coup::AlbedoVar>());
        x.set_surf_heat_flow2(j.at("SurfHeatFlow2").get<coup::AlbedoVar>());
    }

    inline void to_json(json & j, const coup::FluffySoilevaporation & x) {
        j = json::object();
        j["SoilEvaporation"] = x.get_soil_evaporation();
        j["SoilEvaporation1"] = x.get_soil_evaporation1();
        j["SoilEvaporation2"] = x.get_soil_evaporation2();
        j["SurfHeatFlow1"] = x.get_surf_heat_flow1();
        j["SurfHeatFlow2"] = x.get_surf_heat_flow2();
    }

    inline void from_json(const json & j, coup::FlowAtmosphericRelatedProcesses& x) {
        x.set_snow_pack(j.at("SnowPack").get<coup::TentacledSnowPack>());
        x.set_soilevaporation(j.at("Soilevaporation").get<coup::FluffySoilevaporation>());
    }

    inline void to_json(json & j, const coup::FlowAtmosphericRelatedProcesses & x) {
        j = json::object();
        j["SnowPack"] = x.get_snow_pack();
        j["Soilevaporation"] = x.get_soilevaporation();
    }

    inline void from_json(const json & j, coup::PurpleIrrigation& x) {
        x.set_drip_fill(j.at("DripFill").get<coup::CanopyFracRadDiffuse>());
        x.set_drip_outlet(j.at("DripOutlet").get<coup::CanopyFracRadDiffuse>());
    }

    inline void to_json(json & j, const coup::PurpleIrrigation & x) {
        j = json::object();
        j["DripFill"] = x.get_drip_fill();
        j["DripOutlet"] = x.get_drip_outlet();
    }

    inline void from_json(const json & j, coup::FlowModelFacilities& x) {
        x.set_irrigation(j.at("Irrigation").get<coup::PurpleIrrigation>());
    }

    inline void to_json(json & j, const coup::FlowModelFacilities & x) {
        j = json::object();
        j["Irrigation"] = x.get_irrigation();
    }

    inline void from_json(const json & j, coup::PurpleExternalPInputs& x) {
        x.set_p_fert_appl_rate(j.at("PFertApplRate").get<coup::CanopyFracRadDiffuse>());
        x.set_p_fert_solution_rate(j.at("PFertSolutionRate").get<coup::CanopyFracRadDiffuse>());
    }

    inline void to_json(json & j, const coup::PurpleExternalPInputs & x) {
        j = json::object();
        j["PFertApplRate"] = x.get_p_fert_appl_rate();
        j["PFertSolutionRate"] = x.get_p_fert_solution_rate();
    }

    inline void from_json(const json & j, coup::FlowNitrogenandCarbon& x) {
        x.set_external_ninputs(j.at("ExternalNinputs").get<std::map<std::string, coup::AlbedoVar>>());
        x.set_external_p_inputs(j.at("ExternalPInputs").get<coup::PurpleExternalPInputs>());
        x.set_plant_growth(j.at("PlantGrowth").get<std::map<std::string, coup::AlbedoVar>>());
    }

    inline void to_json(json & j, const coup::FlowNitrogenandCarbon & x) {
        j = json::object();
        j["ExternalNinputs"] = x.get_external_ninputs();
        j["ExternalPInputs"] = x.get_external_p_inputs();
        j["PlantGrowth"] = x.get_plant_growth();
    }

    inline void from_json(const json & j, coup::FluffyGasprocesses& x) {
        x.set_ch4_surface_emission(j.at("CH4SurfaceEmission").get<coup::CanopyFracRadDiffuse>());
        x.set_co2_flux_out(j.at("CO2FluxOut").get<coup::CanopyFracRadDiffuse>());
        x.set_n2_emissionrate(j.at("N2emissionrate").get<coup::CanopyFracRadDiffuse>());
        x.set_n2_oemissionrate(j.at("N2Oemissionrate").get<coup::CanopyFracRadDiffuse>());
        x.set_n_oemissionrate(j.at("NOemissionrate").get<coup::CanopyFracRadDiffuse>());
        x.set_oxygen_flux_infil(j.at("OxygenFluxInfil").get<coup::CanopyFracRadDiffuse>());
    }

    inline void to_json(json & j, const coup::FluffyGasprocesses & x) {
        j = json::object();
        j["CH4SurfaceEmission"] = x.get_ch4_surface_emission();
        j["CO2FluxOut"] = x.get_co2_flux_out();
        j["N2emissionrate"] = x.get_n2_emissionrate();
        j["N2Oemissionrate"] = x.get_n2_oemissionrate();
        j["NOemissionrate"] = x.get_n_oemissionrate();
        j["OxygenFluxInfil"] = x.get_oxygen_flux_infil();
    }

    inline void from_json(const json & j, coup::TentacledSoilmineralPProcesses& x) {
        x.set_p_surface_runoff(j.at("PSurfaceRunoff").get<coup::AlbedoVar>());
    }

    inline void to_json(json & j, const coup::TentacledSoilmineralPProcesses & x) {
        j = json::object();
        j["PSurfaceRunoff"] = x.get_p_surface_runoff();
    }

    inline void from_json(const json & j, coup::PurpleSoilorganicprocesses& x) {
        x.set_c_surface_l_litter1(j.at("CSurfaceLLitter1").get<coup::CanopyFracRadDiffuse>());
        x.set_c_surface_l_litter2(j.at("CSurfaceLLitter2").get<coup::CanopyFracRadDiffuse>());
        x.set_n_surface_l_litter1(j.at("NSurfaceLLitter1").get<coup::CanopyFracRadDiffuse>());
        x.set_n_surface_l_litter2(j.at("NSurfaceLLitter2").get<coup::CanopyFracRadDiffuse>());
        x.set_p_surface_l_litter1(j.at("PSurfaceLLitter1").get<coup::CanopyFracRadDiffuse>());
        x.set_p_surface_l_litter2(j.at("PSurfaceLLitter2").get<coup::CanopyFracRadDiffuse>());
    }

    inline void to_json(json & j, const coup::PurpleSoilorganicprocesses & x) {
        j = json::object();
        j["CSurfaceLLitter1"] = x.get_c_surface_l_litter1();
        j["CSurfaceLLitter2"] = x.get_c_surface_l_litter2();
        j["NSurfaceLLitter1"] = x.get_n_surface_l_litter1();
        j["NSurfaceLLitter2"] = x.get_n_surface_l_litter2();
        j["PSurfaceLLitter1"] = x.get_p_surface_l_litter1();
        j["PSurfaceLLitter2"] = x.get_p_surface_l_litter2();
    }

    inline void from_json(const json & j, coup::FlowNitrogenandCarbonBelowGround& x) {
        x.set_gasprocesses(j.at("Gasprocesses").get<coup::FluffyGasprocesses>());
        x.set_soilmineral_p_processes(j.at("SoilmineralPProcesses").get<coup::TentacledSoilmineralPProcesses>());
        x.set_soilorganicprocesses(j.at("Soilorganicprocesses").get<coup::PurpleSoilorganicprocesses>());
    }

    inline void to_json(json & j, const coup::FlowNitrogenandCarbonBelowGround & x) {
        j = json::object();
        j["Gasprocesses"] = x.get_gasprocesses();
        j["SoilmineralPProcesses"] = x.get_soilmineral_p_processes();
        j["Soilorganicprocesses"] = x.get_soilorganicprocesses();
    }

    inline void from_json(const json & j, coup::FlowPlantWaterProcesses& x) {
        x.set_salt_tracer(j.at("SaltTracer").get<std::map<std::string, coup::AlbedoVar>>());
    }

    inline void to_json(json & j, const coup::FlowPlantWaterProcesses & x) {
        j = json::object();
        j["SaltTracer"] = x.get_salt_tracer();
    }

    inline void from_json(const json & j, coup::Soilheatpump& x) {
        x.set_heat_pump_flow(j.at("HeatPumpFlow").get<coup::AlbedoVar>());
    }

    inline void to_json(json & j, const coup::Soilheatpump & x) {
        j = json::object();
        j["HeatPumpFlow"] = x.get_heat_pump_flow();
    }

    inline void from_json(const json & j, coup::FlowSoilHeatProcesses& x) {
        x.set_soilheatflows(j.at("Soilheatflows").get<std::map<std::string, coup::CanopyFracRadDiffuse>>());
        x.set_soilheatpump(j.at("Soilheatpump").get<coup::Soilheatpump>());
    }

    inline void to_json(json & j, const coup::FlowSoilHeatProcesses & x) {
        j = json::object();
        j["Soilheatflows"] = x.get_soilheatflows();
        j["Soilheatpump"] = x.get_soilheatpump();
    }

    inline void from_json(const json & j, coup::IndigoDrainageanddeeppercolation& x) {
        x.set_deep_perc(j.at("DeepPerc").get<coup::CanopyFracRadDiffuse>());
        x.set_net_emp_drainage(j.at("NetEmpDrainage").get<coup::CanopyFracRadDiffuse>());
        x.set_net_phys_drainage(j.at("NetPhysDrainage").get<coup::CanopyFracRadDiffuse>());
        x.set_total_drainage(j.at("TotalDrainage").get<coup::CanopyFracRadDiffuse>());
        x.set_total_runoff(j.at("TotalRunoff").get<coup::CanopyFracRadDiffuse>());
        x.set_v_drive_drain_level(j.at("vDriveDrainLevel").get<coup::CanopyFracRadDiffuse>());
    }

    inline void to_json(json & j, const coup::IndigoDrainageanddeeppercolation & x) {
        j = json::object();
        j["DeepPerc"] = x.get_deep_perc();
        j["NetEmpDrainage"] = x.get_net_emp_drainage();
        j["NetPhysDrainage"] = x.get_net_phys_drainage();
        j["TotalDrainage"] = x.get_total_drainage();
        j["TotalRunoff"] = x.get_total_runoff();
        j["vDriveDrainLevel"] = x.get_v_drive_drain_level();
    }

    inline void from_json(const json & j, coup::TentacledSoilwaterflows& x) {
        x.set_surface_out_flow(j.at("SurfaceOutFlow").get<coup::AlbedoVar>());
        x.set_vapourflow_surf(j.at("VapourflowSurf").get<coup::AlbedoVar>());
    }

    inline void to_json(json & j, const coup::TentacledSoilwaterflows & x) {
        j = json::object();
        j["SurfaceOutFlow"] = x.get_surface_out_flow();
        j["VapourflowSurf"] = x.get_vapourflow_surf();
    }

    inline void from_json(const json & j, coup::TentacledSurfacewater& x) {
        x.set_furrow_infil(j.at("FurrowInfil").get<coup::CanopyFracRadDiffuse>());
        x.set_furrow_prec(j.at("FurrowPrec").get<coup::CanopyFracRadDiffuse>());
        x.set_pump_in_flow(j.at("PumpInFlow").get<coup::CanopyFracRadDiffuse>());
        x.set_pump_out_flow(j.at("PumpOutFlow").get<coup::CanopyFracRadDiffuse>());
        x.set_soil_infil(j.at("SoilInfil").get<coup::CanopyFracRadDiffuse>());
        x.set_spool_delay_runoff(j.at("SpoolDelayRunoff").get<coup::CanopyFracRadDiffuse>());
        x.set_spoolinflow(j.at("Spoolinflow").get<coup::CanopyFracRadDiffuse>());
        x.set_spool_runoff(j.at("SpoolRunoff").get<coup::CanopyFracRadDiffuse>());
        x.set_spool_soil_infil(j.at("SpoolSoilInfil").get<coup::CanopyFracRadDiffuse>());
    }

    inline void to_json(json & j, const coup::TentacledSurfacewater & x) {
        j = json::object();
        j["FurrowInfil"] = x.get_furrow_infil();
        j["FurrowPrec"] = x.get_furrow_prec();
        j["PumpInFlow"] = x.get_pump_in_flow();
        j["PumpOutFlow"] = x.get_pump_out_flow();
        j["SoilInfil"] = x.get_soil_infil();
        j["SpoolDelayRunoff"] = x.get_spool_delay_runoff();
        j["Spoolinflow"] = x.get_spoolinflow();
        j["SpoolRunoff"] = x.get_spool_runoff();
        j["SpoolSoilInfil"] = x.get_spool_soil_infil();
    }

    inline void from_json(const json & j, coup::FlowSoilWaterProcesses& x) {
        x.set_drainageanddeeppercolation(j.at("Drainageanddeeppercolation").get<coup::IndigoDrainageanddeeppercolation>());
        x.set_soilwaterflows(j.at("Soilwaterflows").get<coup::TentacledSoilwaterflows>());
        x.set_surfacewater(j.at("Surfacewater").get<coup::TentacledSurfacewater>());
    }

    inline void to_json(json & j, const coup::FlowSoilWaterProcesses & x) {
        j = json::object();
        j["Drainageanddeeppercolation"] = x.get_drainageanddeeppercolation();
        j["Soilwaterflows"] = x.get_soilwaterflows();
        j["Surfacewater"] = x.get_surfacewater();
    }

    inline void from_json(const json & j, coup::Flow& x) {
        x.set_atmospheric_related_processes(j.at("AtmosphericRelatedProcesses").get<coup::FlowAtmosphericRelatedProcesses>());
        x.set_model_facilities(j.at("ModelFacilities").get<coup::FlowModelFacilities>());
        x.set_nitrogenand_carbon(j.at("NitrogenandCarbon").get<coup::FlowNitrogenandCarbon>());
        x.set_nitrogenand_carbon_below_ground(j.at("NitrogenandCarbon-BelowGround").get<coup::FlowNitrogenandCarbonBelowGround>());
        x.set_plant_water_processes(j.at("PlantWaterProcesses").get<coup::FlowPlantWaterProcesses>());
        x.set_soil_heat_processes(j.at("SoilHeatProcesses").get<coup::FlowSoilHeatProcesses>());
        x.set_soil_water_processes(j.at("SoilWaterProcesses").get<coup::FlowSoilWaterProcesses>());
    }

    inline void to_json(json & j, const coup::Flow & x) {
        j = json::object();
        j["AtmosphericRelatedProcesses"] = x.get_atmospheric_related_processes();
        j["ModelFacilities"] = x.get_model_facilities();
        j["NitrogenandCarbon"] = x.get_nitrogenand_carbon();
        j["NitrogenandCarbon-BelowGround"] = x.get_nitrogenand_carbon_below_ground();
        j["PlantWaterProcesses"] = x.get_plant_water_processes();
        j["SoilHeatProcesses"] = x.get_soil_heat_processes();
        j["SoilWaterProcesses"] = x.get_soil_water_processes();
    }

    inline void from_json(const json & j, coup::TentacledExternalNinputs& x) {
        x.set_deposition_n_leaf(j.at("DepositionNLeaf").get<coup::LaiAbovecanopy>());
    }

    inline void to_json(json & j, const coup::TentacledExternalNinputs & x) {
        j = json::object();
        j["DepositionNLeaf"] = x.get_deposition_n_leaf();
    }

    inline void from_json(const json & j, coup::FlowArraysNitrogenandCarbon& x) {
        x.set_external_ninputs(j.at("ExternalNinputs").get<coup::TentacledExternalNinputs>());
        x.set_plant_growth(j.at("PlantGrowth").get<std::map<std::string, coup::SnowReduceLaiFactor>>());
    }

    inline void to_json(json & j, const coup::FlowArraysNitrogenandCarbon & x) {
        j = json::object();
        j["ExternalNinputs"] = x.get_external_ninputs();
        j["PlantGrowth"] = x.get_plant_growth();
    }

    inline void from_json(const json & j, coup::StickySoilmineralPProcesses& x) {
        x.set_soil_phosphate_drainage(j.at("SoilPhosphateDrainage").get<coup::CCoarseRootsAtmLayer>());
        x.set_soil_phosphate_flow(j.at("SoilPhosphateFlow").get<coup::CCoarseRootsAtmLayer>());
        x.set_soil_phosphate_uptake(j.at("SoilPhosphateUptake").get<coup::CCoarseRootsAtmLayer>());
        x.set_weathering_rate(j.at("WeatheringRate").get<coup::CCoarseRootsAtmLayer>());
    }

    inline void to_json(json & j, const coup::StickySoilmineralPProcesses & x) {
        j = json::object();
        j["SoilPhosphateDrainage"] = x.get_soil_phosphate_drainage();
        j["SoilPhosphateFlow"] = x.get_soil_phosphate_flow();
        j["SoilPhosphateUptake"] = x.get_soil_phosphate_uptake();
        j["WeatheringRate"] = x.get_weathering_rate();
    }

    inline void from_json(const json & j, coup::FlowArraysNitrogenandCarbonBelowGround& x) {
        x.set_gasprocesses(j.at("Gasprocesses").get<std::map<std::string, coup::CCoarseRootsAtmLayer>>());
        x.set_soilmineral_nprocesses(j.at("SoilmineralNprocesses").get<std::map<std::string, coup::CCoarseRootsAtmLayer>>());
        x.set_soilmineral_p_processes(j.at("SoilmineralPProcesses").get<coup::StickySoilmineralPProcesses>());
        x.set_soilorganicprocesses(j.at("Soilorganicprocesses").get<std::map<std::string, coup::CCoarseRootsAtmLayer>>());
    }

    inline void to_json(json & j, const coup::FlowArraysNitrogenandCarbonBelowGround & x) {
        j = json::object();
        j["Gasprocesses"] = x.get_gasprocesses();
        j["SoilmineralNprocesses"] = x.get_soilmineral_nprocesses();
        j["SoilmineralPProcesses"] = x.get_soilmineral_p_processes();
        j["Soilorganicprocesses"] = x.get_soilorganicprocesses();
    }

    inline void from_json(const json & j, coup::StickyInterception& x) {
        x.set_canopy_interc_act_eva(j.at("CanopyIntercActEva").get<coup::LaiAbovecanopy>());
    }

    inline void to_json(json & j, const coup::StickyInterception & x) {
        j = json::object();
        j["CanopyIntercActEva"] = x.get_canopy_interc_act_eva();
    }

    inline void from_json(const json & j, coup::StickySaltTracer& x) {
        x.set_salt_drain_flow(j.at("SaltDrainFlow").get<coup::CCoarseRootsAtmLayer>());
        x.set_salt_flow(j.at("SaltFlow").get<coup::CCoarseRootsAtmLayer>());
        x.set_salt_plant_uptake(j.at("SaltPlantUptake").get<coup::CCoarseRootsAtmLayer>());
        x.set_salt_source_flow(j.at("SaltSourceFlow").get<coup::CCoarseRootsAtmLayer>());
        x.set_soil_resistivity(j.at("SoilResistivity").get<coup::CCoarseRootsAtmLayer>());
        x.set_te_grain_surface_litter(j.at("TEGrainSurfaceLitter").get<coup::SnowReduceLaiFactor>());
        x.set_te_humus_min_rate(j.at("TEHumusMinRate").get<coup::CCoarseRootsAtmLayer>());
        x.set_te_leaf_grain(j.at("TELeafGrain").get<coup::SnowReduceLaiFactor>());
        x.set_te_leaf_old_leaf(j.at("TELeafOldLeaf").get<coup::SnowReduceLaiFactor>());
        x.set_te_leaf_surface_litter(j.at("TELeafSurfaceLitter").get<coup::SnowReduceLaiFactor>());
        x.set_te_litter1_humus_rate(j.at("TELitter1HumusRate").get<coup::CCoarseRootsAtmLayer>());
        x.set_te_litter1_min_rate(j.at("TELitter1MinRate").get<coup::CCoarseRootsAtmLayer>());
        x.set_te_old_leaf_surface_litter(j.at("TEOldLeafSurfaceLitter").get<coup::SnowReduceLaiFactor>());
        x.set_te_old_roots_litter(j.at("TEOldRootsLitter").get<coup::SnowReduceLaiFactor>());
        x.set_te_old_stem_surface_litter(j.at("TEOldStemSurfaceLitter").get<coup::SnowReduceLaiFactor>());
        x.set_te_plant_leaf_uptake(j.at("TEPlantLeafUptake").get<coup::SnowReduceLaiFactor>());
        x.set_te_plant_root_uptake(j.at("TEPlantRootUptake").get<coup::SnowReduceLaiFactor>());
        x.set_te_plant_stem_uptake(j.at("TEPlantStemUptake").get<coup::SnowReduceLaiFactor>());
        x.set_te_roots_grain(j.at("TERootsGrain").get<coup::SnowReduceLaiFactor>());
        x.set_te_roots_litter(j.at("TERootsLitter").get<coup::SnowReduceLaiFactor>());
        x.set_te_roots_litter1(j.at("TERootsLitter1").get<coup::CCoarseRootsAtmLayer>());
        x.set_te_roots_old_roots(j.at("TERootsOldRoots").get<coup::SnowReduceLaiFactor>());
        x.set_te_stem_grain(j.at("TEStemGrain").get<coup::SnowReduceLaiFactor>());
        x.set_te_stem_old_stem(j.at("TEStemOldStem").get<coup::SnowReduceLaiFactor>());
        x.set_te_stem_surface_litter(j.at("TEStemSurfaceLitter").get<coup::SnowReduceLaiFactor>());
        x.set_water_resistivity(j.at("WaterResistivity").get<coup::CCoarseRootsAtmLayer>());
    }

    inline void to_json(json & j, const coup::StickySaltTracer & x) {
        j = json::object();
        j["SaltDrainFlow"] = x.get_salt_drain_flow();
        j["SaltFlow"] = x.get_salt_flow();
        j["SaltPlantUptake"] = x.get_salt_plant_uptake();
        j["SaltSourceFlow"] = x.get_salt_source_flow();
        j["SoilResistivity"] = x.get_soil_resistivity();
        j["TEGrainSurfaceLitter"] = x.get_te_grain_surface_litter();
        j["TEHumusMinRate"] = x.get_te_humus_min_rate();
        j["TELeafGrain"] = x.get_te_leaf_grain();
        j["TELeafOldLeaf"] = x.get_te_leaf_old_leaf();
        j["TELeafSurfaceLitter"] = x.get_te_leaf_surface_litter();
        j["TELitter1HumusRate"] = x.get_te_litter1_humus_rate();
        j["TELitter1MinRate"] = x.get_te_litter1_min_rate();
        j["TEOldLeafSurfaceLitter"] = x.get_te_old_leaf_surface_litter();
        j["TEOldRootsLitter"] = x.get_te_old_roots_litter();
        j["TEOldStemSurfaceLitter"] = x.get_te_old_stem_surface_litter();
        j["TEPlantLeafUptake"] = x.get_te_plant_leaf_uptake();
        j["TEPlantRootUptake"] = x.get_te_plant_root_uptake();
        j["TEPlantStemUptake"] = x.get_te_plant_stem_uptake();
        j["TERootsGrain"] = x.get_te_roots_grain();
        j["TERootsLitter"] = x.get_te_roots_litter();
        j["TERootsLitter1"] = x.get_te_roots_litter1();
        j["TERootsOldRoots"] = x.get_te_roots_old_roots();
        j["TEStemGrain"] = x.get_te_stem_grain();
        j["TEStemOldStem"] = x.get_te_stem_old_stem();
        j["TEStemSurfaceLitter"] = x.get_te_stem_surface_litter();
        j["WaterResistivity"] = x.get_water_resistivity();
    }

    inline void from_json(const json & j, coup::StickyWateruptake& x) {
        x.set_plant_water_uptake(j.at("PlantWaterUptake").get<coup::SnowReduceLaiFactor>());
        x.set_transpiration(j.at("Transpiration").get<coup::SnowReduceLaiFactor>());
        x.set_w_uptake_rate(j.at("WUptakeRate").get<coup::CCoarseRootsAtmLayer>());
    }

    inline void to_json(json & j, const coup::StickyWateruptake & x) {
        j = json::object();
        j["PlantWaterUptake"] = x.get_plant_water_uptake();
        j["Transpiration"] = x.get_transpiration();
        j["WUptakeRate"] = x.get_w_uptake_rate();
    }

    inline void from_json(const json & j, coup::FlowArraysPlantWaterProcesses& x) {
        x.set_interception(j.at("Interception").get<coup::StickyInterception>());
        x.set_salt_tracer(j.at("SaltTracer").get<coup::StickySaltTracer>());
        x.set_wateruptake(j.at("Wateruptake").get<coup::StickyWateruptake>());
    }

    inline void to_json(json & j, const coup::FlowArraysPlantWaterProcesses & x) {
        j = json::object();
        j["Interception"] = x.get_interception();
        j["SaltTracer"] = x.get_salt_tracer();
        j["Wateruptake"] = x.get_wateruptake();
    }

    inline void from_json(const json & j, coup::FluffySoilfrost& x) {
        x.set_in_freeze(j.at("InFreeze").get<coup::CCoarseRootsAtmLayer>());
        x.set_waterflow_hd_ld(j.at("WaterflowHD_LD").get<coup::CCoarseRootsAtmLayer>());
        x.set_waterflow_hfd(j.at("WaterflowHFD").get<coup::CCoarseRootsAtmLayer>());
        x.set_waterflow_ld_hd(j.at("WaterflowLD_HD").get<coup::CCoarseRootsAtmLayer>());
    }

    inline void to_json(json & j, const coup::FluffySoilfrost & x) {
        j = json::object();
        j["InFreeze"] = x.get_in_freeze();
        j["WaterflowHD_LD"] = x.get_waterflow_hd_ld();
        j["WaterflowHFD"] = x.get_waterflow_hfd();
        j["WaterflowLD_HD"] = x.get_waterflow_ld_hd();
    }

    inline void from_json(const json & j, coup::HeatBox& x) {
        x.set_array_name(j.at("ArrayName").get<std::string>());
        x.set_condition_1(j.at("Condition_1").get<coup::Condition3Enum>());
        x.set_condition_2(j.at("Condition_2").get<std::string>());
        x.set_out_multi_index_1(j.at("OutMulti_Index_1").get<std::string>());
        x.set_out_multi_index_2(j.at("OutMulti_Index_2").get<std::string>());
        x.set_out_multi_index_3(j.at("OutMulti_Index_3").get<std::string>());
        x.set_out_multi_index_4(j.at("OutMulti_Index_4").get<std::string>());
        x.set_out_single_index_1(j.at("OutSingle_Index_1").get<std::string>());
        x.set_out_single_index_2(j.at("OutSingle_Index_2").get<std::string>());
        x.set_out_single_index_3(j.at("OutSingle_Index_3").get<std::string>());
        x.set_out_single_index_4(j.at("OutSingle_Index_4").get<std::string>());
        x.set_sizeof_array(j.at("SizeofArray").get<std::string>());
    }

    inline void to_json(json & j, const coup::HeatBox & x) {
        j = json::object();
        j["ArrayName"] = x.get_array_name();
        j["Condition_1"] = x.get_condition_1();
        j["Condition_2"] = x.get_condition_2();
        j["OutMulti_Index_1"] = x.get_out_multi_index_1();
        j["OutMulti_Index_2"] = x.get_out_multi_index_2();
        j["OutMulti_Index_3"] = x.get_out_multi_index_3();
        j["OutMulti_Index_4"] = x.get_out_multi_index_4();
        j["OutSingle_Index_1"] = x.get_out_single_index_1();
        j["OutSingle_Index_2"] = x.get_out_single_index_2();
        j["OutSingle_Index_3"] = x.get_out_single_index_3();
        j["OutSingle_Index_4"] = x.get_out_single_index_4();
        j["SizeofArray"] = x.get_sizeof_array();
    }

    inline void from_json(const json & j, coup::TentacledSoilheatflows& x) {
        x.set_cold_pipe_flux(j.at("ColdPipeFlux").get<coup::TempColdPipe>());
        x.set_cold_pipe_sink_flux(j.at("ColdPipeSinkFlux").get<coup::TempColdPipe>());
        x.set_heat_box_boundary_flux(j.at("HeatBoxBoundaryFlux").get<coup::HeatBox>());
        x.set_heat_box_heater_flux(j.at("HeatBoxHeaterFlux").get<coup::HeatBox>());
        x.set_out_pipe_flux(j.at("OutPipeFlux").get<coup::TempColdPipe>());
        x.set_out_pipe_sink_flux(j.at("OutPipeSinkFlux").get<coup::TempColdPipe>());
        x.set_soil_heat_flow(j.at("SoilHeatFlow").get<coup::CCoarseRootsAtmLayer>());
        x.set_soil_heat_sink(j.at("SoilHeatSink").get<coup::CCoarseRootsAtmLayer>());
        x.set_soil_heat_source(j.at("SoilHeatSource").get<coup::CCoarseRootsAtmLayer>());
    }

    inline void to_json(json & j, const coup::TentacledSoilheatflows & x) {
        j = json::object();
        j["ColdPipeFlux"] = x.get_cold_pipe_flux();
        j["ColdPipeSinkFlux"] = x.get_cold_pipe_sink_flux();
        j["HeatBoxBoundaryFlux"] = x.get_heat_box_boundary_flux();
        j["HeatBoxHeaterFlux"] = x.get_heat_box_heater_flux();
        j["OutPipeFlux"] = x.get_out_pipe_flux();
        j["OutPipeSinkFlux"] = x.get_out_pipe_sink_flux();
        j["SoilHeatFlow"] = x.get_soil_heat_flow();
        j["SoilHeatSink"] = x.get_soil_heat_sink();
        j["SoilHeatSource"] = x.get_soil_heat_source();
    }

    inline void from_json(const json & j, coup::FlowArraysSoilHeatProcesses& x) {
        x.set_soilfrost(j.at("Soilfrost").get<coup::FluffySoilfrost>());
        x.set_soilheatflows(j.at("Soilheatflows").get<coup::TentacledSoilheatflows>());
    }

    inline void to_json(json & j, const coup::FlowArraysSoilHeatProcesses & x) {
        j = json::object();
        j["Soilfrost"] = x.get_soilfrost();
        j["Soilheatflows"] = x.get_soilheatflows();
    }

    inline void from_json(const json & j, coup::IndecentDrainageanddeeppercolation& x) {
        x.set_water_drainflow(j.at("WaterDrainflow").get<coup::CCoarseRootsAtmLayer>());
    }

    inline void to_json(json & j, const coup::IndecentDrainageanddeeppercolation & x) {
        j = json::object();
        j["WaterDrainflow"] = x.get_water_drainflow();
    }

    inline void from_json(const json & j, coup::StickySoilwaterflows& x) {
        x.set_vapourflow(j.at("Vapourflow").get<coup::CCoarseRootsAtmLayer>());
        x.set_waterflow(j.at("Waterflow").get<coup::CCoarseRootsAtmLayer>());
    }

    inline void to_json(json & j, const coup::StickySoilwaterflows & x) {
        j = json::object();
        j["Vapourflow"] = x.get_vapourflow();
        j["Waterflow"] = x.get_waterflow();
    }

    inline void from_json(const json & j, coup::FlowArraysSoilWaterProcesses& x) {
        x.set_drainageanddeeppercolation(j.at("Drainageanddeeppercolation").get<coup::IndecentDrainageanddeeppercolation>());
        x.set_soilwaterflows(j.at("Soilwaterflows").get<coup::StickySoilwaterflows>());
    }

    inline void to_json(json & j, const coup::FlowArraysSoilWaterProcesses & x) {
        j = json::object();
        j["Drainageanddeeppercolation"] = x.get_drainageanddeeppercolation();
        j["Soilwaterflows"] = x.get_soilwaterflows();
    }

    inline void from_json(const json & j, coup::FlowArrays& x) {
        x.set_nitrogenand_carbon(j.at("NitrogenandCarbon").get<coup::FlowArraysNitrogenandCarbon>());
        x.set_nitrogenand_carbon_below_ground(j.at("NitrogenandCarbon-BelowGround").get<coup::FlowArraysNitrogenandCarbonBelowGround>());
        x.set_plant_water_processes(j.at("PlantWaterProcesses").get<coup::FlowArraysPlantWaterProcesses>());
        x.set_soil_heat_processes(j.at("SoilHeatProcesses").get<coup::FlowArraysSoilHeatProcesses>());
        x.set_soil_water_processes(j.at("SoilWaterProcesses").get<coup::FlowArraysSoilWaterProcesses>());
    }

    inline void to_json(json & j, const coup::FlowArrays & x) {
        j = json::object();
        j["NitrogenandCarbon"] = x.get_nitrogenand_carbon();
        j["NitrogenandCarbon-BelowGround"] = x.get_nitrogenand_carbon_below_ground();
        j["PlantWaterProcesses"] = x.get_plant_water_processes();
        j["SoilHeatProcesses"] = x.get_soil_heat_processes();
        j["SoilWaterProcesses"] = x.get_soil_water_processes();
    }

    inline void from_json(const json & j, coup::StickySnowPack& x) {
        x.set_ice_in_snow_pack(j.at("IceInSnowPack").get<coup::AlbedoVar>());
        x.set_snow_depth(j.at("SnowDepth").get<coup::AlbedoVar>());
        x.set_total_snow_mass(j.at("TotalSnowMass").get<coup::AlbedoVar>());
        x.set_water_in_snow_pack(j.at("WaterInSnowPack").get<coup::AlbedoVar>());
    }

    inline void to_json(json & j, const coup::StickySnowPack & x) {
        j = json::object();
        j["IceInSnowPack"] = x.get_ice_in_snow_pack();
        j["SnowDepth"] = x.get_snow_depth();
        j["TotalSnowMass"] = x.get_total_snow_mass();
        j["WaterInSnowPack"] = x.get_water_in_snow_pack();
    }

    inline void from_json(const json & j, coup::StateAtmosphericRelatedProcesses& x) {
        x.set_snow_pack(j.at("SnowPack").get<coup::StickySnowPack>());
    }

    inline void to_json(json & j, const coup::StateAtmosphericRelatedProcesses & x) {
        j = json::object();
        j["SnowPack"] = x.get_snow_pack();
    }

    inline void from_json(const json & j, coup::FluffyIrrigation& x) {
        x.set_drip_container(j.at("DripContainer").get<coup::CanopyFracRadDiffuse>());
    }

    inline void to_json(json & j, const coup::FluffyIrrigation & x) {
        j = json::object();
        j["DripContainer"] = x.get_drip_container();
    }

    inline void from_json(const json & j, coup::StateModelFacilities& x) {
        x.set_irrigation(j.at("Irrigation").get<coup::FluffyIrrigation>());
    }

    inline void to_json(json & j, const coup::StateModelFacilities & x) {
        j = json::object();
        j["Irrigation"] = x.get_irrigation();
    }

    inline void from_json(const json & j, coup::StickyExternalNinputs& x) {
        x.set_n_fertilizer(j.at("NFertilizer").get<coup::AlbedoVar>());
    }

    inline void to_json(json & j, const coup::StickyExternalNinputs & x) {
        j = json::object();
        j["NFertilizer"] = x.get_n_fertilizer();
    }

    inline void from_json(const json & j, coup::FluffyExternalPInputs& x) {
        x.set_p_fertilizer(j.at("PFertilizer").get<coup::CanopyFracRadDiffuse>());
    }

    inline void to_json(json & j, const coup::FluffyExternalPInputs & x) {
        j = json::object();
        j["PFertilizer"] = x.get_p_fertilizer();
    }

    inline void from_json(const json & j, coup::TentacledPlantGrowth& x) {
        x.set_c_grazing_organism(j.at("CGrazingOrganism").get<coup::AlbedoVar>());
        x.set_c_wood_eater(j.at("CWoodEater").get<coup::AlbedoVar>());
        x.set_n_grazing_organism(j.at("NGrazingOrganism").get<coup::AlbedoVar>());
        x.set_n_wood_eater(j.at("NWoodEater").get<coup::AlbedoVar>());
    }

    inline void to_json(json & j, const coup::TentacledPlantGrowth & x) {
        j = json::object();
        j["CGrazingOrganism"] = x.get_c_grazing_organism();
        j["CWoodEater"] = x.get_c_wood_eater();
        j["NGrazingOrganism"] = x.get_n_grazing_organism();
        j["NWoodEater"] = x.get_n_wood_eater();
    }

    inline void from_json(const json & j, coup::StateNitrogenandCarbon& x) {
        x.set_external_ninputs(j.at("ExternalNinputs").get<coup::StickyExternalNinputs>());
        x.set_external_p_inputs(j.at("ExternalPInputs").get<coup::FluffyExternalPInputs>());
        x.set_plant_growth(j.at("PlantGrowth").get<coup::TentacledPlantGrowth>());
    }

    inline void to_json(json & j, const coup::StateNitrogenandCarbon & x) {
        j = json::object();
        j["ExternalNinputs"] = x.get_external_ninputs();
        j["ExternalPInputs"] = x.get_external_p_inputs();
        j["PlantGrowth"] = x.get_plant_growth();
    }

    inline void from_json(const json & j, coup::TentacledGasprocesses& x) {
        x.set_acc_ch4_bubble_emission(j.at("AccCH4BubbleEmission").get<coup::CanopyFracRadDiffuse>());
        x.set_acc_ch4_emission(j.at("AccCH4Emission").get<coup::CanopyFracRadDiffuse>());
        x.set_acc_ch4_oxidation(j.at("AccCH4Oxidation").get<coup::CanopyFracRadDiffuse>());
        x.set_acc_ch4_plant_emission(j.at("AccCH4PlantEmission").get<coup::CanopyFracRadDiffuse>());
        x.set_acc_ch4_production(j.at("AccCH4Production").get<coup::CanopyFracRadDiffuse>());
        x.set_ch4_massbalance_check(j.at("CH4MassbalanceCheck").get<coup::CanopyFracRadDiffuse>());
        x.set_diff_ch4_storage(j.at("DiffCH4Storage").get<coup::CanopyFracRadDiffuse>());
    }

    inline void to_json(json & j, const coup::TentacledGasprocesses & x) {
        j = json::object();
        j["AccCH4BubbleEmission"] = x.get_acc_ch4_bubble_emission();
        j["AccCH4Emission"] = x.get_acc_ch4_emission();
        j["AccCH4Oxidation"] = x.get_acc_ch4_oxidation();
        j["AccCH4PlantEmission"] = x.get_acc_ch4_plant_emission();
        j["AccCH4Production"] = x.get_acc_ch4_production();
        j["CH4MassbalanceCheck"] = x.get_ch4_massbalance_check();
        j["DiffCH4Storage"] = x.get_diff_ch4_storage();
    }

    inline void from_json(const json & j, coup::IndigoSoilmineralPProcesses& x) {
        x.set_p_min_balance_check(j.at("PMinBalanceCheck").get<coup::AlbedoVar>());
    }

    inline void to_json(json & j, const coup::IndigoSoilmineralPProcesses & x) {
        j = json::object();
        j["PMinBalanceCheck"] = x.get_p_min_balance_check();
    }

    inline void from_json(const json & j, coup::FluffySoilorganicprocesses& x) {
        x.set_c_surface_litter1(j.at("CSurfaceLitter1").get<coup::CanopyFracRadDiffuse>());
        x.set_c_surface_litter2(j.at("CSurfaceLitter2").get<coup::CanopyFracRadDiffuse>());
        x.set_n_surface_litter1(j.at("NSurfaceLitter1").get<coup::CanopyFracRadDiffuse>());
        x.set_n_surface_litter2(j.at("NSurfaceLitter2").get<coup::CanopyFracRadDiffuse>());
        x.set_p_surface_litter1(j.at("PSurfaceLitter1").get<coup::CanopyFracRadDiffuse>());
        x.set_p_surface_litter2(j.at("PSurfaceLitter2").get<coup::CanopyFracRadDiffuse>());
    }

    inline void to_json(json & j, const coup::FluffySoilorganicprocesses & x) {
        j = json::object();
        j["CSurfaceLitter1"] = x.get_c_surface_litter1();
        j["CSurfaceLitter2"] = x.get_c_surface_litter2();
        j["NSurfaceLitter1"] = x.get_n_surface_litter1();
        j["NSurfaceLitter2"] = x.get_n_surface_litter2();
        j["PSurfaceLitter1"] = x.get_p_surface_litter1();
        j["PSurfaceLitter2"] = x.get_p_surface_litter2();
    }

    inline void from_json(const json & j, coup::StateNitrogenandCarbonBelowGround& x) {
        x.set_gasprocesses(j.at("Gasprocesses").get<coup::TentacledGasprocesses>());
        x.set_soilmineral_p_processes(j.at("SoilmineralPProcesses").get<coup::IndigoSoilmineralPProcesses>());
        x.set_soilorganicprocesses(j.at("Soilorganicprocesses").get<coup::FluffySoilorganicprocesses>());
    }

    inline void to_json(json & j, const coup::StateNitrogenandCarbonBelowGround & x) {
        j = json::object();
        j["Gasprocesses"] = x.get_gasprocesses();
        j["SoilmineralPProcesses"] = x.get_soilmineral_p_processes();
        j["Soilorganicprocesses"] = x.get_soilorganicprocesses();
    }

    inline void from_json(const json & j, coup::IndigoSaltTracer& x) {
        x.set_acc_salt_input(j.at("AccSaltInput").get<coup::AlbedoVar>());
        x.set_acc_salt_output(j.at("AccSaltOutput").get<coup::AlbedoVar>());
        x.set_salt_close_to_road(j.at("SaltCloseToRoad").get<coup::AlbedoVar>());
        x.set_saltin_snow_pack(j.at("SaltinSnowPack").get<coup::AlbedoVar>());
        x.set_salt_on_road(j.at("SaltOnRoad").get<coup::AlbedoVar>());
        x.set_te_balance(j.at("TE_Balance").get<coup::AlbedoVar>());
        x.set_te_surface_litter(j.at("TESurfaceLitter").get<coup::AlbedoVar>());
    }

    inline void to_json(json & j, const coup::IndigoSaltTracer & x) {
        j = json::object();
        j["AccSaltInput"] = x.get_acc_salt_input();
        j["AccSaltOutput"] = x.get_acc_salt_output();
        j["SaltCloseToRoad"] = x.get_salt_close_to_road();
        j["SaltinSnowPack"] = x.get_saltin_snow_pack();
        j["SaltOnRoad"] = x.get_salt_on_road();
        j["TE_Balance"] = x.get_te_balance();
        j["TESurfaceLitter"] = x.get_te_surface_litter();
    }

    inline void from_json(const json & j, coup::StatePlantWaterProcesses& x) {
        x.set_salt_tracer(j.at("SaltTracer").get<coup::IndigoSaltTracer>());
    }

    inline void to_json(json & j, const coup::StatePlantWaterProcesses & x) {
        j = json::object();
        j["SaltTracer"] = x.get_salt_tracer();
    }

    inline void from_json(const json & j, coup::StickySoilheatflows& x) {
        x.set_sewage_heat_store(j.at("SewageHeatStore").get<coup::CanopyFracRadDiffuse>());
        x.set_sewage_water_store(j.at("SewageWaterStore").get<coup::CanopyFracRadDiffuse>());
        x.set_travel_distance(j.at("TravelDistance").get<coup::CanopyFracRadDiffuse>());
    }

    inline void to_json(json & j, const coup::StickySoilheatflows & x) {
        j = json::object();
        j["SewageHeatStore"] = x.get_sewage_heat_store();
        j["SewageWaterStore"] = x.get_sewage_water_store();
        j["TravelDistance"] = x.get_travel_distance();
    }

    inline void from_json(const json & j, coup::StateSoilHeatProcesses& x) {
        x.set_soilheatflows(j.at("Soilheatflows").get<coup::StickySoilheatflows>());
    }

    inline void to_json(json & j, const coup::StateSoilHeatProcesses & x) {
        j = json::object();
        j["Soilheatflows"] = x.get_soilheatflows();
    }

    inline void from_json(const json & j, coup::StickySurfacewater& x) {
        x.set_pump_pool(j.at("PumpPool").get<coup::AlbedoVar>());
        x.set_surface_pool(j.at("SurfacePool").get<coup::AlbedoVar>());
    }

    inline void to_json(json & j, const coup::StickySurfacewater & x) {
        j = json::object();
        j["PumpPool"] = x.get_pump_pool();
        j["SurfacePool"] = x.get_surface_pool();
    }

    inline void from_json(const json & j, coup::StateSoilWaterProcesses& x) {
        x.set_surfacewater(j.at("Surfacewater").get<coup::StickySurfacewater>());
    }

    inline void to_json(json & j, const coup::StateSoilWaterProcesses & x) {
        j = json::object();
        j["Surfacewater"] = x.get_surfacewater();
    }

    inline void from_json(const json & j, coup::State& x) {
        x.set_atmospheric_related_processes(j.at("AtmosphericRelatedProcesses").get<coup::StateAtmosphericRelatedProcesses>());
        x.set_model_facilities(j.at("ModelFacilities").get<coup::StateModelFacilities>());
        x.set_nitrogenand_carbon(j.at("NitrogenandCarbon").get<coup::StateNitrogenandCarbon>());
        x.set_nitrogenand_carbon_below_ground(j.at("NitrogenandCarbon-BelowGround").get<coup::StateNitrogenandCarbonBelowGround>());
        x.set_plant_water_processes(j.at("PlantWaterProcesses").get<coup::StatePlantWaterProcesses>());
        x.set_soil_heat_processes(j.at("SoilHeatProcesses").get<coup::StateSoilHeatProcesses>());
        x.set_soil_water_processes(j.at("SoilWaterProcesses").get<coup::StateSoilWaterProcesses>());
    }

    inline void to_json(json & j, const coup::State & x) {
        j = json::object();
        j["AtmosphericRelatedProcesses"] = x.get_atmospheric_related_processes();
        j["ModelFacilities"] = x.get_model_facilities();
        j["NitrogenandCarbon"] = x.get_nitrogenand_carbon();
        j["NitrogenandCarbon-BelowGround"] = x.get_nitrogenand_carbon_below_ground();
        j["PlantWaterProcesses"] = x.get_plant_water_processes();
        j["SoilHeatProcesses"] = x.get_soil_heat_processes();
        j["SoilWaterProcesses"] = x.get_soil_water_processes();
    }

    inline void from_json(const json & j, coup::StateArraysNitrogenandCarbon& x) {
        x.set_plant_growth(j.at("PlantGrowth").get<std::map<std::string, coup::LaiAbovecanopy>>());
    }

    inline void to_json(json & j, const coup::StateArraysNitrogenandCarbon & x) {
        j = json::object();
        j["PlantGrowth"] = x.get_plant_growth();
    }

    inline void from_json(const json & j, coup::StickyGasprocesses& x) {
        x.set_co2_soil(j.at("CO2Soil").get<coup::CCoarseRootsAtmLayer>());
        x.set_methanecontent(j.at("Methanecontent").get<coup::CCoarseRootsAtmLayer>());
        x.set_nitric_oxide(j.at("NitricOxide").get<coup::CCoarseRootsAtmLayer>());
        x.set_nitrogengas(j.at("Nitrogengas").get<coup::CCoarseRootsAtmLayer>());
        x.set_nitrous_oxide(j.at("NitrousOxide").get<coup::CCoarseRootsAtmLayer>());
        x.set_oxygen(j.at("Oxygen").get<coup::CCoarseRootsAtmLayer>());
    }

    inline void to_json(json & j, const coup::StickyGasprocesses & x) {
        j = json::object();
        j["CO2Soil"] = x.get_co2_soil();
        j["Methanecontent"] = x.get_methanecontent();
        j["NitricOxide"] = x.get_nitric_oxide();
        j["Nitrogengas"] = x.get_nitrogengas();
        j["NitrousOxide"] = x.get_nitrous_oxide();
        j["Oxygen"] = x.get_oxygen();
    }

    inline void from_json(const json & j, coup::IndecentSoilmineralPProcesses& x) {
        x.set_soilmineral_p(j.at("SoilmineralP").get<coup::CCoarseRootsAtmLayer>());
        x.set_soil_phosphate(j.at("SoilPhosphate").get<coup::CCoarseRootsAtmLayer>());
    }

    inline void to_json(json & j, const coup::IndecentSoilmineralPProcesses & x) {
        j = json::object();
        j["SoilmineralP"] = x.get_soilmineral_p();
        j["SoilPhosphate"] = x.get_soil_phosphate();
    }

    inline void from_json(const json & j, coup::StateArraysNitrogenandCarbonBelowGround& x) {
        x.set_gasprocesses(j.at("Gasprocesses").get<coup::StickyGasprocesses>());
        x.set_soilmineral_nprocesses(j.at("SoilmineralNprocesses").get<std::map<std::string, coup::CCoarseRootsAtmLayer>>());
        x.set_soilmineral_p_processes(j.at("SoilmineralPProcesses").get<coup::IndecentSoilmineralPProcesses>());
        x.set_soilorganicprocesses(j.at("Soilorganicprocesses").get<std::map<std::string, coup::CCoarseRootsAtmLayer>>());
    }

    inline void to_json(json & j, const coup::StateArraysNitrogenandCarbonBelowGround & x) {
        j = json::object();
        j["Gasprocesses"] = x.get_gasprocesses();
        j["SoilmineralNprocesses"] = x.get_soilmineral_nprocesses();
        j["SoilmineralPProcesses"] = x.get_soilmineral_p_processes();
        j["Soilorganicprocesses"] = x.get_soilorganicprocesses();
    }

    inline void from_json(const json & j, coup::IndigoInterception& x) {
        x.set_canopy_interc_storage(j.at("CanopyIntercStorage").get<coup::SnowReduceLaiFactor>());
    }

    inline void to_json(json & j, const coup::IndigoInterception & x) {
        j = json::object();
        j["CanopyIntercStorage"] = x.get_canopy_interc_storage();
    }

    inline void from_json(const json & j, coup::IndecentSaltTracer& x) {
        x.set_salt_storage(j.at("SaltStorage").get<coup::CCoarseRootsAtmLayer>());
        x.set_te_grain(j.at("TEGrain").get<coup::LaiAbovecanopy>());
        x.set_te_humus(j.at("TEHumus").get<coup::CCoarseRootsAtmLayer>());
        x.set_te_leaf(j.at("TELeaf").get<coup::LaiAbovecanopy>());
        x.set_te_litter1(j.at("TELitter1").get<coup::CCoarseRootsAtmLayer>());
        x.set_te_old_leaf(j.at("TEOldLeaf").get<coup::LaiAbovecanopy>());
        x.set_te_old_roots(j.at("TEOldRoots").get<coup::LaiAbovecanopy>());
        x.set_te_old_stem(j.at("TEOldStem").get<coup::LaiAbovecanopy>());
        x.set_te_roots(j.at("TERoots").get<coup::LaiAbovecanopy>());
        x.set_te_stem(j.at("TEStem").get<coup::LaiAbovecanopy>());
    }

    inline void to_json(json & j, const coup::IndecentSaltTracer & x) {
        j = json::object();
        j["SaltStorage"] = x.get_salt_storage();
        j["TEGrain"] = x.get_te_grain();
        j["TEHumus"] = x.get_te_humus();
        j["TELeaf"] = x.get_te_leaf();
        j["TELitter1"] = x.get_te_litter1();
        j["TEOldLeaf"] = x.get_te_old_leaf();
        j["TEOldRoots"] = x.get_te_old_roots();
        j["TEOldStem"] = x.get_te_old_stem();
        j["TERoots"] = x.get_te_roots();
        j["TEStem"] = x.get_te_stem();
    }

    inline void from_json(const json & j, coup::IndigoWateruptake& x) {
        x.set_plant_water(j.at("PlantWater").get<coup::SnowReduceLaiFactor>());
    }

    inline void to_json(json & j, const coup::IndigoWateruptake & x) {
        j = json::object();
        j["PlantWater"] = x.get_plant_water();
    }

    inline void from_json(const json & j, coup::StateArraysPlantWaterProcesses& x) {
        x.set_interception(j.at("Interception").get<coup::IndigoInterception>());
        x.set_salt_tracer(j.at("SaltTracer").get<coup::IndecentSaltTracer>());
        x.set_wateruptake(j.at("Wateruptake").get<coup::IndigoWateruptake>());
    }

    inline void to_json(json & j, const coup::StateArraysPlantWaterProcesses & x) {
        j = json::object();
        j["Interception"] = x.get_interception();
        j["SaltTracer"] = x.get_salt_tracer();
        j["Wateruptake"] = x.get_wateruptake();
    }

    inline void from_json(const json & j, coup::TentacledSoilfrost& x) {
        x.set_water_hfd(j.at("WaterHFD").get<coup::CCoarseRootsAtmLayer>());
    }

    inline void to_json(json & j, const coup::TentacledSoilfrost & x) {
        j = json::object();
        j["WaterHFD"] = x.get_water_hfd();
    }

    inline void from_json(const json & j, coup::IndigoSoilheatflows& x) {
        x.set_cold_pipe_heat(j.at("ColdPipeHeat").get<coup::TempColdPipe>());
        x.set_heat_box_storage(j.at("HeatBoxStorage").get<coup::HeatBox>());
        x.set_heat_box_temp(j.at("HeatBoxTemp").get<coup::HeatBox>());
        x.set_out_pipe_heat(j.at("OutPipeHeat").get<coup::TempColdPipe>());
        x.set_soil_heat(j.at("SoilHeat").get<coup::CCoarseRootsAtmLayer>());
    }

    inline void to_json(json & j, const coup::IndigoSoilheatflows & x) {
        j = json::object();
        j["ColdPipeHeat"] = x.get_cold_pipe_heat();
        j["HeatBoxStorage"] = x.get_heat_box_storage();
        j["HeatBoxTemp"] = x.get_heat_box_temp();
        j["OutPipeHeat"] = x.get_out_pipe_heat();
        j["SoilHeat"] = x.get_soil_heat();
    }

    inline void from_json(const json & j, coup::StateArraysSoilHeatProcesses& x) {
        x.set_soilfrost(j.at("Soilfrost").get<coup::TentacledSoilfrost>());
        x.set_soilheatflows(j.at("Soilheatflows").get<coup::IndigoSoilheatflows>());
    }

    inline void to_json(json & j, const coup::StateArraysSoilHeatProcesses & x) {
        j = json::object();
        j["Soilfrost"] = x.get_soilfrost();
        j["Soilheatflows"] = x.get_soilheatflows();
    }

    inline void from_json(const json & j, coup::IndigoSoilwaterflows& x) {
        x.set_water_storage(j.at("WaterStorage").get<coup::CCoarseRootsAtmLayer>());
    }

    inline void to_json(json & j, const coup::IndigoSoilwaterflows & x) {
        j = json::object();
        j["WaterStorage"] = x.get_water_storage();
    }

    inline void from_json(const json & j, coup::StateArraysSoilWaterProcesses& x) {
        x.set_soilwaterflows(j.at("Soilwaterflows").get<coup::IndigoSoilwaterflows>());
    }

    inline void to_json(json & j, const coup::StateArraysSoilWaterProcesses & x) {
        j = json::object();
        j["Soilwaterflows"] = x.get_soilwaterflows();
    }

    inline void from_json(const json & j, coup::StateArrays& x) {
        x.set_nitrogenand_carbon(j.at("NitrogenandCarbon").get<coup::StateArraysNitrogenandCarbon>());
        x.set_nitrogenand_carbon_below_ground(j.at("NitrogenandCarbon-BelowGround").get<coup::StateArraysNitrogenandCarbonBelowGround>());
        x.set_plant_water_processes(j.at("PlantWaterProcesses").get<coup::StateArraysPlantWaterProcesses>());
        x.set_soil_heat_processes(j.at("SoilHeatProcesses").get<coup::StateArraysSoilHeatProcesses>());
        x.set_soil_water_processes(j.at("SoilWaterProcesses").get<coup::StateArraysSoilWaterProcesses>());
    }

    inline void to_json(json & j, const coup::StateArrays & x) {
        j = json::object();
        j["NitrogenandCarbon"] = x.get_nitrogenand_carbon();
        j["NitrogenandCarbon-BelowGround"] = x.get_nitrogenand_carbon_below_ground();
        j["PlantWaterProcesses"] = x.get_plant_water_processes();
        j["SoilHeatProcesses"] = x.get_soil_heat_processes();
        j["SoilWaterProcesses"] = x.get_soil_water_processes();
    }

    inline void from_json(const json & j, coup::OutputVariables& x) {
        x.set_auxiliary(j.at("Auxiliary").get<coup::Auxiliary>());
        x.set_auxiliary_arrays(j.at("Auxiliary_Arrays").get<coup::AuxiliaryArrays>());
        x.set_driving(j.at("Driving").get<coup::Driving>());
        x.set_driving_arrays(j.at("Driving_Arrays").get<coup::DrivingArrays>());
        x.set_flow(j.at("Flow").get<coup::Flow>());
        x.set_flow_arrays(j.at("Flow_Arrays").get<coup::FlowArrays>());
        x.set_state(j.at("State").get<coup::State>());
        x.set_state_arrays(j.at("State_Arrays").get<coup::StateArrays>());
    }

    inline void to_json(json & j, const coup::OutputVariables & x) {
        j = json::object();
        j["Auxiliary"] = x.get_auxiliary();
        j["Auxiliary_Arrays"] = x.get_auxiliary_arrays();
        j["Driving"] = x.get_driving();
        j["Driving_Arrays"] = x.get_driving_arrays();
        j["Flow"] = x.get_flow();
        j["Flow_Arrays"] = x.get_flow_arrays();
        j["State"] = x.get_state();
        j["State_Arrays"] = x.get_state_arrays();
    }

    inline void from_json(const json & j, coup::IndigoSnowPack& x) {
        x.set_density_coef_mass(j.at("DensityCoefMass").get<coup::PrecInput>());
        x.set_density_coef_water(j.at("DensityCoefWater").get<coup::PrecInput>());
        x.set_melt_coef_air_temp(j.at("MeltCoefAirTemp").get<coup::PrecInput>());
        x.set_melt_coef_glob_rad(j.at("MeltCoefGlobRad").get<coup::PrecInput>());
        x.set_melt_coef_glob_rad_age1(j.at("MeltCoefGlobRadAge1").get<coup::PrecInput>());
    }

    inline void to_json(json & j, const coup::IndigoSnowPack & x) {
        j = json::object();
        j["DensityCoefMass"] = x.get_density_coef_mass();
        j["DensityCoefWater"] = x.get_density_coef_water();
        j["MeltCoefAirTemp"] = x.get_melt_coef_air_temp();
        j["MeltCoefGlobRad"] = x.get_melt_coef_glob_rad();
        j["MeltCoefGlobRadAge1"] = x.get_melt_coef_glob_rad_age1();
    }

    inline void from_json(const json & j, coup::ParametersAtmosphericRelatedProcesses& x) {
        x.set_snow_pack(j.at("SnowPack").get<coup::IndigoSnowPack>());
    }

    inline void to_json(json & j, const coup::ParametersAtmosphericRelatedProcesses & x) {
        j = json::object();
        j["SnowPack"] = x.get_snow_pack();
    }

    inline void from_json(const json & j, coup::TentacledModelStructure& x) {
        x.set_xa_div(j.at("XADiv").get<coup::PrecInput>());
        x.set_xloop(j.at("Xloop").get<coup::PrecInput>());
        x.set_xn_lev(j.at("XNLev").get<coup::PrecInput>());
    }

    inline void to_json(json & j, const coup::TentacledModelStructure & x) {
        j = json::object();
        j["XADiv"] = x.get_xa_div();
        j["Xloop"] = x.get_xloop();
        j["XNLev"] = x.get_xn_lev();
    }

    inline void from_json(const json & j, coup::ParametersModelStructure& x) {
        x.set_model_structure(j.at("ModelStructure").get<coup::TentacledModelStructure>());
    }

    inline void to_json(json & j, const coup::ParametersModelStructure & x) {
        j = json::object();
        j["ModelStructure"] = x.get_model_structure();
    }

    inline void from_json(const json & j, coup::IndecentWateruptake& x) {
        x.set_crit_threshold_dry(j.at("CritThresholdDry").get<coup::PrecInput>());
    }

    inline void to_json(json & j, const coup::IndecentWateruptake & x) {
        j = json::object();
        j["CritThresholdDry"] = x.get_crit_threshold_dry();
    }

    inline void from_json(const json & j, coup::ParametersPlantWaterProcesses& x) {
        x.set_wateruptake(j.at("Wateruptake").get<coup::IndecentWateruptake>());
    }

    inline void to_json(json & j, const coup::ParametersPlantWaterProcesses & x) {
        j = json::object();
        j["Wateruptake"] = x.get_wateruptake();
    }

    inline void from_json(const json & j, coup::SoilThermal& x) {
        x.set_clay_frozen_c1(j.at("ClayFrozenC1").get<coup::PrecInput>());
        x.set_sand_frozen_c1(j.at("SandFrozenC1").get<coup::PrecInput>());
    }

    inline void to_json(json & j, const coup::SoilThermal & x) {
        j = json::object();
        j["ClayFrozenC1"] = x.get_clay_frozen_c1();
        j["SandFrozenC1"] = x.get_sand_frozen_c1();
    }

    inline void from_json(const json & j, coup::StickySoilfrost& x) {
        x.set_alpha_heat_coef(j.at("AlphaHeatCoef").get<coup::PrecInput>());
        x.set_freezepoint_f0(j.at("FreezepointF0").get<coup::PrecInput>());
        x.set_freezepoint_f_wi(j.at("FreezepointFWi").get<coup::PrecInput>());
        x.set_high_flow_damp_c(j.at("HighFlowDampC").get<coup::PrecInput>());
    }

    inline void to_json(json & j, const coup::StickySoilfrost & x) {
        j = json::object();
        j["AlphaHeatCoef"] = x.get_alpha_heat_coef();
        j["FreezepointF0"] = x.get_freezepoint_f0();
        j["FreezepointFWi"] = x.get_freezepoint_f_wi();
        j["HighFlowDampC"] = x.get_high_flow_damp_c();
    }

    inline void from_json(const json & j, coup::IndecentSoilheatflows& x) {
        x.set_soil_init_temp_const(j.at("SoilInitTempConst").get<coup::EvaporationMethod>());
    }

    inline void to_json(json & j, const coup::IndecentSoilheatflows & x) {
        j = json::object();
        j["SoilInitTempConst"] = x.get_soil_init_temp_const();
    }

    inline void from_json(const json & j, coup::ParametersSoilHeatProcesses& x) {
        x.set_soilfrost(j.at("Soilfrost").get<coup::StickySoilfrost>());
        x.set_soilheatflows(j.at("Soilheatflows").get<coup::IndecentSoilheatflows>());
        x.set_soil_thermal(j.at("SoilThermal").get<coup::SoilThermal>());
    }

    inline void to_json(json & j, const coup::ParametersSoilHeatProcesses & x) {
        j = json::object();
        j["Soilfrost"] = x.get_soilfrost();
        j["Soilheatflows"] = x.get_soilheatflows();
        j["SoilThermal"] = x.get_soil_thermal();
    }

    inline void from_json(const json & j, coup::HilariousDrainageanddeeppercolation& x) {
        x.set_emp_gf_lev_base(j.at("EmpGFLevBase").get<coup::PrecInput>());
        x.set_emp_gf_lev_peak(j.at("EmpGFLevPeak").get<coup::PrecInput>());
        x.set_emp_gf_lowbase(j.at("EmpGFLowbase").get<coup::PrecInput>());
        x.set_emp_g_flow_peak(j.at("EmpGFlowPeak").get<coup::PrecInput>());
        x.set_h_flow_input_index(j.at("HFlowInputIndex").get<coup::PrecInput>());
        x.set_h_flow_output_index(j.at("HFlowOutputIndex").get<coup::PrecInput>());
    }

    inline void to_json(json & j, const coup::HilariousDrainageanddeeppercolation & x) {
        j = json::object();
        j["EmpGFLevBase"] = x.get_emp_gf_lev_base();
        j["EmpGFLevPeak"] = x.get_emp_gf_lev_peak();
        j["EmpGFLowbase"] = x.get_emp_gf_lowbase();
        j["EmpGFlowPeak"] = x.get_emp_g_flow_peak();
        j["HFlowInputIndex"] = x.get_h_flow_input_index();
        j["HFlowOutputIndex"] = x.get_h_flow_output_index();
    }

    inline void from_json(const json & j, coup::IndecentSoilwaterflows& x) {
        x.set_initial_ground_water(j.at("InitialGroundWater").get<coup::EvaporationMethod>());
    }

    inline void to_json(json & j, const coup::IndecentSoilwaterflows & x) {
        j = json::object();
        j["InitialGroundWater"] = x.get_initial_ground_water();
    }

    inline void from_json(const json & j, coup::IndigoSurfacewater& x) {
        x.set_surf_coef(j.at("SurfCoef").get<coup::PrecInput>());
    }

    inline void to_json(json & j, const coup::IndigoSurfacewater & x) {
        j = json::object();
        j["SurfCoef"] = x.get_surf_coef();
    }

    inline void from_json(const json & j, coup::ParametersSoilWaterProcesses& x) {
        x.set_drainageanddeeppercolation(j.at("Drainageanddeeppercolation").get<coup::HilariousDrainageanddeeppercolation>());
        x.set_soilwaterflows(j.at("Soilwaterflows").get<coup::IndecentSoilwaterflows>());
        x.set_surfacewater(j.at("Surfacewater").get<coup::IndigoSurfacewater>());
    }

    inline void to_json(json & j, const coup::ParametersSoilWaterProcesses & x) {
        j = json::object();
        j["Drainageanddeeppercolation"] = x.get_drainageanddeeppercolation();
        j["Soilwaterflows"] = x.get_soilwaterflows();
        j["Surfacewater"] = x.get_surfacewater();
    }

    inline void from_json(const json & j, coup::Parameters& x) {
        x.set_atmospheric_related_processes(j.at("AtmosphericRelatedProcesses").get<coup::ParametersAtmosphericRelatedProcesses>());
        x.set_model_structure(j.at("ModelStructure").get<coup::ParametersModelStructure>());
        x.set_plant_water_processes(j.at("PlantWaterProcesses").get<coup::ParametersPlantWaterProcesses>());
        x.set_soil_heat_processes(j.at("SoilHeatProcesses").get<coup::ParametersSoilHeatProcesses>());
        x.set_soil_water_processes(j.at("SoilWaterProcesses").get<coup::ParametersSoilWaterProcesses>());
    }

    inline void to_json(json & j, const coup::Parameters & x) {
        j = json::object();
        j["AtmosphericRelatedProcesses"] = x.get_atmospheric_related_processes();
        j["ModelStructure"] = x.get_model_structure();
        j["PlantWaterProcesses"] = x.get_plant_water_processes();
        j["SoilHeatProcesses"] = x.get_soil_heat_processes();
        j["SoilWaterProcesses"] = x.get_soil_water_processes();
    }

    inline void from_json(const json & j, coup::KonzelmannCoef& x) {
        x.set_array_name(j.at("ArrayName").get<std::string>());
        x.set_condition_1(j.at("Condition_1").get<coup::Condition3Enum>());
        x.set_condition_2(coup::get_optional<std::string>(j, "Condition_2"));
        x.set_condition_3(coup::get_optional<std::string>(j, "Condition_3"));
        x.set_condition_4(coup::get_optional<std::string>(j, "Condition_4"));
        x.set_default_index_1(j.at("Default_Index_1").get<std::string>());
        x.set_default_index_2(j.at("Default_Index_2").get<std::string>());
        x.set_default_index_3(j.at("Default_Index_3").get<std::string>());
        x.set_default_index_4(coup::get_optional<std::string>(j, "Default_Index_4"));
        x.set_index_1(j.at("Index_1").get<std::string>());
        x.set_index_2(j.at("Index_2").get<std::string>());
        x.set_index_3(j.at("Index_3").get<std::string>());
        x.set_index_4(coup::get_optional<std::string>(j, "Index_4"));
        x.set_max_value_index_1(j.at("MaxValue_Index_1").get<std::string>());
        x.set_max_value_index_2(j.at("MaxValue_Index_2").get<std::string>());
        x.set_max_value_index_3(j.at("MaxValue_Index_3").get<std::string>());
        x.set_max_value_index_4(coup::get_optional<std::string>(j, "MaxValue_Index_4"));
        x.set_min_value_index_1(j.at("MinValue_Index_1").get<std::string>());
        x.set_min_value_index_2(j.at("MinValue_Index_2").get<std::string>());
        x.set_min_value_index_3(j.at("MinValue_Index_3").get<std::string>());
        x.set_min_value_index_4(coup::get_optional<std::string>(j, "MinValue_Index_4"));
        x.set_sizeof_array(j.at("SizeofArray").get<std::string>());
    }

    inline void to_json(json & j, const coup::KonzelmannCoef & x) {
        j = json::object();
        j["ArrayName"] = x.get_array_name();
        j["Condition_1"] = x.get_condition_1();
        j["Condition_2"] = x.get_condition_2();
        j["Condition_3"] = x.get_condition_3();
        j["Condition_4"] = x.get_condition_4();
        j["Default_Index_1"] = x.get_default_index_1();
        j["Default_Index_2"] = x.get_default_index_2();
        j["Default_Index_3"] = x.get_default_index_3();
        j["Default_Index_4"] = x.get_default_index_4();
        j["Index_1"] = x.get_index_1();
        j["Index_2"] = x.get_index_2();
        j["Index_3"] = x.get_index_3();
        j["Index_4"] = x.get_index_4();
        j["MaxValue_Index_1"] = x.get_max_value_index_1();
        j["MaxValue_Index_2"] = x.get_max_value_index_2();
        j["MaxValue_Index_3"] = x.get_max_value_index_3();
        j["MaxValue_Index_4"] = x.get_max_value_index_4();
        j["MinValue_Index_1"] = x.get_min_value_index_1();
        j["MinValue_Index_2"] = x.get_min_value_index_2();
        j["MinValue_Index_3"] = x.get_min_value_index_3();
        j["MinValue_Index_4"] = x.get_min_value_index_4();
        j["SizeofArray"] = x.get_sizeof_array();
    }

    inline void from_json(const json & j, coup::RntLaIv& x) {
        x.set_array_name(j.at("ArrayName").get<coup::LaiAbovecanopyArrayName>());
        x.set_condition_1(j.at("Condition_1").get<coup::RntLaIvCondition1>());
        x.set_condition_2(coup::get_optional<std::string>(j, "Condition_2"));
        x.set_condition_3(coup::get_optional<std::string>(j, "Condition_3"));
        x.set_condition_4(coup::get_optional<std::string>(j, "Condition_4"));
        x.set_condition_5(coup::get_optional<std::string>(j, "Condition_5"));
        x.set_default_index_1(j.at("Default_Index_1").get<std::string>());
        x.set_index_1(j.at("Index_1").get<std::string>());
        x.set_max_value_index_1(j.at("MaxValue_Index_1").get<std::string>());
        x.set_min_value_index_1(j.at("MinValue_Index_1").get<std::string>());
        x.set_sizeof_array(j.at("SizeofArray").get<std::string>());
    }

    inline void to_json(json & j, const coup::RntLaIv & x) {
        j = json::object();
        j["ArrayName"] = x.get_array_name();
        j["Condition_1"] = x.get_condition_1();
        j["Condition_2"] = x.get_condition_2();
        j["Condition_3"] = x.get_condition_3();
        j["Condition_4"] = x.get_condition_4();
        j["Condition_5"] = x.get_condition_5();
        j["Default_Index_1"] = x.get_default_index_1();
        j["Index_1"] = x.get_index_1();
        j["MaxValue_Index_1"] = x.get_max_value_index_1();
        j["MinValue_Index_1"] = x.get_min_value_index_1();
        j["SizeofArray"] = x.get_sizeof_array();
    }

    inline void from_json(const json & j, coup::StickyRadiationproperties& x) {
        x.set_konzelmann_coef(j.at("KonzelmannCoef").get<coup::KonzelmannCoef>());
        x.set_rnt_la_iv(j.at("RntLAIv").get<coup::RntLaIv>());
    }

    inline void to_json(json & j, const coup::StickyRadiationproperties & x) {
        j = json::object();
        j["KonzelmannCoef"] = x.get_konzelmann_coef();
        j["RntLAIv"] = x.get_rnt_la_iv();
    }

    inline void from_json(const json & j, coup::ParametersArraysAtmosphericRelatedProcesses& x) {
        x.set_radiationproperties(j.at("Radiationproperties").get<coup::StickyRadiationproperties>());
    }

    inline void to_json(json & j, const coup::ParametersArraysAtmosphericRelatedProcesses & x) {
        j = json::object();
        j["Radiationproperties"] = x.get_radiationproperties();
    }

    inline void from_json(const json & j, coup::InfilDistF& x) {
        x.set_array_name(j.at("ArrayName").get<coup::CCoarseRootsAtmLayerArrayName>());
        x.set_condition_1(coup::get_optional<std::string>(j, "Condition_1"));
        x.set_condition_2(coup::get_optional<std::string>(j, "Condition_2"));
        x.set_condition_3(coup::get_optional<std::string>(j, "Condition_3"));
        x.set_condition_4(coup::get_optional<coup::Condition3Enum>(j, "Condition_4"));
        x.set_default_index_1(j.at("Default_Index_1").get<std::string>());
        x.set_default_index_2(j.at("Default_Index_2").get<std::string>());
        x.set_default_index_3(j.at("Default_Index_3").get<std::string>());
        x.set_default_index_4(j.at("Default_Index_4").get<std::string>());
        x.set_default_index_5(j.at("Default_Index_5").get<std::string>());
        x.set_default_index_6(j.at("Default_Index_6").get<std::string>());
        x.set_default_index_7(j.at("Default_Index_7").get<std::string>());
        x.set_default_index_8(j.at("Default_Index_8").get<std::string>());
        x.set_index_1(j.at("Index_1").get<std::string>());
        x.set_index_2(j.at("Index_2").get<std::string>());
        x.set_index_3(j.at("Index_3").get<std::string>());
        x.set_index_4(j.at("Index_4").get<std::string>());
        x.set_index_5(j.at("Index_5").get<std::string>());
        x.set_index_6(j.at("Index_6").get<std::string>());
        x.set_index_7(j.at("Index_7").get<std::string>());
        x.set_index_8(j.at("Index_8").get<std::string>());
        x.set_max_value_index_1(j.at("MaxValue_Index_1").get<std::string>());
        x.set_max_value_index_2(j.at("MaxValue_Index_2").get<std::string>());
        x.set_max_value_index_3(j.at("MaxValue_Index_3").get<std::string>());
        x.set_max_value_index_4(j.at("MaxValue_Index_4").get<std::string>());
        x.set_max_value_index_5(j.at("MaxValue_Index_5").get<std::string>());
        x.set_max_value_index_6(j.at("MaxValue_Index_6").get<std::string>());
        x.set_max_value_index_7(j.at("MaxValue_Index_7").get<std::string>());
        x.set_max_value_index_8(j.at("MaxValue_Index_8").get<std::string>());
        x.set_min_value_index_1(j.at("MinValue_Index_1").get<std::string>());
        x.set_min_value_index_2(j.at("MinValue_Index_2").get<std::string>());
        x.set_min_value_index_3(j.at("MinValue_Index_3").get<std::string>());
        x.set_min_value_index_4(j.at("MinValue_Index_4").get<std::string>());
        x.set_min_value_index_5(j.at("MinValue_Index_5").get<std::string>());
        x.set_min_value_index_6(j.at("MinValue_Index_6").get<std::string>());
        x.set_min_value_index_7(j.at("MinValue_Index_7").get<std::string>());
        x.set_min_value_index_8(j.at("MinValue_Index_8").get<std::string>());
        x.set_sizeof_array(j.at("SizeofArray").get<std::string>());
    }

    inline void to_json(json & j, const coup::InfilDistF & x) {
        j = json::object();
        j["ArrayName"] = x.get_array_name();
        j["Condition_1"] = x.get_condition_1();
        j["Condition_2"] = x.get_condition_2();
        j["Condition_3"] = x.get_condition_3();
        j["Condition_4"] = x.get_condition_4();
        j["Default_Index_1"] = x.get_default_index_1();
        j["Default_Index_2"] = x.get_default_index_2();
        j["Default_Index_3"] = x.get_default_index_3();
        j["Default_Index_4"] = x.get_default_index_4();
        j["Default_Index_5"] = x.get_default_index_5();
        j["Default_Index_6"] = x.get_default_index_6();
        j["Default_Index_7"] = x.get_default_index_7();
        j["Default_Index_8"] = x.get_default_index_8();
        j["Index_1"] = x.get_index_1();
        j["Index_2"] = x.get_index_2();
        j["Index_3"] = x.get_index_3();
        j["Index_4"] = x.get_index_4();
        j["Index_5"] = x.get_index_5();
        j["Index_6"] = x.get_index_6();
        j["Index_7"] = x.get_index_7();
        j["Index_8"] = x.get_index_8();
        j["MaxValue_Index_1"] = x.get_max_value_index_1();
        j["MaxValue_Index_2"] = x.get_max_value_index_2();
        j["MaxValue_Index_3"] = x.get_max_value_index_3();
        j["MaxValue_Index_4"] = x.get_max_value_index_4();
        j["MaxValue_Index_5"] = x.get_max_value_index_5();
        j["MaxValue_Index_6"] = x.get_max_value_index_6();
        j["MaxValue_Index_7"] = x.get_max_value_index_7();
        j["MaxValue_Index_8"] = x.get_max_value_index_8();
        j["MinValue_Index_1"] = x.get_min_value_index_1();
        j["MinValue_Index_2"] = x.get_min_value_index_2();
        j["MinValue_Index_3"] = x.get_min_value_index_3();
        j["MinValue_Index_4"] = x.get_min_value_index_4();
        j["MinValue_Index_5"] = x.get_min_value_index_5();
        j["MinValue_Index_6"] = x.get_min_value_index_6();
        j["MinValue_Index_7"] = x.get_min_value_index_7();
        j["MinValue_Index_8"] = x.get_min_value_index_8();
        j["SizeofArray"] = x.get_sizeof_array();
    }

    inline void from_json(const json & j, coup::TentacledIrrigation& x) {
        x.set_infil_dist_f(j.at("InfilDistF").get<coup::InfilDistF>());
    }

    inline void to_json(json & j, const coup::TentacledIrrigation & x) {
        j = json::object();
        j["InfilDistF"] = x.get_infil_dist_f();
    }

    inline void from_json(const json & j, coup::AbsError& x) {
        x.set_array_name(j.at("ArrayName").get<std::string>());
        x.set_condition_1(j.at("Condition_1").get<std::string>());
        x.set_sizeof_array(j.at("SizeofArray").get<std::string>());
    }

    inline void to_json(json & j, const coup::AbsError & x) {
        j = json::object();
        j["ArrayName"] = x.get_array_name();
        j["Condition_1"] = x.get_condition_1();
        j["SizeofArray"] = x.get_sizeof_array();
    }

    inline void from_json(const json & j, coup::BoxCox& x) {
        x.set_array_name(j.at("ArrayName").get<std::string>());
        x.set_sizeof_array(j.at("SizeofArray").get<std::string>());
    }

    inline void to_json(json & j, const coup::BoxCox & x) {
        j = json::object();
        j["ArrayName"] = x.get_array_name();
        j["SizeofArray"] = x.get_sizeof_array();
    }

    inline void from_json(const json & j, coup::TentacledTechnical& x) {
        x.set_abs_error(j.at("AbsError").get<coup::AbsError>());
        x.set_box_coxoffset(j.at("BoxCoxoffset").get<coup::BoxCox>());
        x.set_box_coxpower(j.at("BoxCoxpower").get<coup::BoxCox>());
        x.set_key_index(j.at("KeyIndex").get<coup::AbsError>());
        x.set_rel_error(j.at("RelError").get<coup::AbsError>());
        x.set_scaling_index(j.at("ScalingIndex").get<coup::AbsError>());
        x.set_scaling_observed(j.at("ScalingObserved").get<coup::AbsError>());
    }

    inline void to_json(json & j, const coup::TentacledTechnical & x) {
        j = json::object();
        j["AbsError"] = x.get_abs_error();
        j["BoxCoxoffset"] = x.get_box_coxoffset();
        j["BoxCoxpower"] = x.get_box_coxpower();
        j["KeyIndex"] = x.get_key_index();
        j["RelError"] = x.get_rel_error();
        j["ScalingIndex"] = x.get_scaling_index();
        j["ScalingObserved"] = x.get_scaling_observed();
    }

    inline void from_json(const json & j, coup::ParametersArraysModelFacilities& x) {
        x.set_irrigation(j.at("Irrigation").get<coup::TentacledIrrigation>());
        x.set_technical(j.at("Technical").get<coup::TentacledTechnical>());
    }

    inline void to_json(json & j, const coup::ParametersArraysModelFacilities & x) {
        j = json::object();
        j["Irrigation"] = x.get_irrigation();
        j["Technical"] = x.get_technical();
    }

    inline void from_json(const json & j, coup::TentacledExternalPInputs& x) {
        x.set_p_fert_rate(j.at("PFertRate").get<coup::RntLaIv>());
    }

    inline void to_json(json & j, const coup::TentacledExternalPInputs & x) {
        j = json::object();
        j["PFertRate"] = x.get_p_fert_rate();
    }

    inline void from_json(const json & j, coup::StickyPlantGrowth& x) {
        x.set_allocation_grain_range(j.at("AllocationGrainRange").get<coup::RntLaIv>());
        x.set_allo_fungic1(j.at("AlloFungic1").get<coup::RntLaIv>());
        x.set_allo_max_fungic1(j.at("AlloMaxFungic1").get<coup::RntLaIv>());
        x.set_allo_rate_coef(j.at("AlloRateCoef").get<coup::RntLaIv>());
        x.set_c3_type(j.at("C3Type").get<coup::RntLaIv>());
        x.set_c_leafto_grain(j.at("CLeaftoGrain").get<coup::RntLaIv>());
        x.set_c_leafto_stem(j.at("CLeaftoStem").get<coup::RntLaIv>());
        x.set_cleaning_day_no(j.at("CleaningDayNo").get<coup::KonzelmannCoef>());
        x.set_cleaning_years(j.at("CleaningYears").get<coup::KonzelmannCoef>());
        x.set_cnl_opt(j.at("CNLOpt").get<coup::RntLaIv>());
        x.set_cnl_th(j.at("CNLTh").get<coup::RntLaIv>());
        x.set_cn_ratio_max_litter(j.at("CNRatioMaxLitter").get<coup::RntLaIv>());
        x.set_cn_ratio_min_c_roots(j.at("CNRatioMinCRoots").get<coup::RntLaIv>());
        x.set_cn_ratio_min_leaf(j.at("CNRatioMinLeaf").get<coup::RntLaIv>());
        x.set_cn_ratio_min_roots(j.at("CNRatioMinRoots").get<coup::RntLaIv>());
        x.set_cn_ratio_min_stem(j.at("CNRatioMinStem").get<coup::RntLaIv>());
        x.set_coarse_root_lf2(j.at("CoarseRoot_LF2").get<coup::RntLaIv>());
        x.set_coarse_root_rate1(j.at("CoarseRootRate1").get<coup::RntLaIv>());
        x.set_coarse_root_rate2(j.at("CoarseRootRate2").get<coup::RntLaIv>());
        x.set_coarse_root_tsum1(j.at("CoarseRootTsum1").get<coup::RntLaIv>());
        x.set_coarse_root_tsum2(j.at("CoarseRootTsum2").get<coup::RntLaIv>());
        x.set_cpl_opt(j.at("CPLOpt").get<coup::RntLaIv>());
        x.set_cpl_th(j.at("CPLTh").get<coup::RntLaIv>());
        x.set_cp_ratio_max_litter(j.at("CPRatioMaxLitter").get<coup::RntLaIv>());
        x.set_cp_ratio_min_c_roots(j.at("CPRatioMinCRoots").get<coup::RntLaIv>());
        x.set_cp_ratio_min_leaf(j.at("CPRatioMinLeaf").get<coup::RntLaIv>());
        x.set_cp_ratio_min_roots(j.at("CPRatioMinRoots").get<coup::RntLaIv>());
        x.set_cp_ratio_min_stem(j.at("CPRatioMinStem").get<coup::RntLaIv>());
        x.set_c_rootsto_grain(j.at("CRootstoGrain").get<coup::RntLaIv>());
        x.set_c_seed(j.at("CSeed").get<coup::RntLaIv>());
        x.set_c_stemto_grain(j.at("CStemtoGrain").get<coup::RntLaIv>());
        x.set_degreeof_cleaning(j.at("DegreeofCleaning").get<coup::KonzelmannCoef>());
        x.set_dorm_final_day_no(j.at("Dorm_FinalDayNo").get<coup::RntLaIv>());
        x.set_dormancy_tth(j.at("DormancyTth").get<coup::RntLaIv>());
        x.set_drip(j.at("Drip").get<coup::RntLaIv>());
        x.set_emergence_dayno(j.at("EmergenceDayno").get<coup::RntLaIv>());
        x.set_emergence_days(j.at("EmergenceDays").get<coup::RntLaIv>());
        x.set_emerge_tsum(j.at("EmergeTsum").get<coup::RntLaIv>());
        x.set_emerge_tth(j.at("EmergeTth").get<coup::RntLaIv>());
        x.set_f_harvest_c_roots(j.at("FHarvestCRoots").get<coup::RntLaIv>());
        x.set_f_harvest_grain(j.at("FHarvestGrain").get<coup::RntLaIv>());
        x.set_f_harvest_leaf(j.at("FHarvestLeaf").get<coup::RntLaIv>());
        x.set_f_harvest_roots(j.at("FHarvestRoots").get<coup::RntLaIv>());
        x.set_f_harvest_stem(j.at("FHarvestStem").get<coup::RntLaIv>());
        x.set_fix_nsupply(j.at("FixNsupply").get<coup::RntLaIv>());
        x.set_f_litter_c_roots(j.at("FLitterCRoots").get<coup::RntLaIv>());
        x.set_f_litter_grain(j.at("FLitterGrain").get<coup::RntLaIv>());
        x.set_f_litter_leaf(j.at("FLitterLeaf").get<coup::RntLaIv>());
        x.set_f_litter_roots(j.at("FLitterRoots").get<coup::RntLaIv>());
        x.set_f_litter_stem(j.at("FLitterStem").get<coup::RntLaIv>());
        x.set_fraction_r(j.at("FractionR").get<coup::RntLaIv>());
        x.set_fungi_carbondemand_coef(j.at("FungiCarbondemandCoef").get<coup::RntLaIv>());
        x.set_fungi_mantle_rate(j.at("FungiMantleRate").get<coup::RntLaIv>());
        x.set_fungi_max_cn(j.at("FungiMaxCN").get<coup::RntLaIv>());
        x.set_fungi_max_cp(j.at("FungiMaxCP").get<coup::RntLaIv>());
        x.set_fungi_min_cn(j.at("FungiMinCN").get<coup::RntLaIv>());
        x.set_fungi_min_cp(j.at("FungiMinCP").get<coup::RntLaIv>());
        x.set_fungi_min_nmycon_supply(j.at("FungiMinNMYCONSupply").get<coup::RntLaIv>());
        x.set_fungi_min_pmycon_supply(j.at("FungiMinPMYCONSupply").get<coup::RntLaIv>());
        x.set_fungi_myc_rate(j.at("FungiMycRate").get<coup::RntLaIv>());
        x.set_fungi_nh4_uptrate(j.at("FungiNH4uptrate").get<coup::RntLaIv>());
        x.set_fungi_no3_uptrate(j.at("FungiNO3uptrate").get<coup::RntLaIv>());
        x.set_fungi_norguptrate(j.at("FungiNorguptrate").get<coup::RntLaIv>());
        x.set_fungi_po4_uptrate(j.at("FungiPO4uptrate").get<coup::RntLaIv>());
        x.set_fungi_porguptrate(j.at("FungiPorguptrate").get<coup::RntLaIv>());
        x.set_fungi_rate1(j.at("FungiRate1").get<coup::RntLaIv>());
        x.set_fungi_rate2(j.at("FungiRate2").get<coup::RntLaIv>());
        x.set_grain_lf2(j.at("Grain_LF2").get<coup::RntLaIv>());
        x.set_grain_rate1(j.at("GrainRate1").get<coup::RntLaIv>());
        x.set_grain_rate2(j.at("GrainRate2").get<coup::RntLaIv>());
        x.set_grain_step(j.at("GrainStep").get<coup::RntLaIv>());
        x.set_grain_step_day(j.at("GrainStepDay").get<coup::RntLaIv>());
        x.set_grain_step_temp(j.at("GrainStepTemp").get<coup::RntLaIv>());
        x.set_grain_th_day(j.at("GrainThDay").get<coup::RntLaIv>());
        x.set_grain_th_temp(j.at("GrainThTemp").get<coup::RntLaIv>());
        x.set_grain_tsum1(j.at("GrainTsum1").get<coup::RntLaIv>());
        x.set_grain_tsum2(j.at("GrainTsum2").get<coup::RntLaIv>());
        x.set_growth_coef(j.at("GrowthCoef").get<coup::RntLaIv>());
        x.set_gsi_post_harvest(j.at("GSIPostHarvest").get<coup::RntLaIv>());
        x.set_harvest_day_no(j.at("HarvestDayNo").get<coup::KonzelmannCoef>());
        x.set_harvest_dayno(j.at("HarvestDayno").get<coup::RntLaIv>());
        x.set_harvest_days(j.at("HarvestDays").get<coup::RntLaIv>());
        x.set_harvest_lai(j.at("HarvestLAI").get<coup::RntLaIv>());
        x.set_harvest_years(j.at("HarvestYears").get<coup::KonzelmannCoef>());
        x.set_ic_coarse_root(j.at("ICCoarseRoot").get<coup::RntLaIv>());
        x.set_ic_grain(j.at("ICGrain").get<coup::RntLaIv>());
        x.set_ic_leaf(j.at("ICLeaf").get<coup::RntLaIv>());
        x.set_icn_coarse_root(j.at("ICNCoarseRoot").get<coup::RntLaIv>());
        x.set_icn_grain(j.at("ICNGrain").get<coup::RntLaIv>());
        x.set_icn_leaf(j.at("ICNLeaf").get<coup::RntLaIv>());
        x.set_icn_old_coarse_root(j.at("ICNOldCoarseRoot").get<coup::RntLaIv>());
        x.set_icn_old_leaf(j.at("ICNOldLeaf").get<coup::RntLaIv>());
        x.set_icn_old_root(j.at("ICNOldRoot").get<coup::RntLaIv>());
        x.set_icn_old_stem(j.at("ICNOldStem").get<coup::RntLaIv>());
        x.set_icn_root(j.at("ICNRoot").get<coup::RntLaIv>());
        x.set_icn_stem(j.at("ICNStem").get<coup::RntLaIv>());
        x.set_ic_old_coarse_root(j.at("ICOldCoarseRoot").get<coup::RntLaIv>());
        x.set_ic_old_leaf(j.at("ICOldLeaf").get<coup::RntLaIv>());
        x.set_ic_old_root(j.at("ICOldRoot").get<coup::RntLaIv>());
        x.set_ic_old_stem(j.at("ICOldStem").get<coup::RntLaIv>());
        x.set_icp_coarse_root(j.at("ICPCoarseRoot").get<coup::RntLaIv>());
        x.set_icp_grain(j.at("ICPGrain").get<coup::RntLaIv>());
        x.set_icp_leaf(j.at("ICPLeaf").get<coup::RntLaIv>());
        x.set_icp_old_coarse_root(j.at("ICPOldCoarseRoot").get<coup::RntLaIv>());
        x.set_icp_old_leaf(j.at("ICPOldLeaf").get<coup::RntLaIv>());
        x.set_icp_old_root(j.at("ICPOldRoot").get<coup::RntLaIv>());
        x.set_icp_old_stem(j.at("ICPOldStem").get<coup::RntLaIv>());
        x.set_icp_root(j.at("ICPRoot").get<coup::RntLaIv>());
        x.set_icp_stem(j.at("ICPStem").get<coup::RntLaIv>());
        x.set_ic_root(j.at("ICRoot").get<coup::RntLaIv>());
        x.set_ic_stem(j.at("ICStem").get<coup::RntLaIv>());
        x.set_in_coarse_root(j.at("INCoarseRoot").get<coup::RntLaIv>());
        x.set_in_grain(j.at("INGrain").get<coup::RntLaIv>());
        x.set_initial_gsi(j.at("InitialGSI").get<coup::RntLaIv>());
        x.set_initial_tsum(j.at("InitialTsum").get<coup::RntLaIv>());
        x.set_in_leaf(j.at("INLeaf").get<coup::RntLaIv>());
        x.set_in_old_coarse_root(j.at("INOldCoarseRoot").get<coup::RntLaIv>());
        x.set_in_old_leaf(j.at("INOldLeaf").get<coup::RntLaIv>());
        x.set_in_old_root(j.at("INOldRoot").get<coup::RntLaIv>());
        x.set_in_old_stem(j.at("INOldStem").get<coup::RntLaIv>());
        x.set_in_root(j.at("INRoot").get<coup::RntLaIv>());
        x.set_in_stem(j.at("INStem").get<coup::RntLaIv>());
        x.set_ip_coarse_root(j.at("IPCoarseRoot").get<coup::RntLaIv>());
        x.set_ip_grain(j.at("IPGrain").get<coup::RntLaIv>());
        x.set_i_plant_age(j.at("IPlantAge").get<coup::RntLaIv>());
        x.set_ip_leaf(j.at("IPLeaf").get<coup::RntLaIv>());
        x.set_ip_old_coarse_root(j.at("IPOldCoarseRoot").get<coup::RntLaIv>());
        x.set_ip_old_leaf(j.at("IPOldLeaf").get<coup::RntLaIv>());
        x.set_ip_old_root(j.at("IPOldRoot").get<coup::RntLaIv>());
        x.set_ip_old_stem(j.at("IPOldStem").get<coup::RntLaIv>());
        x.set_ip_root(j.at("IPRoot").get<coup::RntLaIv>());
        x.set_ip_stem(j.at("IPStem").get<coup::RntLaIv>());
        x.set_lai_enh_coef(j.at("LAIEnhCoef").get<coup::RntLaIv>());
        x.set_leaf_lf2(j.at("Leaf_LF2").get<coup::RntLaIv>());
        x.set_leafc1(j.at("Leafc1").get<coup::RntLaIv>());
        x.set_leafc2(j.at("Leafc2").get<coup::RntLaIv>());
        x.set_leafc3(j.at("Leafc3").get<coup::RntLaIv>());
        x.set_leaf_rate1(j.at("LeafRate1").get<coup::RntLaIv>());
        x.set_leaf_rate2(j.at("LeafRate2").get<coup::RntLaIv>());
        x.set_leaf_tsum1(j.at("LeafTsum1").get<coup::RntLaIv>());
        x.set_leaf_tsum2(j.at("LeafTsum2").get<coup::RntLaIv>());
        x.set_mature_tsum(j.at("MatureTsum").get<coup::RntLaIv>());
        x.set_mature_tth(j.at("MatureTth").get<coup::RntLaIv>());
        x.set_max_gsi(j.at("MaxGSI").get<coup::RntLaIv>());
        x.set_max_leaf_lifetime(j.at("MaxLeafLifetime").get<coup::RntLaIv>());
        x.set_max_plant_lifetime(j.at("MaxPlantLifetime").get<coup::RntLaIv>());
        x.set_m_coef_coarse_root(j.at("MCoefCoarseRoot").get<coup::RntLaIv>());
        x.set_m_coef_grain(j.at("MCoefGrain").get<coup::RntLaIv>());
        x.set_m_coef_leaf(j.at("MCoefLeaf").get<coup::RntLaIv>());
        x.set_m_coef_root(j.at("MCoefRoot").get<coup::RntLaIv>());
        x.set_m_coef_stem(j.at("MCoefStem").get<coup::RntLaIv>());
        x.set_min_frac_green_response(j.at("MinFracGreenResponse").get<coup::RntLaIv>());
        x.set_min_gsi(j.at("MinGSI").get<coup::RntLaIv>());
        x.set_minimum_response(j.at("MinimumResponse").get<coup::RntLaIv>());
        x.set_mobile_allo_coef(j.at("MobileAlloCoef").get<coup::RntLaIv>());
        x.set_mulch(j.at("Mulch").get<coup::RntLaIv>());
        x.set_mycelia_frac(j.at("MyceliaFrac").get<coup::RntLaIv>());
        x.set_myco_degree_fungi_coef(j.at("MycoDegreeFungiCoef").get<coup::RntLaIv>());
        x.set_navail_coef(j.at("NavailCoef").get<coup::RntLaIv>());
        x.set_new_coarse_roots(j.at("NewCoarseRoots").get<coup::RntLaIv>());
        x.set_new_leaf(j.at("NewLeaf").get<coup::RntLaIv>());
        x.set_new_roots(j.at("NewRoots").get<coup::RntLaIv>());
        x.set_new_stem(j.at("NewStem").get<coup::RntLaIv>());
        x.set_n_fix_coef(j.at("NFixCoef").get<coup::RntLaIv>());
        x.set_nh4_coef(j.at("NH4Coef").get<coup::RntLaIv>());
        x.set_n_leafto_grain(j.at("NLeaftoGrain").get<coup::RntLaIv>());
        x.set_no3_coef(j.at("NO3Coef").get<coup::RntLaIv>());
        x.set_n_org_coef(j.at("NOrgCoef").get<coup::RntLaIv>());
        x.set_nretention_fungi(j.at("NretentionFungi").get<coup::RntLaIv>());
        x.set_n_rootsto_grain(j.at("NRootstoGrain").get<coup::RntLaIv>());
        x.set_n_stemto_grain(j.at("NStemtoGrain").get<coup::RntLaIv>());
        x.set_old_coarse_roots(j.at("OldCoarseRoots").get<coup::RntLaIv>());
        x.set_old_leaf(j.at("OldLeaf").get<coup::RntLaIv>());
        x.set_old_roots(j.at("OldRoots").get<coup::RntLaIv>());
        x.set_old_stem(j.at("OldStem").get<coup::RntLaIv>());
        x.set_opt_green_index(j.at("OptGreenIndex").get<coup::RntLaIv>());
        x.set_pavail_coef(j.at("PavailCoef").get<coup::RntLaIv>());
        x.set_p_f_harvest_c_roots(j.at("pFHarvestCRoots").get<coup::RntLaIv>());
        x.set_p_f_harvest_grain(j.at("pFHarvestGrain").get<coup::RntLaIv>());
        x.set_p_f_harvest_leaf(j.at("pFHarvestLeaf").get<coup::RntLaIv>());
        x.set_p_f_harvest_roots(j.at("pFHarvestRoots").get<coup::RntLaIv>());
        x.set_p_f_harvest_stem(j.at("pFHarvestStem").get<coup::RntLaIv>());
        x.set_p_f_litter_c_roots(j.at("pFLitterCRoots").get<coup::RntLaIv>());
        x.set_p_f_litter_grain(j.at("pFLitterGrain").get<coup::RntLaIv>());
        x.set_p_f_litter_leaf(j.at("pFLitterLeaf").get<coup::RntLaIv>());
        x.set_p_f_litter_roots(j.at("pFLitterRoots").get<coup::RntLaIv>());
        x.set_p_f_litter_stem(j.at("pFLitterStem").get<coup::RntLaIv>());
        x.set_plant_cleaning_index(j.at("PlantCleaningIndex").get<coup::KonzelmannCoef>());
        x.set_plant_day_index(j.at("PlantDayIndex").get<coup::KonzelmannCoef>());
        x.set_plant_year_index(j.at("PlantYearIndex").get<coup::KonzelmannCoef>());
        x.set_p_leafto_grain(j.at("PLeaftoGrain").get<coup::RntLaIv>());
        x.set_pmax(j.at("Pmax").get<coup::RntLaIv>());
        x.set_position4_target(j.at("Position4Target").get<coup::RntLaIv>());
        x.set_pretention_fungi(j.at("PretentionFungi").get<coup::RntLaIv>());
        x.set_p_rootsto_grain(j.at("PRootstoGrain").get<coup::RntLaIv>());
        x.set_p_stemto_grain(j.at("PStemtoGrain").get<coup::RntLaIv>());
        x.set_quan_eff(j.at("QuanEff").get<coup::RntLaIv>());
        x.set_rad_efficiency(j.at("RadEfficiency").get<coup::RntLaIv>());
        x.set_rad_eff_red(j.at("RadEffRed").get<coup::RntLaIv>());
        x.set_rate_coef_f_root(j.at("RateCoef_fRoot").get<coup::RntLaIv>());
        x.set_r_boundary(j.at("RBoundary").get<coup::RntLaIv>());
        x.set_rel_w_water(j.at("RelWWater").get<coup::RntLaIv>());
        x.set_resp_coef_fungi(j.at("RespCoefFungi").get<coup::RntLaIv>());
        x.set_ripening_tsum(j.at("RipeningTsum").get<coup::RntLaIv>());
        x.set_ripening_tth(j.at("RipeningTth").get<coup::RntLaIv>());
        x.set_root_lf2(j.at("Root_LF2").get<coup::RntLaIv>());
        x.set_root_c_nc1(j.at("RootCNc1").get<coup::RntLaIv>());
        x.set_root_c_nc2(j.at("RootCNc2").get<coup::RntLaIv>());
        x.set_root_c_nc3(j.at("RootCNc3").get<coup::RntLaIv>());
        x.set_root_c_pc1(j.at("RootCPc1").get<coup::RntLaIv>());
        x.set_root_c_pc2(j.at("RootCPc2").get<coup::RntLaIv>());
        x.set_root_c_pc3(j.at("RootCPc3").get<coup::RntLaIv>());
        x.set_root_leaf_ratio(j.at("RootLeafRatio").get<coup::RntLaIv>());
        x.set_root_massc1(j.at("RootMassc1").get<coup::RntLaIv>());
        x.set_root_massc2(j.at("RootMassc2").get<coup::RntLaIv>());
        x.set_root_massc3(j.at("RootMassc3").get<coup::RntLaIv>());
        x.set_root_nodule_ratio(j.at("RootNoduleRatio").get<coup::RntLaIv>());
        x.set_root_rate1(j.at("RootRate1").get<coup::RntLaIv>());
        x.set_root_rate2(j.at("RootRate2").get<coup::RntLaIv>());
        x.set_root_tsum1(j.at("RootTsum1").get<coup::RntLaIv>());
        x.set_root_tsum2(j.at("RootTsum2").get<coup::RntLaIv>());
        x.set_root_waterc1(j.at("RootWaterc1").get<coup::RntLaIv>());
        x.set_root_waterc2(j.at("RootWaterc2").get<coup::RntLaIv>());
        x.set_root_waterc3(j.at("RootWaterc3").get<coup::RntLaIv>());
        x.set_shoot_coef(j.at("ShootCoef").get<coup::RntLaIv>());
        x.set_sowing_dayno(j.at("SowingDayno").get<coup::RntLaIv>());
        x.set_sowing_days(j.at("SowingDays").get<coup::RntLaIv>());
        x.set_sow_tsum(j.at("SowTsum").get<coup::RntLaIv>());
        x.set_sow_tth(j.at("SowTth").get<coup::RntLaIv>());
        x.set_specific_max_fixation(j.at("SpecificMaxFixation").get<coup::RntLaIv>());
        x.set_specific_min_fixation(j.at("SpecificMinFixation").get<coup::RntLaIv>());
        x.set_specific_nsensivity(j.at("SpecificNsensivity").get<coup::RntLaIv>());
        x.set_start_years(j.at("StartYears").get<coup::RntLaIv>());
        x.set_stem_lf2(j.at("Stem_LF2").get<coup::RntLaIv>());
        x.set_stem_leaf_nodule_ratio(j.at("StemLeafNoduleRatio").get<coup::RntLaIv>());
        x.set_stem_rate1(j.at("StemRate1").get<coup::RntLaIv>());
        x.set_stem_rate2(j.at("StemRate2").get<coup::RntLaIv>());
        x.set_stem_tsum1(j.at("StemTsum1").get<coup::RntLaIv>());
        x.set_stem_tsum2(j.at("StemTsum2").get<coup::RntLaIv>());
        x.set_stubble_leaf(j.at("StubbleLeaf").get<coup::RntLaIv>());
        x.set_stubble_stem(j.at("StubbleStem").get<coup::RntLaIv>());
        x.set_tf_sum_start(j.at("TFSumStart").get<coup::RntLaIv>());
        x.set_tl_max(j.at("TLMax").get<coup::RntLaIv>());
        x.set_tl_min(j.at("TLMin").get<coup::RntLaIv>());
        x.set_tl_opt1(j.at("TLOpt1").get<coup::RntLaIv>());
        x.set_tl_opt2(j.at("TLOpt2").get<coup::RntLaIv>());
        x.set_tr_current(j.at("TRCurrent").get<coup::RntLaIv>());
        x.set_t_sum_opt(j.at("TSumOpt").get<coup::RntLaIv>());
        x.set_up_a_coef(j.at("UpACoef").get<coup::RntLaIv>());
        x.set_up_b_coef(j.at("UpBCoef").get<coup::RntLaIv>());
        x.set_up_c_coef(j.at("UpCCoef").get<coup::RntLaIv>());
        x.set_up_cn_ratio(j.at("UpCNRatio").get<coup::RntLaIv>());
        x.set_up_end(j.at("UpEnd").get<coup::RntLaIv>());
        x.set_up_start(j.at("UpStart").get<coup::RntLaIv>());
        x.set_vcmax(j.at("Vcmax").get<coup::RntLaIv>());
        x.set_water_efficiency(j.at("WaterEfficiency").get<coup::RntLaIv>());
    }

    inline void to_json(json & j, const coup::StickyPlantGrowth & x) {
        j = json::object();
        j["AllocationGrainRange"] = x.get_allocation_grain_range();
        j["AlloFungic1"] = x.get_allo_fungic1();
        j["AlloMaxFungic1"] = x.get_allo_max_fungic1();
        j["AlloRateCoef"] = x.get_allo_rate_coef();
        j["C3Type"] = x.get_c3_type();
        j["CLeaftoGrain"] = x.get_c_leafto_grain();
        j["CLeaftoStem"] = x.get_c_leafto_stem();
        j["CleaningDayNo"] = x.get_cleaning_day_no();
        j["CleaningYears"] = x.get_cleaning_years();
        j["CNLOpt"] = x.get_cnl_opt();
        j["CNLTh"] = x.get_cnl_th();
        j["CNRatioMaxLitter"] = x.get_cn_ratio_max_litter();
        j["CNRatioMinCRoots"] = x.get_cn_ratio_min_c_roots();
        j["CNRatioMinLeaf"] = x.get_cn_ratio_min_leaf();
        j["CNRatioMinRoots"] = x.get_cn_ratio_min_roots();
        j["CNRatioMinStem"] = x.get_cn_ratio_min_stem();
        j["CoarseRoot_LF2"] = x.get_coarse_root_lf2();
        j["CoarseRootRate1"] = x.get_coarse_root_rate1();
        j["CoarseRootRate2"] = x.get_coarse_root_rate2();
        j["CoarseRootTsum1"] = x.get_coarse_root_tsum1();
        j["CoarseRootTsum2"] = x.get_coarse_root_tsum2();
        j["CPLOpt"] = x.get_cpl_opt();
        j["CPLTh"] = x.get_cpl_th();
        j["CPRatioMaxLitter"] = x.get_cp_ratio_max_litter();
        j["CPRatioMinCRoots"] = x.get_cp_ratio_min_c_roots();
        j["CPRatioMinLeaf"] = x.get_cp_ratio_min_leaf();
        j["CPRatioMinRoots"] = x.get_cp_ratio_min_roots();
        j["CPRatioMinStem"] = x.get_cp_ratio_min_stem();
        j["CRootstoGrain"] = x.get_c_rootsto_grain();
        j["CSeed"] = x.get_c_seed();
        j["CStemtoGrain"] = x.get_c_stemto_grain();
        j["DegreeofCleaning"] = x.get_degreeof_cleaning();
        j["Dorm_FinalDayNo"] = x.get_dorm_final_day_no();
        j["DormancyTth"] = x.get_dormancy_tth();
        j["Drip"] = x.get_drip();
        j["EmergenceDayno"] = x.get_emergence_dayno();
        j["EmergenceDays"] = x.get_emergence_days();
        j["EmergeTsum"] = x.get_emerge_tsum();
        j["EmergeTth"] = x.get_emerge_tth();
        j["FHarvestCRoots"] = x.get_f_harvest_c_roots();
        j["FHarvestGrain"] = x.get_f_harvest_grain();
        j["FHarvestLeaf"] = x.get_f_harvest_leaf();
        j["FHarvestRoots"] = x.get_f_harvest_roots();
        j["FHarvestStem"] = x.get_f_harvest_stem();
        j["FixNsupply"] = x.get_fix_nsupply();
        j["FLitterCRoots"] = x.get_f_litter_c_roots();
        j["FLitterGrain"] = x.get_f_litter_grain();
        j["FLitterLeaf"] = x.get_f_litter_leaf();
        j["FLitterRoots"] = x.get_f_litter_roots();
        j["FLitterStem"] = x.get_f_litter_stem();
        j["FractionR"] = x.get_fraction_r();
        j["FungiCarbondemandCoef"] = x.get_fungi_carbondemand_coef();
        j["FungiMantleRate"] = x.get_fungi_mantle_rate();
        j["FungiMaxCN"] = x.get_fungi_max_cn();
        j["FungiMaxCP"] = x.get_fungi_max_cp();
        j["FungiMinCN"] = x.get_fungi_min_cn();
        j["FungiMinCP"] = x.get_fungi_min_cp();
        j["FungiMinNMYCONSupply"] = x.get_fungi_min_nmycon_supply();
        j["FungiMinPMYCONSupply"] = x.get_fungi_min_pmycon_supply();
        j["FungiMycRate"] = x.get_fungi_myc_rate();
        j["FungiNH4uptrate"] = x.get_fungi_nh4_uptrate();
        j["FungiNO3uptrate"] = x.get_fungi_no3_uptrate();
        j["FungiNorguptrate"] = x.get_fungi_norguptrate();
        j["FungiPO4uptrate"] = x.get_fungi_po4_uptrate();
        j["FungiPorguptrate"] = x.get_fungi_porguptrate();
        j["FungiRate1"] = x.get_fungi_rate1();
        j["FungiRate2"] = x.get_fungi_rate2();
        j["Grain_LF2"] = x.get_grain_lf2();
        j["GrainRate1"] = x.get_grain_rate1();
        j["GrainRate2"] = x.get_grain_rate2();
        j["GrainStep"] = x.get_grain_step();
        j["GrainStepDay"] = x.get_grain_step_day();
        j["GrainStepTemp"] = x.get_grain_step_temp();
        j["GrainThDay"] = x.get_grain_th_day();
        j["GrainThTemp"] = x.get_grain_th_temp();
        j["GrainTsum1"] = x.get_grain_tsum1();
        j["GrainTsum2"] = x.get_grain_tsum2();
        j["GrowthCoef"] = x.get_growth_coef();
        j["GSIPostHarvest"] = x.get_gsi_post_harvest();
        j["HarvestDayNo"] = x.get_harvest_day_no();
        j["HarvestDayno"] = x.get_harvest_dayno();
        j["HarvestDays"] = x.get_harvest_days();
        j["HarvestLAI"] = x.get_harvest_lai();
        j["HarvestYears"] = x.get_harvest_years();
        j["ICCoarseRoot"] = x.get_ic_coarse_root();
        j["ICGrain"] = x.get_ic_grain();
        j["ICLeaf"] = x.get_ic_leaf();
        j["ICNCoarseRoot"] = x.get_icn_coarse_root();
        j["ICNGrain"] = x.get_icn_grain();
        j["ICNLeaf"] = x.get_icn_leaf();
        j["ICNOldCoarseRoot"] = x.get_icn_old_coarse_root();
        j["ICNOldLeaf"] = x.get_icn_old_leaf();
        j["ICNOldRoot"] = x.get_icn_old_root();
        j["ICNOldStem"] = x.get_icn_old_stem();
        j["ICNRoot"] = x.get_icn_root();
        j["ICNStem"] = x.get_icn_stem();
        j["ICOldCoarseRoot"] = x.get_ic_old_coarse_root();
        j["ICOldLeaf"] = x.get_ic_old_leaf();
        j["ICOldRoot"] = x.get_ic_old_root();
        j["ICOldStem"] = x.get_ic_old_stem();
        j["ICPCoarseRoot"] = x.get_icp_coarse_root();
        j["ICPGrain"] = x.get_icp_grain();
        j["ICPLeaf"] = x.get_icp_leaf();
        j["ICPOldCoarseRoot"] = x.get_icp_old_coarse_root();
        j["ICPOldLeaf"] = x.get_icp_old_leaf();
        j["ICPOldRoot"] = x.get_icp_old_root();
        j["ICPOldStem"] = x.get_icp_old_stem();
        j["ICPRoot"] = x.get_icp_root();
        j["ICPStem"] = x.get_icp_stem();
        j["ICRoot"] = x.get_ic_root();
        j["ICStem"] = x.get_ic_stem();
        j["INCoarseRoot"] = x.get_in_coarse_root();
        j["INGrain"] = x.get_in_grain();
        j["InitialGSI"] = x.get_initial_gsi();
        j["InitialTsum"] = x.get_initial_tsum();
        j["INLeaf"] = x.get_in_leaf();
        j["INOldCoarseRoot"] = x.get_in_old_coarse_root();
        j["INOldLeaf"] = x.get_in_old_leaf();
        j["INOldRoot"] = x.get_in_old_root();
        j["INOldStem"] = x.get_in_old_stem();
        j["INRoot"] = x.get_in_root();
        j["INStem"] = x.get_in_stem();
        j["IPCoarseRoot"] = x.get_ip_coarse_root();
        j["IPGrain"] = x.get_ip_grain();
        j["IPlantAge"] = x.get_i_plant_age();
        j["IPLeaf"] = x.get_ip_leaf();
        j["IPOldCoarseRoot"] = x.get_ip_old_coarse_root();
        j["IPOldLeaf"] = x.get_ip_old_leaf();
        j["IPOldRoot"] = x.get_ip_old_root();
        j["IPOldStem"] = x.get_ip_old_stem();
        j["IPRoot"] = x.get_ip_root();
        j["IPStem"] = x.get_ip_stem();
        j["LAIEnhCoef"] = x.get_lai_enh_coef();
        j["Leaf_LF2"] = x.get_leaf_lf2();
        j["Leafc1"] = x.get_leafc1();
        j["Leafc2"] = x.get_leafc2();
        j["Leafc3"] = x.get_leafc3();
        j["LeafRate1"] = x.get_leaf_rate1();
        j["LeafRate2"] = x.get_leaf_rate2();
        j["LeafTsum1"] = x.get_leaf_tsum1();
        j["LeafTsum2"] = x.get_leaf_tsum2();
        j["MatureTsum"] = x.get_mature_tsum();
        j["MatureTth"] = x.get_mature_tth();
        j["MaxGSI"] = x.get_max_gsi();
        j["MaxLeafLifetime"] = x.get_max_leaf_lifetime();
        j["MaxPlantLifetime"] = x.get_max_plant_lifetime();
        j["MCoefCoarseRoot"] = x.get_m_coef_coarse_root();
        j["MCoefGrain"] = x.get_m_coef_grain();
        j["MCoefLeaf"] = x.get_m_coef_leaf();
        j["MCoefRoot"] = x.get_m_coef_root();
        j["MCoefStem"] = x.get_m_coef_stem();
        j["MinFracGreenResponse"] = x.get_min_frac_green_response();
        j["MinGSI"] = x.get_min_gsi();
        j["MinimumResponse"] = x.get_minimum_response();
        j["MobileAlloCoef"] = x.get_mobile_allo_coef();
        j["Mulch"] = x.get_mulch();
        j["MyceliaFrac"] = x.get_mycelia_frac();
        j["MycoDegreeFungiCoef"] = x.get_myco_degree_fungi_coef();
        j["NavailCoef"] = x.get_navail_coef();
        j["NewCoarseRoots"] = x.get_new_coarse_roots();
        j["NewLeaf"] = x.get_new_leaf();
        j["NewRoots"] = x.get_new_roots();
        j["NewStem"] = x.get_new_stem();
        j["NFixCoef"] = x.get_n_fix_coef();
        j["NH4Coef"] = x.get_nh4_coef();
        j["NLeaftoGrain"] = x.get_n_leafto_grain();
        j["NO3Coef"] = x.get_no3_coef();
        j["NOrgCoef"] = x.get_n_org_coef();
        j["NretentionFungi"] = x.get_nretention_fungi();
        j["NRootstoGrain"] = x.get_n_rootsto_grain();
        j["NStemtoGrain"] = x.get_n_stemto_grain();
        j["OldCoarseRoots"] = x.get_old_coarse_roots();
        j["OldLeaf"] = x.get_old_leaf();
        j["OldRoots"] = x.get_old_roots();
        j["OldStem"] = x.get_old_stem();
        j["OptGreenIndex"] = x.get_opt_green_index();
        j["PavailCoef"] = x.get_pavail_coef();
        j["pFHarvestCRoots"] = x.get_p_f_harvest_c_roots();
        j["pFHarvestGrain"] = x.get_p_f_harvest_grain();
        j["pFHarvestLeaf"] = x.get_p_f_harvest_leaf();
        j["pFHarvestRoots"] = x.get_p_f_harvest_roots();
        j["pFHarvestStem"] = x.get_p_f_harvest_stem();
        j["pFLitterCRoots"] = x.get_p_f_litter_c_roots();
        j["pFLitterGrain"] = x.get_p_f_litter_grain();
        j["pFLitterLeaf"] = x.get_p_f_litter_leaf();
        j["pFLitterRoots"] = x.get_p_f_litter_roots();
        j["pFLitterStem"] = x.get_p_f_litter_stem();
        j["PlantCleaningIndex"] = x.get_plant_cleaning_index();
        j["PlantDayIndex"] = x.get_plant_day_index();
        j["PlantYearIndex"] = x.get_plant_year_index();
        j["PLeaftoGrain"] = x.get_p_leafto_grain();
        j["Pmax"] = x.get_pmax();
        j["Position4Target"] = x.get_position4_target();
        j["PretentionFungi"] = x.get_pretention_fungi();
        j["PRootstoGrain"] = x.get_p_rootsto_grain();
        j["PStemtoGrain"] = x.get_p_stemto_grain();
        j["QuanEff"] = x.get_quan_eff();
        j["RadEfficiency"] = x.get_rad_efficiency();
        j["RadEffRed"] = x.get_rad_eff_red();
        j["RateCoef_fRoot"] = x.get_rate_coef_f_root();
        j["RBoundary"] = x.get_r_boundary();
        j["RelWWater"] = x.get_rel_w_water();
        j["RespCoefFungi"] = x.get_resp_coef_fungi();
        j["RipeningTsum"] = x.get_ripening_tsum();
        j["RipeningTth"] = x.get_ripening_tth();
        j["Root_LF2"] = x.get_root_lf2();
        j["RootCNc1"] = x.get_root_c_nc1();
        j["RootCNc2"] = x.get_root_c_nc2();
        j["RootCNc3"] = x.get_root_c_nc3();
        j["RootCPc1"] = x.get_root_c_pc1();
        j["RootCPc2"] = x.get_root_c_pc2();
        j["RootCPc3"] = x.get_root_c_pc3();
        j["RootLeafRatio"] = x.get_root_leaf_ratio();
        j["RootMassc1"] = x.get_root_massc1();
        j["RootMassc2"] = x.get_root_massc2();
        j["RootMassc3"] = x.get_root_massc3();
        j["RootNoduleRatio"] = x.get_root_nodule_ratio();
        j["RootRate1"] = x.get_root_rate1();
        j["RootRate2"] = x.get_root_rate2();
        j["RootTsum1"] = x.get_root_tsum1();
        j["RootTsum2"] = x.get_root_tsum2();
        j["RootWaterc1"] = x.get_root_waterc1();
        j["RootWaterc2"] = x.get_root_waterc2();
        j["RootWaterc3"] = x.get_root_waterc3();
        j["ShootCoef"] = x.get_shoot_coef();
        j["SowingDayno"] = x.get_sowing_dayno();
        j["SowingDays"] = x.get_sowing_days();
        j["SowTsum"] = x.get_sow_tsum();
        j["SowTth"] = x.get_sow_tth();
        j["SpecificMaxFixation"] = x.get_specific_max_fixation();
        j["SpecificMinFixation"] = x.get_specific_min_fixation();
        j["SpecificNsensivity"] = x.get_specific_nsensivity();
        j["StartYears"] = x.get_start_years();
        j["Stem_LF2"] = x.get_stem_lf2();
        j["StemLeafNoduleRatio"] = x.get_stem_leaf_nodule_ratio();
        j["StemRate1"] = x.get_stem_rate1();
        j["StemRate2"] = x.get_stem_rate2();
        j["StemTsum1"] = x.get_stem_tsum1();
        j["StemTsum2"] = x.get_stem_tsum2();
        j["StubbleLeaf"] = x.get_stubble_leaf();
        j["StubbleStem"] = x.get_stubble_stem();
        j["TFSumStart"] = x.get_tf_sum_start();
        j["TLMax"] = x.get_tl_max();
        j["TLMin"] = x.get_tl_min();
        j["TLOpt1"] = x.get_tl_opt1();
        j["TLOpt2"] = x.get_tl_opt2();
        j["TRCurrent"] = x.get_tr_current();
        j["TSumOpt"] = x.get_t_sum_opt();
        j["UpACoef"] = x.get_up_a_coef();
        j["UpBCoef"] = x.get_up_b_coef();
        j["UpCCoef"] = x.get_up_c_coef();
        j["UpCNRatio"] = x.get_up_cn_ratio();
        j["UpEnd"] = x.get_up_end();
        j["UpStart"] = x.get_up_start();
        j["Vcmax"] = x.get_vcmax();
        j["WaterEfficiency"] = x.get_water_efficiency();
    }

    inline void from_json(const json & j, coup::ParametersArraysNitrogenandCarbon& x) {
        x.set_external_ninputs(j.at("ExternalNinputs").get<std::map<std::string, coup::RntLaIv>>());
        x.set_external_p_inputs(j.at("ExternalPInputs").get<coup::TentacledExternalPInputs>());
        x.set_plant_growth(j.at("PlantGrowth").get<coup::StickyPlantGrowth>());
    }

    inline void to_json(json & j, const coup::ParametersArraysNitrogenandCarbon & x) {
        j = json::object();
        j["ExternalNinputs"] = x.get_external_ninputs();
        j["ExternalPInputs"] = x.get_external_p_inputs();
        j["PlantGrowth"] = x.get_plant_growth();
    }

    inline void from_json(const json & j, coup::IndigoGasprocesses& x) {
        x.set_init_co2_conc(j.at("InitCO2Conc").get<coup::InfilDistF>());
        x.set_init_oxygen_conc(j.at("InitOxygenConc").get<coup::InfilDistF>());
        x.set_p_hvalue(j.at("pHvalue").get<coup::InfilDistF>());
    }

    inline void to_json(json & j, const coup::IndigoGasprocesses & x) {
        j = json::object();
        j["InitCO2Conc"] = x.get_init_co2_conc();
        j["InitOxygenConc"] = x.get_init_oxygen_conc();
        j["pHvalue"] = x.get_p_hvalue();
    }

    inline void from_json(const json & j, coup::SoilmineralNprocesses& x) {
        x.set_denit_dist_z(j.at("DenitDistZ").get<coup::InfilDistF>());
        x.set_flex_degree(j.at("FlexDegree").get<coup::RntLaIv>());
        x.set_i_ammonium_conc(j.at("IAmmoniumConc").get<coup::InfilDistF>());
        x.set_i_nitrate_conc(j.at("INitrateConc").get<coup::InfilDistF>());
        x.set_nh4_ads_frac(j.at("NH4AdsFrac").get<coup::InfilDistF>());
        x.set_rel_scale_response(j.at("RelScaleResponse").get<coup::InfilDistF>());
    }

    inline void to_json(json & j, const coup::SoilmineralNprocesses & x) {
        j = json::object();
        j["DenitDistZ"] = x.get_denit_dist_z();
        j["FlexDegree"] = x.get_flex_degree();
        j["IAmmoniumConc"] = x.get_i_ammonium_conc();
        j["INitrateConc"] = x.get_i_nitrate_conc();
        j["NH4AdsFrac"] = x.get_nh4_ads_frac();
        j["RelScaleResponse"] = x.get_rel_scale_response();
    }

    inline void from_json(const json & j, coup::HilariousSoilmineralPProcesses& x) {
        x.set_i_labile_phosphate_conc(j.at("ILabilePhosphateConc").get<coup::InfilDistF>());
        x.set_inital_pcontent(j.at("InitalPcontent").get<coup::InfilDistF>());
    }

    inline void to_json(json & j, const coup::HilariousSoilmineralPProcesses & x) {
        j = json::object();
        j["ILabilePhosphateConc"] = x.get_i_labile_phosphate_conc();
        j["InitalPcontent"] = x.get_inital_pcontent();
    }

    inline void from_json(const json & j, coup::TentacledSoilorganicprocesses& x) {
        x.set_init_bulk_density(j.at("InitBulkDensity").get<std::map<std::string, std::string>>());
        x.set_init_c_cont(j.at("InitCCont").get<std::map<std::string, std::string>>());
        x.set_init_cn_humus(j.at("InitCNHumus").get<std::map<std::string, std::string>>());
        x.set_init_cn_litter(j.at("InitCNLitter").get<std::map<std::string, std::string>>());
        x.set_init_fc(j.at("InitFC").get<coup::InfilDistF>());
        x.set_init_fcn(j.at("InitFCN").get<coup::InfilDistF>());
        x.set_init_fcp(j.at("InitFCP").get<coup::InfilDistF>());
        x.set_init_fn(j.at("InitFN").get<coup::InfilDistF>());
        x.set_init_fp(j.at("InitFP").get<coup::InfilDistF>());
        x.set_init_frac_litter2(j.at("InitFracLitter2").get<std::map<std::string, std::string>>());
        x.set_init_hc(j.at("InitHC").get<coup::InfilDistF>());
        x.set_init_hcn(j.at("InitHCN").get<coup::InfilDistF>());
        x.set_init_hcp(j.at("InitHCP").get<coup::InfilDistF>());
        x.set_init_hn(j.at("InitHN").get<coup::InfilDistF>());
        x.set_init_hp(j.at("InitHP").get<coup::InfilDistF>());
        x.set_init_l1_c(j.at("InitL1C").get<coup::InfilDistF>());
        x.set_init_l1_cn(j.at("InitL1CN").get<coup::InfilDistF>());
        x.set_init_l1_cp(j.at("InitL1CP").get<coup::InfilDistF>());
        x.set_init_l1_n(j.at("InitL1N").get<coup::InfilDistF>());
        x.set_init_l1_p(j.at("InitL1P").get<coup::InfilDistF>());
        x.set_init_l2_c(j.at("InitL2C").get<coup::InfilDistF>());
        x.set_init_l2_cn(j.at("InitL2CN").get<coup::InfilDistF>());
        x.set_init_l2_cp(j.at("InitL2CP").get<coup::InfilDistF>());
        x.set_init_l2_n(j.at("InitL2N").get<coup::InfilDistF>());
        x.set_init_l2_p(j.at("InitL2P").get<coup::InfilDistF>());
        x.set_init_mc(j.at("InitMC").get<coup::InfilDistF>());
        x.set_init_mcn(j.at("InitMCN").get<coup::InfilDistF>());
        x.set_init_mcp(j.at("InitMCP").get<coup::InfilDistF>());
        x.set_init_mn(j.at("InitMN").get<coup::InfilDistF>());
        x.set_init_mp(j.at("InitMP").get<coup::InfilDistF>());
        x.set_init_n_cont(j.at("InitNCont").get<std::map<std::string, std::string>>());
        x.set_rate_coef_dissolved(j.at("RateCoefDissolved").get<coup::InfilDistF>());
    }

    inline void to_json(json & j, const coup::TentacledSoilorganicprocesses & x) {
        j = json::object();
        j["InitBulkDensity"] = x.get_init_bulk_density();
        j["InitCCont"] = x.get_init_c_cont();
        j["InitCNHumus"] = x.get_init_cn_humus();
        j["InitCNLitter"] = x.get_init_cn_litter();
        j["InitFC"] = x.get_init_fc();
        j["InitFCN"] = x.get_init_fcn();
        j["InitFCP"] = x.get_init_fcp();
        j["InitFN"] = x.get_init_fn();
        j["InitFP"] = x.get_init_fp();
        j["InitFracLitter2"] = x.get_init_frac_litter2();
        j["InitHC"] = x.get_init_hc();
        j["InitHCN"] = x.get_init_hcn();
        j["InitHCP"] = x.get_init_hcp();
        j["InitHN"] = x.get_init_hn();
        j["InitHP"] = x.get_init_hp();
        j["InitL1C"] = x.get_init_l1_c();
        j["InitL1CN"] = x.get_init_l1_cn();
        j["InitL1CP"] = x.get_init_l1_cp();
        j["InitL1N"] = x.get_init_l1_n();
        j["InitL1P"] = x.get_init_l1_p();
        j["InitL2C"] = x.get_init_l2_c();
        j["InitL2CN"] = x.get_init_l2_cn();
        j["InitL2CP"] = x.get_init_l2_cp();
        j["InitL2N"] = x.get_init_l2_n();
        j["InitL2P"] = x.get_init_l2_p();
        j["InitMC"] = x.get_init_mc();
        j["InitMCN"] = x.get_init_mcn();
        j["InitMCP"] = x.get_init_mcp();
        j["InitMN"] = x.get_init_mn();
        j["InitMP"] = x.get_init_mp();
        j["InitNCont"] = x.get_init_n_cont();
        j["RateCoefDissolved"] = x.get_rate_coef_dissolved();
    }

    inline void from_json(const json & j, coup::ParametersArraysNitrogenandCarbonBelowGround& x) {
        x.set_gasprocesses(j.at("Gasprocesses").get<coup::IndigoGasprocesses>());
        x.set_soilmineral_nprocesses(j.at("SoilmineralNprocesses").get<coup::SoilmineralNprocesses>());
        x.set_soilmineral_p_processes(j.at("SoilmineralPProcesses").get<coup::HilariousSoilmineralPProcesses>());
        x.set_soilorganicprocesses(j.at("Soilorganicprocesses").get<coup::TentacledSoilorganicprocesses>());
    }

    inline void to_json(json & j, const coup::ParametersArraysNitrogenandCarbonBelowGround & x) {
        j = json::object();
        j["Gasprocesses"] = x.get_gasprocesses();
        j["SoilmineralNprocesses"] = x.get_soilmineral_nprocesses();
        j["SoilmineralPProcesses"] = x.get_soilmineral_p_processes();
        j["Soilorganicprocesses"] = x.get_soilorganicprocesses();
    }

    inline void from_json(const json & j, coup::IndecentInterception& x) {
        x.set_lai_cover_sensitivity(j.at("LAICoverSensitivity").get<coup::RntLaIv>());
        x.set_maximal_cover(j.at("MaximalCover").get<coup::RntLaIv>());
    }

    inline void to_json(json & j, const coup::IndecentInterception & x) {
        j = json::object();
        j["LAICoverSensitivity"] = x.get_lai_cover_sensitivity();
        j["MaximalCover"] = x.get_maximal_cover();
    }

    inline void from_json(const json & j, coup::AlbedoV& x) {
        x.set_array_name(j.at("ArrayName").get<coup::AlbedoVArrayName>());
        x.set_condition_1(j.at("Condition_1").get<std::string>());
        x.set_condition_2(j.at("Condition_2").get<std::string>());
        x.set_condition_3(j.at("Condition_3").get<std::string>());
        x.set_condition_4(coup::get_optional<std::string>(j, "Condition_4"));
        x.set_default_index_1(j.at("Default_Index_1").get<std::string>());
        x.set_default_index_2(j.at("Default_Index_2").get<std::string>());
        x.set_default_index_3(j.at("Default_Index_3").get<std::string>());
        x.set_default_index_4(j.at("Default_Index_4").get<std::string>());
        x.set_default_index_5(j.at("Default_Index_5").get<std::string>());
        x.set_index_1(j.at("Index_1").get<std::string>());
        x.set_index_2(j.at("Index_2").get<std::string>());
        x.set_index_3(j.at("Index_3").get<std::string>());
        x.set_index_4(j.at("Index_4").get<std::string>());
        x.set_index_5(j.at("Index_5").get<std::string>());
        x.set_max_value_index_1(j.at("MaxValue_Index_1").get<std::string>());
        x.set_max_value_index_2(j.at("MaxValue_Index_2").get<std::string>());
        x.set_max_value_index_3(j.at("MaxValue_Index_3").get<std::string>());
        x.set_max_value_index_4(j.at("MaxValue_Index_4").get<std::string>());
        x.set_max_value_index_5(j.at("MaxValue_Index_5").get<std::string>());
        x.set_min_value_index_1(j.at("MinValue_Index_1").get<std::string>());
        x.set_min_value_index_2(j.at("MinValue_Index_2").get<std::string>());
        x.set_min_value_index_3(j.at("MinValue_Index_3").get<std::string>());
        x.set_min_value_index_4(j.at("MinValue_Index_4").get<std::string>());
        x.set_min_value_index_5(j.at("MinValue_Index_5").get<std::string>());
        x.set_sizeof_array(j.at("SizeofArray").get<std::string>());
    }

    inline void to_json(json & j, const coup::AlbedoV & x) {
        j = json::object();
        j["ArrayName"] = x.get_array_name();
        j["Condition_1"] = x.get_condition_1();
        j["Condition_2"] = x.get_condition_2();
        j["Condition_3"] = x.get_condition_3();
        j["Condition_4"] = x.get_condition_4();
        j["Default_Index_1"] = x.get_default_index_1();
        j["Default_Index_2"] = x.get_default_index_2();
        j["Default_Index_3"] = x.get_default_index_3();
        j["Default_Index_4"] = x.get_default_index_4();
        j["Default_Index_5"] = x.get_default_index_5();
        j["Index_1"] = x.get_index_1();
        j["Index_2"] = x.get_index_2();
        j["Index_3"] = x.get_index_3();
        j["Index_4"] = x.get_index_4();
        j["Index_5"] = x.get_index_5();
        j["MaxValue_Index_1"] = x.get_max_value_index_1();
        j["MaxValue_Index_2"] = x.get_max_value_index_2();
        j["MaxValue_Index_3"] = x.get_max_value_index_3();
        j["MaxValue_Index_4"] = x.get_max_value_index_4();
        j["MaxValue_Index_5"] = x.get_max_value_index_5();
        j["MinValue_Index_1"] = x.get_min_value_index_1();
        j["MinValue_Index_2"] = x.get_min_value_index_2();
        j["MinValue_Index_3"] = x.get_min_value_index_3();
        j["MinValue_Index_4"] = x.get_min_value_index_4();
        j["MinValue_Index_5"] = x.get_min_value_index_5();
        j["SizeofArray"] = x.get_sizeof_array();
    }

    inline void from_json(const json & j, coup::StickyPlant& x) {
        x.set_a_end_value(j.at("aEndValue").get<coup::RntLaIv>());
        x.set_albedo_grain_stage(j.at("AlbedoGrainStage").get<coup::RntLaIv>());
        x.set_albedo_v(j.at("AlbedoV").get<coup::AlbedoV>());
        x.set_albedo_veg_stage(j.at("AlbedoVegStage").get<coup::RntLaIv>());
        x.set_a_optimum_value(j.at("aOptimumValue").get<coup::RntLaIv>());
        x.set_areak_exp(j.at("AreakExp").get<coup::RntLaIv>());
        x.set_a_start_value(j.at("aStartValue").get<coup::RntLaIv>());
        x.set_canopy_height(j.at("CanopyHeight").get<coup::AlbedoV>());
        x.set_c_form(j.at("CForm").get<coup::AlbedoV>());
        x.set_day_number(j.at("DayNumber").get<coup::AlbedoV>());
        x.set_diameter_height_ratio(j.at("DiameterHeightRatio").get<coup::RntLaIv>());
        x.set_end_day_no(j.at("EndDayNo").get<coup::RntLaIv>());
        x.set_height_age_coef(j.at("HeightAgeCoef").get<coup::RntLaIv>());
        x.set_height_grain_coef(j.at("HeightGrainCoef").get<coup::RntLaIv>());
        x.set_height_mass_coef(j.at("HeightMassCoef").get<coup::RntLaIv>());
        x.set_height_max_grain(j.at("HeightMaxGrain").get<coup::RntLaIv>());
        x.set_h_end_value(j.at("hEndValue").get<coup::RntLaIv>());
        x.set_h_optimum_value(j.at("hOptimumValue").get<coup::RntLaIv>());
        x.set_h_start_value(j.at("hStartValue").get<coup::RntLaIv>());
        x.set_leaf_area_index(j.at("LeafAreaIndex").get<coup::AlbedoV>());
        x.set_l_end_value(j.at("lEndValue").get<coup::RntLaIv>());
        x.set_l_optimum_value(j.at("lOptimumValue").get<coup::RntLaIv>());
        x.set_l_start_value(j.at("lStartValue").get<coup::RntLaIv>());
        x.set_max_cover(j.at("MaxCover").get<coup::RntLaIv>());
        x.set_max_height(j.at("MaxHeight").get<coup::RntLaIv>());
        x.set_optimum_day_no(j.at("OptimumDayNo").get<coup::RntLaIv>());
        x.set_p_day_number(j.at("pDayNumber").get<coup::AlbedoV>());
        x.set_p_root_depth(j.at("pRootDepth").get<coup::AlbedoV>());
        x.set_p_root_length(j.at("pRootLength").get<coup::AlbedoV>());
        x.set_r_end_value(j.at("rEndValue").get<coup::RntLaIv>());
        x.set_rl_end_value(j.at("rlEndValue").get<coup::RntLaIv>());
        x.set_rl_optimum_value(j.at("rlOptimumValue").get<coup::RntLaIv>());
        x.set_rl_start_value(j.at("rlStartValue").get<coup::RntLaIv>());
        x.set_root_fraction(j.at("RootFraction").get<coup::InfilDistF>());
        x.set_root_inc_depth(j.at("RootIncDepth").get<coup::RntLaIv>());
        x.set_root_lowest_depth(j.at("RootLowestDepth").get<coup::RntLaIv>());
        x.set_r_optimum_value(j.at("rOptimumValue").get<coup::RntLaIv>());
        x.set_r_start_value(j.at("rStartValue").get<coup::RntLaIv>());
        x.set_shape_end(j.at("ShapeEnd").get<coup::RntLaIv>());
        x.set_shape_start(j.at("ShapeStart").get<coup::RntLaIv>());
        x.set_specific_leaf_area(j.at("SpecificLeafArea").get<coup::RntLaIv>());
        x.set_specific_root_length(j.at("SpecificRootLength").get<coup::RntLaIv>());
        x.set_spec_leaf_area_begin(j.at("SpecLeafAreaBegin").get<coup::RntLaIv>());
        x.set_start_day_no(j.at("StartDayNo").get<coup::RntLaIv>());
        x.set_xcenter_pos(j.at("XcenterPos").get<coup::RntLaIv>());
    }

    inline void to_json(json & j, const coup::StickyPlant & x) {
        j = json::object();
        j["aEndValue"] = x.get_a_end_value();
        j["AlbedoGrainStage"] = x.get_albedo_grain_stage();
        j["AlbedoV"] = x.get_albedo_v();
        j["AlbedoVegStage"] = x.get_albedo_veg_stage();
        j["aOptimumValue"] = x.get_a_optimum_value();
        j["AreakExp"] = x.get_areak_exp();
        j["aStartValue"] = x.get_a_start_value();
        j["CanopyHeight"] = x.get_canopy_height();
        j["CForm"] = x.get_c_form();
        j["DayNumber"] = x.get_day_number();
        j["DiameterHeightRatio"] = x.get_diameter_height_ratio();
        j["EndDayNo"] = x.get_end_day_no();
        j["HeightAgeCoef"] = x.get_height_age_coef();
        j["HeightGrainCoef"] = x.get_height_grain_coef();
        j["HeightMassCoef"] = x.get_height_mass_coef();
        j["HeightMaxGrain"] = x.get_height_max_grain();
        j["hEndValue"] = x.get_h_end_value();
        j["hOptimumValue"] = x.get_h_optimum_value();
        j["hStartValue"] = x.get_h_start_value();
        j["LeafAreaIndex"] = x.get_leaf_area_index();
        j["lEndValue"] = x.get_l_end_value();
        j["lOptimumValue"] = x.get_l_optimum_value();
        j["lStartValue"] = x.get_l_start_value();
        j["MaxCover"] = x.get_max_cover();
        j["MaxHeight"] = x.get_max_height();
        j["OptimumDayNo"] = x.get_optimum_day_no();
        j["pDayNumber"] = x.get_p_day_number();
        j["pRootDepth"] = x.get_p_root_depth();
        j["pRootLength"] = x.get_p_root_length();
        j["rEndValue"] = x.get_r_end_value();
        j["rlEndValue"] = x.get_rl_end_value();
        j["rlOptimumValue"] = x.get_rl_optimum_value();
        j["rlStartValue"] = x.get_rl_start_value();
        j["RootFraction"] = x.get_root_fraction();
        j["RootIncDepth"] = x.get_root_inc_depth();
        j["RootLowestDepth"] = x.get_root_lowest_depth();
        j["rOptimumValue"] = x.get_r_optimum_value();
        j["rStartValue"] = x.get_r_start_value();
        j["ShapeEnd"] = x.get_shape_end();
        j["ShapeStart"] = x.get_shape_start();
        j["SpecificLeafArea"] = x.get_specific_leaf_area();
        j["SpecificRootLength"] = x.get_specific_root_length();
        j["SpecLeafAreaBegin"] = x.get_spec_leaf_area_begin();
        j["StartDayNo"] = x.get_start_day_no();
        j["XcenterPos"] = x.get_xcenter_pos();
    }

    inline void from_json(const json & j, coup::TentacledPotentialTranspiration& x) {
        x.set_air_resist_lai_effect(j.at("AirResistLAIEffect").get<coup::RntLaIv>());
        x.set_canopy_dens_max(j.at("CanopyDensMax").get<coup::RntLaIv>());
        x.set_conduct_max(j.at("ConductMax").get<coup::RntLaIv>());
        x.set_conduct_ris(j.at("ConductRis").get<coup::RntLaIv>());
        x.set_conduct_vpd(j.at("ConductVPD").get<coup::RntLaIv>());
        x.set_d_end_value(j.at("DEndValue").get<coup::RntLaIv>());
        x.set_displace(j.at("Displace").get<coup::AlbedoV>());
        x.set_d_optimum_value(j.at("DOptimumValue").get<coup::RntLaIv>());
        x.set_d_start_value(j.at("DStartValue").get<coup::RntLaIv>());
        x.set_plant_add_index(j.at("PlantAddIndex").get<coup::RntLaIv>());
        x.set_resistance_surface(j.at("ResistanceSurface").get<coup::AlbedoV>());
        x.set_roughness_length(j.at("RoughnessLength").get<coup::AlbedoV>());
        x.set_roughness_max(j.at("RoughnessMax").get<coup::RntLaIv>());
        x.set_roughness_min(j.at("RoughnessMin").get<coup::RntLaIv>());
        x.set_z_end_value(j.at("ZEndValue").get<coup::RntLaIv>());
        x.set_z_optimum_value(j.at("ZOptimumValue").get<coup::RntLaIv>());
        x.set_z_start_value(j.at("ZStartValue").get<coup::RntLaIv>());
    }

    inline void to_json(json & j, const coup::TentacledPotentialTranspiration & x) {
        j = json::object();
        j["AirResistLAIEffect"] = x.get_air_resist_lai_effect();
        j["CanopyDensMax"] = x.get_canopy_dens_max();
        j["ConductMax"] = x.get_conduct_max();
        j["ConductRis"] = x.get_conduct_ris();
        j["ConductVPD"] = x.get_conduct_vpd();
        j["DEndValue"] = x.get_d_end_value();
        j["Displace"] = x.get_displace();
        j["DOptimumValue"] = x.get_d_optimum_value();
        j["DStartValue"] = x.get_d_start_value();
        j["PlantAddIndex"] = x.get_plant_add_index();
        j["ResistanceSurface"] = x.get_resistance_surface();
        j["RoughnessLength"] = x.get_roughness_length();
        j["RoughnessMax"] = x.get_roughness_max();
        j["RoughnessMin"] = x.get_roughness_min();
        j["ZEndValue"] = x.get_z_end_value();
        j["ZOptimumValue"] = x.get_z_optimum_value();
        j["ZStartValue"] = x.get_z_start_value();
    }

    inline void from_json(const json & j, coup::HilariousSaltTracer& x) {
        x.set_ad_c(j.at("Ad_c").get<coup::InfilDistF>());
        x.set_init_salt_conc(j.at("InitSaltConc").get<coup::InfilDistF>());
    }

    inline void to_json(json & j, const coup::HilariousSaltTracer & x) {
        j = json::object();
        j["Ad_c"] = x.get_ad_c();
        j["InitSaltConc"] = x.get_init_salt_conc();
    }

    inline void from_json(const json & j, coup::ParametersArraysPlantWaterProcesses& x) {
        x.set_interception(j.at("Interception").get<coup::IndecentInterception>());
        x.set_plant(j.at("Plant").get<coup::StickyPlant>());
        x.set_potential_transpiration(j.at("PotentialTranspiration").get<coup::TentacledPotentialTranspiration>());
        x.set_salt_tracer(j.at("SaltTracer").get<coup::HilariousSaltTracer>());
        x.set_wateruptake(j.at("Wateruptake").get<std::map<std::string, coup::RntLaIv>>());
    }

    inline void to_json(json & j, const coup::ParametersArraysPlantWaterProcesses & x) {
        j = json::object();
        j["Interception"] = x.get_interception();
        j["Plant"] = x.get_plant();
        j["PotentialTranspiration"] = x.get_potential_transpiration();
        j["SaltTracer"] = x.get_salt_tracer();
        j["Wateruptake"] = x.get_wateruptake();
    }

    inline void from_json(const json & j, coup::HilariousSoilheatflows& x) {
        x.set_heatstorage(j.at("Heatstorage").get<coup::InfilDistF>());
        x.set_pipe_segment_length(j.at("PipeSegmentLength").get<std::map<std::string, std::string>>());
        x.set_prod_coef_a(j.at("ProdCoef_A").get<coup::InfilDistF>());
        x.set_prod_coef_a2(j.at("ProdCoef_A2").get<coup::InfilDistF>());
        x.set_temperature(j.at("Temperature").get<coup::InfilDistF>());
        x.set_water_pipe_box_layer(j.at("WaterPipeBoxLayer").get<coup::KonzelmannCoef>());
    }

    inline void to_json(json & j, const coup::HilariousSoilheatflows & x) {
        j = json::object();
        j["Heatstorage"] = x.get_heatstorage();
        j["PipeSegmentLength"] = x.get_pipe_segment_length();
        j["ProdCoef_A"] = x.get_prod_coef_a();
        j["ProdCoef_A2"] = x.get_prod_coef_a2();
        j["Temperature"] = x.get_temperature();
        j["WaterPipeBoxLayer"] = x.get_water_pipe_box_layer();
    }

    inline void from_json(const json & j, coup::ParametersArraysSoilHeatProcesses& x) {
        x.set_soilheatflows(j.at("Soilheatflows").get<coup::HilariousSoilheatflows>());
        x.set_soil_thermal(j.at("SoilThermal").get<std::map<std::string, coup::InfilDistF>>());
    }

    inline void to_json(json & j, const coup::ParametersArraysSoilHeatProcesses & x) {
        j = json::object();
        j["Soilheatflows"] = x.get_soilheatflows();
        j["SoilThermal"] = x.get_soil_thermal();
    }

    inline void from_json(const json & j, coup::SoilHydraulic& x) {
        x.set_air_entry(j.at("AirEntry").get<std::map<std::string, std::string>>());
        x.set_alpha(j.at("Alpha").get<std::map<std::string, std::string>>());
        x.set_b_m_value(j.at("b_m-value").get<coup::InfilDistF>());
        x.set_b_n_value(j.at("b_n-value").get<coup::InfilDistF>());
        x.set_b_n_power_sat_effective(j.at("b_nPowerSatEffective").get<coup::InfilDistF>());
        x.set_b_n_power_sat_rel(j.at("b_nPowerSatRel").get<coup::InfilDistF>());
        x.set_b_n_tortuosity(j.at("b_nTortuosity").get<coup::InfilDistF>());
        x.set_b_air_entry(j.at("bAirEntry").get<coup::InfilDistF>());
        x.set_b_alpha(j.at("bAlpha").get<coup::InfilDistF>());
        x.set_b_lambda(j.at("bLambda").get<coup::InfilDistF>());
        x.set_b_macro_pore(j.at("bMacroPore").get<coup::InfilDistF>());
        x.set_b_matrix_conductivity(j.at("bMatrixConductivity").get<coup::InfilDistF>());
        x.set_b_residual_water(j.at("bResidualWater").get<coup::InfilDistF>());
        x.set_b_saturation(j.at("bSaturation").get<coup::InfilDistF>());
        x.set_b_scalingp_f(j.at("bScalingpF").get<coup::InfilDistF>());
        x.set_b_total_conductivity(j.at("bTotalConductivity").get<coup::InfilDistF>());
        x.set_b_upper_boundary(j.at("bUpperBoundary").get<coup::InfilDistF>());
        x.set_b_wilting_point(j.at("bWiltingPoint").get<coup::InfilDistF>());
        x.set_clay_content(j.at("ClayContent").get<std::map<std::string, std::string>>());
        x.set_lambda(j.at("Lambda").get<std::map<std::string, std::string>>());
        x.set_lower_valid(j.at("LowerValid").get<std::map<std::string, std::string>>());
        x.set_m_value(j.at("m-value").get<std::map<std::string, std::string>>());
        x.set_m_m_value(j.at("m_m-value").get<coup::InfilDistF>());
        x.set_m_n_value(j.at("m_n-value").get<coup::InfilDistF>());
        x.set_m_n_power_sat_effective(j.at("m_nPowerSatEffective").get<coup::InfilDistF>());
        x.set_m_n_power_sat_rel(j.at("m_nPowerSatRel").get<coup::InfilDistF>());
        x.set_m_n_tortuosity(j.at("m_nTortuosity").get<coup::InfilDistF>());
        x.set_m_scalingp_f(j.at("M_ScalingpF").get<coup::InfilDistF>());
        x.set_macro_pore(j.at("MacroPore").get<std::map<std::string, std::string>>());
        x.set_m_air_entry(j.at("mAirEntry").get<coup::InfilDistF>());
        x.set_m_alpha(j.at("mAlpha").get<coup::InfilDistF>());
        x.set_matrix_conductivity(j.at("MatrixConductivity").get<std::map<std::string, std::string>>());
        x.set_m_lambda(j.at("mLambda").get<coup::InfilDistF>());
        x.set_m_macro_pore(j.at("mMacroPore").get<coup::InfilDistF>());
        x.set_m_matrix_conductivity(j.at("mMatrixConductivity").get<coup::InfilDistF>());
        x.set_m_residual_water(j.at("mResidualWater").get<coup::InfilDistF>());
        x.set_m_saturation(j.at("mSaturation").get<coup::InfilDistF>());
        x.set_m_total_conductivity(j.at("mTotalConductivity").get<coup::InfilDistF>());
        x.set_m_upper_boundary(j.at("mUpperBoundary").get<coup::InfilDistF>());
        x.set_m_upper_boundary_theta(j.at("mUpperBoundaryTheta").get<coup::InfilDistF>());
        x.set_m_wilting_point(j.at("mWiltingPoint").get<coup::InfilDistF>());
        x.set_n_value(j.at("n-value").get<std::map<std::string, std::string>>());
        x.set_n_power_sat_effective(j.at("nPowerSatEffective").get<std::map<std::string, std::string>>());
        x.set_n_power_sat_rel(j.at("nPowerSatRel").get<std::map<std::string, std::string>>());
        x.set_n_tortuosity(j.at("nTortuosity").get<std::map<std::string, std::string>>());
        x.set_profile_layer(j.at("ProfileLayer").get<std::map<std::string, std::string>>());
        x.set_profile_no(j.at("ProfileNo").get<std::map<std::string, std::string>>());
        x.set_profile_rep_no(j.at("ProfileRepNo").get<std::map<std::string, std::string>>());
        x.set_regline_n(j.at("ReglineN").get<std::map<std::string, std::string>>());
        x.set_regline_r2(j.at("ReglineR2").get<std::map<std::string, std::string>>());
        x.set_residual_water(j.at("ResidualWater").get<std::map<std::string, std::string>>());
        x.set_sand_content(j.at("SandContent").get<std::map<std::string, std::string>>());
        x.set_saturation(j.at("Saturation").get<std::map<std::string, std::string>>());
        x.set_scalingp_f(j.at("ScalingpF").get<std::map<std::string, std::string>>());
        x.set_total_conductivity(j.at("TotalConductivity").get<std::map<std::string, std::string>>());
        x.set_upper_boundary(j.at("UpperBoundary").get<std::map<std::string, std::string>>());
        x.set_upper_boundary_theta(j.at("UpperBoundaryTheta").get<coup::InfilDistF>());
        x.set_upper_theta_boundary(j.at("UpperThetaBoundary").get<std::map<std::string, std::string>>());
        x.set_upper_valid(j.at("UpperValid").get<std::map<std::string, std::string>>());
        x.set_wilting_point(j.at("WiltingPoint").get<std::map<std::string, std::string>>());
    }

    inline void to_json(json & j, const coup::SoilHydraulic & x) {
        j = json::object();
        j["AirEntry"] = x.get_air_entry();
        j["Alpha"] = x.get_alpha();
        j["b_m-value"] = x.get_b_m_value();
        j["b_n-value"] = x.get_b_n_value();
        j["b_nPowerSatEffective"] = x.get_b_n_power_sat_effective();
        j["b_nPowerSatRel"] = x.get_b_n_power_sat_rel();
        j["b_nTortuosity"] = x.get_b_n_tortuosity();
        j["bAirEntry"] = x.get_b_air_entry();
        j["bAlpha"] = x.get_b_alpha();
        j["bLambda"] = x.get_b_lambda();
        j["bMacroPore"] = x.get_b_macro_pore();
        j["bMatrixConductivity"] = x.get_b_matrix_conductivity();
        j["bResidualWater"] = x.get_b_residual_water();
        j["bSaturation"] = x.get_b_saturation();
        j["bScalingpF"] = x.get_b_scalingp_f();
        j["bTotalConductivity"] = x.get_b_total_conductivity();
        j["bUpperBoundary"] = x.get_b_upper_boundary();
        j["bWiltingPoint"] = x.get_b_wilting_point();
        j["ClayContent"] = x.get_clay_content();
        j["Lambda"] = x.get_lambda();
        j["LowerValid"] = x.get_lower_valid();
        j["m-value"] = x.get_m_value();
        j["m_m-value"] = x.get_m_m_value();
        j["m_n-value"] = x.get_m_n_value();
        j["m_nPowerSatEffective"] = x.get_m_n_power_sat_effective();
        j["m_nPowerSatRel"] = x.get_m_n_power_sat_rel();
        j["m_nTortuosity"] = x.get_m_n_tortuosity();
        j["M_ScalingpF"] = x.get_m_scalingp_f();
        j["MacroPore"] = x.get_macro_pore();
        j["mAirEntry"] = x.get_m_air_entry();
        j["mAlpha"] = x.get_m_alpha();
        j["MatrixConductivity"] = x.get_matrix_conductivity();
        j["mLambda"] = x.get_m_lambda();
        j["mMacroPore"] = x.get_m_macro_pore();
        j["mMatrixConductivity"] = x.get_m_matrix_conductivity();
        j["mResidualWater"] = x.get_m_residual_water();
        j["mSaturation"] = x.get_m_saturation();
        j["mTotalConductivity"] = x.get_m_total_conductivity();
        j["mUpperBoundary"] = x.get_m_upper_boundary();
        j["mUpperBoundaryTheta"] = x.get_m_upper_boundary_theta();
        j["mWiltingPoint"] = x.get_m_wilting_point();
        j["n-value"] = x.get_n_value();
        j["nPowerSatEffective"] = x.get_n_power_sat_effective();
        j["nPowerSatRel"] = x.get_n_power_sat_rel();
        j["nTortuosity"] = x.get_n_tortuosity();
        j["ProfileLayer"] = x.get_profile_layer();
        j["ProfileNo"] = x.get_profile_no();
        j["ProfileRepNo"] = x.get_profile_rep_no();
        j["ReglineN"] = x.get_regline_n();
        j["ReglineR2"] = x.get_regline_r2();
        j["ResidualWater"] = x.get_residual_water();
        j["SandContent"] = x.get_sand_content();
        j["Saturation"] = x.get_saturation();
        j["ScalingpF"] = x.get_scalingp_f();
        j["TotalConductivity"] = x.get_total_conductivity();
        j["UpperBoundary"] = x.get_upper_boundary();
        j["UpperBoundaryTheta"] = x.get_upper_boundary_theta();
        j["UpperThetaBoundary"] = x.get_upper_theta_boundary();
        j["UpperValid"] = x.get_upper_valid();
        j["WiltingPoint"] = x.get_wilting_point();
    }

    inline void from_json(const json & j, coup::HilariousSoilwaterflows& x) {
        x.set_hys_max_eff_cond(j.at("HysMaxEffCond").get<coup::InfilDistF>());
        x.set_hys_max_eff_ret(j.at("HysMaxEffRet").get<coup::InfilDistF>());
        x.set_ini_pressure_heads(j.at("IniPressureHeads").get<coup::InfilDistF>());
        x.set_ini_water_contents(j.at("IniWaterContents").get<coup::InfilDistF>());
    }

    inline void to_json(json & j, const coup::HilariousSoilwaterflows & x) {
        j = json::object();
        j["HysMaxEffCond"] = x.get_hys_max_eff_cond();
        j["HysMaxEffRet"] = x.get_hys_max_eff_ret();
        j["IniPressureHeads"] = x.get_ini_pressure_heads();
        j["IniWaterContents"] = x.get_ini_water_contents();
    }

    inline void from_json(const json & j, coup::ParametersArraysSoilWaterProcesses& x) {
        x.set_soil_hydraulic(j.at("SoilHydraulic").get<coup::SoilHydraulic>());
        x.set_soilwaterflows(j.at("Soilwaterflows").get<coup::HilariousSoilwaterflows>());
    }

    inline void to_json(json & j, const coup::ParametersArraysSoilWaterProcesses & x) {
        j = json::object();
        j["SoilHydraulic"] = x.get_soil_hydraulic();
        j["Soilwaterflows"] = x.get_soilwaterflows();
    }

    inline void from_json(const json & j, coup::ParametersArrays& x) {
        x.set_atmospheric_related_processes(j.at("AtmosphericRelatedProcesses").get<coup::ParametersArraysAtmosphericRelatedProcesses>());
        x.set_model_facilities(j.at("ModelFacilities").get<coup::ParametersArraysModelFacilities>());
        x.set_nitrogenand_carbon(j.at("NitrogenandCarbon").get<coup::ParametersArraysNitrogenandCarbon>());
        x.set_nitrogenand_carbon_below_ground(j.at("NitrogenandCarbon-BelowGround").get<coup::ParametersArraysNitrogenandCarbonBelowGround>());
        x.set_plant_water_processes(j.at("PlantWaterProcesses").get<coup::ParametersArraysPlantWaterProcesses>());
        x.set_soil_heat_processes(j.at("SoilHeatProcesses").get<coup::ParametersArraysSoilHeatProcesses>());
        x.set_soil_water_processes(j.at("SoilWaterProcesses").get<coup::ParametersArraysSoilWaterProcesses>());
    }

    inline void to_json(json & j, const coup::ParametersArrays & x) {
        j = json::object();
        j["AtmosphericRelatedProcesses"] = x.get_atmospheric_related_processes();
        j["ModelFacilities"] = x.get_model_facilities();
        j["NitrogenandCarbon"] = x.get_nitrogenand_carbon();
        j["NitrogenandCarbon-BelowGround"] = x.get_nitrogenand_carbon_below_ground();
        j["PlantWaterProcesses"] = x.get_plant_water_processes();
        j["SoilHeatProcesses"] = x.get_soil_heat_processes();
        j["SoilWaterProcesses"] = x.get_soil_water_processes();
    }

    inline void from_json(const json & j, coup::AdditionalDetails& x) {
        x.set_locked_multi_store(j.at("LockedMultiStore").get<std::string>());
    }

    inline void to_json(json & j, const coup::AdditionalDetails & x) {
        j = json::object();
        j["LockedMultiStore"] = x.get_locked_multi_store();
    }

    inline void from_json(const json & j, coup::GeneralInformation& x) {
        x.set_comments(j.at("Comments").get<std::string>());
        x.set_date_created(j.at("Date_Created").get<std::string>());
        x.set_date_modification(j.at("Date_Modification").get<std::string>());
        x.set_exe_file_date(j.at("ExeFileDate").get<std::string>());
        x.set_file_version_number(j.at("FileVersionNumber").get<std::string>());
        x.set_finished(j.at("Finished").get<std::string>());
        x.set_m_bin_file(j.at("MBinFile").get<std::string>());
        x.set_multi_simulaton(j.at("MultiSimulaton").get<std::string>());
        x.set_original_file_name(j.at("OriginalFileName").get<std::string>());
        x.set_rund_id(j.at("RundId").get<std::string>());
        x.set_sim_number(j.at("SimNumber").get<std::string>());
    }

    inline void to_json(json & j, const coup::GeneralInformation & x) {
        j = json::object();
        j["Comments"] = x.get_comments();
        j["Date_Created"] = x.get_date_created();
        j["Date_Modification"] = x.get_date_modification();
        j["ExeFileDate"] = x.get_exe_file_date();
        j["FileVersionNumber"] = x.get_file_version_number();
        j["Finished"] = x.get_finished();
        j["MBinFile"] = x.get_m_bin_file();
        j["MultiSimulaton"] = x.get_multi_simulaton();
        j["OriginalFileName"] = x.get_original_file_name();
        j["RundId"] = x.get_rund_id();
        j["SimNumber"] = x.get_sim_number();
    }

    inline void from_json(const json & j, coup::NumericalOptions& x) {
        x.set_number_iterations(j.at("NumberIterations").get<std::string>());
    }

    inline void to_json(json & j, const coup::NumericalOptions & x) {
        j = json::object();
        j["NumberIterations"] = x.get_number_iterations();
    }

    inline void from_json(const json & j, coup::SimulationPeriod& x) {
        x.set_length_post_period(j.at("LengthPostPeriod").get<std::string>());
        x.set_prior_sim_time(j.at("PriorSimTime").get<std::string>());
        x.set_sim_end_date(j.at("SimEndDate").get<std::string>());
        x.set_sim_end_min(j.at("SimEndMin").get<std::string>());
        x.set_sim_start_date(j.at("SimStartDate").get<std::string>());
        x.set_sim_start_min(j.at("SimStartMin").get<std::string>());
        x.set_sim_start_scaling(j.at("SimStartScaling").get<std::string>());
    }

    inline void to_json(json & j, const coup::SimulationPeriod & x) {
        j = json::object();
        j["LengthPostPeriod"] = x.get_length_post_period();
        j["PriorSimTime"] = x.get_prior_sim_time();
        j["SimEndDate"] = x.get_sim_end_date();
        j["SimEndMin"] = x.get_sim_end_min();
        j["SimStartDate"] = x.get_sim_start_date();
        j["SimStartMin"] = x.get_sim_start_min();
        j["SimStartScaling"] = x.get_sim_start_scaling();
    }

    inline void from_json(const json & j, coup::TimeResolution& x) {
        x.set_output_interval_days(j.at("OutputInterval_Days").get<std::string>());
        x.set_output_interval_minutes(j.at("OutputInterval_Minutes").get<std::string>());
        x.set_time_resoluton(j.at("TimeResoluton").get<std::string>());
    }

    inline void to_json(json & j, const coup::TimeResolution & x) {
        j = json::object();
        j["OutputInterval_Days"] = x.get_output_interval_days();
        j["OutputInterval_Minutes"] = x.get_output_interval_minutes();
        j["TimeResoluton"] = x.get_time_resoluton();
    }

    inline void from_json(const json & j, coup::RunInfo& x) {
        x.set_additional_details(j.at("Additional_Details").get<coup::AdditionalDetails>());
        x.set_general_information(j.at("General_Information").get<coup::GeneralInformation>());
        x.set_numerical_options(j.at("Numerical_Options").get<coup::NumericalOptions>());
        x.set_simulation_period(j.at("Simulation_Period").get<coup::SimulationPeriod>());
        x.set_time_resolution(j.at("Time_Resolution").get<coup::TimeResolution>());
    }

    inline void to_json(json & j, const coup::RunInfo & x) {
        j = json::object();
        j["Additional_Details"] = x.get_additional_details();
        j["General_Information"] = x.get_general_information();
        j["Numerical_Options"] = x.get_numerical_options();
        j["Simulation_Period"] = x.get_simulation_period();
        j["Time_Resolution"] = x.get_time_resolution();
    }

    inline void from_json(const json & j, coup::Node& x) {
        x.set_model_files(j.at("Model_Files").get<coup::ModelFiles>());
        x.set_model_options(j.at("Model_Options").get<coup::ModelOptions>());
        x.set_output_variables(j.at("Output_Variables").get<coup::OutputVariables>());
        x.set_parameters(j.at("Parameters").get<coup::Parameters>());
        x.set_parameters_arrays(j.at("Parameters_Arrays").get<coup::ParametersArrays>());
        x.set_run_info(j.at("Run_Info").get<coup::RunInfo>());
    }

    inline void to_json(json & j, const coup::Node & x) {
        j = json::object();
        j["Model_Files"] = x.get_model_files();
        j["Model_Options"] = x.get_model_options();
        j["Output_Variables"] = x.get_output_variables();
        j["Parameters"] = x.get_parameters();
        j["Parameters_Arrays"] = x.get_parameters_arrays();
        j["Run_Info"] = x.get_run_info();
    }

    inline void from_json(const json & j, coup::Coup& x) {
        x.set_node(j.at("node").get<coup::Node>());
    }

    inline void to_json(json & j, const coup::Coup & x) {
        j = json::object();
        j["node"] = x.get_node();
    }

    inline void from_json(const json & j, coup::Condition3Enum & x) {
        static std::unordered_map<std::string, coup::Condition3Enum> enumValues {
            {"Evaporation > 0 is true", coup::Condition3Enum::EVAPORATION_0_IS_TRUE},
            {"HeatEq > 0 is true", coup::Condition3Enum::HEAT_EQ_0_IS_TRUE},
            {"Heat Pump >= 1 is false", coup::Condition3Enum::HEAT_PUMP_1_IS_FALSE},
            {"Nitrogen and Carbon > 0 is false", coup::Condition3Enum::NITROGEN_AND_CARBON_0_IS_FALSE},
            {"Nitrogen and Carbon >= 1 is false", coup::Condition3Enum::NITROGEN_AND_CARBON_1_IS_FALSE},
            {"OnlyNC < 1 is true", coup::Condition3Enum::ONLY_NC_1_IS_TRUE},
            {"Phosphorus > 0 is false", coup::Condition3Enum::PHOSPHORUS_0_IS_FALSE},
            {"PlantType > 0 is true", coup::Condition3Enum::PLANT_TYPE_0_IS_TRUE},
            {"PlantType >= 2 is true", coup::Condition3Enum::PLANT_TYPE_2_IS_TRUE},
            {"RadiationInput > 0 is true", coup::Condition3Enum::RADIATION_INPUT_0_IS_TRUE},
            {"SaltTracer > 0 is false", coup::Condition3Enum::SALT_TRACER_0_IS_FALSE},
            {"SnowPack > 0 is true", coup::Condition3Enum::SNOW_PACK_0_IS_TRUE},
            {"SoilDrainageInput > 0 is false", coup::Condition3Enum::SOIL_DRAINAGE_INPUT_0_IS_FALSE},
            {"Terminating Harvest > 0 is false", coup::Condition3Enum::TERMINATING_HARVEST_0_IS_FALSE},
            {"WaterEq > 0 is true", coup::Condition3Enum::WATER_EQ_0_IS_TRUE},
            {"WaterEq >= 1 is true", coup::Condition3Enum::WATER_EQ_1_IS_TRUE},
        };
        auto iter = enumValues.find(j.get<std::string>());
        if (iter != enumValues.end()) {
            x = iter->second;
        }
    }

    inline void to_json(json & j, const coup::Condition3Enum & x) {
        switch (x) {
            case coup::Condition3Enum::EVAPORATION_0_IS_TRUE: j = "Evaporation > 0 is true"; break;
            case coup::Condition3Enum::HEAT_EQ_0_IS_TRUE: j = "HeatEq > 0 is true"; break;
            case coup::Condition3Enum::HEAT_PUMP_1_IS_FALSE: j = "Heat Pump >= 1 is false"; break;
            case coup::Condition3Enum::NITROGEN_AND_CARBON_0_IS_FALSE: j = "Nitrogen and Carbon > 0 is false"; break;
            case coup::Condition3Enum::NITROGEN_AND_CARBON_1_IS_FALSE: j = "Nitrogen and Carbon >= 1 is false"; break;
            case coup::Condition3Enum::ONLY_NC_1_IS_TRUE: j = "OnlyNC < 1 is true"; break;
            case coup::Condition3Enum::PHOSPHORUS_0_IS_FALSE: j = "Phosphorus > 0 is false"; break;
            case coup::Condition3Enum::PLANT_TYPE_0_IS_TRUE: j = "PlantType > 0 is true"; break;
            case coup::Condition3Enum::PLANT_TYPE_2_IS_TRUE: j = "PlantType >= 2 is true"; break;
            case coup::Condition3Enum::RADIATION_INPUT_0_IS_TRUE: j = "RadiationInput > 0 is true"; break;
            case coup::Condition3Enum::SALT_TRACER_0_IS_FALSE: j = "SaltTracer > 0 is false"; break;
            case coup::Condition3Enum::SNOW_PACK_0_IS_TRUE: j = "SnowPack > 0 is true"; break;
            case coup::Condition3Enum::SOIL_DRAINAGE_INPUT_0_IS_FALSE: j = "SoilDrainageInput > 0 is false"; break;
            case coup::Condition3Enum::TERMINATING_HARVEST_0_IS_FALSE: j = "Terminating Harvest > 0 is false"; break;
            case coup::Condition3Enum::WATER_EQ_0_IS_TRUE: j = "WaterEq > 0 is true"; break;
            case coup::Condition3Enum::WATER_EQ_1_IS_TRUE: j = "WaterEq >= 1 is true"; break;
            default: throw "This should not happen";
        }
    }

    inline void from_json(const json & j, coup::Condition2Enum & x) {
        if (j == "Grazing > 0 is false") x = coup::Condition2Enum::GRAZING_0_IS_FALSE;
        else if (j == "Growth > 0 is false") x = coup::Condition2Enum::GROWTH_0_IS_FALSE;
        else if (j == "Growth > 2 is false") x = coup::Condition2Enum::GROWTH_2_IS_FALSE;
        else if (j == "Growth = 4 is false") x = coup::Condition2Enum::GROWTH_4_IS_FALSE;
        else if (j == "Nitrogen and Carbon >= 1 is false") x = coup::Condition2Enum::NITROGEN_AND_CARBON_1_IS_FALSE;
        else if (j == "PlantType > 0 is true") x = coup::Condition2Enum::PLANT_TYPE_0_IS_TRUE;
        else if (j == "PlantWaterStorage > 0 is false") x = coup::Condition2Enum::PLANT_WATER_STORAGE_0_IS_FALSE;
        else if (j == "PrecInterception > 0 is true") x = coup::Condition2Enum::PREC_INTERCEPTION_0_IS_TRUE;
        else if (j == "Salinity stress > 0 is false") x = coup::Condition2Enum::SALINITY_STRESS_0_IS_FALSE;
        else if (j == "SnowPack >= 1 is true") x = coup::Condition2Enum::SNOW_PACK_1_IS_TRUE;
        else if (j == "WaterEq = 1 is true") x = coup::Condition2Enum::WATER_EQ_1_IS_TRUE;
        else if (j == "Wood Eating > 0 is false") x = coup::Condition2Enum::WOOD_EATING_0_IS_FALSE;
        else throw "Input JSON does not conform to schema";
    }

    inline void to_json(json & j, const coup::Condition2Enum & x) {
        switch (x) {
            case coup::Condition2Enum::GRAZING_0_IS_FALSE: j = "Grazing > 0 is false"; break;
            case coup::Condition2Enum::GROWTH_0_IS_FALSE: j = "Growth > 0 is false"; break;
            case coup::Condition2Enum::GROWTH_2_IS_FALSE: j = "Growth > 2 is false"; break;
            case coup::Condition2Enum::GROWTH_4_IS_FALSE: j = "Growth = 4 is false"; break;
            case coup::Condition2Enum::NITROGEN_AND_CARBON_1_IS_FALSE: j = "Nitrogen and Carbon >= 1 is false"; break;
            case coup::Condition2Enum::PLANT_TYPE_0_IS_TRUE: j = "PlantType > 0 is true"; break;
            case coup::Condition2Enum::PLANT_WATER_STORAGE_0_IS_FALSE: j = "PlantWaterStorage > 0 is false"; break;
            case coup::Condition2Enum::PREC_INTERCEPTION_0_IS_TRUE: j = "PrecInterception > 0 is true"; break;
            case coup::Condition2Enum::SALINITY_STRESS_0_IS_FALSE: j = "Salinity stress > 0 is false"; break;
            case coup::Condition2Enum::SNOW_PACK_1_IS_TRUE: j = "SnowPack >= 1 is true"; break;
            case coup::Condition2Enum::WATER_EQ_1_IS_TRUE: j = "WaterEq = 1 is true"; break;
            case coup::Condition2Enum::WOOD_EATING_0_IS_FALSE: j = "Wood Eating > 0 is false"; break;
            default: throw "This should not happen";
        }
    }

    inline void from_json(const json & j, coup::LaiAbovecanopyArrayName & x) {
        if (j == "") x = coup::LaiAbovecanopyArrayName::EMPTY;
        else if (j == "NumberofPlants") x = coup::LaiAbovecanopyArrayName::NUMBEROF_PLANTS;
        else if (j == "NumofFertDays") x = coup::LaiAbovecanopyArrayName::NUMOF_FERT_DAYS;
        else if (j == "NumofFertStages") x = coup::LaiAbovecanopyArrayName::NUMOF_FERT_STAGES;
        else if (j == "NumofFertYears") x = coup::LaiAbovecanopyArrayName::NUMOF_FERT_YEARS;
        else if (j == "NumofManureDays") x = coup::LaiAbovecanopyArrayName::NUMOF_MANURE_DAYS;
        else throw "Input JSON does not conform to schema";
    }

    inline void to_json(json & j, const coup::LaiAbovecanopyArrayName & x) {
        switch (x) {
            case coup::LaiAbovecanopyArrayName::EMPTY: j = ""; break;
            case coup::LaiAbovecanopyArrayName::NUMBEROF_PLANTS: j = "NumberofPlants"; break;
            case coup::LaiAbovecanopyArrayName::NUMOF_FERT_DAYS: j = "NumofFertDays"; break;
            case coup::LaiAbovecanopyArrayName::NUMOF_FERT_STAGES: j = "NumofFertStages"; break;
            case coup::LaiAbovecanopyArrayName::NUMOF_FERT_YEARS: j = "NumofFertYears"; break;
            case coup::LaiAbovecanopyArrayName::NUMOF_MANURE_DAYS: j = "NumofManureDays"; break;
            default: throw "This should not happen";
        }
    }

    inline void from_json(const json & j, coup::LaiAbovecanopyCondition1 & x) {
        if (j == "Evaporation > 1 is true") x = coup::LaiAbovecanopyCondition1::EVAPORATION_1_IS_TRUE;
        else if (j == "Nitrogen and Carbon >= 1 is false") x = coup::LaiAbovecanopyCondition1::NITROGEN_AND_CARBON_1_IS_FALSE;
        else if (j == "PlantType > 0 is true") x = coup::LaiAbovecanopyCondition1::PLANT_TYPE_0_IS_TRUE;
        else if (j == "PlantType = 3 is false") x = coup::LaiAbovecanopyCondition1::PLANT_TYPE_3_IS_FALSE;
        else if (j == "SaltTracer > 0 is false") x = coup::LaiAbovecanopyCondition1::SALT_TRACER_0_IS_FALSE;
        else throw "Input JSON does not conform to schema";
    }

    inline void to_json(json & j, const coup::LaiAbovecanopyCondition1 & x) {
        switch (x) {
            case coup::LaiAbovecanopyCondition1::EVAPORATION_1_IS_TRUE: j = "Evaporation > 1 is true"; break;
            case coup::LaiAbovecanopyCondition1::NITROGEN_AND_CARBON_1_IS_FALSE: j = "Nitrogen and Carbon >= 1 is false"; break;
            case coup::LaiAbovecanopyCondition1::PLANT_TYPE_0_IS_TRUE: j = "PlantType > 0 is true"; break;
            case coup::LaiAbovecanopyCondition1::PLANT_TYPE_3_IS_FALSE: j = "PlantType = 3 is false"; break;
            case coup::LaiAbovecanopyCondition1::SALT_TRACER_0_IS_FALSE: j = "SaltTracer > 0 is false"; break;
            default: throw "This should not happen";
        }
    }

    inline void from_json(const json & j, coup::CCoarseRootsAtmLayerArrayName & x) {
        if (j == "NumberofLayers") x = coup::CCoarseRootsAtmLayerArrayName::NUMBEROF_LAYERS;
        else throw "Input JSON does not conform to schema";
    }

    inline void to_json(json & j, const coup::CCoarseRootsAtmLayerArrayName & x) {
        switch (x) {
            case coup::CCoarseRootsAtmLayerArrayName::NUMBEROF_LAYERS: j = "NumberofLayers"; break;
            default: throw "This should not happen";
        }
    }

    inline void from_json(const json & j, coup::ArrayName & x) {
        if (j == "HeatEq > 0 is true") x = coup::ArrayName::HEAT_EQ_0_IS_TRUE;
        else if (j == "Insulated Water Pipe > 0 is false") x = coup::ArrayName::INSULATED_WATER_PIPE_0_IS_FALSE;
        else if (j == "NumberofWaterPipesegments") x = coup::ArrayName::NUMBEROF_WATER_PIPESEGMENTS;
        else if (j == "0.10000000000000001") x = coup::ArrayName::THE_010000000000000001;
        else throw "Input JSON does not conform to schema";
    }

    inline void to_json(json & j, const coup::ArrayName & x) {
        switch (x) {
            case coup::ArrayName::HEAT_EQ_0_IS_TRUE: j = "HeatEq > 0 is true"; break;
            case coup::ArrayName::INSULATED_WATER_PIPE_0_IS_FALSE: j = "Insulated Water Pipe > 0 is false"; break;
            case coup::ArrayName::NUMBEROF_WATER_PIPESEGMENTS: j = "NumberofWaterPipesegments"; break;
            case coup::ArrayName::THE_010000000000000001: j = "0.10000000000000001"; break;
            default: throw "This should not happen";
        }
    }

    inline void from_json(const json & j, coup::RntLaIvCondition1 & x) {
        if (j == "Nitrogen and Carbon > 0 is false") x = coup::RntLaIvCondition1::NITROGEN_AND_CARBON_0_IS_FALSE;
        else if (j == "Nitrogen and Carbon >= 1 is false") x = coup::RntLaIvCondition1::NITROGEN_AND_CARBON_1_IS_FALSE;
        else if (j == "Phosphorus >= 1 is false") x = coup::RntLaIvCondition1::PHOSPHORUS_1_IS_FALSE;
        else if (j == "PlantType > 0 is true") x = coup::RntLaIvCondition1::PLANT_TYPE_0_IS_TRUE;
        else if (j == "PlantType >= 3 is false") x = coup::RntLaIvCondition1::PLANT_TYPE_3_IS_FALSE;
        else if (j == "PlantType = 3 is false") x = coup::RntLaIvCondition1::RNT_LA_IV_CONDITION1_PLANT_TYPE_3_IS_FALSE;
        else throw "Input JSON does not conform to schema";
    }

    inline void to_json(json & j, const coup::RntLaIvCondition1 & x) {
        switch (x) {
            case coup::RntLaIvCondition1::NITROGEN_AND_CARBON_0_IS_FALSE: j = "Nitrogen and Carbon > 0 is false"; break;
            case coup::RntLaIvCondition1::NITROGEN_AND_CARBON_1_IS_FALSE: j = "Nitrogen and Carbon >= 1 is false"; break;
            case coup::RntLaIvCondition1::PHOSPHORUS_1_IS_FALSE: j = "Phosphorus >= 1 is false"; break;
            case coup::RntLaIvCondition1::PLANT_TYPE_0_IS_TRUE: j = "PlantType > 0 is true"; break;
            case coup::RntLaIvCondition1::PLANT_TYPE_3_IS_FALSE: j = "PlantType >= 3 is false"; break;
            case coup::RntLaIvCondition1::RNT_LA_IV_CONDITION1_PLANT_TYPE_3_IS_FALSE: j = "PlantType = 3 is false"; break;
            default: throw "This should not happen";
        }
    }

    inline void from_json(const json & j, coup::AlbedoVArrayName & x) {
        if (j == "NumberofDayNumberforSinglePlantSeasonality") x = coup::AlbedoVArrayName::NUMBEROF_DAY_NUMBERFOR_SINGLE_PLANT_SEASONALITY;
        else if (j == "NumberRootDayLayers") x = coup::AlbedoVArrayName::NUMBER_ROOT_DAY_LAYERS;
        else throw "Input JSON does not conform to schema";
    }

    inline void to_json(json & j, const coup::AlbedoVArrayName & x) {
        switch (x) {
            case coup::AlbedoVArrayName::NUMBEROF_DAY_NUMBERFOR_SINGLE_PLANT_SEASONALITY: j = "NumberofDayNumberforSinglePlantSeasonality"; break;
            case coup::AlbedoVArrayName::NUMBER_ROOT_DAY_LAYERS: j = "NumberRootDayLayers"; break;
            default: throw "This should not happen";
        }
    }
}
