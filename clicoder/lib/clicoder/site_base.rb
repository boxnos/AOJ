require 'open-uri'
require 'nokogiri'
require 'yaml'
require 'net/http'
require 'abstract_method'
require 'kconv'

require 'clicoder'
require 'clicoder/config'

module Clicoder
  class SiteBase
    include Helper

    # Parameters
    abstract_method :site_name
    abstract_method :problem_url
    abstract_method :description_xpath
    abstract_method :inputs_xpath
    abstract_method :outputs_xpath
    abstract_method :working_directory

    # Operations
    abstract_method :login
    abstract_method :submit
    abstract_method :open_submission

    def self.new_with_config(config)
      case config['site']
      when 'sample_site'
        SampleSite.new
      when 'aoj'
        AOJ.new(config['problem_number'])
      when 'atcoder'
        AtCoder.new(config['contest_id'], config['problem_number'])
      end
    end

    def start
      if fetch_description
        prepare_directories
        login do
          download_description
          download_inputs
          download_outputs
        end
        copy_template
        copy_makefile
        store_local_config

        true
      else
        false
      end
    end

    def prepare_directories
      FileUtils.mkdir_p(working_directory)
      [INPUTS_DIRNAME, OUTPUTS_DIRNAME, MY_OUTPUTS_DIRNAME].each do |dir|
        FileUtils.mkdir_p("#{working_directory}/#{dir}")
      end
    end

    def download_description
      File.open("#{working_directory}/description.md", 'w') do |f|
        IO.popen("pandoc -f html -t markdown", "r+") do |io|
          io.write fetch_description
          io.close_write
          f.write io.read
        end
      end
    end


    def download_inputs
      fetch_inputs.each_with_index do |input, i|
        File.open("#{working_directory}/#{INPUTS_DIRNAME}/#{i}.txt", 'w') do |f|
          f.write(clean_io input)
        end
      end
    end

    def download_outputs
      fetch_outputs.each_with_index do |output, i|
        File.open("#{working_directory}/#{OUTPUTS_DIRNAME}/#{i}.txt", 'w') do |f|
          f.write(clean_io output)
        end
      end
    end

    def copy_template
      template_file = config.asset('template')
      return unless File.file?(template_file)
      ext = File.extname(template_file)
      FileUtils.cp(template_file, "#{working_directory}/main#{ext}")
    end

    def copy_makefile
      makefile = config.asset('makefile')
      return unless File.file?(makefile)
      ext = File.extname(makefile)
      FileUtils.cp(makefile, "#{working_directory}/Makefile")
    end

    def fetch_description
      xml_document.at_xpath(description_xpath)
    end

    def fetch_inputs
      input_nodes = xml_document.xpath(inputs_xpath)
      input_nodes.map(&:text)
    end

    def fetch_outputs
      outputs_nodes = xml_document.xpath(outputs_xpath)
      outputs_nodes.map(&:text)
    end

    def store_local_config
      config.local['site'] = site_name
      File.open("#{working_directory}/.config.yml", 'w') do |f|
        f.write(config.local.to_yaml)
      end
    end

    def xml_document
      @xml_document ||= Nokogiri::HTML(open(problem_url).read.toutf8)
    end

    def config
      @config ||= Config.new
    end

    private
    def clean_io(text)
      text.lstrip.gsub(/\r/, '')
    end
  end
end
