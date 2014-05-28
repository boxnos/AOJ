require 'clicoder/site_base'
require 'clicoder/config'

module Clicoder
  class AOJ < SiteBase

    def initialize(problem_number)
      config.local['problem_number'] = problem_number
      @problem_id =
        if problem_number =~ /^+\d$/
          "%04d" % problem_number
        else
          problem_number
        end
    end

    def submit
      submit_url = 'http://judge.u-aizu.ac.jp/onlinejudge/servlet/Submit'
      post_params = {
        userID: config.get('aoj', 'user_id'),
        password: config.get('aoj', 'password'),
        problemNO: @problem_id,
        language: ext_to_language_name(File.extname(detect_main)),
        sourceCode: File.read(detect_main),
        submit: 'Send'
      }
      response = Net::HTTP.post_form(URI(submit_url), post_params)
      return response.body !~ /UserID or Password is Wrong/
    end

    def open_submission
      Launchy.open('http://judge.u-aizu.ac.jp/onlinejudge/status.jsp')
    end

    def login
      # no need to login for now
      yield
    end

    def site_name
      'aoj'
    end

    def problem_url
      "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=#{@problem_id}"
    end

    def description_xpath
      '//div[@class="description"]'
    end

    def inputs_xpath
      '//div[@class="description"]/h2[starts-with(.,"Sample Input")]/following-sibling::pre[1]'
    end

    def outputs_xpath
      '//div[@class="description"]/h2[starts-with(.,"Sample Output") or starts-with(.,"Output for the Sample Input")]/following-sibling::pre[1]'
    end

    def working_directory
      @problem_id
    end
  end
end
